#if !defined(AFX_CERTIFICATIONDLG_H__2FD005CF_FB5C_4FC1_B823_397AE2F56B8A__INCLUDED_)
#define AFX_CERTIFICATIONDLG_H__2FD005CF_FB5C_4FC1_B823_397AE2F56B8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CertificationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCertificationDlg dialog

class CCertificationDlg : public CDialog
{
// Construction
public:
	CCertificationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCertificationDlg)
	enum { IDD = IDD_CERTIFICATION_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCertificationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCertificationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSet();
	afx_msg void OnButtonQuery();
	afx_msg void OnButtonManager();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CERTIFICATIONDLG_H__2FD005CF_FB5C_4FC1_B823_397AE2F56B8A__INCLUDED_)
