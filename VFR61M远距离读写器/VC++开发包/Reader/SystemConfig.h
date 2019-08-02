#if !defined(AFX_SYSTEMCONFIG_H__ACAD6AE5_F4CE_4B66_BB4D_3645628C38C7__INCLUDED_)
#define AFX_SYSTEMCONFIG_H__ACAD6AE5_F4CE_4B66_BB4D_3645628C38C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SystemConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSystemConfig dialog

class CSystemConfig : public CDialog
{
// Construction
public:
	void GetSerialNum();
	void CheckRelay();
	void InterfaceRadioCheck();
	void WorkModelRadioCheck();
	void LanguageChinese();
	void LanguageEnglish();
	int TriggerTime(int ReaderNum, CString Text);
	void WeigenStyle(int ReaderNum, CString Text);
	void RelayDelayTime(int ReaderNum, CString Text);
	int OutInterface(int ReaderNum, CString Text);
	int WorkModel(int ReaderNum, CString Text);
	void GetOutPort();
	void ByteToDecimalstr(CString & ToStr, unsigned char Buf[]);
	void DecimalstrToByte(unsigned char Buf[], CString Str);
	void GetInternetAccess();
	void SetInternetAccess();
	void SetOutPort();
	void SetTestMode();
	void GetSingleFastTagMode();
	void SetSingleFastTagMode();
	void GetAntenna();
	void SetAntenna();
	void SetFrequency();
	void GetFrequency();
	void Get_RfPower();
	void Set_RfPower();
	void ResetReader();
	void SetBaud();
	void GetVersion();
	CSystemConfig(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CSystemConfig)
	enum { IDD = IDD_SYSCONFIG_DIALOG };
	CIPAddressCtrl	m_maskcode;
	CIPAddressCtrl	m_ipaddress;
	CIPAddressCtrl	m_gateway;
	CStatic	m_ant4_bitmap;
	CStatic	m_ant3_bitmap;
	CStatic	m_ant2_bitmap;
	CStatic	m_ant1_bitmap;
	CString	m_tagmode;
	int		m_wstyle;
	int		m_delaytime;
	int		m_triggertime;
	CString	m_ant1;
	CString	m_ant2;
	CString	m_ant3;
	CString	m_ant4;
	CString	m_internetport;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSystemConfig)
	afx_msg void OnResetReaderButton();
	virtual BOOL OnInitDialog();
	afx_msg void OnGetrfpowerButton();
	afx_msg void OnSetrfpowerButton();
	afx_msg void OnSetFrequencyButton();
	afx_msg void OnGetFrequencyButton();
	afx_msg void OnOthersRadio();
	afx_msg void OnSetAntennaButton();
	afx_msg void OnGetAntennaButton();
	afx_msg void OnSetSingleFastmTagModeButton();
	afx_msg void OnGetSingleFastmTagModeButton();
	afx_msg void OnOutPortButton();
	afx_msg void OnSetInternetButton();
	afx_msg void OnGetInternetButton();
	afx_msg void OnGetOutPortButton();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonCertification();
	afx_msg void OnSetIntrfaceButton();
	afx_msg void OnQueryInterfaceButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMCONFIG_H__ACAD6AE5_F4CE_4B66_BB4D_3645628C38C7__INCLUDED_)
