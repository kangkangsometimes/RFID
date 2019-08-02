// EPCGEN2.cpp : implementation file
//

#include "stdafx.h"
#include "uhfreader.h"
#include "EPCGEN2.h"
#include "UHFReaderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern hComSocket CS;
static int Stopflag = 0;
extern int Language;
/////////////////////////////////////////////////////////////////////////////
// CEPCGEN2 dialog

unsigned char DisplayBuf[2000][512];
int DisplayCnt = 0;
int OperTime = 0;

CString OperationType = "";
CString RStr = "";
CString EStr = "";
CString TStr = "";
CString UStr = "";
CEPCGEN2::CEPCGEN2(CWnd* pParent /*=NULL*/)
	: CDialog(CEPCGEN2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEPCGEN2)
	m_epc_cnum = -1;
	m_epc_saddr = -1;
	m_reserve_cnum = -1;
	m_tid_cnum = -1;
	m_user_cnum = -1;
	m_user_saddr = -1;
	m_tid_saddr = -1;
	m_reserve_saddr = -1;
	m_writeLen = -1;
	m_writeAddr = -1;
	m_writeMembank = -1;
	m_writeValue = _T("");
	m_slength = -1;
	m_saskpassword = _T("");
	m_smatch = -1;
	m_slocklevel = -1;
	m_smembank = -1;
	m_sstartaddr = -1;
	m_svalue = _T("");
	m_lockmembank = -1;
	m_time = _T("");
	m_number = _T("");
	m_speed = -1;
	//}}AFX_DATA_INIT
}


void CEPCGEN2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEPCGEN2)
	DDX_Control(pDX, IDC_TAGDATA_LIST, m_data);
	DDX_CBIndex(pDX, IDC_EPC_CNTNUM_COMBO, m_epc_cnum);
	DDX_CBIndex(pDX, IDC_EPC_STARTADDR_COMBO, m_epc_saddr);
	DDX_CBIndex(pDX, IDC_RESERVE_CNTNUM_COMBO, m_reserve_cnum);
	DDX_CBIndex(pDX, IDC_TID_CNTNUM_COMBO, m_tid_cnum);
	DDX_CBIndex(pDX, IDC_USER_CNTNUM_COMBO, m_user_cnum);
	DDX_CBIndex(pDX, IDC_USER_STARTADDR_COMBO, m_user_saddr);
	DDX_CBIndex(pDX, IDC_TID_STARTADDR_COMBO, m_tid_saddr);
	DDX_CBIndex(pDX, IDC_RESERVE_STARTADDR_COMBO, m_reserve_saddr);
	DDX_CBIndex(pDX, IDC_WRITEWORDNUM_COMBO, m_writeLen);
	DDX_CBIndex(pDX, IDC_WRITEWORDADDR_COMBO, m_writeAddr);
	DDX_CBIndex(pDX, IDC_WRITEMEMBANK_COMBO, m_writeMembank);
	DDX_Text(pDX, IDC_WRITEVALUE_EDIT, m_writeValue);
	DDX_CBIndex(pDX, IDC_LENGTH_SINGLE_COMBO, m_slength);
	DDX_Text(pDX, IDC_ASKPASSWORD_SINGLE_EDIT, m_saskpassword);
	DDX_CBIndex(pDX, IDC_MATCH_SINGLE_COMBO, m_smatch);
	DDX_CBIndex(pDX, IDC_LOCKLEVEL_SINGLE_COMBO, m_slocklevel);
	DDX_CBIndex(pDX, IDC_MEMBANK_SINGLE_COMBO, m_smembank);
	DDX_CBIndex(pDX, IDC_STARTADDR_SINGLE_COMBO, m_sstartaddr);
	DDX_Text(pDX, IDC_VALUE_SINGLE_EDIT, m_svalue);
	DDX_CBIndex(pDX, IDC_LOCKMEMBANK_COMBO, m_lockmembank);
	DDX_Text(pDX, IDC_TIME_STATIC, m_time);
	DDX_Text(pDX, IDC_NUMBER_STATIC, m_number);
	DDX_CBIndex(pDX, IDC_SPEED_COMBO, m_speed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEPCGEN2, CDialog)
	//{{AFX_MSG_MAP(CEPCGEN2)
	ON_BN_CLICKED(IDC_SECREAD_RADIO, OnSecReadRadio)
	ON_BN_CLICKED(IDC_SECWRITE_RADIO, OnSecWriteRadio)
	ON_BN_CLICKED(IDC_SECLOCK_RADIO, OnSecLockRadio)
	ON_BN_CLICKED(IDC_KILLTAG_RADIO, OnKillTagRadio)
	ON_BN_CLICKED(IDC_CONFIGTAG_RADIO, OnConfigTagRadio)
	ON_BN_CLICKED(IDC_MULTI_TAG_INVENTORY_RADIO, OnMultiTagInventoryRadio)
	ON_BN_CLICKED(IDC_MULTI_TAG_READ_RADIO, OnMultiTagReadRadio)
	ON_BN_CLICKED(IDC_MULTI_TAG_WRITE_RADIO, OnMultiTagWriteRadio)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ONCEINVENTORY_BUTTON, OnOnceInventoryButton)
	ON_BN_CLICKED(IDC_RESERVE_CHECK, OnMultiTagReadReserveCheck)
	ON_BN_CLICKED(IDC_EPC_CHECK, OnMultiTagReadEpcCheck)
	ON_BN_CLICKED(IDC_TID_CHECK, OnMultiTagReadTidCheck)
	ON_BN_CLICKED(IDC_USER_CHECK, OnMultiTagReadUserCheck)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_START_BUTTON, OnStartButton)
	ON_BN_CLICKED(IDC_EXECUTE_BUTTON, OnExecuteButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEPCGEN2 message handlers

BOOL CEPCGEN2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(0 == Language)
		LanguageChinese();
	if(1 == Language)
		LanguageEnglish();
	((CButton *)GetDlgItem(IDC_SECREAD_RADIO))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_MULTI_TAG_INVENTORY_RADIO))->SetCheck(1);
	//m_cb_baud.SetCurSel(9);		//9600
	m_epc_saddr = 0;
	m_epc_cnum = 1;
	m_user_saddr = 0;
	m_user_cnum = 1;
	m_tid_saddr = 0;
	m_tid_cnum = 1;
	m_reserve_saddr = 0;
	m_reserve_cnum = 1;
	m_saskpassword = "00000000";
	UpdateData(false);
	OnSecReadRadio();
	OnMultiTagInventoryRadio();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEPCGEN2::OnSecReadRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LOCKMEMBANK_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_ASKPASSWORD_SINGLE_EDIT))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_EDIT))->ShowWindow(SW_SHOW);
}

void CEPCGEN2::OnSecWriteRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LOCKMEMBANK_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_ASKPASSWORD_SINGLE_EDIT))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_EDIT))->ShowWindow(SW_SHOW);
}

void CEPCGEN2::OnSecLockRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LOCKMEMBANK_COMBO))->ShowWindow(SW_SHOW);
	

	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_ASKPASSWORD_SINGLE_EDIT))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_EDIT))->ShowWindow(SW_HIDE);
}

void CEPCGEN2::OnKillTagRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LOCKMEMBANK_COMBO))->ShowWindow(SW_HIDE);
	

	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_ASKPASSWORD_SINGLE_EDIT))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_EDIT))->ShowWindow(SW_HIDE);
}

void CEPCGEN2::OnConfigTagRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LOCKMEMBANK_COMBO))->ShowWindow(SW_HIDE);
	

	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_ASKPASSWORD_SINGLE_EDIT))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_EDIT))->ShowWindow(SW_SHOW);
}

void CEPCGEN2::OnMultiTagInventoryRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_SELECTMEMBANK_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_RESERVE_CHECK))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_EPC_CHECK))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_TID_CHECK))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_USER_CHECK))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_STARTADDR_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_RESERVE_STARTADDR_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_EPC_STARTADDR_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_TID_STARTADDR_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_USER_STARTADDR_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WORDCNTNUM_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_RESERVE_CNTNUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_EPC_CNTNUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_TID_CNTNUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_USER_CNTNUM_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEVALUE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEVALUE_EDIT))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_ONCEINVENTORY_BUTTON))->ShowWindow(SW_SHOW);
	
	((CButton *)GetDlgItem(IDC_SPEED_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_SPEED_COMBO))->ShowWindow(SW_SHOW);
	//初始化List初始化Listctrl控件 // initialize list initialize ActiveX
	InitListCtrl();
	//设置新风格 //set new style
	if(0 == Language)
	{
		m_data.InsertColumn(0,"序号",LVCFMT_CENTER,40); //serial number 
		m_data.InsertColumn(1,"EPC盘询数据",LVCFMT_CENTER,350); //EPC query data
		m_data.InsertColumn(2,"次数",LVCFMT_CENTER,70); //times
	}
	else
	{
		m_data.InsertColumn(0,"No.",LVCFMT_CENTER,40); //serial number 
		m_data.InsertColumn(1,"EPCData",LVCFMT_CENTER,350); //EPC query data
		m_data.InsertColumn(2,"Times",LVCFMT_CENTER,70); //times
	}


	memset( DisplayBuf, 0, sizeof(unsigned char)*2000*512);
	DisplayCnt = 0;
	OperationType = "Inventory";
	m_speed = 2;
	UpdateData(false);
}

void CEPCGEN2::OnMultiTagReadRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_SELECTMEMBANK_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_RESERVE_CHECK))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_EPC_CHECK))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_TID_CHECK))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_USER_CHECK))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_STARTADDR_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_RESERVE_STARTADDR_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_EPC_STARTADDR_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_TID_STARTADDR_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_USER_STARTADDR_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_RESERVE_STARTADDR_COMBO))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_EPC_STARTADDR_COMBO))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_TID_STARTADDR_COMBO))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_USER_STARTADDR_COMBO))->EnableWindow(false);
	

	((CButton *)GetDlgItem(IDC_WORDCNTNUM_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_RESERVE_CNTNUM_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_EPC_CNTNUM_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_TID_CNTNUM_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_USER_CNTNUM_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_RESERVE_CNTNUM_COMBO))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_EPC_CNTNUM_COMBO))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_TID_CNTNUM_COMBO))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_USER_CNTNUM_COMBO))->EnableWindow(false);

	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEVALUE_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_WRITEVALUE_EDIT))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_ONCEINVENTORY_BUTTON))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_SPEED_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_SPEED_COMBO))->ShowWindow(SW_HIDE);

	//初始化List初始化Listctrl控件
	InitListCtrl();
	//设置新风格
	if(0 == Language)
	{
		m_data.InsertColumn(0,"序号",LVCFMT_CENTER,40);
		m_data.InsertColumn(1,"Reserve区",LVCFMT_CENTER,83);
		m_data.InsertColumn(2,"Epc区",LVCFMT_CENTER,100);
		m_data.InsertColumn(3,"Tid区",LVCFMT_CENTER,100);
		m_data.InsertColumn(4,"User区",LVCFMT_CENTER,100);
		m_data.InsertColumn(5,"次数",LVCFMT_CENTER,40);
	}
	else
	{
		m_data.InsertColumn(0,"No.",LVCFMT_CENTER,40);
		m_data.InsertColumn(1,"Reserve",LVCFMT_CENTER,83);
		m_data.InsertColumn(2,"Epc",LVCFMT_CENTER,100);
		m_data.InsertColumn(3,"Tid",LVCFMT_CENTER,90);
		m_data.InsertColumn(4,"User",LVCFMT_CENTER,100);
		m_data.InsertColumn(5,"Times",LVCFMT_CENTER,50);
	}
	

	memset( DisplayBuf, 0, sizeof(unsigned char)*2000*512);
	DisplayCnt = 0;
	OperationType = "Read";
}

void CEPCGEN2::OnMultiTagWriteRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_SELECTMEMBANK_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_RESERVE_CHECK))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_EPC_CHECK))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_TID_CHECK))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_USER_CHECK))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_STARTADDR_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_RESERVE_STARTADDR_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_EPC_STARTADDR_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_TID_STARTADDR_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_USER_STARTADDR_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WORDCNTNUM_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_RESERVE_CNTNUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_EPC_CNTNUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_TID_CNTNUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_USER_CNTNUM_COMBO))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_COMBO))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_WRITEVALUE_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_WRITEVALUE_EDIT))->ShowWindow(SW_SHOW);

	((CButton *)GetDlgItem(IDC_ONCEINVENTORY_BUTTON))->ShowWindow(SW_HIDE);

	((CButton *)GetDlgItem(IDC_SPEED_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_SPEED_COMBO))->ShowWindow(SW_HIDE);

	//初始化List初始化Listctrl控件 //initialize list initialize ActiveX
	InitListCtrl();
	//设置新风格 (set new style)
	if(0 == Language)
	{
		m_data.InsertColumn(0,"序号",LVCFMT_CENTER,40);
		m_data.InsertColumn(1,"EPC盘询数据",LVCFMT_CENTER,350);
		m_data.InsertColumn(2,"次数",LVCFMT_CENTER,70);
	}
	else
	{
		m_data.InsertColumn(0,"No.",LVCFMT_CENTER,40);
		m_data.InsertColumn(1,"EPC Data",LVCFMT_CENTER,350);
		m_data.InsertColumn(2,"Times",LVCFMT_CENTER,70);
	}

	memset( DisplayBuf, 0, sizeof(unsigned char)*2000*512);
	DisplayCnt = 0;
	OperationType = "Write";
}

void CEPCGEN2::OnMultiTagReadReserveCheck() 
{
	// TODO: Add your control notification handler code here
	if(((CButton *)GetDlgItem(IDC_RESERVE_CHECK))->GetCheck()==1)
	{
		((CButton *)GetDlgItem(IDC_RESERVE_STARTADDR_COMBO))->EnableWindow(true);
		((CButton *)GetDlgItem(IDC_RESERVE_CNTNUM_COMBO))->EnableWindow(true);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_RESERVE_STARTADDR_COMBO))->EnableWindow(false);
		((CButton *)GetDlgItem(IDC_RESERVE_CNTNUM_COMBO))->EnableWindow(false);
	}
}

void CEPCGEN2::OnMultiTagReadEpcCheck() 
{
	// TODO: Add your control notification handler code here
	if(((CButton *)GetDlgItem(IDC_EPC_CHECK))->GetCheck()==1)
	{
		((CButton *)GetDlgItem(IDC_EPC_STARTADDR_COMBO))->EnableWindow(true);
		((CButton *)GetDlgItem(IDC_EPC_CNTNUM_COMBO))->EnableWindow(true);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_EPC_STARTADDR_COMBO))->EnableWindow(false);
		((CButton *)GetDlgItem(IDC_EPC_CNTNUM_COMBO))->EnableWindow(false);
	}
}

void CEPCGEN2::OnMultiTagReadTidCheck() 
{
	// TODO: Add your control notification handler code here
	if(((CButton *)GetDlgItem(IDC_TID_CHECK))->GetCheck()==1)
	{
		((CButton *)GetDlgItem(IDC_TID_STARTADDR_COMBO))->EnableWindow(true);
		((CButton *)GetDlgItem(IDC_TID_CNTNUM_COMBO))->EnableWindow(true);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_TID_STARTADDR_COMBO))->EnableWindow(false);
		((CButton *)GetDlgItem(IDC_TID_CNTNUM_COMBO))->EnableWindow(false);
	}
}

void CEPCGEN2::OnMultiTagReadUserCheck() 
{
	// TODO: Add your control notification handler code here
	if(((CButton *)GetDlgItem(IDC_USER_CHECK))->GetCheck()==1)
	{
		((CButton *)GetDlgItem(IDC_USER_STARTADDR_COMBO))->EnableWindow(true);
		((CButton *)GetDlgItem(IDC_USER_CNTNUM_COMBO))->EnableWindow(true);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_USER_STARTADDR_COMBO))->EnableWindow(false);
		((CButton *)GetDlgItem(IDC_USER_CNTNUM_COMBO))->EnableWindow(false);
	}
}
/////////////////////////////////////////////////////////////////////////////
// CSystemConfig message handlers
/********************************EPC GEN2标签盘询***************************************/ //EPC GEN2 Tag Query//

void CEPCGEN2::OnOnceInventoryButton() 
{
	// TODO: Add your control notification handler code here
	ClearIDBuffer();
	MultiTagInventory();
}

void CEPCGEN2::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		ClearIDBuffer();
		MultiTagInventory();
		break;
	case 2:
		ClearIDBuffer();
		MultiTagRead();
		break;
	case 3:
		ClearIDBuffer();
		MultiTagWrite();
		break;
	case 4:
		OperationTime();
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CEPCGEN2::OnStartButton() 
{
	// TODO: Add your control notification handler code here
	CString TempStr = "";
	CString TempStrEnglish = "";

	UpdateData(true);
	int speed = m_speed;
	int timer = 0;
	switch(speed)
	{
	case 0:
		timer = 10;
		break;
	case 1:
		timer = 20;
		break;
	case 2:
		timer = 50;
		break;
	case 3:
		timer = 100;
		break;
	case 4:
		timer = 200;
		break;
	case 5:
		timer = 300;
		break;
	case 6:
		timer = 400;
		break;
	case 7:
		timer = 500;
		break;
	}
	OnButtonClear();
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_INVENTORY_RADIO))->GetCheck()==1)
	{
		TempStr = "开始盘询!";
		TempStrEnglish = "start query!";
		SetTimer(4, 1000, NULL);
		SetTimer(1, timer, NULL);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->GetCheck()==1)
	{
		TempStr = "开始多标签读取!";
		TempStrEnglish = "start multi-tag read!";
		SetTimer(4, 1000, NULL);
		SetTimer(2, 100, NULL);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->GetCheck()==1)
	{
		TempStr = "开始多标签写入!";
		TempStrEnglish = "start multi-tag write!";
		SetTimer(4, 1000, NULL);
		SetTimer(3, 100, NULL);
	}
	((CButton *)GetDlgItem(IDC_START_BUTTON))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->EnableWindow(true);
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

void CEPCGEN2::OnStopButton() 
{
	// TODO: Add your control notification handler code here
	CString TempStr = "";
	CString TempStrEnglish = "";

	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_INVENTORY_RADIO))->GetCheck()==1)
	{
		TempStr = "停止盘询!";
		TempStrEnglish = "stop query!";
		KillTimer(1);
		KillTimer(4);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->GetCheck()==1)
	{
		TempStr = "停止多标签读取!";
		TempStrEnglish = "stop multi-tag read!";
		KillTimer(2);
		KillTimer(4);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->GetCheck()==1)
	{
		TempStr = "停止多标签写入!";
		TempStrEnglish = "stop multi-tag write!";
		KillTimer(3);
		KillTimer(4);
	}
	((CButton *)GetDlgItem(IDC_START_BUTTON))->EnableWindow(true);
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->EnableWindow(false);
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

void CEPCGEN2::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_data.DeleteAllItems();
	memset( DisplayBuf, 0, sizeof(unsigned char)*2000*512);
	DisplayCnt = 0;
	OperTime = 0;
	m_time = "";
	m_number = "";
	UpdateData(false);
}

void CEPCGEN2::OnExecuteButton() 
{
	// TODO: Add your control notification handler code here
	CString PassWord = "";
	((CButton *)GetDlgItem(IDC_ASKPASSWORD_SINGLE_EDIT))->GetWindowText(PassWord);
	if(PassWord.GetLength() != 8)
	{
		MessageBox("执行密码长度必须为4字节!");
		return;
	}
	if(((CButton *)GetDlgItem(IDC_SECREAD_RADIO))->GetCheck()==1)
	{
		SECRead();
	}
	if(((CButton *)GetDlgItem(IDC_SECWRITE_RADIO))->GetCheck()==1)
	{
		SECWrite();
	}
	if(((CButton *)GetDlgItem(IDC_SECLOCK_RADIO))->GetCheck()==1)
	{
		SECLock();
	}
	if(((CButton *)GetDlgItem(IDC_KILLTAG_RADIO))->GetCheck()==1)
	{
		SECKill();
	}
	if(((CButton *)GetDlgItem(IDC_CONFIGTAG_RADIO))->GetCheck()==1)
	{
		SECSelectConfig();
	}
}

/////////////////////////////////////调用函数//call function//////////////////////////////////////////
/********************************缓存管理*清空缓存//buffer management*clear buffer***************************************/
void CEPCGEN2::ClearIDBuffer()
{
	if(0x00 == BufferM_ClearBuffer(CS, 0xFF))
	{
		;//CUHFReaderDlg::ListBoxAdd("清空缓存成功(clear buffer success)!");
	}
	else
	{
		;//CUHFReaderDlg::ListBoxAdd("清空缓存失败(clear buffer failed)!");
	}
}

/********************************EPC GEN2启动标签盘询//EPC GEN2 start tag query***************************************/
void CEPCGEN2::MultiTagInventory()
{
	int TagCount = 0;
	int GetCount = 0;
	int Count = 0;
	int i, j = 0;
	int Cnt = 0;
	int status;
	CString Tempstr = "";
	CString SNo = "";
	BufferData Data[16] = {0};
	status = GEN2_MultiTagInventory(CS, TagCount, 0xFF);
	if(0x00 == status) 
	{
		if(0 != TagCount)		//标签盘询成功(tag query success)
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("盘询到的标签数量为0(query tag quantity is 0)!");
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf[j], (Data[i].Len - 1)) == 0)		//相同(same)
							{
								Cnt = (int)(DisplayBuf[j][(Data[i].Len - 1)] << 8) + (int)DisplayBuf[j][Data[i].Len];
								Cnt ++;
								DisplayBuf[j][(Data[i].Len - 1)] = (unsigned char)(Cnt >> 8);
								DisplayBuf[j][Data[i].Len] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);
								m_data.SetItemText(j, 2, SNo);									// 更新显示(update display)
								break;
							}
						}
						if(j == DisplayCnt)	//不相同(not same)
						{
							memcpy(DisplayBuf[j], Data[i].Data, (Data[i].Len - 1));
							DisplayBuf[j][Data[i].Len] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, (Data[i].Len - 1));
							DisplayNewTag(Tempstr);							// 显示(display)
							DisplayCnt++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else			//取数据失败(get data failed)
				{
					;
					//CUHFReaderDlg::ListBoxAdd("EPC GEN2取数据失败(get data failed)!");
					//CUHFReaderDlg::ListBoxAdd("停止盘询(stop query)!");
					//KillTimer(1);
				}
			}
		}
	}
	else		//盘询失败(query failed)
	{
		;
		//CUHFReaderDlg::ListBoxAdd("EPC GEN2标签盘询失败(tag query failed)!");
		//CUHFReaderDlg::ListBoxAdd("停止盘询(stop query)");
		//KillTimer(1);
	}
}

/********************************EPC GEN2标签多标签读取(EPC GEN2 Tag multi-tag read)***************************************/
void CEPCGEN2::MultiTagRead()
{
	int TagCount = 0;
	int GetCount = 0;
	int Count = 0;
	int i, j;
	int status;
	int Cnt = 0;
	int RCnt = 0;							//Reserve区读取数据字节数(Reserve memory read data numbers of byte)
	int ECnt = 0;							//Epc区读取数据字节数(EPC memory read data numbers of byte)
	int TCnt = 0;							//Tid区读取数据字节数(TID memory read data numbers of byte)
	int UCnt = 0;							//User区读取数据字节数(User memory read data numbers of byte)
	unsigned char Reserve[100] = {0};		//Reserve区读取数据(Reserve memory read data)
	unsigned char Epc[100] = {0};			//Epc区读取数据(EPC memory read data)
	unsigned char Tid[100] = {0};			//Tid区读取数据(TID memory read data)
	unsigned char User[100] = {0};			//User区读取数据(User memory read data)
	CString Tempstr = "";
	BufferData Data[16] = {0};
	CString SNo = "";

	//初始化(initialize)
	WordptrAndLength WpALen;
	WpALen.ReserveWordPtr = 0;
	WpALen.ReserveWordCnt = 0;
	WpALen.EpcWordPtr = 0;
	WpALen.EpcWordCnt = 0;
	WpALen.TidWordPtr = 0;
	WpALen.TidWordCnt = 0;
	WpALen.UserWordPtr = 0;
	WpALen.UserWordCnt = 0;
	WpALen.MembankMask = 0;

	UpdateData(true);
	if(((CButton *)GetDlgItem(IDC_RESERVE_CHECK))->GetCheck()==1)
	{
		WpALen.MembankMask += 1;
		WpALen.ReserveWordPtr = m_reserve_saddr;
		WpALen.ReserveWordCnt = m_reserve_cnum;
		RCnt = m_reserve_cnum * 2;
	}
	if(((CButton *)GetDlgItem(IDC_EPC_CHECK))->GetCheck()==1)
	{
		WpALen.MembankMask += 2;
		WpALen.EpcWordPtr = m_epc_saddr;
		WpALen.EpcWordCnt = m_epc_cnum;
		ECnt = m_epc_cnum * 2;
	}
	if(((CButton *)GetDlgItem(IDC_TID_CHECK))->GetCheck()==1)
	{
		WpALen.MembankMask += 4;
		WpALen.TidWordPtr = m_tid_saddr;
		WpALen.TidWordCnt = m_tid_cnum;
		TCnt = m_tid_cnum * 2;
	}
	if(((CButton *)GetDlgItem(IDC_USER_CHECK))->GetCheck()==1)
	{
		WpALen.MembankMask += 8;
		WpALen.UserWordPtr = m_user_saddr;
		WpALen.UserWordCnt = m_user_cnum;
		UCnt = m_user_cnum * 2;
	}
	status = GEN2_MultiTagRead(CS, WpALen, TagCount, 0xFF);
	if(0x00 == status)
	{
		if(0 != TagCount)			//多标签读取成功(multi-tag read success)
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("成功读取的标签数量为0(read tag quantity is 0)!");
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf[j], EPCLEN) == 0)	//相同(same)
							{
								Cnt = (int)(DisplayBuf[j][12] << 8) + (int)DisplayBuf[j][13];
								Cnt ++;
								DisplayBuf[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);			// 重复次数加1(times of repetition add one)
								m_data.SetItemText(j, 5, SNo);
								break;
							}
						}
						if(j == DisplayCnt)	//不相同(not same)
						{
							memcpy(DisplayBuf[j], Data[i].Data, EPCLEN);
							DisplayBuf[j][13] = 1;
							if(0 != RCnt)
							{
								memcpy(Reserve, &Data[i].Data[EPCLEN], RCnt);
								RStr = CUHFReaderDlg::ByteToHexStr(Reserve, RCnt);
								memset( Reserve, 0, 100 );
							}
							if(0 != ECnt)
							{
								memcpy(Epc, &Data[i].Data[EPCLEN + RCnt], ECnt);
								EStr = CUHFReaderDlg::ByteToHexStr(Epc, ECnt);
								memset( Epc, 0, 100 );
							}
							if(0 != TCnt)
							{
								memcpy(Tid, &Data[i].Data[EPCLEN + RCnt + ECnt], TCnt);
								TStr = CUHFReaderDlg::ByteToHexStr(Tid, TCnt);
								memset( Tid, 0, 100 );
							}
							if(0 != UCnt)
							{
								memcpy(User, &Data[i].Data[EPCLEN + RCnt + ECnt + TCnt], UCnt);
								UStr = CUHFReaderDlg::ByteToHexStr(User, UCnt);
								memset( User, 0, 100 );
							}
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, EPCLEN);
							DisplayNewTag(Tempstr);						// 显示(Display)
							DisplayCnt++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else
				{
					;
					//CUHFReaderDlg::ListBoxAdd("EPC GEN2取数据失败(EPC GEN2 get data failed)!");
					//CUHFReaderDlg::ListBoxAdd("停止多标签读取(stop multi-tag read)");
					//KillTimer(2);
					//break;
				}
			}
		}
	}
	else
	{
		;
		//CUHFReaderDlg::ListBoxAdd("EPC GEN2标签多标签读取失败(EPC GEN2 Tag multi-tag read failed)!");
		//CUHFReaderDlg::ListBoxAdd("停止多标签读取(stop multi-tag read)");
		//KillTimer(2);
	}
}

/********************************EPC GEN2标签多标签写入(EPC GEN2 Tag multi-tag write)***************************************/
void CEPCGEN2::MultiTagWrite()
{
	UpdateData(true);
	MutiWriteParam MutiWP;
	MutiWP.MemBank = m_writeMembank;
	MutiWP.StartAddr = m_writeAddr;
	MutiWP.WriteLen = m_writeLen + 1;
	CUHFReaderDlg::HexStrToByte(MutiWP.WriteValue, m_writeValue);
	int i,j;
	int status;
	int mTemp = 0;
	int TagCount = 0;
	int GetCount = 0;
	int Count = 0;
	int Cnt = 0;
	CString SNo = "";
	CString Tempstr = "";
	BufferData Data[16] = {0};
	status = GEN2_MultiTagWrite(CS, MutiWP, TagCount, 0xFF);
	if(0x00 == status)
	{
		if(0 != TagCount)				//多标签写入成功(multi-tag write success)
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("成功写入的标签数量为0(success write the tag quantityt is 0)!");
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf[j], EPCLEN) == 0)	//相同(same)
							{
								Cnt = (int)(DisplayBuf[j][12] << 8) + (int)DisplayBuf[j][13];
								Cnt ++;
								DisplayBuf[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);			// 重复次数加1(times of repetition add one)
								m_data.SetItemText(j, 2, SNo);						// 更新显示(update display)
								break;
							}
						}
						if(j == DisplayCnt)	//不相同(not same)
						{
							memcpy(DisplayBuf[j], Data[i].Data, EPCLEN);
							DisplayBuf[j][13] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, EPCLEN);
							DisplayNewTag(Tempstr);
							DisplayCnt++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else
				{
					;
					//CUHFReaderDlg::ListBoxAdd("EPC GEN2取数据失败(EPC GEN2 get data failed)!");
					//CUHFReaderDlg::ListBoxAdd("停止多标签写入(stop multi-tag write)");
					//KillTimer(3);
					//break;
				}
			}
		}
	}
	else
	{
		;
		//CUHFReaderDlg::ListBoxAdd("EPC GEN2标签多标签写入失败(EPC GEN2 tag multi-tag write failed)!");
		//CUHFReaderDlg::ListBoxAdd("停止多标签写入(stop multi-tag write)");
		//KillTimer(3);
	}
}

void CEPCGEN2::DisplayNewTag(CString EpcStr)
{
	CString SN = "";
	if(OperationType == "Inventory" || OperationType == "Write")
	{
		SN.Format("%d", (DisplayCnt + 1));

		m_data.InsertItem(DisplayCnt, SN);
		m_data.SetItemText(DisplayCnt, 1, EpcStr);
		m_data.SetItemText(DisplayCnt, 2, "1");
	}
	if(OperationType == "Read")
	{
		SN.Format("%d", (DisplayCnt + 1));
		m_data.InsertItem(DisplayCnt, SN);
		m_data.SetItemText(DisplayCnt, 1, RStr);
		m_data.SetItemText(DisplayCnt, 2, EStr);
		m_data.SetItemText(DisplayCnt, 3, TStr);
		m_data.SetItemText(DisplayCnt, 4, UStr);
		m_data.SetItemText(DisplayCnt, 5, "1");
		RStr = "";
		EStr = "";
		TStr = "";
		UStr = "";
	}
	m_number = SN;
	UpdateData(false);
}

void CEPCGEN2::InitListCtrl()
{
	//初始化List初始化Listctrl控件(initialize List initialize ActiveX)
	//清除原有风格(clear original style)
	m_data.DeleteAllItems();		//清除所有内容(clear all content)
	int Column;
	CHeaderCtrl*   pHeaderCtrl = m_data.GetHeaderCtrl(); 
	if(pHeaderCtrl) 
	{ 
        Column = pHeaderCtrl->GetItemCount(); 
	}
	for(Column; Column > 0; Column --)
	{
		m_data.DeleteColumn(Column - 1);
	}
	//设置新风格(set new style)
	DWORD dwStyle = m_data.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;		//选中某行使整行高亮（只适用与report风格的listctrl）Select an exercise of the entire line highlighted(only apply same report style listctrl)
    dwStyle |= LVS_EX_GRIDLINES;			//网格线（只适用与report风格的listctrl）(Gridline(only apply same report style listctrl))
	//dwStyle |= LVS_EX_CHECKBOXES;			//item前生成checkbox控件(front itme generate checkbox ActiveX)
	m_data.SetExtendedStyle(dwStyle);		//设置扩展风格(set expand style)
}

void CEPCGEN2::SECRead()
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	UpdateData(true);
	int status = 0;
	int SMembank = 0;
	CString PWstr = "";
	int RSAddr = 0;
	int RCnt = 0;
	unsigned char PassWord[4] = {0};
	unsigned char RData[100] = {0};
	
	SMembank = m_smembank;
	PWstr = m_saskpassword;
	RSAddr = m_sstartaddr;
	RCnt = m_slength;

	CUHFReaderDlg::HexStrToByte(PassWord, PWstr);

	status = GEN2_SecRead(CS, SMembank, PassWord, RSAddr, RCnt, RData, 0xFF);
	if(0 == status)
	{
		TempStr = "标签读取成功";
		TempStrEnglish = "Tag read success";
		CString TStr = "";
		TStr = CUHFReaderDlg::ByteToHexStr(RData, RCnt*2);
		m_svalue = TStr;
		UpdateData(false);
	}
	else
	{
		TempStr = "标签读取失败";
		TempStrEnglish = "Tag read failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

void CEPCGEN2::SECWrite()
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	UpdateData(true);
	int status = 0;
	int SMembank = 0;
	CString PWstr = "";
	CString WDataStr = "";
	int WSAddr = 0;
	int WCnt = 0;
	unsigned char PassWord[4] = {0};
	unsigned char WData[100] = {0};
	
	SMembank = m_smembank;
	PWstr = m_saskpassword;
	WSAddr = m_sstartaddr;
	WCnt = m_slength;
	WDataStr = m_svalue;
	
	if(WDataStr.GetLength() == WCnt*4)
	{
		CUHFReaderDlg::HexStrToByte(PassWord, PWstr);
		CUHFReaderDlg::HexStrToByte(WData, WDataStr);
		status = GEN2_SecWrite(CS, SMembank, PassWord, WSAddr, WCnt, WData, 0xFF);
		if(0 == status)
		{
			TempStr = "标签写入成功";
			TempStrEnglish = "tag write success";
		}
		else
		{
			TempStr = "标签写入失败";
			TempStrEnglish = "tag write failed";
		}
	}
	else
	{
		if(0 == Language)
			AfxMessageBox("写入标签的数据与写入的长度不匹配!请检查后重试");
		else
			AfxMessageBox("the data input is incorrect length,please check and try again");
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

void CEPCGEN2::SECLock()
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	UpdateData(true);
	int status = 0;
	int SMembank = 0;
	int LSLevel = 0;
	CString PWstr = "";
	unsigned char PassWord[4] = {0};
	
	SMembank = m_lockmembank;
	PWstr = m_saskpassword;
	LSLevel = m_slocklevel;
	
	CUHFReaderDlg::HexStrToByte(PassWord, PWstr);
	status = GEN2_SecLock(CS, SMembank, PassWord, LSLevel, 0xFF);
	if(0 == status)
	{
		TempStr = "标签锁定成功";
		TempStrEnglish = "tag lock success";
	}
	else
	{
		TempStr = "标签锁定失败";
		TempStrEnglish = "tag lock failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

void CEPCGEN2::SECKill()
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	UpdateData(true);
	int status = 0;
	CString PWstr = "";
	unsigned char PassWord[4] = {0};
	
	PWstr = m_saskpassword;
	
	CUHFReaderDlg::HexStrToByte(PassWord, PWstr);
	status = GEN2_KillTag(CS, PassWord, 0xFF);
	if(0 == status)
	{
		TempStr = "标签销毁成功";
		TempStrEnglish = "tag kill success";
	}
	else
	{
		TempStr = "标签销毁失败";
		TempStrEnglish = "tag kill failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}


void CEPCGEN2::SECSelectConfig()
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	UpdateData(true);
	int status = 0;
	int SMembank = 0;
	int SCSAddr = 0;
	int SCCnt = 0;
	int SCMatch = 0;
	CString WDataStr = "";
	unsigned char WData[100] = {0};
	
	SMembank = m_smembank;
	SCSAddr = m_sstartaddr;
	SCCnt = m_slength;
	SCMatch = m_smatch;
	WDataStr = m_svalue;
	
	if(WDataStr.GetLength() == SCCnt*4)
	{
		CUHFReaderDlg::HexStrToByte(WData, WDataStr);
		status = GEN2_SecSelectConfig(CS, SMembank, SCMatch, SCSAddr, SCCnt, WData, 0xFF);
		if(0 == status)
		{
			TempStr = "标签筛选配置成功";
			TempStrEnglish = "tag selection set success";
		}
		else
		{
			TempStr = "标签筛选配置失败";
			TempStrEnglish = "tag selection set failed";
		}
	}
	else
	{
		if(0 == Language)
			AfxMessageBox("标签的筛选数据长度与选择的筛选长度不匹配!请检查后重试");
		else
			AfxMessageBox("tag selection data length is incorrect, please check and try again");
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/*******************************工具函数//tool function***************************************/
void CEPCGEN2::OperationTime()
{
	CString time = "";
	OperTime ++;
	time.Format("%d", (OperTime));
	m_time = time;
	UpdateData(false);
}

void CEPCGEN2::LanguageChinese()
{
	((CButton *)GetDlgItem(IDC_MULTITAG_STATIC))->SetWindowText("多标签操作");
	((CButton *)GetDlgItem(IDC_SHOWDATA_STATIC))->SetWindowText("数据显示");
	((CButton *)GetDlgItem(IDC_SELECTMEMBANK_STATIC))->SetWindowText("数据区域:");
	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_STATIC))->SetWindowText("写入区域:");
	
	((CButton *)GetDlgItem(IDC_STARTADDR_STATIC))->SetWindowText("起始地址:");
	((CButton *)GetDlgItem(IDC_WRITEVALUE_STATIC))->SetWindowText("写入数据:");
	((CButton *)GetDlgItem(IDC_WORDCNTNUM_STATIC))->SetWindowText("读取字数:");	
	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_STATIC))->SetWindowText("起始地址");
	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_STATIC))->SetWindowText("写入字数");
	
	((CButton *)GetDlgItem(IDC_TIMES_STATIC))->SetWindowText("时间");
	((CButton *)GetDlgItem(IDC_NUM_STATIC))->SetWindowText("数量");		
	((CButton *)GetDlgItem(IDC_SPEED_STATIC))->SetWindowText("速率");
	((CButton *)GetDlgItem(IDC_UNIQUETAG_STATIC))->SetWindowText("单标签操作");
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->SetWindowText("访问区域:");
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->SetWindowText("起始地址:");
	
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->SetWindowText("数据长度:");
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->SetWindowText("锁定等级:");
	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->SetWindowText("访问密码:");	
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->SetWindowText("匹配度:");
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->SetWindowText("数据:");
	
	((CButton *)GetDlgItem(IDC_MULTI_TAG_INVENTORY_RADIO))->SetWindowText("多标签盘询");
	((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->SetWindowText("多标签读取");
	((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->SetWindowText("多标签写入");
	((CButton *)GetDlgItem(IDC_SECREAD_RADIO))->SetWindowText("安全读");
	((CButton *)GetDlgItem(IDC_SECWRITE_RADIO))->SetWindowText("安全写");
	((CButton *)GetDlgItem(IDC_SECLOCK_RADIO))->SetWindowText("安全锁");
	((CButton *)GetDlgItem(IDC_KILLTAG_RADIO))->SetWindowText("销毁标签");
	((CButton *)GetDlgItem(IDC_CONFIGTAG_RADIO))->SetWindowText("筛选配置");	
	((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("开始");
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->SetWindowText("停止");	
	((CButton *)GetDlgItem(IDC_ONCEINVENTORY_BUTTON))->SetWindowText("单次盘询");
	((CButton *)GetDlgItem(IDC_BUTTON_CLEAR))->SetWindowText("清空");	
	((CButton *)GetDlgItem(IDC_EXECUTE_BUTTON))->SetWindowText("执行");
	
}

void CEPCGEN2::LanguageEnglish()
{
	((CButton *)GetDlgItem(IDC_MULTITAG_STATIC))->SetWindowText("MultiTagIdentify");
	((CButton *)GetDlgItem(IDC_SHOWDATA_STATIC))->SetWindowText("ShowData");
	((CButton *)GetDlgItem(IDC_SELECTMEMBANK_STATIC))->SetWindowText("DMembank:");
	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_STATIC))->SetWindowText("WMembank:");
	
	((CButton *)GetDlgItem(IDC_STARTADDR_STATIC))->SetWindowText("StartAddr:");
	((CButton *)GetDlgItem(IDC_WRITEVALUE_STATIC))->SetWindowText("WriteValue:");
	((CButton *)GetDlgItem(IDC_WORDCNTNUM_STATIC))->SetWindowText("ReadWordN:");	
	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_STATIC))->SetWindowText("StartAddr:");
	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_STATIC))->SetWindowText("WriteWordN:");
	
	((CButton *)GetDlgItem(IDC_TIMES_STATIC))->SetWindowText("Time");
	((CButton *)GetDlgItem(IDC_NUM_STATIC))->SetWindowText("Num");		
	((CButton *)GetDlgItem(IDC_SPEED_STATIC))->SetWindowText("Speed");
	((CButton *)GetDlgItem(IDC_UNIQUETAG_STATIC))->SetWindowText("uniquetagOperation");
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->SetWindowText("AskMembank:");
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->SetWindowText("StartAddr:");
	
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->SetWindowText("Vlength:");
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->SetWindowText("LockLevel:");
	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->SetWindowText("AskPW:");	
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->SetWindowText("Match:");
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->SetWindowText("Value:");
	
	((CButton *)GetDlgItem(IDC_MULTI_TAG_INVENTORY_RADIO))->SetWindowText("multitagI");
	((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->SetWindowText("multitagR");
	((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->SetWindowText("multitagW");
	((CButton *)GetDlgItem(IDC_SECREAD_RADIO))->SetWindowText("SecRead");
	((CButton *)GetDlgItem(IDC_SECWRITE_RADIO))->SetWindowText("SecWrite");
	((CButton *)GetDlgItem(IDC_SECLOCK_RADIO))->SetWindowText("SecLock");
	((CButton *)GetDlgItem(IDC_KILLTAG_RADIO))->SetWindowText("KillTag");
	((CButton *)GetDlgItem(IDC_CONFIGTAG_RADIO))->SetWindowText("SelectConfig");	
	((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("Start");
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->SetWindowText("Stop");	
	((CButton *)GetDlgItem(IDC_ONCEINVENTORY_BUTTON))->SetWindowText("Onec");
	((CButton *)GetDlgItem(IDC_BUTTON_CLEAR))->SetWindowText("Clear");	
	((CButton *)GetDlgItem(IDC_EXECUTE_BUTTON))->SetWindowText("EXECUTE");
}
