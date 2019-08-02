// UHFReaderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UHFReader.h"
#include "UHFReaderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int Language = 0;
int UpdateDataFlag = 0;

//全局变量(global variable)
hComSocket CS;				//通信句柄结构体(connect handle struct)

HANDLE hCom = NULL;			//串口句柄(comm handle)
                                        
SOCKET sockClient = 0;		//网口句柄(TCP/IP handle)
                                 //
int ConnectFlag = 0;		//连接标志位(connect falg)
int ResetFlag = 0;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUHFReaderDlg dialog

CUHFReaderDlg::CUHFReaderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUHFReaderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUHFReaderDlg)
	m_language = -1;
	m_ipPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUHFReaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUHFReaderDlg)
	DDX_Control(pDX, IDC_SP_NUM_COMBO, m_spNum);
	DDX_Control(pDX, IDC_SP_BAUD_COMBO, m_spBaud);
	DDX_Control(pDX, IDC_IP_ADDR_IPADDRESS, m_ipAddr);
	DDX_CBIndex(pDX, IDC_COMBO_LANGUAGE, m_language);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_SYSTEM_TAB, m_system_tab);
	DDX_Text(pDX, IDC_IP_PORT_EDIT, m_ipPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUHFReaderDlg, CDialog)
	//{{AFX_MSG_MAP(CUHFReaderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_SYSTEM_TAB, OnSelchangeSystemTab)
	ON_BN_CLICKED(IDC_CLEARSYSMSG_BUTTON, OnClearSysMsgButton)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_SWITCH_BUTTON, OnSwitchButton)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CONNECT_BUTTON, OnConnectButton)
	ON_BN_CLICKED(IDC_DISCONNECT_BUTTON, OnDisconnectButton)
	ON_BN_CLICKED(IDC_IP_RADIO, OnIpRadio)
	ON_BN_CLICKED(IDC_SP_RADIO, OnSpRadio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUHFReaderDlg message handlers

BOOL CUHFReaderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	ReadLanguageFile(Language);
	if(0 == Language)
	{
		m_language = 0;
		LanguageChinese();
	}
	if(1 == Language)
	{
		m_language = 1;
		LanguageEnglish();
	}
CUIntArray ports;
	ReadLanguageFile(Language);
	if(0 == Language)
	{
		m_language = 0;
		LanguageChinese();
	}
	if(1 == Language)
	{
		m_language = 1;
		LanguageEnglish();
	}
    GetLocalSerialPort(ports);
	for (int i=0; i<ports.GetSize(); i++)
	{
		CString str="";
		CString port="COM";
		str.Format("%d",ports.ElementAt(i));
		port = port+str;
		((CComboBox *)GetDlgItem(IDC_SP_NUM_COMBO))->AddString(port);
	}
	((CButton *)GetDlgItem(IDC_IP_RADIO))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_CONNECT_BUTTON))->EnableWindow(true);
	((CButton *)GetDlgItem(IDC_DISCONNECT_BUTTON))->EnableWindow(false);
	m_spBaud.SetCurSel(9);
	m_ipAddr.SetWindowText("192.168.1.200");
	m_ipPort = 100;
	OnIpRadio();
	InitTab();
	//设置默认的选项卡//Set the default TAB
	m_system_tab.SetCurSel(0); 
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUHFReaderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUHFReaderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUHFReaderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUHFReaderDlg::OnSelchangeSystemTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int CurSel; 
    CurSel=m_system_tab.GetCurSel();
    switch(CurSel) 	
	{
		
	case 0: 	
		m_system_config.ShowWindow(true); 	
		m_iso180006b.ShowWindow(false);
		m_epcgen2.ShowWindow(false);
		break; 	
	case 1: 
		m_system_config.ShowWindow(false); 	
		m_iso180006b.ShowWindow(true);
		m_epcgen2.ShowWindow(false);
		break;
	case 2: 
		m_system_config.ShowWindow(false); 	
		m_iso180006b.ShowWindow(false);
		m_epcgen2.ShowWindow(true);
		break; 		
	default: ; 	
	} 
	*pResult = 0;
}

void CUHFReaderDlg::ListBoxAdd(CString Str)
{
	 m_list.AddString(Str);
	 m_list.SetTopIndex(m_list.GetCount()-1);
}

void CUHFReaderDlg::TabEnableWindow(int flag)
{
	if(flag)
	{
		m_system_tab.EnableWindow(true);
	}
	else
	{
		m_system_tab.EnableWindow(false);
	}
}

void CUHFReaderDlg::OnClearSysMsgButton() 
{
	// TODO: Add your control notification handler code here
	m_list.ResetContent();
}

void CUHFReaderDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	int select = 0;
	if(0 == Language)
	{
		select = MessageBox("是否确定关闭应用程序?", "关闭应用程序", MB_YESNO);
	}
	else
	{
		select = MessageBox("Are you sure to close application?", "Close application", MB_YESNO);
	}
	if(IDYES == select)
	{
		CDialog::OnClose();
	}
	else
	{
		return ;
	}
}

void CUHFReaderDlg::OnSwitchButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int Languagef = 0;
	int select = 0;
	if(0 == m_language)
		Languagef = 0;
	else if(1 == m_language)
		Languagef = 1;
	WriteLanguageFile(Languagef);
	if(0 == Language)
		select = MessageBox("重新启动应用程序?", "提示", MB_YESNO);
	else
		select = MessageBox("Restart the application?", "Reminder", MB_YESNO);
	if(IDYES == select)			//关闭应用程序
	{
		this->EndDialog(0);
	}
	else
	{
		return ;
	}
}

int CUHFReaderDlg::ReadLanguageFile(int &LanguageFlag)
{
	LanguageFlag = 0;

	FILE *pfile = NULL;
	pfile = fopen("./Language.dat", "r");
	if (pfile == NULL)
	{
		pfile = fopen("./Language.dat", "w+");
		fprintf(pfile, "%d", 0);
		LanguageFlag = 0;
		
	}
	else
	{
		int iRet = fscanf(pfile, "%d", &LanguageFlag);
		if (iRet <= 0)
		{
			LanguageFlag = 0;
		}
	}
	
	
	fclose(pfile);
	return 0;
}

int CUHFReaderDlg::WriteLanguageFile(int LanguageFlag)
{
	FILE *pfile = fopen("./Language.dat", "w");
	fprintf(pfile, "%d", LanguageFlag);
	fclose(pfile);
	return 0;
}

void CUHFReaderDlg::InitTab()
{	
	//-----------------------IDC_SYSTEM_TAB->m_system_tab-------------------------------------

	if(0 == Language)
	{
		m_system_tab.InsertItem(0,"系统配置");
		m_system_tab.InsertItem(1,"ISO18000-6B");
		m_system_tab.InsertItem(2,"EPC GEN2");
	}
	else
	{
		m_system_tab.InsertItem(0,"System Configure");
		m_system_tab.InsertItem(1,"ISO18000-6B");
		m_system_tab.InsertItem(2,"EPC GEN2");
	}
	
	//关联对话框,并且将IDC_SYSTEM_TAB控件设为父窗口(association dialog and put IDC_SYSTEM_TAB ActiveX set to parent window)
	m_system_config.Create(IDD_SYSCONFIG_DIALOG,GetDlgItem(IDC_SYSTEM_TAB));
	m_iso180006b.Create(IDD_ISO180006B_DIALOG,GetDlgItem(IDC_SYSTEM_TAB));
	m_epcgen2.Create(IDD_EPCGEN2_DIALOG,GetDlgItem(IDC_SYSTEM_TAB));
	//获得IDC_SYSTEM_TAB客户区大小//obtain IDC_SYSTEM_TAB client area size
	CRect rs; 
	m_system_tab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置//adjust the child dialogs in the positions of the parent window
	rs.top+=20; 
	rs.bottom-=5; 
	rs.left+=5;
	rs.right-=5; 
	
	//设置子对话框尺寸并移动到指定位置//Settings dialog box size and move to the specified location
	m_system_config.MoveWindow(&rs);
	m_iso180006b.MoveWindow(&rs);
	m_epcgen2.MoveWindow(&rs);
	//分别设置隐藏和显示//Set to hide and display, respectively
	m_system_config.ShowWindow(true);
	m_iso180006b.ShowWindow(false);
	m_epcgen2.ShowWindow(false);
}

void CUHFReaderDlg::LanguageChinese()
{
	((CButton *)GetDlgItem(IDC_IP_RADIO))->SetWindowText("网口");
	((CButton *)GetDlgItem(IDC_SP_RADIO))->SetWindowText("串口");

	((CButton *)GetDlgItem(IDC_IP_ADDR_STATIC))->SetWindowText("IP:");
	((CButton *)GetDlgItem(IDC_IP_PORT_STATIC))->SetWindowText("端口:");
	((CButton *)GetDlgItem(IDC_SP_NUM_STATIC))->SetWindowText("串口号:");
	((CButton *)GetDlgItem(IDC_SP_BAUD_STATIC))->SetWindowText("波特率:");

	((CButton *)GetDlgItem(IDC_CONNECT_BUTTON))->SetWindowText("连接");
	((CButton *)GetDlgItem(IDC_DISCONNECT_BUTTON))->SetWindowText("断开");
	((CButton *)GetDlgItem(IDC_STATIC_CONNECTTYPE))->SetWindowText("连接方式");
	((CButton *)GetDlgItem(IDC_STATIC_SYSTEM))->SetWindowText("系统提示");
	((CButton *)GetDlgItem(IDC_CLEARSYSMSG_BUTTON))->SetWindowText("清空");
}

void CUHFReaderDlg::LanguageEnglish()
{
	((CButton *)GetDlgItem(IDC_IP_RADIO))->SetWindowText("Internet");
	((CButton *)GetDlgItem(IDC_SP_RADIO))->SetWindowText("SerialPort");

	((CButton *)GetDlgItem(IDC_IP_ADDR_STATIC))->SetWindowText("IP:");
	((CButton *)GetDlgItem(IDC_IP_PORT_STATIC))->SetWindowText("Port:");
	((CButton *)GetDlgItem(IDC_SP_NUM_STATIC))->SetWindowText("ComNo:");
	((CButton *)GetDlgItem(IDC_SP_BAUD_STATIC))->SetWindowText("Baud:");

	((CButton *)GetDlgItem(IDC_CONNECT_BUTTON))->SetWindowText("Connect");
	((CButton *)GetDlgItem(IDC_DISCONNECT_BUTTON))->SetWindowText("Disconnect");
	((CButton *)GetDlgItem(IDC_STATIC_CONNECTTYPE))->SetWindowText("Connect type");
	((CButton *)GetDlgItem(IDC_STATIC_SYSTEM))->SetWindowText("System prompt");
	((CButton *)GetDlgItem(IDC_CLEARSYSMSG_BUTTON))->SetWindowText("clear");
}

/*******************************工具函数***************************************/ //Tool function
//将unsigned char 型数组装换为字符串(type package change to character string)
CString CUHFReaderDlg::ByteToHexStr(unsigned char byte_arr[], int arr_len)
{
	CString* hexstr = new CString;  
    for(int i=0; i<arr_len; i++)  
    {  
        char hex1;  
        char hex2;  
        int value = byte_arr[i];
        int v1 = value/16;  
        int v2 = value % 16;  
        //将商转换为字母(change divide to alphabet)
        if (v1>=0 && v1<=9)  
        {  
            hex1 = (char)(48 + v1);  
        }  
        else  
        {  
            hex1 = (char)(55 + v1);  
        }  
        //将余数转成字母(change remainder to alphabet)
        if (v2>=0 && v2<=9)  
        {  
            hex2 = (char)(48 + v2);  
        }  
        else  
        {  
            hex2 = (char)(55 + v2);  
        }  
        //将字母连成一串(put alphabet as one string)
        *hexstr = *hexstr + hex1 + hex2;  
    }  
    CString str=*hexstr;
	if(NULL!=hexstr)
	{
		delete hexstr;
		hexstr=NULL;
	}	
	return str;
}

//16进制字符串转换为unsigned char(Hex character change to unsigned char)
unsigned char TConvertHexChar(unsigned char ch)
{
	unsigned char refV = 0x00;
	if( ( (char)ch >= '0' ) && ( (char)ch <= '9' ) )
	{
		
		refV = ((unsigned char)ch - 0x30);
        return refV;
	}
	else if( ( (char)ch >= 'A' ) && ( (char)ch <= 'F' ) )
	{
		refV = (unsigned char)((char)ch - 'A' + 10);
        return refV;
	}
	else if( ( (char)ch >= 'a' ) && ( (char)ch <= 'f' ) )
	{
		refV = (unsigned char)((char)ch - 'a' + 10);
        return refV;
	}
	else
        return -1;
}

void CUHFReaderDlg::HexStrToByte(unsigned char byteT[], CString str)
{
	unsigned char tmpByte = 0x00;
	int strLen = strlen(str);
	int i = 0;
	memset(byteT, '\0', sizeof(byteT));
	for (int j = 0; j < strLen; j = j+2)
	{
		tmpByte = (unsigned char)str[j];
		byteT[i] = TConvertHexChar(tmpByte)  << 4;	//左移4位(left shift 4 bit)
		tmpByte = (unsigned char)str[j+1];
		byteT[i] = byteT[i] + (TConvertHexChar(tmpByte) & 0x0F);	//取低4位然后相加(get low 4 bits then add)
		i++;
	}
}

void CUHFReaderDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		if(1 == ResetFlag)
		{
			OnDisconnectButton();
			KillTimer(1);
			ResetFlag = 0;
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CUHFReaderDlg::OnConnectButton() 
{
	// TODO: Add your control notification handler code here
	int status = 0;
	int ComFlag = 0;
	int SocketFlag = 0;
	CString Version = "";
	CString SerialNum = "";
	ComFlag = ((CButton *)GetDlgItem(IDC_SP_RADIO))->GetCheck();
	SocketFlag = ((CButton *)GetDlgItem(IDC_IP_RADIO))->GetCheck();

	status = ConnectReader();
	if(0 == status)
	{
		if(1 == ComFlag)
		{
			CS.hCom = hCom;
			CS.sockClient = 0;
		}
		if(1 == SocketFlag)
		{
			CS.hCom = NULL;
			CS.sockClient = sockClient;
		}
		((CButton *)GetDlgItem(IDC_CONNECT_BUTTON))->EnableWindow(false);
		((CButton *)GetDlgItem(IDC_DISCONNECT_BUTTON))->EnableWindow(true);

		ConnectFlag = 1;		//连接标志位(connect flag)

		GetVersion(255);
		SetTimer(1, 500, NULL);
		QuerySerialNo(255);
	}
}

void CUHFReaderDlg::OnDisconnectButton() 
{
	// TODO: Add your control notification handler code here
	int status = 0;
	status = DisConnectReader();

	if(0 == status)
	{
		((CButton *)GetDlgItem(IDC_CONNECT_BUTTON))->EnableWindow(true);
		((CButton *)GetDlgItem(IDC_DISCONNECT_BUTTON))->EnableWindow(false);
		ConnectFlag = 0;		//连接标志位(connect falg)
	}
}

void CUHFReaderDlg::OnIpRadio() 
{
	// TODO: Add your control notification handler code here
	//网口(TCP/IP)
	((CButton *)GetDlgItem(IDC_IP_ADDR_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_IP_PORT_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_IP_ADDR_IPADDRESS))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_IP_PORT_EDIT))->ShowWindow(SW_SHOW);
	//串口(Com)
	((CButton *)GetDlgItem(IDC_SP_NUM_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_SP_BAUD_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_SP_NUM_COMBO))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_SP_BAUD_COMBO))->ShowWindow(SW_HIDE);
}

void CUHFReaderDlg::OnSpRadio() 
{
	// TODO: Add your control notification handler code here
	//网口(TCP/IP)
	((CButton *)GetDlgItem(IDC_IP_ADDR_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_IP_PORT_STATIC))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_IP_ADDR_IPADDRESS))->ShowWindow(SW_HIDE);
	((CButton *)GetDlgItem(IDC_IP_PORT_EDIT))->ShowWindow(SW_HIDE);
	//串口(Com)
	((CButton *)GetDlgItem(IDC_SP_NUM_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_SP_BAUD_STATIC))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_SP_NUM_COMBO))->ShowWindow(SW_SHOW);
	((CButton *)GetDlgItem(IDC_SP_BAUD_COMBO))->ShowWindow(SW_SHOW);
}

int CUHFReaderDlg::ConnectReader()
{
	int status = 0;
	int ComFlag = 0;
	int SocketFlag = 0;
	CString TempStr = "";
	CString TempStrEnglish = "";

	ComFlag = ((CButton *)GetDlgItem(IDC_SP_RADIO))->GetCheck();
	SocketFlag = ((CButton *)GetDlgItem(IDC_IP_RADIO))->GetCheck();
	
	if(1 == ComFlag)
	{
		status = ComConnect();
	}
	if(1 == SocketFlag)
	{
		status = SocketConnect();
	}

	switch(status)
	{
	case 0:
		TempStr = "连接成功!";
        TempStrEnglish = "Connect success!";
		break;
	case -1:
		TempStr = "连接失败!";
		TempStrEnglish = "Connect fail!";
		break;
	case -2:
		TempStr = "连接参数不完整!";
		TempStrEnglish = "Connect parameter incomplete!";
		break;
	}
	if(0 == Language)
		ListBoxAdd(TempStr);
	else
		ListBoxAdd(TempStrEnglish);
	if(TempStr != "连接成功!" || TempStrEnglish != "Connect success!")
		return -1;
	return 0;
}

int CUHFReaderDlg::DisConnectReader()
{
	int status = 0;
	int ComFlag = 0;
	int SocketFlag = 0;
	CString TempStr = "";
	CString TempStrEnglish = "";

	ComFlag = ((CButton *)GetDlgItem(IDC_SP_RADIO))->GetCheck();
	SocketFlag = ((CButton *)GetDlgItem(IDC_IP_RADIO))->GetCheck();

	if(1 == ComFlag)
	{
		status = ComDisConnect();
	}
	if(1 == SocketFlag)
	{
		status = SocketDisConnect();
	}

	switch(status)
	{
	case 0:
		TempStr = "关闭成功!";
        TempStrEnglish = "Close success!";
		break;
	case -1:
		TempStr = "关闭失败!";
		TempStrEnglish = "Close fail!";
		break;
	case -2:
		TempStr = "关闭句柄无效!";
		TempStrEnglish = "Handle unavailable!";
		break;
	}
	if(0 == Language)
		ListBoxAdd(TempStr);
	else
		ListBoxAdd(TempStrEnglish);
	if(TempStr != "关闭成功!" || TempStrEnglish != "Close success!")
		return -1;
	return 0;
}


int CUHFReaderDlg::SocketConnect()
{
	CString IPAddress = "";
	int ipport = 0;
	UpdateData(true);

	m_ipAddr.GetWindowText(IPAddress);
	ipport = m_ipPort;

	if(IPAddress == "" || 0 == ipport)
	{
		return -2;			//输入信息不完整(input info incomplete)
	}
	else
	{
		char *ipaddr = (LPSTR)(LPCTSTR)IPAddress;
		if(!Socket_ConnectSocket(&sockClient, ipaddr, ipport))
			return 0;		//连接成功(connect success)
		else
			return -1;		//连接失败(connect fail)
	}
	return 0;
}

int CUHFReaderDlg::SocketDisConnect()
{
	if(sockClient != 0)
	{
		if(!Socket_CloseSocket(sockClient))
			return 0;		//关闭成功(close success)
		else
			return -1;		//关闭失败(close fail)
	}
	else
	{
		return -2;			//句柄无效(handle unavailable)
	}
	return 0;
}

int CUHFReaderDlg::ComConnect()
{
	CString strSPNum = "";
	CString strSPBaud = "";
	int SnIndex = -1;
	int BnIndex = -1;
	UpdateData(true);
	SnIndex = m_spNum.GetCurSel();
	BnIndex = m_spBaud.GetCurSel();
	
	if(SnIndex == -1 || BnIndex == -1)
	{
		return -2;		//输入信息不完整(input info incomplete)
	}
	else
	{
		m_spNum.GetLBText(SnIndex,strSPNum);
		m_spBaud.GetLBText(BnIndex, strSPBaud);
		int Baud = atoi((LPCTSTR)strSPBaud);
		char * strSPort = (LPSTR)(LPCTSTR)strSPNum;
		if(!Serial_OpenSeries(&hCom, strSPort, Baud))
			return 0;		//连接成功(connect success)
		else
			return -1;		//连接失败(connect fail)
	}
	return 0;
}

int CUHFReaderDlg::ComDisConnect()
{
	if(hCom != NULL)
	{
		if(Serial_CloseSeries(hCom))
			return 0;	//关闭成功(close success)
		else 
			return -1;	//关闭失败(close fail)
	}
	else
	{
		return -2;		//句柄无效(handle unavailable)
	}
	return 0;
}

void CUHFReaderDlg::GetVersion(int ReaderNum)
{
	unsigned char major = 0;
	unsigned char minor = 0;
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	if(0x00 == Config_GetLocatorVersion(CS, major, minor, ReaderAddr))
	{
		CString Major = "";
		CString Minor = "";
		Major.Format("%02d", (int)major);
		Minor.Format("%02d", (int)minor);
		TempStr = "V" + Major + "." + Minor;

		if(0 == Language)
			ListBoxAdd("读写器固件版本号为: " + TempStr);
		else
			ListBoxAdd("Reader firmware version: " + TempStr);
		((CButton *)GetDlgItem(IDC_VERSION_STATIC))->SetWindowText(TempStr);
	}
	else
	{
		TempStr = "获取版本号失败!";
        TempStrEnglish = "Get version fail!";
		if(0 == Language)
			ListBoxAdd(TempStr);
		else
			ListBoxAdd(TempStrEnglish);
	}
}


int CUHFReaderDlg::QuerySerialNo(int ReaderNum)
{
	UpdateData(true);
	CString TempStr = "";
	CString TempStrEnglish = "";
	CString Sno = "";
	unsigned char ReaderAddr = (unsigned char)(ReaderNum & 0xFF);
	unsigned char PAddr = 0x10;
	int PLen = 6;
	unsigned char PRefData[1024] = {0};

	if(0x00 == Parameter_GetReader(CS, PAddr, PLen, PRefData, ReaderAddr))
	{
		Sno = ByteToHexStr(PRefData, PLen);
		((CButton *)GetDlgItem(IDC_SERIALNO_STATIC))->SetWindowText(Sno);
		TempStr = "查询读写器序列号成功!";
		TempStrEnglish = "Reader serial No query success!";
	}
	else
	{
		TempStr = "查询读写器序列号失败!";
		TempStrEnglish = "Reader serial No query fail!";
	}
	if(0 == Language)
		ListBoxAdd(TempStr);
	else
		ListBoxAdd(TempStrEnglish);
	UpdateData(false);
	return 0;
}

BOOL CUHFReaderDlg::GetLocalSerialPort(CUIntArray &ports)
{
	//Make sure we clear out any elements which may already be in the array
	ports.RemoveAll();
	//Determine what OS we are running on
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	BOOL bGetVer = GetVersionEx(&osvi);
	
	//On NT use the QueryDosDevice API
	if (bGetVer && (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT))
	{
		//Use QueryDosDevice to look for all devices of the form COMx. This is a better
		//solution as it means that no ports have to be opened at all.
		TCHAR szDevices[65535];
		DWORD dwChars = QueryDosDevice(NULL, szDevices, 65535);
		if (dwChars)
		{
			int i=0;
			
			for (;;)
			{
				//Get the current device name
				TCHAR* pszCurrentDevice = &szDevices[i];
				
				//If it looks like "COMX" then
				//add it to the array which will be returned
				int nLen = _tcslen(pszCurrentDevice);
				if (nLen > 3 && _tcsnicmp(pszCurrentDevice, _T("COM"), 3) == 0)
				{
					//Work out the port number
					int nPort = _ttoi(&pszCurrentDevice[3]);
					ports.Add(nPort);
				}
				
				// Go to next NULL character
				while(szDevices[i] != _T('\0'))
					i++;
				
				// Bump pointer to the next string
				i++;
				
				// The list is double-NULL terminated, so if the character is
				// now NULL, we're at the end
				if (szDevices[i] == _T('\0'))
					break;
			}
		}
		else
			TRACE(_T("Failed in call to QueryDosDevice, GetLastError:%d\n"), GetLastError());
	}
	else
	{
		//On 95/98 open up each port to determine their existence
		
		//Up to 255 COM ports are supported so we iterate through all of them seeing
		//if we can open them or if we fail to open them, get an access denied or general error error.
		//Both of these cases indicate that there is a COM port at that number. 
		for (UINT i=1; i<256; i++)
		{
			//Form the Raw device name
			CString sPort;
			sPort.Format(_T("\\\\.\\COM%d"), i);
			
			//Try to open the port
			BOOL bSuccess = FALSE;
			HANDLE hPort = ::CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
			if (hPort == INVALID_HANDLE_VALUE)
			{
				DWORD dwError = GetLastError();
				
				//Check to see if the error was because some other app had the port open or a general failure
				if (dwError == ERROR_ACCESS_DENIED || dwError == ERROR_GEN_FAILURE)
					bSuccess = TRUE;
			}
			else
			{
				//The port was opened successfully
				bSuccess = TRUE;
				
				//Don't forget to close the port, since we are going to do nothing with it anyway
				CloseHandle(hPort);
			}
			
			//Add the port number to the array which will be returned
			if (bSuccess)
				ports.Add(i);
		}
	}
	return true;
}
