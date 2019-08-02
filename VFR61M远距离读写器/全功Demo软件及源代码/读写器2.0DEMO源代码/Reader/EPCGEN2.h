#if !defined(AFX_EPCGEN2_H__5BE84801_6597_46AD_9EB4_74B2A6FCB55B__INCLUDED_)
#define AFX_EPCGEN2_H__5BE84801_6597_46AD_9EB4_74B2A6FCB55B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EPCGEN2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEPCGEN2 dialog

class CEPCGEN2 : public CDialog
{
// Construction
public:
	void LanguageEnglish();
	void LanguageChinese();
	void OperationTime();
	void SECSelectConfig();
	void SECKill();
	void SECLock();
	void SECWrite();
	void SECRead();
	void InitListCtrl();
	void DisplayNewTag(CString EpcStr);
	void MultiTagWrite();
	void MultiTagRead();
	void ClearIDBuffer();
	void MultiTagInventory();
	CEPCGEN2(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CEPCGEN2)
	enum { IDD = IDD_EPCGEN2_DIALOG };
	CComboBox	m_match;
	CListCtrl	m_data;
	int		m_epc_cnum;
	int		m_epc_saddr;
	int		m_reserve_cnum;
	int		m_tid_cnum;
	int		m_user_cnum;
	int		m_user_saddr;
	int		m_tid_saddr;
	int		m_reserve_saddr;
	int		m_writeLen;
	int		m_writeAddr;
	int		m_writeMembank;
	CString	m_writeValue;
	CString	m_accesspw;
	CString	m_value;
	int		m_membank;
	int		m_mblock;
	int		m_saddr;
	int		m_level;
	int		m_wordcnt;
	int		m_length;
	int		m_slength;
	CString	m_saskpassword;
	int		m_smatch;
	int		m_slocklevel;
	int		m_smembank;
	int		m_sstartaddr;
	CString	m_svalue;
	int		m_lockmembank;
	CString	m_time;
	CString	m_number;
	int		m_speed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEPCGEN2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEPCGEN2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSecReadRadio();
	afx_msg void OnSecWriteRadio();
	afx_msg void OnSecLockRadio();
	afx_msg void OnKillTagRadio();
	afx_msg void OnConfigTagRadio();
	afx_msg void OnMultiTagInventoryRadio();
	afx_msg void OnMultiTagReadRadio();
	afx_msg void OnMultiTagWriteRadio();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOnceInventoryButton();
	afx_msg void OnMultiTagReadReserveCheck();
	afx_msg void OnMultiTagReadEpcCheck();
	afx_msg void OnMultiTagReadTidCheck();
	afx_msg void OnMultiTagReadUserCheck();
	afx_msg void OnButtonClear();
	afx_msg void OnStopButton();
	afx_msg void OnStartButton();
	afx_msg void OnExecuteButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EPCGEN2_H__5BE84801_6597_46AD_9EB4_74B2A6FCB55B__INCLUDED_)
