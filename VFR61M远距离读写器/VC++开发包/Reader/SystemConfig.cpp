// SystemConfig.cpp : implementation file
//

#include "stdafx.h"
#include "uhfreader.h"
#include "SystemConfig.h"
#include "CertificationDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "FreqPoints.h"
#include "UHFReaderDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CSystemConfig dialog

extern hComSocket CS; 
extern int Language;
extern int freqnum;
extern int freqpoints[124];
int Freqpoints[124] = {0};
int Freqnum = 0;

extern int ConnectFlag;
extern int ResetFlag;
int initfalg = 0;

CSystemConfig::CSystemConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSystemConfig)
	m_tagmode = _T("");
	m_wstyle = -1;
	m_delaytime = 0;
	m_triggertime = 0;
	m_ant1 = _T("");
	m_ant2 = _T("");
	m_ant3 = _T("");
	m_ant4 = _T("");
	m_internetport = _T("");
	//}}AFX_DATA_INIT
}


void CSystemConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSystemConfig)
	DDX_Control(pDX, IDC_MASKCODE, m_maskcode);
	DDX_Control(pDX, IDC_IPADDRESS, m_ipaddress);
	DDX_Control(pDX, IDC_GATEWAY, m_gateway);
	DDX_Control(pDX, IDC_ANT4_BITMAP, m_ant4_bitmap);
	DDX_Control(pDX, IDC_ANT3_BITMAP, m_ant3_bitmap);
	DDX_Control(pDX, IDC_ANT2_BITMAP, m_ant2_bitmap);
	DDX_Control(pDX, IDC_ANT1_BITMAP, m_ant1_bitmap);
	DDX_Text(pDX, IDC_TAGMODE_EDIT, m_tagmode);
	DDX_CBIndex(pDX, IDC_WEIGENSTYLE_COMBO, m_wstyle);
	DDX_Text(pDX, IDC_DELAYTIME_EDIT, m_delaytime);
	DDX_Text(pDX, IDC_TRIGGERTIME_EDIT, m_triggertime);
	DDX_Text(pDX, IDC_ANTENNA1_EDIT, m_ant1);
	DDX_Text(pDX, IDC_ANTENNA2_EDIT, m_ant2);
	DDX_Text(pDX, IDC_ANTENNA3_EDIT, m_ant3);
	DDX_Text(pDX, IDC_ANTENNA4_EDIT, m_ant4);
	DDX_Text(pDX, IDC_INTERNETPORT_EDIT, m_internetport);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSystemConfig, CDialog)
	//{{AFX_MSG_MAP(CSystemConfig)
	ON_BN_CLICKED(IDC_RESET_BUTTON, OnResetReaderButton)
	ON_BN_CLICKED(IDC_GETRFPOWER_BUTTON, OnGetrfpowerButton)
	ON_BN_CLICKED(IDC_SETRFPOWER_BUTTON, OnSetrfpowerButton)
	ON_BN_CLICKED(IDC_SETFREQUENCY_BUTTON, OnSetFrequencyButton)
	ON_BN_CLICKED(IDC_GETFREQUENCY_BUTTON, OnGetFrequencyButton)
	ON_BN_CLICKED(IDC_OTHERS_RADIO, OnOthersRadio)
	ON_BN_CLICKED(IDC_SETANTENNA_BUTTON, OnSetAntennaButton)
	ON_BN_CLICKED(IDC_GETANTENNA_BUTTON, OnGetAntennaButton)
	ON_BN_CLICKED(IDC_SETSFTM_BUTTON, OnSetSingleFastmTagModeButton)
	ON_BN_CLICKED(IDC_GETSFTM_BUTTON, OnGetSingleFastmTagModeButton)
	ON_BN_CLICKED(IDC_OUTPORT_BUTTON, OnOutPortButton)
	ON_BN_CLICKED(IDC_SETINTERNET_BUTTON, OnSetInternetButton)
	ON_BN_CLICKED(IDC_GETINTERNET_BUTTON, OnGetInternetButton)
	ON_BN_CLICKED(IDC_GETOUTPORT_BUTTON, OnGetOutPortButton)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_CERTIFICATION, OnButtonCertification)
	ON_BN_CLICKED(IDC_SETINTRFACE_BUTTON, OnSetIntrfaceButton)
	ON_BN_CLICKED(IDC_QUERYINTERFACE_BUTTON, OnQueryInterfaceButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSystemConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	if(0 == Language)
		LanguageChinese();
	if(1 == Language)
		LanguageEnglish();
	((CButton *)GetDlgItem(IDC_IOPORT1_RADIO))->SetCheck(1);
	SetTimer(1, 100, NULL);
	SetTimer(2, 50, NULL);
	SetTimer(3, 50, NULL);
	SetTimer(4, 50, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
/////////////////////////////////////////////////////////////////////////////
// CSystemConfig message handlers
/********************************复位读写器***************************************/
void CSystemConfig::OnResetReaderButton() //reset reader
{
	// TODO: Add your control notification handler code here
	ResetReader();
	ResetFlag = 1;
}
/********************************设置读写器天线功率***************************************/
void CSystemConfig::OnSetrfpowerButton() //set reader antenna power
{
	// TODO: Add your control notification handler code here
	Set_RfPower();
}
/********************************查询读写器天线功率***************************************/
void CSystemConfig::OnGetrfpowerButton() //query reader antenna power
{
	// TODO: Add your control notification handler code here
	Get_RfPower();
}
/********************************设置读写器射频参数***************************************/
void CSystemConfig::OnSetFrequencyButton() //set reader frequency parameter
{
	// TODO: Add your control notification handler code here
	SetFrequency();
}
/********************************查询读写器射频参数***************************************/
void CSystemConfig::OnGetFrequencyButton() //query reader frequency parameter
{
	// TODO: Add your control notification handler code here
	GetFrequency();
}

void CSystemConfig::OnOthersRadio() 
{
	// TODO: Add your control notification handler code here
	//CFreqPoints fpdlg;
	//fpdlg.DoModal();
	CFreqPoints *cfpDlg=new CFreqPoints; 
	cfpDlg->Create(IDD_FREQPOINTS_DIALOG, NULL); 
	cfpDlg->ShowWindow(SW_SHOW); 
}
/********************************设置读写器天线状态***************************************/
void CSystemConfig::OnSetAntennaButton() //set reader antenna state
{
	// TODO: Add your control notification handler code here
	SetAntenna();
}
/********************************查询读写器天线状态***************************************/
void CSystemConfig::OnGetAntennaButton() //query reader antenna state
{
	// TODO: Add your control notification handler code here
	GetAntenna();
}
/********************************设置读写器载波抵消策略***************************************/
void CSystemConfig::OnSetSingleFastmTagModeButton() //set reader single fast tag mode
{
	// TODO: Add your control notification handler code here
	SetSingleFastTagMode();
}
/********************************查询读写器载波抵消策略***************************************/
void CSystemConfig::OnGetSingleFastmTagModeButton() //query reader single fast tag mode
{
	// TODO: Add your control notification handler code here
	GetSingleFastTagMode();
}
/********************************设置读写器设置可编程IO口***************************************/
void CSystemConfig::OnOutPortButton() //set reader outport 
{
	// TODO: Add your control notification handler code here
	SetOutPort();
}

/********************************查询读写器设置可编程IO口***************************************/
void CSystemConfig::OnGetOutPortButton() //query reader outport 
{
	// TODO: Add your control notification handler code here
	GetOutPort();
}
/********************************设置读写器网口参数***************************************/
void CSystemConfig::OnSetInternetButton() //set reader interest parameter
{
	// TODO: Add your control notification handler code here
	SetInternetAccess();
}
/********************************查询读写器网口参数***************************************/
void CSystemConfig::OnGetInternetButton() //query reader internet parameter
{
	// TODO: Add your control notification handler code here
	GetInternetAccess();
}

void CSystemConfig::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(1 == nIDEvent)
	{
		if(1 == ConnectFlag)
		{
			if(0 == initfalg)
			{
				GetVersion();
				GetSerialNum();
				Get_RfPower();
				GetAntenna();
				GetFrequency();
				GetInternetAccess();
				GetSingleFastTagMode();
				GetOutPort();
				OnQueryInterfaceButton();
				initfalg = 1;
			}
		}
		if(0 == ConnectFlag)
		{
			initfalg = 0;
		}
	}
	switch(nIDEvent)
	{
	case 2:
		InterfaceRadioCheck();
		break;
	case 3:
		WorkModelRadioCheck();
		break;
	case 4:
		CheckRelay();
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CSystemConfig::OnButtonCertification() 
{
	// TODO: Add your control notification handler code here
	CCertificationDlg ctfDlg;
	ctfDlg.DoModal();
}

void CSystemConfig::OnSetIntrfaceButton() 
{
	// TODO: Add your control notification handler code here
	CString Text = "";
	((CButton *)GetDlgItem(IDC_SETINTRFACE_BUTTON))->GetWindowText(Text);
	WorkModel(255, Text);
	OutInterface(255, Text);
}

void CSystemConfig::OnQueryInterfaceButton() 
{
	// TODO: Add your control notification handler code here
	CString Text = "";
	((CButton *)GetDlgItem(IDC_QUERYINTERFACE_BUTTON))->GetWindowText(Text);
	WorkModel(255, Text);
	OutInterface(255, Text);
}

/////////////////////////////////////调用函数//////////////////////////////////////////
/********************************获取版本号***************************************/
void CSystemConfig::GetVersion() //call function  //get version number
{
	unsigned char major = 0;
	unsigned char minor = 0;
	CString TempStr = "";
	CString TempStrEnglish = "";
	if(0x00 == Config_GetLocatorVersion(CS, major, minor, 0xFF))
	{
		
		CString Major = "";
		CString Minor = "";
		Major.Format("%02d", (int)major);
		Minor.Format("%02d", (int)minor);
		TempStr = "读写器固件版本号为: V" + Major + "." + Minor;
		TempStrEnglish = "Reader version : V" + Major + "." + Minor;
		UpdateData(false);
	}
	else
	{
		TempStr = "获取版本号失败!";//
		TempStrEnglish = "get version number failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	return ;
}

/********************************获取序列号***************************************/
void CSystemConfig::GetSerialNum() //GetSerialNo
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	CString str = "";
	int data = 0;
	unsigned char StartAddr = 0x10;
	unsigned char PLen = 6;
	unsigned char GData[6] = {0};
	unsigned char ReaderAddr = (unsigned char)(255 & 0xFF);
	if(0x00 == Parameter_GetReader(CS, StartAddr, PLen, GData, ReaderAddr))
	{
		TempStr = CUHFReaderDlg::ByteToHexStr(GData, PLen);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("读写器序列号为: " + TempStr);
		else
			CUHFReaderDlg::ListBoxAdd("Reader serial No.: " + TempStr);
		UpdateData(false);
	}
	else
	{
		TempStr = "获取序列号号失败!";
		TempStrEnglish = "Get serial No. fail!";
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd(TempStr);
		else
			CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	}
}
/********************************设置波特率***************************************/
void CSystemConfig::SetBaud()//set baudrate
{
	CString strBaud = "";
	CString TempStr = "";
	CString TempStrEnglish = "";
	int BnIndex = -1;
	unsigned char TempParameter = 0x00;
	if(BnIndex == -1)
	{	
		TempStr = "设置的波特率不能为空!";
		TempStrEnglish = "set baudrate can not be empty";
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd(TempStr);
		else
			CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
		return ;
	}
	else
	{
		int baud = atoi((LPCTSTR)strBaud);
		switch(baud)
		{
		case 9600:
			TempParameter = 0x00;
			break;
		case 19200:
			TempParameter = 0x01;
			break;
		case 38400:
			TempParameter = 0x02;
			break;
		case 57600:
			TempParameter = 0x03;
			break;
		case 115200:
			TempParameter = 0x04;
			break;
		default:
			;
		}
		if(0x00 == Config_SetReaderBaud(CS, TempParameter, 0xFF))
		{
			TempStr = "设置的波特率成功!";
			TempStrEnglish = "set baudrate success";
		}
		else
		{
			TempStr = "设置的波特率失败!";
			TempStrEnglish = "set baudrate failed";
		}
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************复位读写器***************************************/
void CSystemConfig::ResetReader()//rest reader
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	if(0x00 == Config_ResetReader(CS, 0xFF))
	{
		TempStr = "读写器复位成功!";
		TempStrEnglish = "reset reader success";
		ConnectFlag = 0;
	}
	else
	{
		TempStr = "读写器复位失败!";
		TempStrEnglish = "reset reader failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************设置读写器天线功率***************************************/
void CSystemConfig::Set_RfPower()//set reader antenna power 
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	int m_anten1_dbm = 0;
	int m_anten2_dbm = 0;
	int m_anten3_dbm = 0;
	int m_anten4_dbm = 0;
	UpdateData(true);
	unsigned char aPwr[4] = {0x00, 0x00, 0x00, 0x00};
	m_anten1_dbm = atoi(m_ant1);
	m_anten2_dbm = atoi(m_ant2);
	m_anten3_dbm = atoi(m_ant3);
	m_anten4_dbm = atoi(m_ant4);
	
	m_anten1_dbm = (m_anten1_dbm<0)?0:m_anten1_dbm;
	m_anten1_dbm = (m_anten1_dbm>32)?32:m_anten1_dbm;

	m_anten2_dbm = (m_anten2_dbm<0)?0:m_anten2_dbm;
	m_anten2_dbm = (m_anten2_dbm>32)?32:m_anten2_dbm;

	m_anten3_dbm = (m_anten3_dbm<0)?0:m_anten3_dbm;
	m_anten3_dbm = (m_anten3_dbm>32)?32:m_anten3_dbm;

	m_anten4_dbm = (m_anten4_dbm<0)?0:m_anten4_dbm;
	m_anten4_dbm = (m_anten4_dbm>32)?32:m_anten4_dbm;
	
	aPwr[0] = (byte)((m_anten1_dbm) & 0xFF);
	aPwr[1] = (byte)((m_anten2_dbm) & 0xFF);
	aPwr[2] = (byte)((m_anten3_dbm) & 0xFF);
	aPwr[3] = (byte)((m_anten4_dbm) & 0xFF);
	if(0x00 == Config_SetRfPower(CS, aPwr, 0xFF))
	{
		TempStr = "天线功率设置成功!";
		TempStrEnglish = "antenna power set success";
	}
	else
	{
		TempStr = "天线功率设置失败!";
		TempStrEnglish = "antenna power set failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************查询读写器天线功率***************************************/
void CSystemConfig::Get_RfPower()//query reader antenna power
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char aPwr[4] = {0x00, 0x00, 0x00, 0x00};
	CString m_anten1_dbm = "";
	CString m_anten2_dbm = "";
	CString m_anten3_dbm = "";
	CString m_anten4_dbm = "";
	if(0x00 == Config_GetRfPower(CS, aPwr, 0xFF))
	{
		TempStr = "天线功率查询成功!";
		TempStrEnglish = "antenna power query success";
		CString Port = "";
		m_anten1_dbm.Format("%d", (int)aPwr[0]);
		m_anten2_dbm.Format("%d", (int)aPwr[1]);
		m_anten3_dbm.Format("%d", (int)aPwr[2]);
		m_anten4_dbm.Format("%d", (int)aPwr[3]);
		m_ant1 = m_anten1_dbm;
		m_ant2 = m_anten2_dbm;
		m_ant3 = m_anten3_dbm;
		m_ant4 = m_anten4_dbm;
		
		UpdateData(false);
	}
	else
	{
		TempStr = "天线功率查询失败!";
		TempStrEnglish = "antenna power query failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************设置读写器射频参数***************************************/
void CSystemConfig::SetFrequency()//set reader frequency parameter
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	if(((CButton *)GetDlgItem(IDC_CHINA_RADIO))->GetCheck() == 1)
	{
		freqnum = 0;
		memset(freqpoints, 0, 124);
		freqpoints[0] = 0;
	}
	if(((CButton *)GetDlgItem(IDC_NORTHAMERICA_RADIO))->GetCheck() == 1)
	{
		freqnum = 0;
		memset(freqpoints, 0, 124);
		freqpoints[0] = 1;
	}
	if(((CButton *)GetDlgItem(IDC_EUROPE_RADIO))->GetCheck() == 1)
	{
		freqnum = 0;
		memset(freqpoints, 0, 124);
		freqpoints[0] = 2;
	}

	if(0x00 == Config_SetFreqPoint(CS, freqnum, freqpoints, 0xFF))
	{
		TempStr = "天线频率率设置成功!";
		TempStrEnglish = "antenna frequency set success";
	}
	else
	{
		TempStr = "天线频率设置失败!";
		TempStrEnglish = "antenna frequency set failed";
	}
	
	UpdateData(false);
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}
/********************************查询读写器射频参数***************************************/
void CSystemConfig::GetFrequency()//query reader frequency parameter
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	if(0x00 == Config_GetFreqPoint(CS, Freqnum, Freqpoints, 0xFF))
	{
		TempStr = "天线频率查询成功!";
		TempStrEnglish = "antenna frequency query success";
		if(0 == Freqnum)
		{
			if(0 == Freqpoints[0])
				((CButton *)GetDlgItem(IDC_CHINA_RADIO))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_CHINA_RADIO))->SetCheck(0);

			if(1 == Freqpoints[0])
				((CButton *)GetDlgItem(IDC_NORTHAMERICA_RADIO))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_NORTHAMERICA_RADIO))->SetCheck(0);

			if(2 == Freqpoints[0])
				((CButton *)GetDlgItem(IDC_EUROPE_RADIO))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_EUROPE_RADIO))->SetCheck(0);

			((CButton *)GetDlgItem(IDC_OTHERS_RADIO))->SetCheck(0);
		}
		else
		{
			((CButton *)GetDlgItem(IDC_CHINA_RADIO))->SetCheck(0);
			((CButton *)GetDlgItem(IDC_NORTHAMERICA_RADIO))->SetCheck(0);
			((CButton *)GetDlgItem(IDC_EUROPE_RADIO))->SetCheck(0);
			((CButton *)GetDlgItem(IDC_OTHERS_RADIO))->SetCheck(1);
			CFreqPoints *cfpDlg=new CFreqPoints; 
			cfpDlg->Create(IDD_FREQPOINTS_DIALOG, NULL); 
			cfpDlg->ShowWindow(SW_HIDE);

		}
	}
	else
	{
		TempStr = "天线频率查询失败!";
		TempStrEnglish = "antenna frequency query failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************设置读写器天线状态***************************************/
void CSystemConfig::SetAntenna()//set reader antenna state
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	int ant[4] = {0};
	int Workant = 0;
	if(((CButton *)GetDlgItem(IDC_ANT1_CHECK))->GetCheck()==1)
		ant[0] = 1;
	if(((CButton *)GetDlgItem(IDC_ANT2_CHECK))->GetCheck()==1)
		ant[1] = 2;
	if(((CButton *)GetDlgItem(IDC_ANT3_CHECK))->GetCheck()==1)
		ant[2] = 4;
	if(((CButton *)GetDlgItem(IDC_ANT4_CHECK))->GetCheck()==1)
		ant[3] = 8;
	Workant = ant[0] + ant[1] + ant[2] + ant[3];
	if(0x00 == Config_SetAntenna(CS, Workant, 0xFF))
	{
		TempStr = "天线工作状态设置成功!";
		TempStrEnglish = "antenna work state set success";
	}
	else
	{
		TempStr = "天线工作状态设置失败!";
		TempStrEnglish = "antenna work state set failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************查询读写器天线状态***************************************/
void CSystemConfig::GetAntenna()//query reader antenna state
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	int Workant = 0;
	int antStatus = 0;
	CBitmap   bmp;
	if(0x00 == Config_GetAntenna(CS, Workant, antStatus, 0xFF))
	{
		TempStr = "天线工作状态查询成功!";
		TempStrEnglish = "antenna work state query success";
		if(Workant & (1 << 0))
			((CButton *)GetDlgItem(IDC_ANT1_CHECK))->SetCheck(1);
		else
			((CButton *)GetDlgItem(IDC_ANT1_CHECK))->SetCheck(0);
		if(Workant & (1 << 1))
			((CButton *)GetDlgItem(IDC_ANT2_CHECK))->SetCheck(1);
		else
			((CButton *)GetDlgItem(IDC_ANT2_CHECK))->SetCheck(0);
		if(Workant & (1 << 2))
			((CButton *)GetDlgItem(IDC_ANT3_CHECK))->SetCheck(1);
		else
			((CButton *)GetDlgItem(IDC_ANT3_CHECK))->SetCheck(0);
		if(Workant & (1 << 3))
			((CButton *)GetDlgItem(IDC_ANT4_CHECK))->SetCheck(1);
		else
			((CButton *)GetDlgItem(IDC_ANT4_CHECK))->SetCheck(0);
		if(antStatus & (1 << 0))
		{
			bmp.LoadBitmap(IDB_SINGLE_BITMAP);
			m_ant1_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		else
		{
			bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
			m_ant1_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		if(antStatus & (1 << 1))
		{
			bmp.LoadBitmap(IDB_SINGLE_BITMAP);
			m_ant2_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		else
		{
			bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
			m_ant2_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		if(antStatus & (1 << 2))
		{
			bmp.LoadBitmap(IDB_SINGLE_BITMAP);
			m_ant3_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		else
		{
			bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
			m_ant3_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		if(antStatus & (1 << 3))
		{
			bmp.LoadBitmap(IDB_SINGLE_BITMAP);
			m_ant4_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
		else
		{
			bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
			m_ant4_bitmap.SetBitmap((HBITMAP)bmp);
			bmp.Detach();
		}
	}
	else
	{
		TempStr = "天线工作状态查询失败!";
		TempStrEnglish = "antenna work state query failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************设置读写器载波抵消策略***************************************/
void CSystemConfig::SetSingleFastTagMode()//set reader singe fast tag mode
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char Mode = 0x00;
	if(((CButton *)GetDlgItem(IDC_LITERTAG_RADIO))->GetCheck() == 1)
	{
		Mode = 0x00;
		if(0x00 == Config_SetSingleFastTagMode(CS, Mode, 0xFF))
		{
			TempStr = "设置读写器载波抵消策略成功!";
			TempStrEnglish = "set single fast tag mode success";
			m_tagmode = "单卡快速模式";
			m_tagmode = "single tag fast mode";

		}
		else
		{
			TempStr = "设置读写器载波抵消策略失败!";
			TempStrEnglish = "set single fast tag mode failed";
		}
	}
	if(((CButton *)GetDlgItem(IDC_MORETAG_RADIO))->GetCheck() == 1)
	{
		Mode = 0x01;
		if(0x00 == Config_SetSingleFastTagMode(CS, Mode, 0xFF))
		{
			TempStr = "设置读写器载波抵消策略成功!";
			TempStrEnglish = "set reader single fast tag mode success";
			m_tagmode = "多卡模式";
			m_tagmode = "multitag mode";
		}
		else
		{
			TempStr = "设置读写器载波抵消策略失败!";
			TempStrEnglish = "set reader single fast tag mode failed";
		}
	}
	UpdateData(false);
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************查询读写器载波抵消策略***************************************/
void CSystemConfig::GetSingleFastTagMode()//query reader single fast tag mode
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char Mode= 0x00;
	if(0x00 == Config_GetSingleFastTagMode(CS, Mode, 0xFF))
	{
		TempStr = "查询读写器载波抵消策略成功!";
		TempStrEnglish = "query reader single fast tag mode success";
		if(0x00 == Mode)
		{
			((CButton *)GetDlgItem(IDC_LITERTAG_RADIO))->SetCheck(1);
			if(0 == Language)
				m_tagmode = "单卡快读模式";
			else
				m_tagmode = "single tag fast mode";
		}
		else
		{
			((CButton *)GetDlgItem(IDC_MORETAG_RADIO))->SetCheck(1);
			if(0 == Language)
				m_tagmode = "多卡模式";
			else
				m_tagmode = "multitag mode";
		}
		UpdateData(false);
	}
	else
	{
		TempStr = "查询读写器载波抵消策略失败!";
		TempStrEnglish = "query reader single fast tag mode failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************设置读写器测试模式***************************************/
void CSystemConfig::SetTestMode()//set reader test mode
{
/*	CString TempStr = "";
	unsigned char TestMode = 0x00;
	int WorkAnt = 0;
	int AntStatus = 0;
	if(((CButton *)GetDlgItem(IDC_OPENPA_RADIO1))->GetCheck() == 1)
		TestMode = 0x00;
	if(((CButton *)GetDlgItem(IDC_CLOSEPA_RADIO2))->GetCheck() == 1)
		TestMode = 0x01;
	if(((CButton *)GetDlgItem(IDC_ANTCORRECT_RADIO3))->GetCheck() == 1)
		TestMode = 0x02;
	if(0x02 == TestMode)
	{
		if(0x00 == Config_GetAntenna(CS, WorkAnt, AntStatus, 0xFF))
		{
			if(0 == WorkAnt)
			{
				if(0x00 == Config_SetTestMode(CS, TestMode, 0xFF))
				{
					TempStr = "设置读写器测试模式成功!";//set reader test mode success
				}
				else
				{
					TempStr = "设置读写器测试模式失败!";//set reader test mode failed
				}
				CUHFReaderDlg::ListBoxAdd(TempStr);
			}
			else
			{
				TempStr = "请将天线状态设置成断开状态!";//set antenna state as disconnect state
				CUHFReaderDlg::ListBoxAdd(TempStr);
				return ;
			}
		}
	}
	else
	{
		if(0x00 == Config_SetTestMode(CS, TestMode, 0xFF))
		{
			TempStr = "设置读写器测试模式成功!";//set reader test mode success
		}
		else
		{
			TempStr = "设置读写器测试模式失败!";//set reader test mode failed
		}		
	}
	CUHFReaderDlg::ListBoxAdd(TempStr);*/
}

/********************************设置读写器设置可编程IO口***************************************/
void CSystemConfig::SetOutPort()//set reader outport IO port
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char Num = 0x00;
	unsigned char Level = 0x00;
	if(((CButton *)GetDlgItem(IDC_IOPORT1_RADIO))->GetCheck() == 1)
		Num = 0x00;
	if(((CButton *)GetDlgItem(IDC_IOPORT2_RADIO))->GetCheck() == 1)
		Num = 0x01;
	if(((CButton *)GetDlgItem(IDC_RELAY_RADIO))->GetCheck() == 1)
		Num = 0x02;
	if(((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->GetCheck() == 1)
		Level = 0x00;
	if(((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->GetCheck() == 1)
		Level = 0x01;
	if(((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->GetCheck() == 0 && ((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->GetCheck() == 0)
		Level = 0x01;
	if(0x00 == Config_SetOutPort(CS, Num, Level, 0xFF))
	{
		TempStr = "设置读写器设置可编程IO口成功!";
		TempStrEnglish = "set reader outport IO port success";
	}
	else
	{
		TempStr = "设置读写器设置可编程IO口失败!";
		TempStrEnglish = "set reader outport IO port failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************查询读写器设置可编程IO口***************************************/
void CSystemConfig::GetOutPort()//query reader set outport IO port
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char Num = 0x00;
	unsigned char Level = 0x00;
	if(((CButton *)GetDlgItem(IDC_IOPORT1_RADIO))->GetCheck() == 1)
		Num = 0x00;
	if(((CButton *)GetDlgItem(IDC_IOPORT2_RADIO))->GetCheck() == 1)
		Num = 0x01;
	if(((CButton *)GetDlgItem(IDC_RELAY_RADIO))->GetCheck() == 1)
		Num = 0x02;

	if(0x00 == Config_GetInPort(CS, Num, Level, 0xFF))
	{
		TempStr = "查询读写器设置可编程IO口成功!";
		TempStrEnglish = "query reader set outport IO port success";
	}
	else
	{
		TempStr = "查询读写器设置可编程IO口失败!";
		TempStrEnglish = "query reader set outport IO port failed";
	}
	if(0x00 == Level)
	{
		((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetCheck(1);
		((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetCheck(0);
	}
	if(0x01 == Level)
	{
		((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetCheck(1);
		((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetCheck(0);
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************设置读写器网口参数***************************************/
void CSystemConfig::SetInternetAccess()//set reader internet port parameter
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	CString IPAddr = "";
	CString MaskCode = "";
	CString GateWay = "";
	int InternetPort = 0;
	unsigned char IPAddrbuf[4] = {0};
	unsigned char MaskCodebuf[4] = {0};
	unsigned char GateWaybuf[4] = {0};
	unsigned char InternetPortbuf[2] = {0};
	UpdateData(TRUE);
	m_ipaddress.GetWindowText(IPAddr);
	m_maskcode.GetWindowText(MaskCode);
	m_gateway.GetWindowText(GateWay);
	InternetPort = atoi(m_internetport);
	
	DecimalstrToByte(IPAddrbuf, IPAddr);
	DecimalstrToByte(MaskCodebuf, MaskCode);
	DecimalstrToByte(GateWaybuf, GateWay);

	InternetPortbuf[0] = (unsigned char)((InternetPort)>> 8);
	InternetPortbuf[1] = (unsigned char)((InternetPort) & 0xFF);
	
	if(0x00 == Config_SetIntrnetAccess(CS, IPAddrbuf, MaskCodebuf, GateWaybuf, InternetPortbuf, 0xFF))
	{
		TempStr = "设置读写器网口参数成功!";
		TempStrEnglish = "set reader internet port parameter success";
	}
	else
	{
		TempStr = "设置读写器网口参数失败!";
		TempStrEnglish = "set reader internet port parameter failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	
}

/********************************查询读写器网口参数***************************************/
void CSystemConfig::GetInternetAccess()//query reader internet port parameter
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	CString IPAddr = "";
	CString MaskCode = "";
	CString GateWay = "";
	int InternetPort = 0;
	unsigned char IPAddrbuf[4] = {0};
	unsigned char MaskCodebuf[4] = {0};
	unsigned char GateWaybuf[4] = {0};
	unsigned char InternetPortbuf[2] = {0};
	if(0x00 == Config_GetIntrnetAccess(CS, IPAddrbuf, MaskCodebuf, GateWaybuf, InternetPortbuf, 0xFF))
	{
		TempStr = "查询读写器网口参数成功!";
		TempStrEnglish = "query reader internet port parameter success";
		ByteToDecimalstr(IPAddr,IPAddrbuf);
		ByteToDecimalstr(MaskCode,MaskCodebuf);
		ByteToDecimalstr(GateWay,GateWaybuf);
		InternetPort = (InternetPortbuf[1]<<8)+(int)InternetPortbuf[0];
	}
	else
	{
		TempStr = "查询读写器网口参数失败!";
		TempStrEnglish = "query reader interest port parameter failed";
	}
	m_ipaddress.SetWindowText(IPAddr);
	m_maskcode.SetWindowText(MaskCode);
	m_gateway.SetWindowText(GateWay);
	CString Port = "";
	Port.Format("%d", InternetPort);
	m_internetport = Port;
	UpdateData(false);
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/*****************************设置或查询工作模式***************************************/
int CSystemConfig::WorkModel(int ReaderNum, CString Text)
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	unsigned char PAddr = 0x90;
	int PLen = 1;
	int workmodel = 0;
	int time = 0;
	unsigned char PSetData[1] = {0};
	unsigned char PRefData[1024] = {0};

	if(Text == "设置" || Text == "Set")
	{

		UpdateData(true);
		if(((CButton *)GetDlgItem(IDC_CMD_RADIO))->GetCheck())
			workmodel = 0;
		if(((CButton *)GetDlgItem(IDC_ANIMATION_RADIO))->GetCheck())
			workmodel = 1;
		if(((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->GetCheck())
			workmodel = 2;
		PSetData[0] = (unsigned char)(workmodel & 0xFF);
		if(0x00 == Parameter_SetReader(CS, PAddr, PLen, PSetData, ReaderAddr))
		{
			TempStr = "工作模式设置成功!";
			TempStrEnglish = "Work model set success!";
			if(((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->GetCheck())
				TriggerTime(255, Text);
		}
		else
		{
			TempStr = "工作模式设置失败!";
			TempStrEnglish = "Work model set fail!";
		}
	}
	else if(Text == "查询" || Text == "Query")
	{
		if(0x00 == Parameter_GetReader(CS, PAddr, PLen, PRefData, ReaderAddr))
		{
			workmodel = (int)PRefData[0];
			if(1 == workmodel)
			{
				((CButton *)GetDlgItem(IDC_CMD_RADIO))->SetCheck(0);
				((CButton *)GetDlgItem(IDC_ANIMATION_RADIO))->SetCheck(1);
				((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->SetCheck(0);
			}
			else if(2 == workmodel)
			{
				((CButton *)GetDlgItem(IDC_CMD_RADIO))->SetCheck(0);
				((CButton *)GetDlgItem(IDC_ANIMATION_RADIO))->SetCheck(0);
				((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->SetCheck(1);
			}
			else
			{
				((CButton *)GetDlgItem(IDC_CMD_RADIO))->SetCheck(1);
				((CButton *)GetDlgItem(IDC_ANIMATION_RADIO))->SetCheck(0);
				((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->SetCheck(0);
			}
			TempStr = "查询工作模式成功!";
			TempStrEnglish = "Work model query success!";
		}
		else
		{
			TempStr = "查询工作模式失败!";
			TempStrEnglish = "Work model query fail!";
		}
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	return 0;
}

/********************************设置或查询接口***************************************/
int CSystemConfig::OutInterface(int ReaderNum, CString Text)
{
	UpdateData(true);
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	unsigned char PAddr = 0x00;
	int PLen = 1;
	unsigned char PSetData[1] = {0};
	unsigned char PRefData[1024] = {0};
	
	int OutPort = 0;
	if(Text == "设置" || Text == "Set")
	{
		if(1 == ((CButton *)GetDlgItem(IDC_RS485_CHECK))->GetCheck())
			OutPort = OutPort + 1;
		if(1 == ((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->GetCheck())
			OutPort = OutPort + 2;
		if(1 == ((CButton *)GetDlgItem(IDC_RS232_CHECK))->GetCheck())
			OutPort = OutPort + 4;
		if(1 == ((CButton *)GetDlgItem(IDC_IP_CHECK))->GetCheck())
			OutPort = OutPort + 8;
		if(1 == ((CButton *)GetDlgItem(IDC_RELAY_CHECK))->GetCheck())
			OutPort = OutPort + 16;
		PAddr = 0x97;
		PSetData[0] = (unsigned char)(OutPort & 0xFF);
		if(0x00 == Parameter_SetReader(CS, PAddr, PLen, PSetData, ReaderAddr))
		{
			TempStr = "设置输出接口成功!";
			TempStrEnglish = "OutInterface set success!";
		}
		else
		{
			TempStr = "设置输出接口失败!";
			TempStrEnglish = "OutInterface set fail!";
		}
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd(TempStr);
		else
			CUHFReaderDlg::ListBoxAdd(TempStrEnglish);

		if(1 == ((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->GetCheck())
		{
			WeigenStyle(ReaderNum, Text);
		}
		if(1 == ((CButton *)GetDlgItem(IDC_RELAY_CHECK))->GetCheck())
		{
			RelayDelayTime(ReaderNum, Text);
		}
	}
	else if(Text == "查询" || Text == "Query")
	{
		PAddr = 0x97;
		if(0x00 == Parameter_GetReader(CS, PAddr, PLen, PRefData, ReaderAddr))
		{
			OutPort = (int)PRefData[0];
			if(OutPort & (1 << 0))
				((CButton *)GetDlgItem(IDC_RS485_CHECK))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_RS485_CHECK))->SetCheck(0);
			if(OutPort & (1 << 1))
				((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->SetCheck(0);
			if(OutPort & (1 << 2))
				((CButton *)GetDlgItem(IDC_RS232_CHECK))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_RS232_CHECK))->SetCheck(0);
			if(OutPort & (1 << 3))
				((CButton *)GetDlgItem(IDC_IP_CHECK))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_IP_CHECK))->SetCheck(0);
			if(OutPort & (1 << 4))
				((CButton *)GetDlgItem(IDC_RELAY_CHECK))->SetCheck(1);
			else
				((CButton *)GetDlgItem(IDC_RELAY_CHECK))->SetCheck(0);
			TempStr = "查询输出接口成功!";
			TempStrEnglish = "OutInterface query success!";
			if(0 == Language)
				CUHFReaderDlg::ListBoxAdd(TempStr);
			else
				CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
			if(OutPort & (1 << 1))
				WeigenStyle(ReaderNum, Text);
			if(OutPort & (1 << 4))
				RelayDelayTime(ReaderNum, Text);
		}
		else
		{
			TempStr = "查询输出接口失败!";
			TempStrEnglish = "OutInterface query fail!";
			if(0 == Language)
				CUHFReaderDlg::ListBoxAdd(TempStr);
			else
				CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
		}
	}
	return 0;
}

/********************************设置触发时间***************************************/
int CSystemConfig::TriggerTime(int ReaderNum, CString Text)
{
	UpdateData(true);
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	unsigned char PAddr = 0x92;
	int PLen = 1;
	int triggertime = 0;
	unsigned char PSetData[1] = {0};
	unsigned char PRefData[1024] = {0};
	triggertime = m_triggertime;
	if(triggertime)
	{
		TempStr = "触发时间不能为空或者0!";
		TempStrEnglish = "Trigger time doesn't null or zero!";
	}
	else
	{
		PSetData[0] = (unsigned char)(triggertime & 0xFF);
		if(Text == "设置" || Text == "Set")
		{
			if(0x00 == Parameter_SetReader(CS, PAddr, PLen, PSetData, ReaderAddr))
			{
				TempStr = "设置触发时间成功!";
				TempStrEnglish = "Trigger time set success!";
			}
			else
			{
				TempStr = "设置触发时间失败!";
				TempStrEnglish = "Trigger time set fail!";
			}
		}
		else if(Text == "查询" || Text == "Query")
		{
			if(0x00 == Parameter_GetReader(CS, PAddr, PLen, PRefData, ReaderAddr))
			{
				triggertime = (int)PRefData[0];
				m_triggertime = triggertime;
				TempStr = "查询触发时间成功!";
				TempStrEnglish = "Trigger time query success!";
			}
			else
			{
				TempStr = "查询触发时间失败!";
				TempStrEnglish = "Trigger time query fail!";
			}
		}
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	UpdateData(false);
	return 0;
}

/********************************设置韦根口类型***************************************/
void CSystemConfig::WeigenStyle(int ReaderNum, CString Text)
{
	UpdateData(true);
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	unsigned char PAddr = 0x00;
	int PLen = 1;
	unsigned char PSetData[1] = {0};
	unsigned char PRefData[1024] = {0};
	int Weigen = 0;
	if(Text == "设置" || Text == "Set")
	{
		Weigen = m_wstyle;
		PSetData[0] = (unsigned char)(Weigen & 0xFF);
		PAddr = 0x98;
		if(0x00 == Parameter_SetReader(CS, PAddr, PLen, PSetData, ReaderAddr))
		{
			TempStr = "设置韦根类型成功!";
			TempStrEnglish = "Weigen style set success!";
		}
		else
		{
			TempStr = "设置韦根类型失败!";
			TempStrEnglish = "Weigen style set fail!";
		}
	}
	else if(Text == "查询" || Text == "Query")
	{
		PAddr = 0x98;
		if(0x00 == Parameter_GetReader(CS, PAddr, PLen, PRefData, ReaderAddr))
		{
			Weigen = (int)PRefData[0];
			m_wstyle = Weigen;
			TempStr = "查询韦根类型成功!";
			TempStrEnglish = "Weigen style query success!";
		}
		else
		{
			TempStr = "查询韦根类型失败!";
			TempStrEnglish = "Weigen style query fail!";
		}
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	UpdateData(false);
}

/********************************设置继电器时间***************************************/
void CSystemConfig::RelayDelayTime(int ReaderNum, CString Text)
{
	UpdateData(true);
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	unsigned char PAddr = 0x00;
	int PLen = 1;
	unsigned char PSetData[1] = {0};
	unsigned char PRefData[1024] = {0};
	int Relay = 0;
	if(Text == "设置" || Text == "Set")
	{
		Relay = m_delaytime;
		if(!Relay)
		{
			TempStr = "继电器保持时间不能为空或者0!";
			TempStrEnglish = "Relay delaytime doesn't null or zero!";
		}
		else
		{
			PSetData[0] = (unsigned char)(Relay & 0xFF);
			PAddr = 0x99;
			if(0x00 == Parameter_SetReader(CS, PAddr, PLen, PSetData, ReaderAddr))
			{
				TempStr = "设置继电器保持时间成功!";
				TempStrEnglish = "Relay delaytime set success!";
			}
			else
			{
				TempStr = "设置继电器保持时间失败!";
				TempStrEnglish = "Relay delaytime set fail!";
			}
		}
	}
	else if(Text == "查询" || Text == "Query")
	{
		PAddr = 0x99;
		if(0x00 == Parameter_GetReader(CS, PAddr, PLen, PRefData, ReaderAddr))
		{
			Relay = (int)PRefData[0];
			m_delaytime = Relay;
			TempStr = "查询继电器保持时间成功!";
			TempStrEnglish = "Relay delaytime query success!";
		}
		else
		{
			TempStr = "查询继电器保持时间成功!";
			TempStrEnglish = "Relay delaytime query success!";
		}
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
	UpdateData(false);
}

/*******************************工具函数***************************************/ //Tool function
//将IP地址型字符串转换为十六进制BYTE //IP address type charcter string change to HEX byte
void CSystemConfig::DecimalstrToByte(unsigned char Buf[], CString Str)
{
	int len=strlen(Str);
	int sum=0;
	int j = 0;
	int flag = 0;
	int Num = 0;
	for(int i=0;i<len;i++)
	{
		if(Str[i] == '.')
		{
			sum = (int)(sum / pow((double)10,(3 - Num)));
			Buf[j] = (unsigned char)((sum) & 0x00FF);
			j++;
			sum = 0;
			flag = 0;
			i++;
			Num = 0;
		}
		switch(Str[i])
		{
		case '0':
			sum+=(int)(0*pow((double)10,2-flag));
			Num ++;
			break;
		case '1':
			sum+=(int)(1*pow((double)10,2-flag));
			Num ++;
			break;
		case '2':
			sum+=(int)(2*pow((double)10,2-flag));
			Num ++;
			break;
		case '3':
			sum+=(int)(3*pow((double)10,2-flag));
			Num ++;
			break;
		case '4':
			sum+=(int)(4*pow((double)10,2-flag));
			Num ++;
			break;
		case '5':
			sum+=(int)(5*pow((double)10,2-flag));
			Num ++;
			break;
		case '6':
			sum+=(int)(6*pow((double)10,2-flag));
			Num ++;
			break;
		case '7':
			sum+=(int)(7*pow((double)10,2-flag));
			Num ++;
			break;
		case '8':
			sum+=(int)(8*pow((double)10,2-flag));
			Num ++;
			break;
		case '9':
			sum += (int)(9*pow((double)10,2-flag));
			Num ++;
			break;
		}
		flag ++;
	}
	sum = (int)(sum / pow((double)10,(3 - Num)));
	Buf[j] = (unsigned char)((sum) & 0x00FF);
}

//将16进制的BYTE转换为十进制的字符串//HEX byte change to decimal character string
CString IntToInt_Str(int value)
{
	CString str="";
	str.Format("%d",value);
	return str;
}
//将十六进制BYTE转换为IP地址型字符串//HEX byte change to IP address type character string
void CSystemConfig::ByteToDecimalstr(CString &ToStr, unsigned char Buf[])
{	
	for(int i = 0; i < 4; i++)
	{
		ToStr = ToStr + IntToInt_Str((int)Buf[i]);
		if(4 != i)
			ToStr = ToStr + ".";
	}
}

void CSystemConfig::InterfaceRadioCheck()
{
	if(1 == ((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->GetCheck())
	{
		((CButton *)GetDlgItem(IDC_WEIGENSTYLE_COMBO))->ShowWindow(SW_SHOW);
		((CButton *)GetDlgItem(IDC_STYLE_STATIC))->ShowWindow(SW_SHOW);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_WEIGENSTYLE_COMBO))->ShowWindow(SW_HIDE);
		((CButton *)GetDlgItem(IDC_STYLE_STATIC))->ShowWindow(SW_HIDE);
	}
	if(1 == ((CButton *)GetDlgItem(IDC_RELAY_CHECK))->GetCheck())
	{
		((CButton *)GetDlgItem(IDC_DELAYTIME_EDIT))->ShowWindow(SW_SHOW);
		((CButton *)GetDlgItem(IDC_DELAYTIME_STATIC))->ShowWindow(SW_SHOW);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_DELAYTIME_EDIT))->ShowWindow(SW_HIDE);
		((CButton *)GetDlgItem(IDC_DELAYTIME_STATIC))->ShowWindow(SW_HIDE);
	}
}

void CSystemConfig::WorkModelRadioCheck()
{
	if(1 == ((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->GetCheck())
	{
		((CButton *)GetDlgItem(IDC_TRIGGERTIME_EDIT))->ShowWindow(SW_SHOW);
		((CButton *)GetDlgItem(IDC_TRIGGERTIME_STATIC))->ShowWindow(SW_SHOW);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_TRIGGERTIME_EDIT))->ShowWindow(SW_HIDE);
		((CButton *)GetDlgItem(IDC_TRIGGERTIME_STATIC))->ShowWindow(SW_HIDE);
	}
	UpdateData(true);
}

void CSystemConfig::LanguageChinese()
{
	((CButton *)GetDlgItem(IDC_SETANTENNA_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_GETANTENNA_BUTTON))->SetWindowText("查询");
	((CButton *)GetDlgItem(IDC_SETRFPOWER_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_GETRFPOWER_BUTTON))->SetWindowText("查询");
	((CButton *)GetDlgItem(IDC_SETINTERNET_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_GETINTERNET_BUTTON))->SetWindowText("查询");
	((CButton *)GetDlgItem(IDC_SETFREQUENCY_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_GETFREQUENCY_BUTTON))->SetWindowText("查询");
	((CButton *)GetDlgItem(IDC_OUTPORT_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_GETOUTPORT_BUTTON))->SetWindowText("查询");
	((CButton *)GetDlgItem(IDC_SETSFTM_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_GETSFTM_BUTTON))->SetWindowText("查询");

	((CButton *)GetDlgItem(IDC_SETINTRFACE_BUTTON))->SetWindowText("设置");
	((CButton *)GetDlgItem(IDC_QUERYINTERFACE_BUTTON))->SetWindowText("查询");
	((CButton *)GetDlgItem(IDC_BUTTON_CERTIFICATION))->SetWindowText("标签认证");
	((CButton *)GetDlgItem(IDC_RESET_BUTTON))->SetWindowText("重启读写器");

	((CButton *)GetDlgItem(IDC_INTERNET_STATIC))->SetWindowText("网络配置");
	((CButton *)GetDlgItem(IDC_PORT_STATIC))->SetWindowText("端口:");
	((CButton *)GetDlgItem(IDC_GATWAY_STATIC))->SetWindowText("网关:");
	((CButton *)GetDlgItem(IDC_MASK_STATIC))->SetWindowText("掩码:");

	((CButton *)GetDlgItem(IDC_RATEFREQ_STATIC))->SetWindowText("频率-频域");
	((CButton *)GetDlgItem(IDC_CHINA_RADIO))->SetWindowText("中国");
	((CButton *)GetDlgItem(IDC_NORTHAMERICA_RADIO))->SetWindowText("北美");
	((CButton *)GetDlgItem(IDC_EUROPE_RADIO))->SetWindowText("欧洲");
	((CButton *)GetDlgItem(IDC_OTHERS_RADIO))->SetWindowText("其它");
	((CButton *)GetDlgItem(IDC_RELAY_RADIO))->SetWindowText("继电器");

	((CButton *)GetDlgItem(IDC_OUTPUT_STATIC))->SetWindowText("输出电平");
	((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetWindowText("低电平");
	((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetWindowText("高电平");

	((CButton *)GetDlgItem(IDC_MODEL_STATIC))->SetWindowText("策略");
	((CButton *)GetDlgItem(IDC_NOWMODEL_STATIC))->SetWindowText("当前策略");
	((CButton *)GetDlgItem(IDC_LITERTAG_RADIO))->SetWindowText("单卡快读");
	((CButton *)GetDlgItem(IDC_MORETAG_RADIO))->SetWindowText("多卡模式");

	((CButton *)GetDlgItem(IDC_MODELINTERFACE_STATIC))->SetWindowText("模式-接口");
	((CButton *)GetDlgItem(IDC_CMD_RADIO))->SetWindowText("命令模式");
	((CButton *)GetDlgItem(IDC_ANIMATION_RADIO))->SetWindowText("自动模式");
	((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->SetWindowText("触发模式");

	((CButton *)GetDlgItem(IDC_RS485_CHECK))->SetWindowText("RS485");
	((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->SetWindowText("韦根");
	((CButton *)GetDlgItem(IDC_RS232_CHECK))->SetWindowText("RS232");
	((CButton *)GetDlgItem(IDC_IP_CHECK))->SetWindowText("网口");
	((CButton *)GetDlgItem(IDC_RELAY_CHECK))->SetWindowText("继电器");
	((CButton *)GetDlgItem(IDC_STYLE_STATIC))->SetWindowText("类型");
}

void CSystemConfig::LanguageEnglish()
{
	((CButton *)GetDlgItem(IDC_SETANTENNA_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_GETANTENNA_BUTTON))->SetWindowText("Query");
	((CButton *)GetDlgItem(IDC_SETRFPOWER_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_GETRFPOWER_BUTTON))->SetWindowText("Query");
	((CButton *)GetDlgItem(IDC_SETINTERNET_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_GETINTERNET_BUTTON))->SetWindowText("Query");
	((CButton *)GetDlgItem(IDC_SETFREQUENCY_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_GETFREQUENCY_BUTTON))->SetWindowText("Query");
	((CButton *)GetDlgItem(IDC_OUTPORT_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_GETOUTPORT_BUTTON))->SetWindowText("Query");
	((CButton *)GetDlgItem(IDC_SETSFTM_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_GETSFTM_BUTTON))->SetWindowText("Query");

	((CButton *)GetDlgItem(IDC_SETINTRFACE_BUTTON))->SetWindowText("Set");
	((CButton *)GetDlgItem(IDC_QUERYINTERFACE_BUTTON))->SetWindowText("Query");
	((CButton *)GetDlgItem(IDC_BUTTON_CERTIFICATION))->SetWindowText("Certification");
	((CButton *)GetDlgItem(IDC_RESET_BUTTON))->SetWindowText("ReStart");

	((CButton *)GetDlgItem(IDC_INTERNET_STATIC))->SetWindowText("IPConfig");
	((CButton *)GetDlgItem(IDC_PORT_STATIC))->SetWindowText("Port:");
	((CButton *)GetDlgItem(IDC_GATWAY_STATIC))->SetWindowText("GW:");
	((CButton *)GetDlgItem(IDC_MASK_STATIC))->SetWindowText("MASK:");

	((CButton *)GetDlgItem(IDC_RATEFREQ_STATIC))->SetWindowText("Rate-Frequency");
	((CButton *)GetDlgItem(IDC_CHINA_RADIO))->SetWindowText("China");
	((CButton *)GetDlgItem(IDC_NORTHAMERICA_RADIO))->SetWindowText("Northamerica");
	((CButton *)GetDlgItem(IDC_EUROPE_RADIO))->SetWindowText("Europe");
	((CButton *)GetDlgItem(IDC_OTHERS_RADIO))->SetWindowText("Others");
	((CButton *)GetDlgItem(IDC_RELAY_RADIO))->SetWindowText("Relay");

	((CButton *)GetDlgItem(IDC_OUTPUT_STATIC))->SetWindowText("OputLevel");
	((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetWindowText("LowLever");
	((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetWindowText("HigLever");

	((CButton *)GetDlgItem(IDC_MODEL_STATIC))->SetWindowText("Model");
	((CButton *)GetDlgItem(IDC_NOWMODEL_STATIC))->SetWindowText("NowModel");
	((CButton *)GetDlgItem(IDC_LITERTAG_RADIO))->SetWindowText("SingleFast");
	((CButton *)GetDlgItem(IDC_MORETAG_RADIO))->SetWindowText("MoreTagModel");

	((CButton *)GetDlgItem(IDC_MODELINTERFACE_STATIC))->SetWindowText("Model-Interface");
	((CButton *)GetDlgItem(IDC_CMD_RADIO))->SetWindowText("Command");
	((CButton *)GetDlgItem(IDC_ANIMATION_RADIO))->SetWindowText("Timing");
	((CButton *)GetDlgItem(IDC_TRIGGER_RADIO))->SetWindowText("Trigger");

	((CButton *)GetDlgItem(IDC_RS485_CHECK))->SetWindowText("RS485");
	((CButton *)GetDlgItem(IDC_WEIGEN_CHECK))->SetWindowText("Weigen");
	((CButton *)GetDlgItem(IDC_RS232_CHECK))->SetWindowText("RS232");
	((CButton *)GetDlgItem(IDC_IP_CHECK))->SetWindowText("IP");
	((CButton *)GetDlgItem(IDC_RELAY_CHECK))->SetWindowText("Relay");
	((CButton *)GetDlgItem(IDC_STYLE_STATIC))->SetWindowText("Type");
}

void CSystemConfig::CheckRelay()
{
	if(1 == ((CButton *)GetDlgItem(IDC_RELAY_RADIO))->GetCheck())
	{
		if(0 == Language)
		{
			((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetWindowText("关");
			((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetWindowText("开");
		}
		else
		{
			((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetWindowText("Close");
			((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetWindowText("Open");
		}
	}
	else
	{
		if(0 == Language)
		{
			((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetWindowText("低电平");
			((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetWindowText("高电平");
		}
		else
		{
			((CButton *)GetDlgItem(IDC_LOWLEVE_RADIO))->SetWindowText("LowLever");
			((CButton *)GetDlgItem(IDC_HIGHLEVE_RADIO))->SetWindowText("HigLever");
		}
	}
}
