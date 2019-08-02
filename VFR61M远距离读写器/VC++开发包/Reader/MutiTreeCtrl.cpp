// MutiTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "MutiTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMutiTreeCtrl

CMutiTreeCtrl::CMutiTreeCtrl()
{
	m_uFlags=0;
}

CMutiTreeCtrl::~CMutiTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CMutiTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CMutiTreeCtrl)
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY_REFLECT(NM_CLICK, OnStateIconClick)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMutiTreeCtrl message handlers

void CMutiTreeCtrl::OnStateIconClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_uFlags&TVHT_ONITEMSTATEICON) *pResult=1;
	else *pResult = 0;
}

void CMutiTreeCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	HTREEITEM hItem = HitTest(point, &m_uFlags);
	if ( (m_uFlags&TVHT_ONITEMSTATEICON ))
	{
		//nState: 0->��ѡ��ť 1->û��ѡ�� 2->����ѡ�� 3->ȫ��ѡ��//0->no selection button 1->no selection2->part selection 3->all selection
		UINT nState = GetItemState( hItem, TVIS_STATEIMAGEMASK ) >> 12;
		nState=(nState==3)?1:3;
		SetItemState( hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
	}
		
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void CMutiTreeCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
 	//����ո��//handle the space key
 	if(nChar==0x20)
 	{
 		HTREEITEM hItem =GetSelectedItem();
 		UINT nState = GetItemState( hItem, TVIS_STATEIMAGEMASK ) >> 12;
 		if(nState!=0)
 		{
 			nState=(nState==3)?1:3;
 			SetItemState( hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
 		}
 	}
	else CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMutiTreeCtrl::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	
	*pResult = 0;
}

BOOL CMutiTreeCtrl::SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask, BOOL bSearch)
{
	BOOL bReturn=CTreeCtrl::SetItemState( hItem, nState, nStateMask );

	UINT iState = nState >> 12;
	if(iState!=0)
	{
		if(bSearch) TravelChild(hItem, iState);
		TravelSiblingAndParent(hItem,iState);
	}
	return bReturn;
}

void CMutiTreeCtrl::TravelChild(HTREEITEM hItem, int nState)
{
	HTREEITEM hChildItem,hBrotherItem;
	
	//�����ӽڵ㣬û�оͽ���//search child item, end it if not find
	hChildItem=GetChildItem(hItem);
	if(hChildItem!=NULL)
	{
		//�����ӽڵ��״̬�뵱ǰ�ڵ��״̬һ��//Set the state of the child item in accordance with state of the current item
		CTreeCtrl::SetItemState( hChildItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
		//�ٵݹ鴦���ӽڵ���ӽڵ���ֵܽڵ�//Recursive processing again the child item of the child item and siblings

		TravelChild(hChildItem, nState);
		
		//�����ӽڵ���ֵܽڵ�����ӽڵ�//handle child item's brother item and its child item
		hBrotherItem=GetNextSiblingItem(hChildItem);
		while (hBrotherItem)
		{
			//�����ӽڵ���ֵܽڵ�״̬�뵱ǰ�ڵ��״̬һ��//Set the child item of brothers item status in accordance with state of the current item
			int nState1 = GetItemState( hBrotherItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=0)
			{
				CTreeCtrl::SetItemState( hBrotherItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
			}
			//�ٵݹ鴦���ӽڵ���ֵܽڵ���ӽڵ���ֵܽڵ�//Recursive processing again the child item of the child item and siblings
			TravelChild(hBrotherItem, nState);
			hBrotherItem=GetNextSiblingItem(hBrotherItem);
		}
	}
}

void CMutiTreeCtrl::TravelSiblingAndParent(HTREEITEM hItem, int nState)
{
	HTREEITEM hNextSiblingItem,hPrevSiblingItem,hParentItem;
	
	//���Ҹ��ڵ㣬û�оͽ���//search parent item, end it if not find
	hParentItem=GetParentItem(hItem);
	if(hParentItem!=NULL)
	{
		int nState1=nState;//���ʼֵ����ֹû���ֵܽڵ�ʱ����//set initial value, to avoid error when no sibling item
		
		//���ҵ�ǰ�ڵ�������ֵܽڵ��״̬//Find the next sibling item state 
		hNextSiblingItem=GetNextSiblingItem(hItem);
		while(hNextSiblingItem!=NULL)
		{
			nState1 = GetItemState( hNextSiblingItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=nState && nState1!=0) break;
			else hNextSiblingItem=GetNextSiblingItem(hNextSiblingItem);
		}
		
		if(nState1==nState)
		{
			//���ҵ�ǰ�ڵ�������ֵܽڵ��״̬//find the previous sibling item state
			hPrevSiblingItem=GetPrevSiblingItem(hItem);
			while(hPrevSiblingItem!=NULL)
			{
				nState1 = GetItemState( hPrevSiblingItem, TVIS_STATEIMAGEMASK ) >> 12;
				if(nState1!=nState && nState1!=0) break;
				else hPrevSiblingItem=GetPrevSiblingItem(hPrevSiblingItem);
			}
		}
		
		if(nState1==nState || nState1==0)
		{
			nState1 = GetItemState( hParentItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=0)
			{
				//���״̬һ�£��򸸽ڵ��״̬�뵱ǰ�ڵ��״̬һ��//if state same, then parent item state accordance with current item state 
				CTreeCtrl::SetItemState( hParentItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
			}
			//�ٵݹ鴦���ڵ���ֵܽڵ���丸�ڵ�//Recursive processing again the brother item of the parent item and own parent item
			TravelSiblingAndParent(hParentItem,nState);
		}
		else
		{
			//״̬��һ�£���ǰ�ڵ�ĸ��ڵ㡢���ڵ�ĸ��ڵ㡭��״̬��Ϊ����̬//status not same, then current item's parent item, parent item's parents item all are third state
			hParentItem=GetParentItem(hItem);
			while(hParentItem!=NULL)
			{
				nState1 = GetItemState( hParentItem, TVIS_STATEIMAGEMASK ) >> 12;
				if(nState1!=0)
				{
					CTreeCtrl::SetItemState( hParentItem, INDEXTOSTATEIMAGEMASK(2), TVIS_STATEIMAGEMASK );
				}
				hParentItem=GetParentItem(hParentItem);
			}
		}
	}	
}

void CMutiTreeCtrl::SetSecondLevelState(HTREEITEM hItem)
{
	//nState: 0->��ѡ��ť 1->û��ѡ�� 2->����ѡ�� 3->ȫ��ѡ��//0->no selection button 1->no selection 2->part selection 3->all selection
	UINT nState = GetItemState( hItem, TVIS_STATEIMAGEMASK ) >> 12;
	nState=(nState==3)?1:3;
	SetItemState( hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
}
