#if !defined(AFX_ANTCONFIGDLG_H__592B3FF3_682B_40A1_B535_51A111F6516D__INCLUDED_)
#define AFX_ANTCONFIGDLG_H__592B3FF3_682B_40A1_B535_51A111F6516D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AntConfigDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAntConfigDlg dialog

class CAntConfigDlg : public CDialog
{
// Construction
public:
	void ResetReader();
	void Set_RfPower();
	void Get_RfPower();
	void SetAntenna();
	void GetAntenna();
	void ShowAnt(int Ant);
	CAntConfigDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAntConfigDlg)
	enum { IDD = IDD_ANTCONFIG_DIALOG };
	CStatic	m_ant4_bitmap;
	CStatic	m_ant9_bitmap;
	CStatic	m_ant8_bitmap;
	CStatic	m_ant7_bitmap;
	CStatic	m_ant6_bitmap;
	CStatic	m_ant5_bitmap;
	CStatic	m_ant3_bitmap;
	CStatic	m_ant2_bitmap;
	CStatic	m_ant16_bitmap;
	CStatic	m_ant15_bitmap;
	CStatic	m_ant14_bitmap;
	CStatic	m_ant13_bitmap;
	CStatic	m_ant12_bitmap;
	CStatic	m_ant11_bitmap;
	CStatic	m_ant10_bitmap;
	CStatic	m_ant1_bitmap;
	int		m_Ant;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAntConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAntConfigDlg)
	afx_msg void OnSetAntButton();
	afx_msg void OnGetAntButton();
	afx_msg void OnRestartButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTCONFIGDLG_H__592B3FF3_682B_40A1_B535_51A111F6516D__INCLUDED_)
