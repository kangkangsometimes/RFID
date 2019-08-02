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
		//nState: 0->无选择钮 1->没有选择 2->部分选择 3->全部选择//0->no selection button 1->no selection2->part selection 3->all selection
		UINT nState = GetItemState( hItem, TVIS_STATEIMAGEMASK ) >> 12;
		nState=(nState==3)?1:3;
		SetItemState( hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
	}
		
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void CMutiTreeCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
 	//处理空格键//handle the space key
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
	
	//查找子节点，没有就结束//search child item, end it if not find
	hChildItem=GetChildItem(hItem);
	if(hChildItem!=NULL)
	{
		//设置子节点的状态与当前节点的状态一致//Set the state of the child item in accordance with state of the current item
		CTreeCtrl::SetItemState( hChildItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
		//再递归处理子节点的子节点和兄弟节点//Recursive processing again the child item of the child item and siblings

		TravelChild(hChildItem, nState);
		
		//处理子节点的兄弟节点和其子节点//handle child item's brother item and its child item
		hBrotherItem=GetNextSiblingItem(hChildItem);
		while (hBrotherItem)
		{
			//设置子节点的兄弟节点状态与当前节点的状态一致//Set the child item of brothers item status in accordance with state of the current item
			int nState1 = GetItemState( hBrotherItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=0)
			{
				CTreeCtrl::SetItemState( hBrotherItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
			}
			//再递归处理子节点的兄弟节点的子节点和兄弟节点//Recursive processing again the child item of the child item and siblings
			TravelChild(hBrotherItem, nState);
			hBrotherItem=GetNextSiblingItem(hBrotherItem);
		}
	}
}

void CMutiTreeCtrl::TravelSiblingAndParent(HTREEITEM hItem, int nState)
{
	HTREEITEM hNextSiblingItem,hPrevSiblingItem,hParentItem;
	
	//查找父节点，没有就结束//search parent item, end it if not find
	hParentItem=GetParentItem(hItem);
	if(hParentItem!=NULL)
	{
		int nState1=nState;//设初始值，防止没有兄弟节点时出错//set initial value, to avoid error when no sibling item
		
		//查找当前节点下面的兄弟节点的状态//Find the next sibling item state 
		hNextSiblingItem=GetNextSiblingItem(hItem);
		while(hNextSiblingItem!=NULL)
		{
			nState1 = GetItemState( hNextSiblingItem, TVIS_STATEIMAGEMASK ) >> 12;
			if(nState1!=nState && nState1!=0) break;
			else hNextSiblingItem=GetNextSiblingItem(hNextSiblingItem);
		}
		
		if(nState1==nState)
		{
			//查找当前节点上面的兄弟节点的状态//find the previous sibling item state
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
				//如果状态一致，则父节点的状态与当前节点的状态一致//if state same, then parent item state accordance with current item state 
				CTreeCtrl::SetItemState( hParentItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
			}
			//再递归处理父节点的兄弟节点和其父节点//Recursive processing again the brother item of the parent item and own parent item
			TravelSiblingAndParent(hParentItem,nState);
		}
		else
		{
			//状态不一致，则当前节点的父节点、父节点的父节点……状态均为第三态//status not same, then current item's parent item, parent item's parents item all are third state
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
	//nState: 0->无选择钮 1->没有选择 2->部分选择 3->全部选择//0->no selection button 1->no selection 2->part selection 3->all selection
	UINT nState = GetItemState( hItem, TVIS_STATEIMAGEMASK ) >> 12;
	nState=(nState==3)?1:3;
	SetItemState( hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK );
}
