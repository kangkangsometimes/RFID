// ScanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UHFReader.h"
#include "ScanDlg.h"


// CScanDlg dialog

IMPLEMENT_DYNAMIC(CScanDlg, CDialog)

CScanDlg::CScanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScanDlg::IDD, pParent)
{

}

CScanDlg::~CScanDlg()
{
}

void CScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SCAN, m_LC_IPSCANED);
}


BEGIN_MESSAGE_MAP(CScanDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CScanDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_SCAN, &CScanDlg::OnBnClickedBtnScan)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_MESSAGE(UM_PACK_RECVED, &CScanDlg::OnUmPackRecved)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_SCAN, &CScanDlg::OnNMDblclkListScan)
END_MESSAGE_MAP()


// CScanDlg message handlers

void CScanDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// OnOK();
}

unsigned int g_SendCnt = 0;

CArray<LPSCAN_PARAM> g_arr_Reader;
BOOL g_bStart = FALSE;

SOCKET g_sock_Recv, g_sock_Send;

void CScanDlg::OnBnClickedBtnScan()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here

	if (g_bStart == FALSE)
	{

		g_sock_Recv = InitRecvSocket();
		g_sock_Send = InitSendSocket();
		if (g_sock_Send == INVALID_SOCKET || g_sock_Recv == INVALID_SOCKET)
		{
			::AfxMessageBox(_T("套接字创建或绑定失败"));

			return;
		}


		g_arr_Reader.RemoveAll();
		m_LC_IPSCANED.DeleteAllItems();
		g_SendCnt = 0;

		SetTimer(101, 500, NULL);
		g_bStart = TRUE;
		SetDlgItemText(IDC_BTN_SCAN, _T("Stop"));
	}
	else
	{
		KillTimer(101);
		g_bStart = FALSE;
		SetDlgItemText(IDC_BTN_SCAN, _T("Start"));

		closesocket(g_sock_Recv);
		closesocket(g_sock_Send);


	}
}

BOOL CScanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	WSAData wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		::AfxMessageBox(_T("Socket库初始化失败，扫描不可用"));
	}

	InitListCtrl();


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

int CScanDlg::InitListCtrl(void)
{
	DWORD dwStyleIdentify = m_LC_IPSCANED.GetExtendedStyle();
    dwStyleIdentify |= LVS_EX_FULLROWSELECT;
    dwStyleIdentify |= LVS_EX_GRIDLINES;	
	m_LC_IPSCANED.SetExtendedStyle(dwStyleIdentify);

	m_LC_IPSCANED.InsertColumn(0, "序号", LVCFMT_CENTER, 60);
	m_LC_IPSCANED.InsertColumn(1, "IP", LVCFMT_CENTER, 150);
	m_LC_IPSCANED.InsertColumn(2, "TCP Port", LVCFMT_CENTER, 100);
	m_LC_IPSCANED.InsertColumn(3, "读写器序列号", LVCFMT_CENTER, 200);

	return 0;
}

SOCKET CScanDlg::InitRecvSocket(void)
{
	/*
	准备套接字接收广播
	*/
	SOCKET recv_sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (recv_sock == INVALID_SOCKET)
	{
		int err = WSAGetLastError();

		return INVALID_SOCKET;
	}

	bool opt = true;
	//setsockopt(recv_sock, IPPROTO_IP, IP_RECEIVE_BROADCAST, (char *)&opt, sizeof (opt));
	setsockopt(recv_sock, SOL_SOCKET, SO_BROADCAST, (char *)&opt, sizeof (opt));

	sockaddr_in LocalAddr;
	LocalAddr.sin_family = AF_INET;
	LocalAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	LocalAddr.sin_port = htons(12346);
	int LocalAddrLen = sizeof (sockaddr);
	if (0 != bind(recv_sock, (sockaddr *)&LocalAddr, LocalAddrLen))
	{
		closesocket(recv_sock);

		int err = WSAGetLastError();

		return INVALID_SOCKET;
	}




	int iRet = WSAAsyncSelect(recv_sock, this->GetSafeHwnd(), UM_PACK_RECVED, FD_READ);
	if (iRet == 0)
	{
		return recv_sock;
	}
	else
	{
		closesocket(recv_sock);

		return INVALID_SOCKET;
	}
}

SOCKET CScanDlg::InitSendSocket(void)
{
	// 准备发送套接字
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET)
	{
		closesocket(sock);

		return INVALID_SOCKET;
	}

	bool opt = true;
	setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&opt, sizeof (opt));	
	//int timeout = 100;
	//setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
	//timeout = 100;
	//setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof (timeout));

	return sock;
}

void CScanDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 101)
	{
		UpdateListShow();
		SetTimer(101, 5000, NULL);

		sockaddr_in addrto;
		addrto.sin_family = AF_INET;
		addrto.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");
		addrto.sin_port = htons(12345);

		char SendBuf[] = {"HELLO"};

		timeval stTimeO;
		stTimeO.tv_sec = 0;
		stTimeO.tv_usec = 0;

		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(g_sock_Send, &fds);

		int SelectRet = select(g_sock_Send + 1, NULL, &fds, NULL, &stTimeO);

		if (SelectRet > 0 && FD_ISSET(g_sock_Send, &fds))
		{
			int SendRet = sendto(g_sock_Send, SendBuf, 5, 0
				, (sockaddr *)&addrto, sizeof (sockaddr));

			if (SendRet == 5)
			{
				g_SendCnt++;
			}
		}

		
	}

	CDialog::OnTimer(nIDEvent);
}

int CScanDlg::UpdateListShow(void)
{
	int j = 0;

	m_LC_IPSCANED.DeleteAllItems();
	int arr_cnt = g_arr_Reader.GetSize();
	for (int i = 0; i < arr_cnt; i++, j++)
	{
		if (g_SendCnt - g_arr_Reader[i]->cnt >= 3)
		{
			continue;
		}

		CString sNo;
		sNo.Format(_T("%d"), j + 1);
		m_LC_IPSCANED.InsertItem(j, sNo);
		m_LC_IPSCANED.SetItemText(j, 1, g_arr_Reader[i]->sIP);
		m_LC_IPSCANED.SetItemText(j, 2, g_arr_Reader[i]->sTCPPort);
		m_LC_IPSCANED.SetItemText(j, 3, g_arr_Reader[i]->sReaderID);

		m_LC_IPSCANED.EnsureVisible(m_LC_IPSCANED.GetItemCount() - 1, true);
	}


	return 0;
}

void CScanDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here


}

LRESULT CScanDlg::OnUmPackRecved(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETSELECTERROR(lParam))
	{
		return -1;
	}

	char RecvBuf[256] = {0};

	switch(WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
		{
			sockaddr_in addrfrom;
			addrfrom.sin_family = AF_INET;
			int addrfrom_len = sizeof (sockaddr);
			int recv_len = recvfrom(g_sock_Recv, RecvBuf, 256, 0, (sockaddr *)&addrfrom, &addrfrom_len);
			if (recv_len <= 0)
			{
				return -1;
			}
			CString sFromIP = inet_ntoa(addrfrom.sin_addr);
			CString sFrom(_T(""));
			sFrom.Format(_T("%s"), RecvBuf);
			sFrom = sFrom.MakeLower();
			if (sFrom.Left(4) != _T("from"))
			{
				memset(RecvBuf, 0, 256);
				
			}
			else
			{
				CString subStr[10];
				CString strTmp;
				int i = 0;
				while ( AfxExtractSubString(strTmp, (LPCTSTR)sFrom, i, _T(' ')) )
				{
				   subStr[i++] = strTmp;
				}

				CString sIP = subStr[1];
				CString sTcpPort = subStr[2];
				CString sSN = subStr[3];
				int iTitle = sSN.Find(_T(':'));
				int rightcount = sSN.GetLength() - iTitle - 1;
				sSN = sSN.Right(rightcount);

				int arr_cnt = g_arr_Reader.GetSize();
				int j = 0;
				for (j = 0; j < arr_cnt; j++)
				{
					if (g_arr_Reader[j]->sIP == sIP)
					{
						g_arr_Reader[j]->cnt = g_SendCnt;

						if (g_arr_Reader[j]->sTCPPort != sTcpPort
							|| g_arr_Reader[j]->sReaderID != sSN)
						{
							g_arr_Reader[j]->sTCPPort = sTcpPort;
							g_arr_Reader[j]->sReaderID = sSN;

							UpdateListShow();
						}

						break;
					}
				}

				if (j == arr_cnt)
				{
					LPSCAN_PARAM sr = new SCAN_PARAM;
					sr->sIP = sIP;
					sr->sTCPPort = sTcpPort;
					sr->sReaderID = sSN;
					sr->cnt = g_SendCnt;
					g_arr_Reader.Add(sr);

					UpdateListShow();
				}

				
			}

		}
		break;
	}

	return 0;
}

extern CDialog *g_pMainDlg;

void CScanDlg::OnNMDblclkListScan(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	static int iDblCnt = 1;
	CString sIP(_T(""));
	CString sPort(_T(""));
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if(pNMListView->iItem != -1)
	{
		LPIPANDTCPPORT InfoToFill = new IPANDTCPPORT;
		InfoToFill->sIP = this->m_LC_IPSCANED.GetItemText(pNMListView->iItem, 1);
		InfoToFill->sTcpPort = this->m_LC_IPSCANED.GetItemText(pNMListView->iItem, 2);

		g_pMainDlg->SendMessage(UM_SCAN_DBCLK, (WPARAM)InfoToFill, (LPARAM)iDblCnt);		

		delete InfoToFill;

		iDblCnt++;
		if (iDblCnt == 5)
		{
			iDblCnt = 1;
		}

	}


	*pResult = 0;
}
