#if !defined(AFX_ISO180006B_H__07EBB358_F980_48AC_AB94_F01F7D8CEF85__INCLUDED_)
#define AFX_ISO180006B_H__07EBB358_F980_48AC_AB94_F01F7D8CEF85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ISO180006B.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CISO180006B dialog

class CISO180006B : public CDialog
{
// Construction
public:
	void LanguageChinese();
	void LanguageEnglish();
	void OperationTime();
	void SingleQueryTagLock();
	void ResultAddString(CString Str);
	void SingleSetTagLock();
	void SingleTagWrite();
	void SingleTagRead();
	void DisplayNewTag(CString SixBStr);
	void MutiTagRead();
	void MutiTagIdentify();
	void InitListCtrl();
	CISO180006B(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CISO180006B)
	enum { IDD = IDD_ISO180006B_DIALOG };
	CListBox	m_result;
	CListCtrl	m_data;
	int		m_readaddr;
	CString	m_tagid;
	int		m_tagaddr;
	CString	m_value;
	CString	m_number;
	CString	m_time;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CISO180006B)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CISO180006B)
	afx_msg void OnMutiTagIdentifyRadio();
	afx_msg void OnMutiTagReadRadio();
	virtual BOOL OnInitDialog();
	afx_msg void OnSingleReadRadio();
	afx_msg void OnSingleWriteRadio();
	afx_msg void OnSingleLockRadio();
	afx_msg void OnStartButton();
	afx_msg void OnStopButton();
	afx_msg void OnOperationButton();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnUidCheck();
	afx_msg void OnClearButton();
	afx_msg void OnClearResultButton();
	afx_msg void OnDblclkTagdataList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnQueryLockButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMClickTagdataList(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ISO180006B_H__07EBB358_F980_48AC_AB94_F01F7D8CEF85__INCLUDED_)
