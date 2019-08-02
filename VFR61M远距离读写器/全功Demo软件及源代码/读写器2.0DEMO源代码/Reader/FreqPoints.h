#if !defined(AFX_FREQPOINTS_H__AAC4E5D3_E9C7_4285_B8B1_E1206AC69A94__INCLUDED_)
#define AFX_FREQPOINTS_H__AAC4E5D3_E9C7_4285_B8B1_E1206AC69A94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FreqPoints.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFreqPoints dialog
#include "MutiTreeCtrl.h"
class CFreqPoints : public CDialog
{
// Construction
public:
	HTREEITEM c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10,
			  c11, c12, c13, c14, c15, c16, c17, c18, c19, c20,
			  c21, c22, c23, c24, c25, c26, c27, c28, c29, c30,
			  c31, c32, c33, c34, c35, c36, c37, c38, c39, c40,
			  c41, c42, c43, c44, c45, c46, c47, c48, c49, c50,
			  c51, c52, c53, c54, c55, c56, c57, c58, c59, c60,
			  c61, c62, c63, c64, c65, c66, c67, c68, c69, c70,
			  c71, c72, c73, c74, c75, c76, c77, c78, c79, c80,
			  c81, c82, c83, c84, c85, c86, c87, c88, c89, c90,
			  c91, c92, c93, c94, c95, c96, c97, c98, c99, c100,
			  c101, c102, c103, c104, c105, c106, c107, c108, c109, c110,
			  c111, c112, c113, c114, c115, c116, c117, c118, c119, c120,
			  c121, c122, c123;
	HTREEITEM h900, h901, h902, h903, h904, 
			  h905, h906, h907, h908, h909,
			  h910, h911, h912, h913, h914, 
			  h915, h916, h917, h918, h919,
			  h920, h921, h922, h923, h924, 
			  h925, h926, h927, h928, h929, 
			  h930;

	void SetTree();
	void InitializeTree();
	CImageList m_imgList;
	CImageList m_imgState;
	
	CFreqPoints(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CFreqPoints)
	enum { IDD = IDD_FREQPOINTS_DIALOG };
	CMutiTreeCtrl m_TripleTree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFreqPoints)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFreqPoints)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelButton();
	afx_msg void OnEnterButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FREQPOINTS_H__AAC4E5D3_E9C7_4285_B8B1_E1206AC69A94__INCLUDED_)
