// FreqPoints.cpp : implementation file
//

#include "stdafx.h"
#include "uhfreader.h"
#include "FreqPoints.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFreqPoints dialog
int freqpoints[124] ={0};
int freqnum = 0;

extern int Freqpoints[124];
extern int Freqnum;

HTREEITEM Childnode[124];
CFreqPoints::CFreqPoints(CWnd* pParent /*=NULL*/)
	: CDialog(CFreqPoints::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFreqPoints)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CFreqPoints::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFreqPoints)
	DDX_Control(pDX, IDC_TREE, m_TripleTree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFreqPoints, CDialog)
	//{{AFX_MSG_MAP(CFreqPoints)
	ON_BN_CLICKED(IDC_CANCEL_BUTTON, OnCancelButton)
	ON_BN_CLICKED(IDC_ENTER_BUTTON, OnEnterButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFreqPoints message handlers

BOOL CFreqPoints::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//加入WS_EX_LAYERED扩展属性//expand property
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,
	GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	if(hInst) 
	{ 
		typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD); 
		MYFUNC fun = NULL;
		//取得SetLayeredWindowAttributes函数指针//function pointer 
		fun=(MYFUNC)GetProcAddress(hInst, "SetLayeredWindowAttributes");
		if(fun)fun(this->GetSafeHwnd(),0,200,2); 
		FreeLibrary(hInst); 
	}
	//tree控件初始化//ActiveX initialization
	InitializeTree();
	SetTree();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFreqPoints::InitializeTree()
{
	m_imgState.Create(IDB_BITMAP_STATE,13, 1, RGB(255,255,255));
	m_imgList.Create(IDB_BITMAP_LIST,16, 1, RGB(255,255,255));
	
	m_TripleTree.SetImageList(&m_imgList,TVSIL_NORMAL);
	m_TripleTree.SetImageList(&m_imgState,TVSIL_STATE);
	
	TV_INSERTSTRUCT tvinsert;
	tvinsert.hParent=NULL;
	tvinsert.hInsertAfter=TVI_LAST;
	tvinsert.item.mask=TVIF_IMAGE|TVIF_SELECTEDIMAGE|TVIF_TEXT|TVIF_STATE;
	tvinsert.item.hItem=NULL;
	tvinsert.item.state=INDEXTOSTATEIMAGEMASK( 1 );
	tvinsert.item.stateMask=TVIS_STATEIMAGEMASK;
	tvinsert.item.cchTextMax=6;
	tvinsert.item.iSelectedImage=1;
	tvinsert.item.cChildren=0;
	tvinsert.item.lParam=0;
	
	/*first level*****************************************************/
	tvinsert.item.pszText="读写器射频参数-频点";//reader RF parameter-frequency point
	tvinsert.item.iImage=0;
	HTREEITEM hRoot=m_TripleTree.InsertItem(&tvinsert);
	m_TripleTree.SetItemState( hRoot, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK );
	
	/*second level*****************************************************/
	tvinsert.hParent = hRoot;
	tvinsert.item.iImage = 0;
	tvinsert.item.pszText = "900";
	h900 = m_TripleTree.InsertItem(&tvinsert);
	
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "901";
	h901 = m_TripleTree.InsertItem(&tvinsert);
	
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "902";
	h902 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "903";
	h903 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "904";
	h904 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "905";
	h905 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "906";
	h906 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "907";
	h907 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "908";
	h908 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "909";
	h909 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "910";
	h910 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "911";
	h911 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "912";
	h912 = m_TripleTree.InsertItem(&tvinsert);
	
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "913";
	h913 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent=hRoot;
	tvinsert.item.pszText="914";
	h914 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "915";
	h915 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent=hRoot;
	tvinsert.item.pszText="916";
	h916 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "917";
	h917 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent=hRoot;
	tvinsert.item.pszText="918";
	h918 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "919";
	h919 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "920";
	h920 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "921";
	h921 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "922";
	h922 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "923";
	h923 = m_TripleTree.InsertItem(&tvinsert);
	
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "924";
	h924 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "925";
	h925 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "926";
	h926 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "927";
	h927 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "928";
	h928 = m_TripleTree.InsertItem(&tvinsert);
	
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "929";
	h929 = m_TripleTree.InsertItem(&tvinsert);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = "930";
	h930 = m_TripleTree.InsertItem(&tvinsert);
	/*third level*****************************************************/
	tvinsert.hParent=h900;
	tvinsert.item.pszText="900.00";
	c0 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[0] = c0;
	m_TripleTree.SetItemData(c0, 0);  

	tvinsert.hParent=h900;
	tvinsert.item.pszText="900.25";
	c1 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[1] = c1;
	m_TripleTree.SetItemData(c1, 1);   

	tvinsert.hParent=h900;
	tvinsert.item.pszText="900.50";
	c2 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[2] = c2;
	m_TripleTree.SetItemData(c2, 2);   
	
	tvinsert.hParent=h900;
	tvinsert.item.pszText="900.75";
	c3 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[3] = c3;
	m_TripleTree.SetItemData(c3, 3);  
	/*************************************/
	tvinsert.hParent=h901;
	tvinsert.item.pszText="901.00";
	c4 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[4] = c4;
	m_TripleTree.SetItemData(c4, 4);  

	tvinsert.hParent=h901;
	tvinsert.item.pszText="901.25";
	c5 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[5] = c5;
	m_TripleTree.SetItemData(c5, 5);    

	tvinsert.hParent=h901;
	tvinsert.item.pszText="901.50";
	c6 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[6] = c6;
	m_TripleTree.SetItemData(c6, 6);  
	
	tvinsert.hParent=h901;
	tvinsert.item.pszText="901.75";
	c7 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[7] = c7;
	m_TripleTree.SetItemData(c7, 7);  
	/*************************************/
	tvinsert.hParent=h902;
	tvinsert.item.pszText="902.00";
	c8 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[8] = c8;
	m_TripleTree.SetItemData(c8, 8);  

	tvinsert.hParent=h902;
	tvinsert.item.pszText="902.25";
	c9 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[9] = c9;
	m_TripleTree.SetItemData(c9, 9);  

	tvinsert.hParent=h902;
	tvinsert.item.pszText="902.50";
	c10 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[10] = c10;
	m_TripleTree.SetItemData(c10, 10);  
	
	tvinsert.hParent=h902;
	tvinsert.item.pszText="902.75";
	c11 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[11] = c11;
	m_TripleTree.SetItemData(c11, 11);
	/*************************************/
	tvinsert.hParent=h903;
	tvinsert.item.pszText="903.00";
	c12 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[12] = c12;
	m_TripleTree.SetItemData(c12, 12);

	tvinsert.hParent=h903;
	tvinsert.item.pszText="903.25";
	c13 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[13] = c13;
	m_TripleTree.SetItemData(c13, 13);

	tvinsert.hParent=h903;
	tvinsert.item.pszText="903.50";
	c14 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[14] = c14;
	m_TripleTree.SetItemData(c14, 14);
	
	tvinsert.hParent=h903;
	tvinsert.item.pszText="903.75";
	c15 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[15] = c15;
	m_TripleTree.SetItemData(c15, 15);
	/*************************************/
	tvinsert.hParent=h904;
	tvinsert.item.pszText="904.00";
	c16 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[16] = c16;
	m_TripleTree.SetItemData(c16, 16);

	tvinsert.hParent=h904;
	tvinsert.item.pszText="904.25";
	c17 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[17] = c17;
	m_TripleTree.SetItemData(c17, 17);

	tvinsert.hParent=h904;
	tvinsert.item.pszText="904.50";
	c18 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[18] = c18;
	m_TripleTree.SetItemData(c18, 18);
	
	tvinsert.hParent=h904;
	tvinsert.item.pszText="904.75";
	c19 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[19] = c19;
	m_TripleTree.SetItemData(c19, 19);
	/*************************************/
	tvinsert.hParent=h905;
	tvinsert.item.pszText="905.00";
	c20 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[20] = c20;
	m_TripleTree.SetItemData(c20, 20);

	tvinsert.hParent=h905;
	tvinsert.item.pszText="905.25";
	c21 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[21] = c21;
	m_TripleTree.SetItemData(c21, 21);

	tvinsert.hParent=h905;
	tvinsert.item.pszText="905.50";
	c22 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[22] = c22;
	m_TripleTree.SetItemData(c22, 22);
	
	tvinsert.hParent=h905;
	tvinsert.item.pszText="905.75";
	c23 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[23] = c23;
	m_TripleTree.SetItemData(c23, 23);
	/*************************************/
	tvinsert.hParent=h906;
	tvinsert.item.pszText="906.00";
	c24 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[24] = c24;
	m_TripleTree.SetItemData(c24, 24);

	tvinsert.hParent=h906;
	tvinsert.item.pszText="906.25";
	c25 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[25] = c25;
	m_TripleTree.SetItemData(c25, 25);

	tvinsert.hParent=h906;
	tvinsert.item.pszText="906.50";
	c26 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[26] = c26;
	m_TripleTree.SetItemData(c26, 26);
	
	tvinsert.hParent=h906;
	tvinsert.item.pszText="906.75";
	c27 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[27] = c27;
	m_TripleTree.SetItemData(c27, 27);
	/*************************************/
	tvinsert.hParent=h907;
	tvinsert.item.pszText="907.00";
	c28 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[28] = c28;
	m_TripleTree.SetItemData(c28, 28);

	tvinsert.hParent=h907;
	tvinsert.item.pszText="907.25";
	c29 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[29] = c29;
	m_TripleTree.SetItemData(c29, 29);

	tvinsert.hParent=h907;
	tvinsert.item.pszText="907.50";
	c30 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[30] = c30;
	m_TripleTree.SetItemData(c30, 30);
	
	tvinsert.hParent=h907;
	tvinsert.item.pszText="907.75";
	c31 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[31] = c31;
	m_TripleTree.SetItemData(c31, 31);
	/*************************************/
	tvinsert.hParent=h908;
	tvinsert.item.pszText="908.00";
	c32 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[32] = c32;
	m_TripleTree.SetItemData(c32, 32);

	tvinsert.hParent=h908;
	tvinsert.item.pszText="908.25";
	c33 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[33] = c33;
	m_TripleTree.SetItemData(c33, 33);

	tvinsert.hParent=h908;
	tvinsert.item.pszText="908.50";
	c34 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[34] = c34;
	m_TripleTree.SetItemData(c34, 34);
	
	tvinsert.hParent=h908;
	tvinsert.item.pszText="908.75";
	c35 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[35] = c35;
	m_TripleTree.SetItemData(c35, 35);
	/*************************************/
	tvinsert.hParent=h909;
	tvinsert.item.pszText="909.00";
	c36 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[36] = c36;
	m_TripleTree.SetItemData(c36, 36);

	tvinsert.hParent=h909;
	tvinsert.item.pszText="909.25";
	c37 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[37] = c37;
	m_TripleTree.SetItemData(c37, 37);

	tvinsert.hParent=h909;
	tvinsert.item.pszText="909.50";
	c38 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[38] = c38;
	m_TripleTree.SetItemData(c38, 38);
	
	tvinsert.hParent=h909;
	tvinsert.item.pszText="909.75";
	c39 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[39] = c39;
	m_TripleTree.SetItemData(c39, 39);
	/*************************************/
	tvinsert.hParent=h910;
	tvinsert.item.pszText="910.00";
	c40 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[40] = c40;
	m_TripleTree.SetItemData(c40, 40);

	tvinsert.hParent=h910;
	tvinsert.item.pszText="910.25";
	c41 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[41] = c41;
	m_TripleTree.SetItemData(c41, 41);

	tvinsert.hParent=h910;
	tvinsert.item.pszText="910.50";
	c42 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[42] = c42;
	m_TripleTree.SetItemData(c42, 42);
	
	tvinsert.hParent=h910;
	tvinsert.item.pszText="910.75";
	c43 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[43] = c43;
	m_TripleTree.SetItemData(c43, 43);
	/*************************************/
	tvinsert.hParent=h911;
	tvinsert.item.pszText="911.00";
	c44 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[44] = c44;
	m_TripleTree.SetItemData(c44, 44);

	tvinsert.hParent=h911;
	tvinsert.item.pszText="911.25";
	c45 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[45] = c45;
	m_TripleTree.SetItemData(c45, 45);

	tvinsert.hParent=h911;
	tvinsert.item.pszText="911.50";
	c46 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[46] = c46;
	m_TripleTree.SetItemData(c46, 46);
	
	tvinsert.hParent=h911;
	tvinsert.item.pszText="911.75";
	c47 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[47] = c47;
	m_TripleTree.SetItemData(c47, 47);
	/*************************************/
	tvinsert.hParent=h912;
	tvinsert.item.pszText="912.00";
	c48 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[48] = c48;
	m_TripleTree.SetItemData(c48, 48);

	tvinsert.hParent=h912;
	tvinsert.item.pszText="912.25";
	c49 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[49] = c49;
	m_TripleTree.SetItemData(c49, 49);

	tvinsert.hParent=h912;
	tvinsert.item.pszText="912.50";
	c50 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[50] = c50;
	m_TripleTree.SetItemData(c50, 50);
	
	tvinsert.hParent=h912;
	tvinsert.item.pszText="912.75";
	c51 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[51] = c51;
	m_TripleTree.SetItemData(c51, 51);
	/*************************************/
	tvinsert.hParent=h913;
	tvinsert.item.pszText="913.00";
	c52 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[52] = c52;
	m_TripleTree.SetItemData(c52, 52);

	tvinsert.hParent=h913;
	tvinsert.item.pszText="913.25";
	c53 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[53] = c53;
	m_TripleTree.SetItemData(c53, 53);

	tvinsert.hParent=h913;
	tvinsert.item.pszText="913.50";
	c54 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[54] = c54;
	m_TripleTree.SetItemData(c54, 54);
	
	tvinsert.hParent=h913;
	tvinsert.item.pszText="913.75";
	c55 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[55] = c55;
	m_TripleTree.SetItemData(c55, 55);
	/*************************************/
	tvinsert.hParent=h914;
	tvinsert.item.pszText="914.00";
	c56 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[56] = c56;
	m_TripleTree.SetItemData(c56, 56);

	tvinsert.hParent=h914;
	tvinsert.item.pszText="914.25";
	c57 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[57] = c57;
	m_TripleTree.SetItemData(c57, 57);

	tvinsert.hParent=h914;
	tvinsert.item.pszText="914.50";
	c58 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[58] = c58;
	m_TripleTree.SetItemData(c58, 58);
	
	tvinsert.hParent=h914;
	tvinsert.item.pszText="914.75";
	c59 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[59] = c59;
	m_TripleTree.SetItemData(c59, 59);
	/*************************************/
	tvinsert.hParent=h915;
	tvinsert.item.pszText="915.00";
	c60 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[60] = c60;
	m_TripleTree.SetItemData(c60, 60);

	tvinsert.hParent=h915;
	tvinsert.item.pszText="915.25";
	c61 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[61] = c61;
	m_TripleTree.SetItemData(c61, 61);

	tvinsert.hParent=h915;
	tvinsert.item.pszText="915.50";
	c62 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[62] = c62;
	m_TripleTree.SetItemData(c62, 62);
	
	tvinsert.hParent=h915;
	tvinsert.item.pszText="915.75";
	c63 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[63] = c63;
	m_TripleTree.SetItemData(c63, 63);
	/*************************************/
	tvinsert.hParent=h916;
	tvinsert.item.pszText="916.00";
	c64 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[64] = c64;
	m_TripleTree.SetItemData(c64, 64);

	tvinsert.hParent=h916;
	tvinsert.item.pszText="916.25";
	c65 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[65] = c65;
	m_TripleTree.SetItemData(c65, 65);

	tvinsert.hParent=h916;
	tvinsert.item.pszText="916.50";
	c66 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[66] = c66;
	m_TripleTree.SetItemData(c66, 66);
	
	tvinsert.hParent=h916;
	tvinsert.item.pszText="916.75";
	c67 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[67] = c67;
	m_TripleTree.SetItemData(c67, 67);
	/*************************************/
	tvinsert.hParent=h917;
	tvinsert.item.pszText="917.00";
	c68 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[68] = c68;
	m_TripleTree.SetItemData(c68, 68);

	tvinsert.hParent=h917;
	tvinsert.item.pszText="917.25";
	c69 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[69] = c69;
	m_TripleTree.SetItemData(c69, 69);

	tvinsert.hParent=h917;
	tvinsert.item.pszText="917.50";
	c70 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[70] = c70;
	m_TripleTree.SetItemData(c70, 70);
	
	tvinsert.hParent=h917;
	tvinsert.item.pszText="917.75";
	c71 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[71] = c71;
	m_TripleTree.SetItemData(c71, 71);
	/*************************************/
	tvinsert.hParent=h918;
	tvinsert.item.pszText="918.00";
	c72 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[72] = c72;
	m_TripleTree.SetItemData(c72, 72);

	tvinsert.hParent=h918;
	tvinsert.item.pszText="918.25";
	c73 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[73] = c73;
	m_TripleTree.SetItemData(c73, 73);

	tvinsert.hParent=h918;
	tvinsert.item.pszText="918.50";
	c74 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[74] = c74;
	m_TripleTree.SetItemData(c74, 74);
	
	tvinsert.hParent=h918;
	tvinsert.item.pszText="918.75";
	c75 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[75] = c75;
	m_TripleTree.SetItemData(c75, 75);
	/*************************************/
	tvinsert.hParent=h919;
	tvinsert.item.pszText="919.00";
	c76 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[76] = c76;
	m_TripleTree.SetItemData(c76, 76);

	tvinsert.hParent=h919;
	tvinsert.item.pszText="919.25";
	c77 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[77] = c77;
	m_TripleTree.SetItemData(c77, 77);

	tvinsert.hParent=h919;
	tvinsert.item.pszText="919.50";
	c78 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[78] = c78;
	m_TripleTree.SetItemData(c78, 78);
	
	tvinsert.hParent=h919;
	tvinsert.item.pszText="919.75";
	c79 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[79] = c79;
	m_TripleTree.SetItemData(c79, 79);
	/*************************************/
	tvinsert.hParent=h920;
	tvinsert.item.pszText="920.00";
	c80 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[80] = c80;
	m_TripleTree.SetItemData(c80, 80);

	tvinsert.hParent=h920;
	tvinsert.item.pszText="920.25";
	c81 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[81] = c81;
	m_TripleTree.SetItemData(c81, 81);

	tvinsert.hParent=h920;
	tvinsert.item.pszText="920.50";
	c82 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[82] = c82;
	m_TripleTree.SetItemData(c82, 82);
	
	tvinsert.hParent=h920;
	tvinsert.item.pszText="920.75";
	c83 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[83] = c83;
	m_TripleTree.SetItemData(c83, 83);
	/*************************************/
	tvinsert.hParent=h921;
	tvinsert.item.pszText="921.00";
	c84 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[84] = c84;
	m_TripleTree.SetItemData(c84, 84);

	tvinsert.hParent=h921;
	tvinsert.item.pszText="921.25";
	c85 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[85] = c85;
	m_TripleTree.SetItemData(c85, 85);

	tvinsert.hParent=h921;
	tvinsert.item.pszText="921.50";
	c86 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[86] = c86;
	m_TripleTree.SetItemData(c86, 86);
	
	tvinsert.hParent=h921;
	tvinsert.item.pszText="921.75";
	c87 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[87] = c87;
	m_TripleTree.SetItemData(c87, 87);
	/*************************************/
	tvinsert.hParent=h922;
	tvinsert.item.pszText="922.00";
	c88 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[88] = c88;
	m_TripleTree.SetItemData(c88, 88);

	tvinsert.hParent=h922;
	tvinsert.item.pszText="922.25";
	c89 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[89] = c89;
	m_TripleTree.SetItemData(c89, 89);

	tvinsert.hParent=h922;
	tvinsert.item.pszText="922.50";
	c90 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[90] = c90;
	m_TripleTree.SetItemData(c90, 90);
	
	tvinsert.hParent=h922;
	tvinsert.item.pszText="922.75";
	c91 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[91] = c91;
	m_TripleTree.SetItemData(c91, 91);
	/*************************************/
	tvinsert.hParent=h923;
	tvinsert.item.pszText="923.00";
	c92 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[92] = c92;
	m_TripleTree.SetItemData(c92, 92);

	tvinsert.hParent=h923;
	tvinsert.item.pszText="923.25";
	c93 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[93] = c93;
	m_TripleTree.SetItemData(c93, 93);

	tvinsert.hParent=h923;
	tvinsert.item.pszText="923.50";
	c94 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[94] = c94;
	m_TripleTree.SetItemData(c94, 94);
	
	tvinsert.hParent=h923;
	tvinsert.item.pszText="923.75";
	c95 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[95] = c95;
	m_TripleTree.SetItemData(c95, 95);
	/*************************************/
	tvinsert.hParent=h924;
	tvinsert.item.pszText="924.00";
	c96 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[96] = c96;
	m_TripleTree.SetItemData(c96, 96);

	tvinsert.hParent=h924;
	tvinsert.item.pszText="924.25";
	c97 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[97] = c97;
	m_TripleTree.SetItemData(c97, 97);

	tvinsert.hParent=h924;
	tvinsert.item.pszText="924.50";
	c98 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[98] = c98;
	m_TripleTree.SetItemData(c98, 98);
	
	tvinsert.hParent=h924;
	tvinsert.item.pszText="924.75";
	c99 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[99] = c99;
	m_TripleTree.SetItemData(c99, 99);
	/*************************************/
	tvinsert.hParent=h925;
	tvinsert.item.pszText="925.00";
	c100 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[100] = c100;
	m_TripleTree.SetItemData(c100, 100);

	tvinsert.hParent=h925;
	tvinsert.item.pszText="925.25";
	c101 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[101] = c101;
	m_TripleTree.SetItemData(c101, 101);

	tvinsert.hParent=h925;
	tvinsert.item.pszText="925.50";
	c102 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[102] = c102;
	m_TripleTree.SetItemData(c102, 102);
	
	tvinsert.hParent=h925;
	tvinsert.item.pszText="925.75";
	c103 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[103] = c103;
	m_TripleTree.SetItemData(c103, 103);
	/*************************************/
	tvinsert.hParent=h926;
	tvinsert.item.pszText="926.00";
	c104 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[104] = c104;
	m_TripleTree.SetItemData(c104, 104);

	tvinsert.hParent=h926;
	tvinsert.item.pszText="926.25";
	c105 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[105] = c105;
	m_TripleTree.SetItemData(c105, 105);

	tvinsert.hParent=h926;
	tvinsert.item.pszText="926.50";
	c106 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[106] = c106;
	m_TripleTree.SetItemData(c106, 106);
	
	tvinsert.hParent=h926;
	tvinsert.item.pszText="926.75";
	c107 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[107] = c107;
	m_TripleTree.SetItemData(c107, 107);
	/*************************************/
	tvinsert.hParent=h927;
	tvinsert.item.pszText="927.00";
	c108 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[108] = c108;
	m_TripleTree.SetItemData(c108, 108);

	tvinsert.hParent=h927;
	tvinsert.item.pszText="927.25";
	c109 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[109] = c109;
	m_TripleTree.SetItemData(c109, 109);

	tvinsert.hParent=h927;
	tvinsert.item.pszText="927.50";
	c110 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[110] = c110;
	m_TripleTree.SetItemData(c110, 110);
	
	tvinsert.hParent=h927;
	tvinsert.item.pszText="927.75";
	c111 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[111] = c111;
	m_TripleTree.SetItemData(c111, 111);
	/*************************************/
	tvinsert.hParent=h928;
	tvinsert.item.pszText="928.00";
	c112 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[112] = c112;
	m_TripleTree.SetItemData(c112, 112);

	tvinsert.hParent=h928;
	tvinsert.item.pszText="928.25";
	c113 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[113] = c113;
	m_TripleTree.SetItemData(c113, 113);

	tvinsert.hParent=h928;
	tvinsert.item.pszText="928.50";
	c114 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[114] = c114;
	m_TripleTree.SetItemData(c114, 114);
	
	tvinsert.hParent=h928;
	tvinsert.item.pszText="928.75";
	c115 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[115] = c115;
	m_TripleTree.SetItemData(c115, 115);
	/*************************************/
	tvinsert.hParent=h929;
	tvinsert.item.pszText="929.00";
	c116 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[116] = c116;
	m_TripleTree.SetItemData(c116, 116);

	tvinsert.hParent=h929;
	tvinsert.item.pszText="929.25";
	c117 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[117] = c117;
	m_TripleTree.SetItemData(c117, 117);

	tvinsert.hParent=h929;
	tvinsert.item.pszText="929.50";
	c118 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[118] = c118;
	m_TripleTree.SetItemData(c118, 118);
	
	tvinsert.hParent=h929;
	tvinsert.item.pszText="929.75";
	c119 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[119] = c119;
	m_TripleTree.SetItemData(c119, 119);
	/*************************************/
	tvinsert.hParent=h930;
	tvinsert.item.pszText="930.00";
	c120 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[120] = c120;
	m_TripleTree.SetItemData(c120, 120);

	tvinsert.hParent=h930;
	tvinsert.item.pszText="930.25";
	c121 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[121] = c121;
	m_TripleTree.SetItemData(c121, 121);

	tvinsert.hParent=h930;
	tvinsert.item.pszText="930.50";
	c122 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[122] = c122;
	m_TripleTree.SetItemData(c122, 122);
	
	tvinsert.hParent=h930;
	tvinsert.item.pszText="930.75";
	c123 = m_TripleTree.InsertItem(&tvinsert);
	Childnode[123] = c123;
	m_TripleTree.SetItemData(c123, 123);
	/*************************************/
}

void CFreqPoints::OnCancelButton() 
{
	// TODO: Add your control notification handler code here
	//this->EndDialog(0);
	DestroyWindow(); 
}

void CFreqPoints::OnEnterButton()
{
	// TODO: Add your control notification handler code here
	//获取选中状态并将其发送给systemconfig窗口//get selected status and send to systemconfig window
	freqnum = 0;
	for(int i = 0; i < 124; i++)
	{
		if( m_TripleTree.GetItemState(Childnode[i], LVIS_SELECTED) == LVIS_SELECTED || m_TripleTree.GetCheck(Childnode[i])) 
		{  
			freqpoints[freqnum] = m_TripleTree.GetItemData(Childnode[i]);
			freqnum ++;
		}
	}
	//this->EndDialog(0);
	DestroyWindow(); 
}

void CFreqPoints::SetTree()
{
	for(int i = 0; i < Freqnum; i++)
	{
		switch(Freqpoints[i])
		{
		case 0:
			m_TripleTree.SetSecondLevelState(c0);
			break;
		case 1:
			m_TripleTree.SetSecondLevelState(c1);
			break;
		case 2:
			m_TripleTree.SetSecondLevelState(c2);
			break;
		case 3:
			m_TripleTree.SetSecondLevelState(c3);
			break;
		case 4:
			m_TripleTree.SetSecondLevelState(c4);
			break;
		case 5:
			m_TripleTree.SetSecondLevelState(c5);
			break;
		case 6:
			m_TripleTree.SetSecondLevelState(c6);
			break;
		case 7:
			m_TripleTree.SetSecondLevelState(c7);
			break;
		case 8:
			m_TripleTree.SetSecondLevelState(c8);
			break;
		case 9:
			m_TripleTree.SetSecondLevelState(c9);
			break;
		case 10:
			m_TripleTree.SetSecondLevelState(c10);
			break;
		case 11:
			m_TripleTree.SetSecondLevelState(c11);
			break;
		case 12:
			m_TripleTree.SetSecondLevelState(c12);
			break;
		case 13:
			m_TripleTree.SetSecondLevelState(c13);
			break;
		case 14:
			m_TripleTree.SetSecondLevelState(c14);
			break;
		case 15:
			m_TripleTree.SetSecondLevelState(c15);
			break;
		case 16:
			m_TripleTree.SetSecondLevelState(c16);
			break;
		case 17:
			m_TripleTree.SetSecondLevelState(c17);
			break;
		case 18:
			m_TripleTree.SetSecondLevelState(c18);
			break;
		case 19:
			m_TripleTree.SetSecondLevelState(c19);
			break;
		case 20:
			m_TripleTree.SetSecondLevelState(c20);
			break;
		case 21:
			m_TripleTree.SetSecondLevelState(c21);
			break;
		case 22:
			m_TripleTree.SetSecondLevelState(c22);
			break;
		case 23:
			m_TripleTree.SetSecondLevelState(c23);
			break;
		case 24:
			m_TripleTree.SetSecondLevelState(c24);
			break;
		case 25:
			m_TripleTree.SetSecondLevelState(c25);
			break;
		case 26:
			m_TripleTree.SetSecondLevelState(c26);
			break;
		case 27:
			m_TripleTree.SetSecondLevelState(h906);
			break;
		case 28:
			m_TripleTree.SetSecondLevelState(c28);
			break;
		case 29:
			m_TripleTree.SetSecondLevelState(c29);
			break;
		case 30:
			m_TripleTree.SetSecondLevelState(c30);
			break;
		case 31:
			m_TripleTree.SetSecondLevelState(c31);
			break;
		case 32:
			m_TripleTree.SetSecondLevelState(c32);
			break;
		case 33:
			m_TripleTree.SetSecondLevelState(c33);
			break;
		case 34:
			m_TripleTree.SetSecondLevelState(c34);
			break;
		case 35:
			m_TripleTree.SetSecondLevelState(c35);
			break;
		case 36:
			m_TripleTree.SetSecondLevelState(c35);
			break;
		case 37:
			m_TripleTree.SetSecondLevelState(c37);
			break;
		case 38:
			m_TripleTree.SetSecondLevelState(c38);
			break;
		case 39:
			m_TripleTree.SetSecondLevelState(c39);
			break;
		case 40:
			m_TripleTree.SetSecondLevelState(c40);
			break;
		case 41:
			m_TripleTree.SetSecondLevelState(c41);
			break;
		case 42:
			m_TripleTree.SetSecondLevelState(c42);
			break;
		case 43:
			m_TripleTree.SetSecondLevelState(c43);
			break;
		case 44:
			m_TripleTree.SetSecondLevelState(c44);
			break;
		case 45:
			m_TripleTree.SetSecondLevelState(c45);
			break;
		case 46:
			m_TripleTree.SetSecondLevelState(c46);
			break;
		case 47:
			m_TripleTree.SetSecondLevelState(c47);
			break;
		case 48:
			m_TripleTree.SetSecondLevelState(c48);
			break;
		case 49:
			m_TripleTree.SetSecondLevelState(c49);
			break;
		case 50:
			m_TripleTree.SetSecondLevelState(c50);
			break;
		case 51:
			m_TripleTree.SetSecondLevelState(c51);
			break;
		case 52:
			m_TripleTree.SetSecondLevelState(c52);
			break;
		case 53:
			m_TripleTree.SetSecondLevelState(c53);
			break;
		case 54:
			m_TripleTree.SetSecondLevelState(c54);
			break;
		case 55:
			m_TripleTree.SetSecondLevelState(h913);
			break;
		case 56:
			m_TripleTree.SetSecondLevelState(c56);
			break;
		case 57:
			m_TripleTree.SetSecondLevelState(c57);
			break;
		case 58:
			m_TripleTree.SetSecondLevelState(c58);
			break;
		case 59:
			m_TripleTree.SetSecondLevelState(c59);
			break;
		case 60:
			m_TripleTree.SetSecondLevelState(c60);
			break;
		case 61:
			m_TripleTree.SetSecondLevelState(c61);
			break;
		case 62:
			m_TripleTree.SetSecondLevelState(c62);
			break;
		case 63:
			m_TripleTree.SetSecondLevelState(c63);
			break;
		case 64:
			m_TripleTree.SetSecondLevelState(c64);
			break;
		case 65:
			m_TripleTree.SetSecondLevelState(c65);
			break;
		case 66:
			m_TripleTree.SetSecondLevelState(c66);
			break;
		case 67:
			m_TripleTree.SetSecondLevelState(c67);
			break;
		case 68:
			m_TripleTree.SetSecondLevelState(c68);
			break;
		case 69:
			m_TripleTree.SetSecondLevelState(c69);
			break;
		case 70:
			m_TripleTree.SetSecondLevelState(c70);
			break;
		case 71:
			m_TripleTree.SetSecondLevelState(c71);
			break;
		case 72:
			m_TripleTree.SetSecondLevelState(c72);
			break;
		case 73:
			m_TripleTree.SetSecondLevelState(c73);
			break;
		case 74:
			m_TripleTree.SetSecondLevelState(c74);
			break;
		case 75:
			m_TripleTree.SetSecondLevelState(c75);
			break;
		case 76:
			m_TripleTree.SetSecondLevelState(c76);
			break;
		case 77:
			m_TripleTree.SetSecondLevelState(c77);
			break;
		case 78:
			m_TripleTree.SetSecondLevelState(c78);
			break;
		case 79:
			m_TripleTree.SetSecondLevelState(c79);
			break;
		case 80:
			m_TripleTree.SetSecondLevelState(c80);
			break;
		case 81:
			m_TripleTree.SetSecondLevelState(c81);
			break;
		case 82:
			m_TripleTree.SetSecondLevelState(c82);
			break;
		case 83:
			m_TripleTree.SetSecondLevelState(c83);
			break;
		case 84:
			m_TripleTree.SetSecondLevelState(c84);
			break;
		case 85:
			m_TripleTree.SetSecondLevelState(c85);
			break;
		case 86:
			m_TripleTree.SetSecondLevelState(c86);
			break;
		case 87:
			m_TripleTree.SetSecondLevelState(c87);
			break;
		case 88:
			m_TripleTree.SetSecondLevelState(c88);
			break;
		case 89:
			m_TripleTree.SetSecondLevelState(c89);
			break;
		case 90:
			m_TripleTree.SetSecondLevelState(c90);
			break;
		case 91:
			m_TripleTree.SetSecondLevelState(c91);
			break;
		case 92:
			m_TripleTree.SetSecondLevelState(c92);
			break;
		case 93:
			m_TripleTree.SetSecondLevelState(c93);
			break;
		case 94:
			m_TripleTree.SetSecondLevelState(c94);
			break;
		case 95:
			m_TripleTree.SetSecondLevelState(c95);
			break;
		case 96:
			m_TripleTree.SetSecondLevelState(c96);
			break;
		case 97:
			m_TripleTree.SetSecondLevelState(c97);
			break;
		case 98:
			m_TripleTree.SetSecondLevelState(c98);
			break;
		case 99:
			m_TripleTree.SetSecondLevelState(c99);
			break;
		case 100:
			m_TripleTree.SetSecondLevelState(c100);
			break;
		case 101:
			m_TripleTree.SetSecondLevelState(c101);
			break;
		case 102:
			m_TripleTree.SetSecondLevelState(c102);
			break;
		case 103:
			m_TripleTree.SetSecondLevelState(c103);
			break;
		case 104:
			m_TripleTree.SetSecondLevelState(c104);
			break;
		case 105:
			m_TripleTree.SetSecondLevelState(c105);
			break;
		case 106:
			m_TripleTree.SetSecondLevelState(c106);
			break;
		case 107:
			m_TripleTree.SetSecondLevelState(c107);
			break;
		case 108:
			m_TripleTree.SetSecondLevelState(c108);
			break;
		case 109:
			m_TripleTree.SetSecondLevelState(c109);
			break;
		case 110:
			m_TripleTree.SetSecondLevelState(c110);
			break;
		case 111:
			m_TripleTree.SetSecondLevelState(c111);
			break;
		case 112:
			m_TripleTree.SetSecondLevelState(c112);
			break;
		case 113:
			m_TripleTree.SetSecondLevelState(c113);
			break;
		case 114:
			m_TripleTree.SetSecondLevelState(c114);
			break;
		case 115:
			m_TripleTree.SetSecondLevelState(c115);
			break;
		case 116:
			m_TripleTree.SetSecondLevelState(c116);
			break;
		case 117:
			m_TripleTree.SetSecondLevelState(c117);
			break;
		case 118:
			m_TripleTree.SetSecondLevelState(c118);
			break;
		case 119:
			m_TripleTree.SetSecondLevelState(c119);
			break;
		case 120:
			m_TripleTree.SetSecondLevelState(c120);
			break;
		case 121:
			m_TripleTree.SetSecondLevelState(c121);
			break;
		case 122:
			m_TripleTree.SetSecondLevelState(c122);
			break;
		case 123:
			m_TripleTree.SetSecondLevelState(c123);
			break;
		default:
			;
		}
	}
}
