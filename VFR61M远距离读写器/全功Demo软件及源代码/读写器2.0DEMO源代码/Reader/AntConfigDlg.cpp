// AntConfigDlg.cpp : implementation file
//

#include "stdafx.h"
#include "uhfreader.h"
#include "AntConfigDlg.h"
#include "UHFReaderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern hComSocket CS;
extern int Language;
extern int ConnectFlag;
extern int ResetFlag;
/////////////////////////////////////////////////////////////////////////////
// CAntConfigDlg dialog


CAntConfigDlg::CAntConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAntConfigDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAntConfigDlg)
	m_Ant = -1;
	//}}AFX_DATA_INIT
}


void CAntConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAntConfigDlg)
	DDX_Control(pDX, IDC_ANT4_BITMAP, m_ant4_bitmap);
	DDX_Control(pDX, IDC_ANT9_BITMAP, m_ant9_bitmap);
	DDX_Control(pDX, IDC_ANT8_BITMAP, m_ant8_bitmap);
	DDX_Control(pDX, IDC_ANT7_BITMAP, m_ant7_bitmap);
	DDX_Control(pDX, IDC_ANT6_BITMAP, m_ant6_bitmap);
	DDX_Control(pDX, IDC_ANT5_BITMAP, m_ant5_bitmap);
	DDX_Control(pDX, IDC_ANT3_BITMAP, m_ant3_bitmap);
	DDX_Control(pDX, IDC_ANT2_BITMAP, m_ant2_bitmap);
	DDX_Control(pDX, IDC_ANT16_BITMAP, m_ant16_bitmap);
	DDX_Control(pDX, IDC_ANT15_BITMAP, m_ant15_bitmap);
	DDX_Control(pDX, IDC_ANT14_BITMAP, m_ant14_bitmap);
	DDX_Control(pDX, IDC_ANT13_BITMAP, m_ant13_bitmap);
	DDX_Control(pDX, IDC_ANT12_BITMAP, m_ant12_bitmap);
	DDX_Control(pDX, IDC_ANT11_BITMAP, m_ant11_bitmap);
	DDX_Control(pDX, IDC_ANT10_BITMAP, m_ant10_bitmap);
	DDX_Control(pDX, IDC_ANT1_BITMAP, m_ant1_bitmap);
	DDX_CBIndex(pDX, IDC_POWER_COMBO, m_Ant);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAntConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CAntConfigDlg)
	ON_BN_CLICKED(IDC_SETANT_BUTTON, OnSetAntButton)
	ON_BN_CLICKED(IDC_GETANT_BUTTON, OnGetAntButton)
	ON_BN_CLICKED(IDC_RESTART_BUTTON, OnRestartButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAntConfigDlg message handlers

void CAntConfigDlg::OnSetAntButton() 
{
	// TODO: Add your control notification handler code here
	SetAntenna();
	Set_RfPower();
}

void CAntConfigDlg::OnGetAntButton() 
{
	// TODO: Add your control notification handler code here
	GetAntenna();
	Get_RfPower();
}

void CAntConfigDlg::OnRestartButton() 
{
	// TODO: Add your control notification handler code here
	ResetReader();
	ResetFlag = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////
/********************************复位读写器***************************************/
void CAntConfigDlg::ResetReader()//rest reader
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

/********************************设置读写器天线状态***************************************/
void CAntConfigDlg::SetAntenna()
{
#ifdef _ANT_16_
	CString TempStr = "";
	CString TempStrEnglish = "";
	int ant[16] = {0};
	unsigned char Workant[2] = {0};
	if(((CButton *)GetDlgItem(IDC_ANT1_CHECK))->GetCheck()==1)
		ant[0] = 1;
	if(((CButton *)GetDlgItem(IDC_ANT2_CHECK))->GetCheck()==1)
		ant[1] = 2;
	if(((CButton *)GetDlgItem(IDC_ANT3_CHECK))->GetCheck()==1)
		ant[2] = 4;
	if(((CButton *)GetDlgItem(IDC_ANT4_CHECK))->GetCheck()==1)
		ant[3] = 8;
	if(((CButton *)GetDlgItem(IDC_ANT5_CHECK))->GetCheck()==1)
		ant[4] = 16;
	if(((CButton *)GetDlgItem(IDC_ANT6_CHECK))->GetCheck()==1)
		ant[5] = 32;
	if(((CButton *)GetDlgItem(IDC_ANT7_CHECK))->GetCheck()==1)
		ant[6] = 64;
	if(((CButton *)GetDlgItem(IDC_ANT8_CHECK))->GetCheck()==1)
		ant[7] = 128;
	if(((CButton *)GetDlgItem(IDC_ANT9_CHECK))->GetCheck()==1)
		ant[8] = 256;
	if(((CButton *)GetDlgItem(IDC_ANT10_CHECK))->GetCheck()==1)
		ant[9] = 512;
	if(((CButton *)GetDlgItem(IDC_ANT11_CHECK))->GetCheck()==1)
		ant[10] = 1024;
	if(((CButton *)GetDlgItem(IDC_ANT12_CHECK))->GetCheck()==1)
		ant[11] = 2048;
	if(((CButton *)GetDlgItem(IDC_ANT13_CHECK))->GetCheck()==1)
		ant[12] = 4096;
	if(((CButton *)GetDlgItem(IDC_ANT14_CHECK))->GetCheck()==1)
		ant[13] = 8192;
	if(((CButton *)GetDlgItem(IDC_ANT15_CHECK))->GetCheck()==1)
		ant[14] = 16384;
	if(((CButton *)GetDlgItem(IDC_ANT16_CHECK))->GetCheck()==1)
		ant[15] = 32768;
	int wkTemp = (ant[0] + ant[1] + ant[2] + ant[3] + ant[4] + ant[5] + ant[6] + ant[7]) + (ant[8] + ant[9] + ant[10] + ant[11] + ant[12] + ant[13] + ant[14] + ant[15]);
	Workant[0] = (unsigned char)(wkTemp >> 8);
	Workant[1] = (unsigned char)(wkTemp & 0xFF);
	if(0x00 == Config_SetAntenna16(CS, Workant, 0xFF))
	{
		TempStr = "16天线工作状态设置成功!";
		TempStrEnglish = "16 antenna work state set success";
	}
	else
	{
		TempStr = "16天线工作状态设置失败!";
		TempStrEnglish = "16 antenna work state set failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);

#endif
}

/********************************查询读写器天线状态***************************************/
void CAntConfigDlg::GetAntenna()
{
#ifdef _ANT_16_

	CString TempStr = "";
	CString TempStrEnglish = "";
	int Workant[2] = {0};
	int Ant = 0;
	if(0x00 == Config_GetAntenna16(CS, Workant, 0xFF))
	{
		TempStr = "16 天线工作状态查询成功!";
		TempStrEnglish = "16 antenna work state query success";

		Ant = ((int)(Workant[0] << 8)) + ((int)Workant[1]);
		
		ShowAnt(Ant);
	}
	else
	{
		TempStr = "16 天线工作状态查询失败!";
		TempStrEnglish = "16 antenna work state query failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);

#endif
}

///////////////////////////////////////////////////////////////////////////////////
void CAntConfigDlg::ShowAnt(int Ant)
{
	CBitmap   bmp;
	//天线1
	if(Ant & (1 << 0))
	{
		((CButton *)GetDlgItem(IDC_ANT1_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant1_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT1_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant1_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线2
	if(Ant & (1 << 1))
	{
		((CButton *)GetDlgItem(IDC_ANT2_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant2_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT2_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant2_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线3
	if(Ant & (1 << 2))
	{
		((CButton *)GetDlgItem(IDC_ANT3_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant3_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT3_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant3_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线4
	if(Ant & (1 << 3))
	{
		((CButton *)GetDlgItem(IDC_ANT4_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant4_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT4_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant4_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线5
	if(Ant & (1 << 4))
	{
		((CButton *)GetDlgItem(IDC_ANT5_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant5_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT5_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant5_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线6
	if(Ant & (1 << 5))
	{
		((CButton *)GetDlgItem(IDC_ANT6_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant6_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT6_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant6_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线7
	if(Ant & (1 << 6))
	{
		((CButton *)GetDlgItem(IDC_ANT7_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant7_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT7_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant7_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线8
	if(Ant & (1 << 7))
	{
		((CButton *)GetDlgItem(IDC_ANT8_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant8_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT8_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant8_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线9
	if(Ant & (1 << 8))
	{
		((CButton *)GetDlgItem(IDC_ANT9_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant9_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT9_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant9_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线10
	if(Ant & (1 << 9))
	{
		((CButton *)GetDlgItem(IDC_ANT10_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant10_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT10_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant10_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线11
	if(Ant & (1 << 10))
	{
		((CButton *)GetDlgItem(IDC_ANT11_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant11_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT11_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant11_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线12
	if(Ant & (1 << 11))
	{
		((CButton *)GetDlgItem(IDC_ANT12_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant12_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT12_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant12_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线13
	if(Ant & (1 << 12))
	{
		((CButton *)GetDlgItem(IDC_ANT13_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant13_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT13_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant13_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线14
	if(Ant & (1 << 13))
	{
		((CButton *)GetDlgItem(IDC_ANT14_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant14_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT14_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant14_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线15
	if(Ant & (1 << 14))
	{
		((CButton *)GetDlgItem(IDC_ANT15_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant15_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT15_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant15_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	//天线16
	if(Ant & (1 << 15))
	{
		((CButton *)GetDlgItem(IDC_ANT16_CHECK))->SetCheck(1);
		bmp.LoadBitmap(IDB_SINGLE_BITMAP);
		m_ant16_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
	else
	{
		((CButton *)GetDlgItem(IDC_ANT16_CHECK))->SetCheck(0);
		bmp.LoadBitmap(IDB_NOSINGEL_BITMAP);
		m_ant16_bitmap.SetBitmap((HBITMAP)bmp);
		bmp.Detach();
	}
}

/********************************设置读写器天线功率***************************************/
void CAntConfigDlg::Set_RfPower()//set reader antenna power 
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	int m_anten_dbm = 0;
	UpdateData(true);
	unsigned char aPwr[4] = {0x00, 0x00, 0x00, 0x00};
	m_anten_dbm = m_Ant;
	aPwr[0] = (unsigned char)((m_anten_dbm) & 0xFF);
	if(0x00 == Config_SetRfPower(CS, aPwr, 0xFF))
	{
		TempStr = "天线功率设置成功!";
		TempStrEnglish = "Antenna power set success";
	}
	else
	{
		TempStr = "天线功率设置失败!";
		TempStrEnglish = "Antenna power set failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}

/********************************查询读写器天线功率***************************************/
void CAntConfigDlg::Get_RfPower()//query reader antenna power
{
	CString TempStr = "";
	CString TempStrEnglish = "";
	unsigned char aPwr[4] = {0x00, 0x00, 0x00, 0x00};
	int m_anten_dbm = 0;
	if(0x00 == Config_GetRfPower(CS, aPwr, 0xFF))
	{
		TempStr = "天线功率查询成功!";
		TempStrEnglish = "Antenna power query failed";
		CString Port = "";
		m_anten_dbm = (int)aPwr[0];
		m_Ant = m_anten_dbm;
		UpdateData(false);
	}
	else
	{
		TempStr = "天线功率查询失败!";
		TempStrEnglish = "Antenna power query failed";
	}
	if(0 == Language)
		CUHFReaderDlg::ListBoxAdd(TempStr);
	else
		CUHFReaderDlg::ListBoxAdd(TempStrEnglish);
}
