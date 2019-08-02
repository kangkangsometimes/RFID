// CertificationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "uhfreader.h"
#include "CertificationDlg.h"
#include "UHFReaderDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCertificationDlg dialog
extern hComSocket CS;
extern int Language;
CCertificationDlg::CCertificationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCertificationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCertificationDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCertificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCertificationDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCertificationDlg, CDialog)
	//{{AFX_MSG_MAP(CCertificationDlg)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_MANAGER, OnButtonManager)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCertificationDlg message handlers

BOOL CCertificationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton *)GetDlgItem(IDC_STATIC_LOGIN))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_EDIT_PW))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_STATIC_SIX))->ShowWindow(false);

	((CButton *)GetDlgItem(IDC_STATIC_CERTIFICATION))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_EDIT_CTF))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_STATIC_TBYTE))->ShowWindow(false);

	((CButton *)GetDlgItem(IDC_BUTTON_SET))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_BUTTON_QUERY))->ShowWindow(false);

	((CButton *)GetDlgItem(IDC_STATIC_MTITLE))->ShowWindow(true);
	((CButton *)GetDlgItem(IDC_EDIT_MPW))->ShowWindow(true);
	((CButton *)GetDlgItem(IDC_BUTTON_MANAGER))->ShowWindow(true);
	
	if(0 == Language)
	{
		((CButton *)GetDlgItem(IDC_STATIC_MTITLE))->SetWindowText("请输入(6位)标签认证管理密码");
		((CButton *)GetDlgItem(IDC_BUTTON_MANAGER))->SetWindowText("开始管理");
		((CButton *)GetDlgItem(IDC_STATIC_LOGIN))->SetWindowText("管理密码:");
		((CButton *)GetDlgItem(IDC_STATIC_CERTIFICATION))->SetWindowText("标签验证码:");
		((CButton *)GetDlgItem(IDC_BUTTON_SET))->SetWindowText("设置");
		((CButton *)GetDlgItem(IDC_BUTTON_QUERY))->SetWindowText("查询");
	}
	else
	{
		((CButton *)GetDlgItem(IDC_STATIC_MTITLE))->SetWindowText("Please input six numbers with certification");
		((CButton *)GetDlgItem(IDC_BUTTON_MANAGER))->SetWindowText("Manager");
		((CButton *)GetDlgItem(IDC_STATIC_LOGIN))->SetWindowText("Access PW:");
		((CButton *)GetDlgItem(IDC_STATIC_CERTIFICATION))->SetWindowText("Certification:");
		((CButton *)GetDlgItem(IDC_BUTTON_SET))->SetWindowText("Set");
		((CButton *)GetDlgItem(IDC_BUTTON_QUERY))->SetWindowText("Query");
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCertificationDlg::OnButtonSet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	unsigned char PAddrCTF = 0xD0;
	unsigned char PAddrMPW = 0xD2;
	unsigned char PLenCTF = 2;
	unsigned char PLenMPW = 6;
	unsigned char PSDataCTF[2] = {0};
	unsigned char *PSDataMPW = NULL;
	unsigned char ReaderAddr = 0xFF;
	CString CTF = "";
	CString MPW = "";
	
	((CButton *)GetDlgItem(IDC_EDIT_CTF))->GetWindowText(CTF);
	((CButton *)GetDlgItem(IDC_EDIT_PW))->GetWindowText(MPW);
	if(CTF.GetLength() == 4)
	{
		CUHFReaderDlg::HexStrToByte(PSDataCTF, CTF);
		if(0 == Parameter_SetReader(CS, PAddrCTF, PLenCTF, PSDataCTF, ReaderAddr))
		{
			if(MPW.GetLength() == 6)
			{
				PSDataMPW = (unsigned char *)MPW.GetBuffer(MPW.GetLength());
				if(0 == Parameter_SetReader(CS, PAddrMPW, PLenMPW, PSDataMPW, ReaderAddr))
				{
					if(0 == Language)
						((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("设置成功!");
					else
						((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("set success!");
				}
				else
				{
					if(0 == Language)
						((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("管理密码设置失败!");
					else
						((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("access password set failed!");
					
				}
			}
			else
			{
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("管理密码不能为空长度不符合!");
				if(0 == Language)
					((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("管理密码不能为空长度不符合!");
				else
					((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("access password can not be null or meet the length!");
			}
		}
		else
		{
			if(0 == Language)
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("标签校验码设置失败!");
			else
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("tag check code set failed!");
		}
	}
	else
	{
		if(0 == Language)
			((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("标签校验码不能为空或长度不符合!");
		else
			((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("check code can not be null or does not meet the length!");
	}
}

void CCertificationDlg::OnButtonQuery() 
{
	// TODO: Add your control notification handler code here
	unsigned char PAddrCTF = 0xD0;
	unsigned char PAddrMPW = 0xD2;
	unsigned char PLenCTF = 2;
	unsigned char PLenMPW = 6;
	unsigned char PSDataCTF[2] = {0};
	unsigned char PSDataMPW[6] = {0};
	unsigned char ReaderAddr = 0xFF;
	CString CTF = "";
	CString MPW = "";
	CString TempStr= "";
	if(0 == Parameter_GetReader(CS, PAddrCTF, PLenCTF, PSDataCTF, ReaderAddr))
	{
		CTF = CUHFReaderDlg::ByteToHexStr(PSDataCTF, 2);
		((CButton *)GetDlgItem(IDC_EDIT_CTF))->SetWindowText(CTF);
		if(0 == Parameter_GetReader(CS, PAddrMPW, PLenMPW, PSDataMPW, ReaderAddr))
		{
			for(int index = 0; index < 6; index ++)
			{
				TempStr = "";
				TempStr.Format("%c", PSDataMPW[index]);
				MPW = MPW + TempStr;
			}

			((CButton *)GetDlgItem(IDC_EDIT_PW))->SetWindowText(MPW);
			if(0 == Language)
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("查询成功!");
			else
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("query success!");
		}
		else
		{
			if(0 == Language)
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("管理密码查询失败!");
			else
				((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("access password query failed!");
		}
	}
	else
	{
		if(0 == Language)
			((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("标签校验码设置查询失败!");
		else
			((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("tag check code set query failed!");
	}
	UpdateData(false);
}

void CCertificationDlg::OnButtonManager() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString mPW = "";
	char *MPW = NULL;

	((CButton *)GetDlgItem(IDC_EDIT_MPW))->GetWindowText(mPW);
	MPW = mPW.GetBuffer(mPW.GetLength());

	if(0 == CheckManagePW(CS, MPW, 0xFF))
	{
		((CButton *)GetDlgItem(IDC_STATIC_LOGIN))->ShowWindow(true);
		((CButton *)GetDlgItem(IDC_EDIT_PW))->ShowWindow(true);
		((CButton *)GetDlgItem(IDC_STATIC_SIX))->ShowWindow(true);

		((CButton *)GetDlgItem(IDC_STATIC_CERTIFICATION))->ShowWindow(true);
		((CButton *)GetDlgItem(IDC_EDIT_CTF))->ShowWindow(true);
		((CButton *)GetDlgItem(IDC_STATIC_TBYTE))->ShowWindow(true);

		((CButton *)GetDlgItem(IDC_BUTTON_SET))->ShowWindow(true);
		((CButton *)GetDlgItem(IDC_BUTTON_QUERY))->ShowWindow(true);

		((CButton *)GetDlgItem(IDC_STATIC_MTITLE))->ShowWindow(false);
		((CButton *)GetDlgItem(IDC_EDIT_MPW))->ShowWindow(false);
		((CButton *)GetDlgItem(IDC_BUTTON_MANAGER))->ShowWindow(false);
	}
	else
	{
		if(0 == Language)
			((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("管理密码校验错误!请重新输入……");
		else
			((CButton *)GetDlgItem(IDC_STATIC_INFO))->SetWindowText("access password check error,please input again");
	}
}