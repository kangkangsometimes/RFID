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
	//��ʼ��List��ʼ��Listctrl�ؼ� // initialize list initialize ActiveX
	InitListCtrl();
	//�����·�� //set new style
	if(0 == Language)
	{
		m_data.InsertColumn(0,"���",LVCFMT_CENTER,40); //serial number 
		m_data.InsertColumn(1,"EPC��ѯ����",LVCFMT_CENTER,350); //EPC query data
		m_data.InsertColumn(2,"����",LVCFMT_CENTER,70); //times
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

	//��ʼ��List��ʼ��Listctrl�ؼ�
	InitListCtrl();
	//�����·��
	if(0 == Language)
	{
		m_data.InsertColumn(0,"���",LVCFMT_CENTER,40);
		m_data.InsertColumn(1,"Reserve��",LVCFMT_CENTER,83);
		m_data.InsertColumn(2,"Epc��",LVCFMT_CENTER,100);
		m_data.InsertColumn(3,"Tid��",LVCFMT_CENTER,100);
		m_data.InsertColumn(4,"User��",LVCFMT_CENTER,100);
		m_data.InsertColumn(5,"����",LVCFMT_CENTER,40);
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

	//��ʼ��List��ʼ��Listctrl�ؼ� //initialize list initialize ActiveX
	InitListCtrl();
	//�����·�� (set new style)
	if(0 == Language)
	{
		m_data.InsertColumn(0,"���",LVCFMT_CENTER,40);
		m_data.InsertColumn(1,"EPC��ѯ����",LVCFMT_CENTER,350);
		m_data.InsertColumn(2,"����",LVCFMT_CENTER,70);
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
/********************************EPC GEN2��ǩ��ѯ***************************************/ //EPC GEN2 Tag Query//

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
		TempStr = "��ʼ��ѯ!";
		TempStrEnglish = "start query!";
		SetTimer(4, 1000, NULL);
		SetTimer(1, timer, NULL);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->GetCheck()==1)
	{
		TempStr = "��ʼ���ǩ��ȡ!";
		TempStrEnglish = "start multi-tag read!";
		SetTimer(4, 1000, NULL);
		SetTimer(2, 100, NULL);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->GetCheck()==1)
	{
		TempStr = "��ʼ���ǩд��!";
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
		TempStr = "ֹͣ��ѯ!";
		TempStrEnglish = "stop query!";
		KillTimer(1);
		KillTimer(4);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->GetCheck()==1)
	{
		TempStr = "ֹͣ���ǩ��ȡ!";
		TempStrEnglish = "stop multi-tag read!";
		KillTimer(2);
		KillTimer(4);
	}
	if(((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->GetCheck()==1)
	{
		TempStr = "ֹͣ���ǩд��!";
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
		MessageBox("ִ�����볤�ȱ���Ϊ4�ֽ�!");
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

/////////////////////////////////////���ú���//call function//////////////////////////////////////////
/********************************�������*��ջ���//buffer management*clear buffer***************************************/
void CEPCGEN2::ClearIDBuffer()
{
	if(0x00 == BufferM_ClearBuffer(CS, 0xFF))
	{
		;//CUHFReaderDlg::ListBoxAdd("��ջ���ɹ�(clear buffer success)!");
	}
	else
	{
		;//CUHFReaderDlg::ListBoxAdd("��ջ���ʧ��(clear buffer failed)!");
	}
}

/********************************EPC GEN2������ǩ��ѯ//EPC GEN2 start tag query***************************************/
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
		if(0 != TagCount)		//��ǩ��ѯ�ɹ�(tag query success)
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("��ѯ���ı�ǩ����Ϊ0(query tag quantity is 0)!");
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf[j], (Data[i].Len - 1)) == 0)		//��ͬ(same)
							{
								Cnt = (int)(DisplayBuf[j][(Data[i].Len - 1)] << 8) + (int)DisplayBuf[j][Data[i].Len];
								Cnt ++;
								DisplayBuf[j][(Data[i].Len - 1)] = (unsigned char)(Cnt >> 8);
								DisplayBuf[j][Data[i].Len] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);
								m_data.SetItemText(j, 2, SNo);									// ������ʾ(update display)
								break;
							}
						}
						if(j == DisplayCnt)	//����ͬ(not same)
						{
							memcpy(DisplayBuf[j], Data[i].Data, (Data[i].Len - 1));
							DisplayBuf[j][Data[i].Len] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, (Data[i].Len - 1));
							DisplayNewTag(Tempstr);							// ��ʾ(display)
							DisplayCnt++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else			//ȡ����ʧ��(get data failed)
				{
					;
					//CUHFReaderDlg::ListBoxAdd("EPC GEN2ȡ����ʧ��(get data failed)!");
					//CUHFReaderDlg::ListBoxAdd("ֹͣ��ѯ(stop query)!");
					//KillTimer(1);
				}
			}
		}
	}
	else		//��ѯʧ��(query failed)
	{
		;
		//CUHFReaderDlg::ListBoxAdd("EPC GEN2��ǩ��ѯʧ��(tag query failed)!");
		//CUHFReaderDlg::ListBoxAdd("ֹͣ��ѯ(stop query)");
		//KillTimer(1);
	}
}

/********************************EPC GEN2��ǩ���ǩ��ȡ(EPC GEN2 Tag multi-tag read)***************************************/
void CEPCGEN2::MultiTagRead()
{
	int TagCount = 0;
	int GetCount = 0;
	int Count = 0;
	int i, j;
	int status;
	int Cnt = 0;
	int RCnt = 0;							//Reserve����ȡ�����ֽ���(Reserve memory read data numbers of byte)
	int ECnt = 0;							//Epc����ȡ�����ֽ���(EPC memory read data numbers of byte)
	int TCnt = 0;							//Tid����ȡ�����ֽ���(TID memory read data numbers of byte)
	int UCnt = 0;							//User����ȡ�����ֽ���(User memory read data numbers of byte)
	unsigned char Reserve[100] = {0};		//Reserve����ȡ����(Reserve memory read data)
	unsigned char Epc[100] = {0};			//Epc����ȡ����(EPC memory read data)
	unsigned char Tid[100] = {0};			//Tid����ȡ����(TID memory read data)
	unsigned char User[100] = {0};			//User����ȡ����(User memory read data)
	CString Tempstr = "";
	BufferData Data[16] = {0};
	CString SNo = "";

	//��ʼ��(initialize)
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
		if(0 != TagCount)			//���ǩ��ȡ�ɹ�(multi-tag read success)
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("�ɹ���ȡ�ı�ǩ����Ϊ0(read tag quantity is 0)!");
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf[j], EPCLEN) == 0)	//��ͬ(same)
							{
								Cnt = (int)(DisplayBuf[j][12] << 8) + (int)DisplayBuf[j][13];
								Cnt ++;
								DisplayBuf[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);			// �ظ�������1(times of repetition add one)
								m_data.SetItemText(j, 5, SNo);
								break;
							}
						}
						if(j == DisplayCnt)	//����ͬ(not same)
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
							DisplayNewTag(Tempstr);						// ��ʾ(Display)
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
					//CUHFReaderDlg::ListBoxAdd("EPC GEN2ȡ����ʧ��(EPC GEN2 get data failed)!");
					//CUHFReaderDlg::ListBoxAdd("ֹͣ���ǩ��ȡ(stop multi-tag read)");
					//KillTimer(2);
					//break;
				}
			}
		}
	}
	else
	{
		;
		//CUHFReaderDlg::ListBoxAdd("EPC GEN2��ǩ���ǩ��ȡʧ��(EPC GEN2 Tag multi-tag read failed)!");
		//CUHFReaderDlg::ListBoxAdd("ֹͣ���ǩ��ȡ(stop multi-tag read)");
		//KillTimer(2);
	}
}

/********************************EPC GEN2��ǩ���ǩд��(EPC GEN2 Tag multi-tag write)***************************************/
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
		if(0 != TagCount)				//���ǩд��ɹ�(multi-tag write success)
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("�ɹ�д��ı�ǩ����Ϊ0(success write the tag quantityt is 0)!");
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf[j], EPCLEN) == 0)	//��ͬ(same)
							{
								Cnt = (int)(DisplayBuf[j][12] << 8) + (int)DisplayBuf[j][13];
								Cnt ++;
								DisplayBuf[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);			// �ظ�������1(times of repetition add one)
								m_data.SetItemText(j, 2, SNo);						// ������ʾ(update display)
								break;
							}
						}
						if(j == DisplayCnt)	//����ͬ(not same)
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
					//CUHFReaderDlg::ListBoxAdd("EPC GEN2ȡ����ʧ��(EPC GEN2 get data failed)!");
					//CUHFReaderDlg::ListBoxAdd("ֹͣ���ǩд��(stop multi-tag write)");
					//KillTimer(3);
					//break;
				}
			}
		}
	}
	else
	{
		;
		//CUHFReaderDlg::ListBoxAdd("EPC GEN2��ǩ���ǩд��ʧ��(EPC GEN2 tag multi-tag write failed)!");
		//CUHFReaderDlg::ListBoxAdd("ֹͣ���ǩд��(stop multi-tag write)");
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
	//��ʼ��List��ʼ��Listctrl�ؼ�(initialize List initialize ActiveX)
	//���ԭ�з��(clear original style)
	m_data.DeleteAllItems();		//�����������(clear all content)
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
	//�����·��(set new style)
	DWORD dwStyle = m_data.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;		//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��Select an exercise of the entire line highlighted(only apply same report style listctrl)
    dwStyle |= LVS_EX_GRIDLINES;			//�����ߣ�ֻ������report����listctrl��(Gridline(only apply same report style listctrl))
	//dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�(front itme generate checkbox ActiveX)
	m_data.SetExtendedStyle(dwStyle);		//������չ���(set expand style)
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
		TempStr = "��ǩ��ȡ�ɹ�";
		TempStrEnglish = "Tag read success";
		CString TStr = "";
		TStr = CUHFReaderDlg::ByteToHexStr(RData, RCnt*2);
		m_svalue = TStr;
		UpdateData(false);
	}
	else
	{
		TempStr = "��ǩ��ȡʧ��";
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
			TempStr = "��ǩд��ɹ�";
			TempStrEnglish = "tag write success";
		}
		else
		{
			TempStr = "��ǩд��ʧ��";
			TempStrEnglish = "tag write failed";
		}
	}
	else
	{
		if(0 == Language)
			AfxMessageBox("д���ǩ��������д��ĳ��Ȳ�ƥ��!���������");
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
		TempStr = "��ǩ�����ɹ�";
		TempStrEnglish = "tag lock success";
	}
	else
	{
		TempStr = "��ǩ����ʧ��";
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
		TempStr = "��ǩ���ٳɹ�";
		TempStrEnglish = "tag kill success";
	}
	else
	{
		TempStr = "��ǩ����ʧ��";
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
			TempStr = "��ǩɸѡ���óɹ�";
			TempStrEnglish = "tag selection set success";
		}
		else
		{
			TempStr = "��ǩɸѡ����ʧ��";
			TempStrEnglish = "tag selection set failed";
		}
	}
	else
	{
		if(0 == Language)
			AfxMessageBox("��ǩ��ɸѡ���ݳ�����ѡ���ɸѡ���Ȳ�ƥ��!���������");
		else
			AfxMessageBox("tag selection data length is incorrect, please check and try again");
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/*******************************���ߺ���//tool function***************************************/
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
	((CButton *)GetDlgItem(IDC_MULTITAG_STATIC))->SetWindowText("���ǩ����");
	((CButton *)GetDlgItem(IDC_SHOWDATA_STATIC))->SetWindowText("������ʾ");
	((CButton *)GetDlgItem(IDC_SELECTMEMBANK_STATIC))->SetWindowText("��������:");
	((CButton *)GetDlgItem(IDC_WRITEMEMBANK_STATIC))->SetWindowText("д������:");
	
	((CButton *)GetDlgItem(IDC_STARTADDR_STATIC))->SetWindowText("��ʼ��ַ:");
	((CButton *)GetDlgItem(IDC_WRITEVALUE_STATIC))->SetWindowText("д������:");
	((CButton *)GetDlgItem(IDC_WORDCNTNUM_STATIC))->SetWindowText("��ȡ����:");	
	((CButton *)GetDlgItem(IDC_WRITEWORDADDR_STATIC))->SetWindowText("��ʼ��ַ");
	((CButton *)GetDlgItem(IDC_WRITEWORDNUM_STATIC))->SetWindowText("д������");
	
	((CButton *)GetDlgItem(IDC_TIMES_STATIC))->SetWindowText("ʱ��");
	((CButton *)GetDlgItem(IDC_NUM_STATIC))->SetWindowText("����");		
	((CButton *)GetDlgItem(IDC_SPEED_STATIC))->SetWindowText("����");
	((CButton *)GetDlgItem(IDC_UNIQUETAG_STATIC))->SetWindowText("����ǩ����");
	((CButton *)GetDlgItem(IDC_MEMBANK_SINGLE_STATIC))->SetWindowText("��������:");
	((CButton *)GetDlgItem(IDC_STARTADDR_SINGLE_STATIC))->SetWindowText("��ʼ��ַ:");
	
	((CButton *)GetDlgItem(IDC_LENGTH_SINGLE_STATIC))->SetWindowText("���ݳ���:");
	((CButton *)GetDlgItem(IDC_LOCKLEVEL_SINGLE_STATIC))->SetWindowText("�����ȼ�:");
	((CButton *)GetDlgItem(IDC_ASKPASSWPRD_SINGLE_STATIC))->SetWindowText("��������:");	
	((CButton *)GetDlgItem(IDC_MATCH_SINGLE_STATIC))->SetWindowText("ƥ���:");
	((CButton *)GetDlgItem(IDC_VALUE_SINGLE_STATIC))->SetWindowText("����:");
	
	((CButton *)GetDlgItem(IDC_MULTI_TAG_INVENTORY_RADIO))->SetWindowText("���ǩ��ѯ");
	((CButton *)GetDlgItem(IDC_MULTI_TAG_READ_RADIO))->SetWindowText("���ǩ��ȡ");
	((CButton *)GetDlgItem(IDC_MULTI_TAG_WRITE_RADIO))->SetWindowText("���ǩд��");
	((CButton *)GetDlgItem(IDC_SECREAD_RADIO))->SetWindowText("��ȫ��");
	((CButton *)GetDlgItem(IDC_SECWRITE_RADIO))->SetWindowText("��ȫд");
	((CButton *)GetDlgItem(IDC_SECLOCK_RADIO))->SetWindowText("��ȫ��");
	((CButton *)GetDlgItem(IDC_KILLTAG_RADIO))->SetWindowText("���ٱ�ǩ");
	((CButton *)GetDlgItem(IDC_CONFIGTAG_RADIO))->SetWindowText("ɸѡ����");	
	((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("��ʼ");
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->SetWindowText("ֹͣ");	
	((CButton *)GetDlgItem(IDC_ONCEINVENTORY_BUTTON))->SetWindowText("������ѯ");
	((CButton *)GetDlgItem(IDC_BUTTON_CLEAR))->SetWindowText("���");	
	((CButton *)GetDlgItem(IDC_EXECUTE_BUTTON))->SetWindowText("ִ��");
	
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
