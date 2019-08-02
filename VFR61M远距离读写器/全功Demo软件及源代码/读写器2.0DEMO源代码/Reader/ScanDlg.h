#pragma once
#include "afxcmn.h"


// CScanDlg dialog

class CScanDlg : public CDialog
{
	DECLARE_DYNAMIC(CScanDlg)

public:
	CScanDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CScanDlg();

// Dialog Data
	enum { IDD = IDD_DLG_SCAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnScan();
	virtual BOOL OnInitDialog();
	int InitListCtrl(void);
	CListCtrl m_LC_IPSCANED;
	SOCKET InitRecvSocket(void);
	SOCKET InitSendSocket(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int UpdateListShow(void);
	afx_msg void OnDestroy();
	afx_msg LRESULT OnUmPackRecved(WPARAM wParam, LPARAM lParam);
	afx_msg void OnNMDblclkListScan(NMHDR *pNMHDR, LRESULT *pResult);
};
