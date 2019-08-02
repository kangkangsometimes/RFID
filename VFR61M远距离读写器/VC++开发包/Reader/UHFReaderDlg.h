// UHFReaderDlg.h : header file
//

#if !defined(AFX_UHFREADERDLG_H__0D01C635_2AE2_46E9_86CC_EC0B5D8A2EFF__INCLUDED_)
#define AFX_UHFREADERDLG_H__0D01C635_2AE2_46E9_86CC_EC0B5D8A2EFF__INCLUDED_

#include "SystemConfig.h"	// Added by ClassView
#include "ISO180006B.h"	// Added by ClassView
#include "EPCGEN2.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUHFReaderDlg dialog
static CListBox	m_list;
static CTabCtrl m_system_tab;	
class CUHFReaderDlg : public CDialog
{
// Construction
public:
	BOOL GetLocalSerialPort(CUIntArray &ports);
	void GetVersion(int ReaderNum);
	int QuerySerialNo(int ReaderNum);

	int ConnectReader();
	int DisConnectReader();
	int SocketConnect();
	int SocketDisConnect();
	int ComConnect();
	int ComDisConnect();
	void LanguageEnglish();
	void LanguageChinese();
	void InitTab();
	int WriteLanguageFile(int LanguageFlag);
	int ReadLanguageFile(int &LanguageFlag);
	
	static CString ByteToHexStr(unsigned char byte_arr[], int arr_len);
	static void HexStrToByte(unsigned char byteT[], CString str);
	static void ListBoxAdd(CString Str);
	static void TabEnableWindow(int flag);
	CSystemConfig m_system_config;
	CISO180006B m_iso180006b;
	CEPCGEN2 m_epcgen2;
	CUHFReaderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUHFReaderDlg)
	enum { IDD = IDD_UHFREADER_DIALOG };
	CComboBox	m_spNum;
	CComboBox	m_spBaud;
	CIPAddressCtrl	m_ipAddr;
	int		m_language;
	int		m_ipPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUHFReaderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUHFReaderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeSystemTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClearSysMsgButton();
	afx_msg void OnClose();
	afx_msg void OnSwitchButton();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnConnectButton();
	afx_msg void OnDisconnectButton();
	afx_msg void OnIpRadio();
	afx_msg void OnSpRadio();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UHFREADERDLG_H__0D01C635_2AE2_46E9_86CC_EC0B5D8A2EFF__INCLUDED_)
