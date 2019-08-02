// ISO180006B.cpp : implementation file
//

#include "stdafx.h"
#include "uhfreader.h"
#include "ISO180006B.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "UHFReaderDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CISO180006B dialog
extern hComSocket CS;
extern int Language;

unsigned char DisplayBuf6B[2000][512];
int DisplayCnt6B = 0;
int OperTime6B = 0;
CISO180006B::CISO180006B(CWnd* pParent /*=NULL*/)
	: CDialog(CISO180006B::IDD, pParent)
{
	//{{AFX_DATA_INIT(CISO180006B)
	m_readaddr = -1;
	m_tagid = _T("");
	m_tagaddr = -1;
	m_value = _T("");
	m_number = _T("");
	m_time = _T("");
	//}}AFX_DATA_INIT
}


void CISO180006B::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CISO180006B)
	DDX_Control(pDX, IDC_RESULT_LIST, m_result);
	DDX_Control(pDX, IDC_TAGDATA_LIST, m_data);
	DDX_CBIndex(pDX, IDC_READADDR_COMBO, m_readaddr);
	DDX_Text(pDX, IDC_TAGID_EDIT, m_tagid);
	DDX_CBIndex(pDX, IDC_TAGADDR_COMBO, m_tagaddr);
	DDX_Text(pDX, IDC_VALUE_EDIT, m_value);
	DDX_Text(pDX, IDC_NUMBER_STATIC, m_number);
	DDX_Text(pDX, IDC_TIME_STATIC, m_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CISO180006B, CDialog)
	//{{AFX_MSG_MAP(CISO180006B)
	ON_BN_CLICKED(IDC_MUTITAGIDENTIFY_RADIO, OnMutiTagIdentifyRadio)
	ON_BN_CLICKED(IDC_MUTITAGREAD_RADIO, OnMutiTagReadRadio)
	ON_BN_CLICKED(IDC_SINGLEREAD_RADIO, OnSingleReadRadio)
	ON_BN_CLICKED(IDC_SINGLEWRITE_RADIO, OnSingleWriteRadio)
	ON_BN_CLICKED(IDC_SINGLELOCK_RADIO, OnSingleLockRadio)
	ON_BN_CLICKED(IDC_START_BUTTON, OnStartButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, OnStopButton)
	ON_BN_CLICKED(IDC_OPERATION_BUTTON, OnOperationButton)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_UID_CHECK, OnUidCheck)
	ON_BN_CLICKED(IDC_CLEARBUTTON, OnClearButton)
	ON_BN_CLICKED(IDC_CLEARRESULT_BUTTON, OnClearResultButton)
	ON_NOTIFY(NM_DBLCLK, IDC_TAGDATA_LIST, OnDblclkTagdataList)
	ON_BN_CLICKED(IDC_QUERYLOCK_BUTTON, OnQueryLockButton)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CLICK, IDC_TAGDATA_LIST, &CISO180006B::OnNMClickTagdataList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CISO180006B message handlers

BOOL CISO180006B::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(0 == Language)
		LanguageChinese();
	if(1 == Language)
		LanguageEnglish();
	((CButton *)GetDlgItem(IDC_MUTITAGIDENTIFY_RADIO))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_SINGLEREAD_RADIO))->SetCheck(1);
	OnMutiTagIdentifyRadio();
	OnSingleReadRadio();
	CString Addrstr = "";
	for(int index = 0; index < 301; index ++)
	{
		Addrstr.Format("%d", index);
		((CComboBox *)GetDlgItem(IDC_TAGADDR_COMBO))->AddString(Addrstr);
	}
	m_tagaddr = 8;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CISO180006B::OnMutiTagIdentifyRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_READADDR_COMBO))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_READADDR_STATIC))->ShowWindow(false);
	if(0 == Language)
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("��ʼʶ��");
	else
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("StartIdentify");
	
	//��ʼ��List��ʼ��Listctrl�ؼ� //initialize list initialize liststrl ActiveX
	InitListCtrl();
	//�����·��//set new style
	if(0 == Language)
	{
		m_data.InsertColumn(0, "���", LVCFMT_CENTER, 60);
		m_data.InsertColumn(1, "IsoI80006Bʶ��ID", LVCFMT_CENTER, 450);
		m_data.InsertColumn(2, "����", LVCFMT_CENTER, 70);
	}
	else
	{
		m_data.InsertColumn(0, "No.", LVCFMT_CENTER, 60);
		m_data.InsertColumn(1, "IsoI80006B identify ID", LVCFMT_CENTER, 450);
		m_data.InsertColumn(2, "Times", LVCFMT_CENTER, 70);
	}
	
}

void CISO180006B::OnMutiTagReadRadio() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_READADDR_COMBO))->ShowWindow(true);
	((CButton *)GetDlgItem(IDC_READADDR_STATIC))->ShowWindow(true);
	m_readaddr = 0;
	UpdateData(false);
	if(0 == Language)
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("��ʼ��ȡ");
	else
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("StartRead");
	
	//��ʼ��List��ʼ��Listctrl�ؼ�//initialize list initialize liststrl ActiveX
	InitListCtrl();
	//�����·��//set new style
	if(0 == Language)
	{
		m_data.InsertColumn(0, "���", LVCFMT_CENTER, 60);
		m_data.InsertColumn(1, "IsoI80006B��ȡ����", LVCFMT_CENTER, 450);
		m_data.InsertColumn(2, "����", LVCFMT_CENTER, 70);
	}
	else
	{
		m_data.InsertColumn(0, "No.", LVCFMT_CENTER, 60);
		m_data.InsertColumn(1, "IsoI80006B ReadData", LVCFMT_CENTER,450);
		m_data.InsertColumn(2, "Times", LVCFMT_CENTER, 70);
	}

}

void CISO180006B::OnSingleReadRadio() 
{
	// TODO: Add your control notification handler code here
	if(0 == Language)
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("��ȡ");
	else
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("Read");
	
	((CButton *)GetDlgItem(IDC_QUERYLOCK_BUTTON))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_UID_CHECK))->EnableWindow(true);
	m_result.ResetContent();
}

void CISO180006B::OnSingleWriteRadio() 
{
	// TODO: Add your control notification handler code here
	if(0 == Language)
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("д��");
	else
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("Write");

	((CButton *)GetDlgItem(IDC_QUERYLOCK_BUTTON))->ShowWindow(false);
	((CButton *)GetDlgItem(IDC_UID_CHECK))->EnableWindow(true);
	m_result.ResetContent();
}

void CISO180006B::OnSingleLockRadio() 
{
	// TODO: Add your control notification handler code here
	if(0 == Language)
	{
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("����");
		((CButton *)GetDlgItem(IDC_QUERYLOCK_BUTTON))->SetWindowText("��ѯ");
	}
	else
	{
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("Lock");
		((CButton *)GetDlgItem(IDC_QUERYLOCK_BUTTON))->SetWindowText("Query");
	}
	((CButton *)GetDlgItem(IDC_QUERYLOCK_BUTTON))->ShowWindow(true);
	((CButton *)GetDlgItem(IDC_UID_CHECK))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_UID_CHECK))->SetCheck(0);
	m_result.ResetContent();
}

void CISO180006B::OnStartButton() 
{
	// TODO: Add your control notification handler code here
	m_data.DeleteAllItems();
	memset( DisplayBuf6B, 0, sizeof(unsigned char)*2000*512);
	DisplayCnt6B = 0;
	CString Text = "";
	((CButton *)GetDlgItem(IDC_START_BUTTON))->GetWindowText(Text);
	if(Text == "��ʼʶ��" || Text == "StartIdentify")
	{
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("��ʼʶ��");
		else
			CUHFReaderDlg::ListBoxAdd("start identify");
		
		SetTimer(3, 1000, NULL);
		SetTimer(1, 50, NULL);
	}
	if(Text == "��ʼ��ȡ" || Text == "StartRead")
	{
		SetTimer(3, 1000, NULL);
		SetTimer(2, 50, NULL);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("��ʼ��ȡ");
		else
			CUHFReaderDlg::ListBoxAdd("start read");
		((CButton *)GetDlgItem(IDC_READADDR_COMBO))->EnableWindow(false);
	}
	
	((CButton *)GetDlgItem(IDC_START_BUTTON))->EnableWindow(false);
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->EnableWindow(true);
}

void CISO180006B::OnStopButton() 
{
	// TODO: Add your control notification handler code here
	CString Text = "";
	((CButton *)GetDlgItem(IDC_START_BUTTON))->GetWindowText(Text);
	if(Text == "��ʼʶ��" || Text == "StartIdentify")
	{
		KillTimer(1);
		KillTimer(3);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("ֹͣʶ��");
		else
			CUHFReaderDlg::ListBoxAdd("stop identify");
		
	}
	if(Text == "��ʼ��ȡ" || Text == "StartRead")
	{
		KillTimer(2);
		KillTimer(3);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("ֹͣ��ȡ");
		else
			CUHFReaderDlg::ListBoxAdd("stop read");
		
	}
	((CButton *)GetDlgItem(IDC_START_BUTTON))->EnableWindow(true);
	((CButton *)GetDlgItem(IDC_READADDR_COMBO))->EnableWindow(true);
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->EnableWindow(false);
}

void CISO180006B::OnOperationButton() 
{
	// TODO: Add your control notification handler code here
	CString Text = "";
	((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->GetWindowText(Text);
	if(Text == "��ȡ" || Text == "Read")
	{
		SingleTagRead();
	}
	if(Text == "д��" || Text == "Write")
	{
		SingleTagWrite();
	}
	if(Text == "����" || Text == "Lock")
	{
		SingleSetTagLock();
	}
}

void CISO180006B::OnQueryLockButton() 
{
	// TODO: Add your control notification handler code here
	SingleQueryTagLock();
}

void CISO180006B::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		MutiTagIdentify();
		break;
	case 2:
		MutiTagRead();
		break;
	case 3:
		OperationTime();
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CISO180006B::OnUidCheck() 
{
	// TODO: Add your control notification handler code here
	if(((CButton *)GetDlgItem(IDC_UID_CHECK))->GetCheck() == 1)
		((CButton *)GetDlgItem(IDC_TAGID_EDIT))->EnableWindow(true);
	else
		((CButton *)GetDlgItem(IDC_TAGID_EDIT))->EnableWindow(false);
}

void CISO180006B::OnClearButton() 
{
	// TODO: Add your control notification handler code here
	m_data.DeleteAllItems();
	memset( DisplayBuf6B, 0, sizeof(unsigned char)*2000*512);
	DisplayCnt6B = 0;
	OperTime6B = 0;
	m_time = "";
	m_number = "";
	UpdateData(false);
}

void CISO180006B::OnClearResultButton() 
{
	// TODO: Add your control notification handler code here
	m_result.ResetContent();
}

void CISO180006B::OnDblclkTagdataList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int item = 0;
	if(((CButton *)GetDlgItem(IDC_UID_CHECK))->GetCheck() == 1)
	{
		for(item = 0; item < m_data.GetItemCount(); item++)
		{
			if( m_data.GetItemState(item, LVIS_SELECTED) == LVIS_SELECTED )
			{
				m_tagid = m_data.GetItemText(item, 1);
				UpdateData(false);
				m_data.SetItemState(item, 0, LVIS_SELECTED|LVIS_FOCUSED);
				break;
			}
		}
	}
	*pResult = 0;
}

//���ǩʶ��//multi-tag identify
void CISO180006B::MutiTagIdentify()
{
	int TagCount = 0;
	int GetCount = 0;
	int Count = 0;
	int i, j = 0;
	int Cnt = 0;
	int status;
	CString Tempstr = "";
	CString SNo = "";
	BufferData Data[16] = {0};
	status = ISO_MultiTagIdentify(CS, TagCount, 0xFF);
	if(0x00 == status) 
	{
		if(0 != TagCount)		//��ǩʶ��ɹ�//tag identify success
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("ʶ�𵽵ı�ǩ����Ϊ0!");//identify tag quantity is 0
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt6B; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf6B[j], SIXBLEN) == 0)	//��ͬ//same
							{
								Cnt = (int)(DisplayBuf6B[j][12] << 8) + (int)DisplayBuf6B[j][13];
								Cnt ++;
								DisplayBuf6B[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf6B[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);								// �ظ�������1//times ofrepetition add 1
								m_data.SetItemText(j, 2, SNo);						// ������ʾ//update display
								break;
							}
						}
						if(j == DisplayCnt6B)										//����ͬ//not same
						{
							memcpy(DisplayBuf6B[j], Data[i].Data, SIXBLEN);
							DisplayBuf6B[j][13] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, SIXBLEN);
							DisplayNewTag(Tempstr);									// ��ʾ//display
							DisplayCnt6B++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else			//ȡ����ʧ��//get data failed
				{
					;
					//CUHFReaderDlg::ListBoxAdd("IsoI8000ȡ����ʧ��!");get dat failed
					//CUHFReaderDlg::ListBoxAdd("ֹͣʶ��");//stop identify
					//KillTimer(1);
				}
			}
		}
	}
	else		//ʶ��ʧ��//identify failed	
	{
		;
		//CUHFReaderDlg::ListBoxAdd("IsoI8000��ǩʶ��ʧ��!");//tag identify failed
		//CUHFReaderDlg::ListBoxAdd("ֹͣʶ��");//stop identify
		//KillTimer(1);
	}
}

//���ǩ��ȡ//multi-tag read
void CISO180006B::MutiTagRead()
{
	int TagCount = 0;
	int GetCount = 0;
	int Count = 0;
	int i, j = 0;
	int Cnt = 0;
	int status;
	CString Tempstr = "";
	CString SNo = "";
	BufferData Data[16] = {0};
	UpdateData(true);
	int RAddr = m_readaddr;
	status = ISO_MultiTagRead(CS, RAddr, TagCount, 0xFF);
	if(0x00 == status) 
	{
		if(0 != TagCount)										//��ǩ��ȡ�ɹ�//Multi-tag read success
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("��ȡ���ı�ǩ����Ϊ0!");//read tag quantity is 0
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt6B; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf6B[j], SIXBLEN) == 0)				//��ͬ//same
							{
								Cnt = (int)(DisplayBuf6B[j][12] << 8) + (int)DisplayBuf6B[j][13];
								Cnt ++;
								DisplayBuf6B[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf6B[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);											// �ظ�������1//times of repitions add one
								m_data.SetItemText(j, 2, SNo);									// ������ʾ//update display
								break;
							}
						}
						if(j == DisplayCnt6B)													//����ͬ//not same
						{
							memcpy(DisplayBuf6B[j], Data[i].Data, SIXBLEN);
							DisplayBuf6B[j][13] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, SIXBLEN);
							DisplayNewTag(Tempstr);												// ��ʾ//display
							DisplayCnt6B++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else			//ȡ����ʧ��//get data failed
				{
					;
					//CUHFReaderDlg::ListBoxAdd("IsoI8000ȡ����ʧ��!");
					//CUHFReaderDlg::ListBoxAdd("ֹͣ��ȡ");
					//KillTimer(1);
				}
			}
		}
	}
	else		//��ȡʧ��//read failed	
	{
		;
		//CUHFReaderDlg::ListBoxAdd("IsoI8000��ǩ��ȡʧ��!");//tag read failed
		//CUHFReaderDlg::ListBoxAdd("ֹͣ��ȡ");//stop read
		//KillTimer(1);
	}
}

//����ǩ��ȡ//single tag read
void CISO180006B::SingleTagRead()
{
	UpdateData(true);
	int status = 0;
	int RAddr = 0;
	unsigned char UID[8] = {0};
	unsigned char RecvData[12] = {0};
	CString ID = "";
	CString ReadData = "";
	RAddr = m_tagaddr;
	
	if(((CButton *)GetDlgItem(IDC_UID_CHECK))->GetCheck() == 1)
	{
		ID = m_tagid;
		CUHFReaderDlg::HexStrToByte(UID, ID);
		status = ISO_TagReadWithUID(CS, UID, RAddr, RecvData, 0xFF);
	}
	else
	{
		status = ISO_TagRead(CS, RAddr, RecvData, 0xFF);
	}
	if(0x00 == status) 
	{
		ReadData = CUHFReaderDlg::ByteToHexStr(&RecvData[1], 8);
		ReadData = "Read:  " + ReadData;
		ResultAddString(ReadData);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩ��ȡ�ɹ�!");
		else
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag read success!");
		
	}
	else		//��ȡʧ��//read failed	
	{
		ReadData = "Read fail, please again...";
		ResultAddString(ReadData);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩ��ȡʧ��!");
		else
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag read failed!");
		
	}
}

//����ǩд��//single tag write
void CISO180006B::SingleTagWrite()
{
	UpdateData(true);
	int status = 0;
	int WAddr = 0;
	unsigned char UID[8] = {0};
	unsigned char RecvData[9] = {0};
	//unsigned char WData[301] = {0};
	CString ID = _T("");
	CString WriteStr = _T("");
	int WriteLen = 0;
	WAddr = m_tagaddr;
	WriteStr = m_value;
	WriteLen = WriteStr.GetLength();
	unsigned char *WData = new unsigned char[WriteLen];
	CUHFReaderDlg::HexStrToByte(WData, WriteStr);
	if(0 != WriteLen)
	{
		if(((CButton *)GetDlgItem(IDC_UID_CHECK))->GetCheck() == 1)
		{
			ID = m_tagid;
			CUHFReaderDlg::HexStrToByte(UID, ID);
			status = ISO_TagWriteWithUID(CS, UID, WAddr, WData, WriteLen/2, 0xFF);
		}
		else
		{
			status = ISO_TagWrite(CS, WAddr, WData, WriteLen/2, 0xFF);
		}

		if(0x00 == status) 
		{
			if(0 == Language)
			{
				ResultAddString("д�����ݳɹ�");
				CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩд��ɹ�!");
			}
			else
			{
				ResultAddString("write data success");
				CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag write success!");
			}
		}
		else
		{
			if(0 == Language)
			{
				ResultAddString("д������ʧ��");
				CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩд��ʧ��!");
			}
			else
			{
				ResultAddString("write data failed");
				CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag wrie failed!");
			}
		}
	}
	else
	{
		if(0 == Language)
		{
			ResultAddString("д������Ϊ��!");
			CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩд������Ϊ��!");
		}
		else
		{
			ResultAddString("write data is null!");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag write data is null!");
		}
	}
}

//����ǩ��������//single tag lock set
void CISO180006B::SingleSetTagLock()
{
	UpdateData(true);
	int status = 0;
	int LAddr = 0;
	unsigned char UID[8] = {0};
	CString ID = "";
	LAddr = m_tagaddr;
	if(((CButton *)GetDlgItem(IDC_UID_CHECK))->GetCheck() == 1)
	{
		ID = m_tagid;
		CUHFReaderDlg::HexStrToByte(UID, ID);
		status = ISO_SetTagLockWithUID(CS, UID, LAddr, 0xFF);
	}
	else
	{
		status = ISO_SetTagLock(CS, LAddr, 0xFF);
	}
	
	if(0x00 == status) 
	{
		if(0 == Language)
		{
			ResultAddString("tag data lock success");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock success!");
		}
		else
		{
			ResultAddString("tag data lock success");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock success!");
		}
	}
	else
	{
		if(0 == Language)
		{
			ResultAddString("��ǩ��������ʧ��");
			CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩ��������ʧ��!");
		}
		else
		{
			ResultAddString("tag data lock failed");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock failed!");
		}
	}
}

//����ǩ������ѯ//single tag lock query
void CISO180006B::SingleQueryTagLock()
{
	UpdateData(true);
	int status = 0;
	int QAddr = 0;
	int LockStatus = 0;
	unsigned char UID[8] = {0};
	CString ID = "";
	QAddr = m_tagaddr;

	if(((CButton *)GetDlgItem(IDC_UID_CHECK))->GetCheck() == 1)
	{
		ID = m_tagid;
		CUHFReaderDlg::HexStrToByte(UID, ID);
		status = ISO_QueryTagLockWithUID(CS, UID, QAddr, LockStatus, 0xFF);
	}
	else
	{
		status = ISO_QueryTagLock(CS, QAddr, LockStatus, 0xFF);
	}
	
	if(0x00 == status) 
	{
		if(0 == LockStatus)
		{
			if(0 == Language)
				ResultAddString("��ǰ��ַδ����!");
			else
				ResultAddString("current address unlock!");
		}
		else if(1 == LockStatus)
		{
			if(0 == Language)
				ResultAddString("��ǰ��ַ�ѱ�����!");
			else
				ResultAddString("current address locked!");
			
		}
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩ��������ѯ�ɹ�!");
		else
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock query success!");
		
	}
	else
	{
		if(0 == Language)
		{
			ResultAddString("��ǩ��������ѯʧ��");
			CUHFReaderDlg::ListBoxAdd("IsoI8000����ǩ��ǩ��������ѯʧ��!");
		}
		else
		{
			ResultAddString("tag data lock query failed");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock query failed!");
		}
	}
}

void CISO180006B::InitListCtrl()
{
	//��ʼ��List��ʼ��Listctrl�ؼ�//initialize list initialize Listrtrl ActiveX
	//���ԭ�з��// clear original style
	m_data.DeleteAllItems();		//�����������//clear all content
	int Column;
	CHeaderCtrl*   pHeaderCtrl = m_data.GetHeaderCtrl(); 
	if(pHeaderCtrl) 
	{ 
        Column = pHeaderCtrl->GetItemCount(); 
	}
	for(Column; Column > 0; Column --)
	{
		m_data.DeleteColumn(Column - 1);
	}
	//�����·��//set new style
	DWORD dwStyle = m_data.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��//Select an exercise of the entire line highlighted(only apply in report style listctrl)
    dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��//Gridline (only apply in report style listctrl)
	//dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�//front item generate checkbox ActiveX
	m_data.SetExtendedStyle(dwStyle); //������չ���//set expand style
}

//�������//interface update
void CISO180006B::DisplayNewTag(CString SixBStr)
{
	CString SN = "";
	CString Text = "";
	((CButton *)GetDlgItem(IDC_START_BUTTON))->GetWindowText(Text);
	if(Text == "��ʼʶ��" || Text == "StartIdentify")
	{
		SN.Format("%d", (DisplayCnt6B + 1));

		m_data.InsertItem(DisplayCnt6B, SN);
		m_data.SetItemText(DisplayCnt6B, 1, SixBStr);
		m_data.SetItemText(DisplayCnt6B, 2, "1");
	}
	if(Text == "��ʼ��ȡ" || Text == "StartRead")
	{
		SN.Format("%d", (DisplayCnt6B + 1));

		m_data.InsertItem(DisplayCnt6B, SN);
		m_data.SetItemText(DisplayCnt6B, 1, SixBStr);
		m_data.SetItemText(DisplayCnt6B, 2, "1");
	}
	m_number = SN;
	UpdateData(false);
}

void CISO180006B::ResultAddString(CString Str)
{
	m_result.AddString(Str);
	m_result.SetTopIndex(m_result.GetCount() - 1);
}

/*******************************���ߺ���//tool function***************************************/
void CISO180006B::OperationTime()
{
	CString time = "";
	OperTime6B ++;
	time.Format("%d", (OperTime6B));
	m_time = time;
	UpdateData(false);
}

void CISO180006B::LanguageChinese()
{
	((CButton *)GetDlgItem(IDC_TAGIDENTIFY_STATIC))->SetWindowText("��ǩ����");
	((CButton *)GetDlgItem(IDC_MUTITAGIDENTIFY_RADIO))->SetWindowText("���ǩʶ��");
	((CButton *)GetDlgItem(IDC_MUTITAGREAD_RADIO))->SetWindowText("���ǩ��ȡ");
	((CButton *)GetDlgItem(IDC_READADDR_STATIC))->SetWindowText("��ȡ��ַ");
	((CButton *)GetDlgItem(IDC_CLEARBUTTON))->SetWindowText("���");
	((CButton *)GetDlgItem(IDC_TIME1_STATIC))->SetWindowText("ʱ��");
	((CButton *)GetDlgItem(IDC_NUM_STATIC))->SetWindowText("����");
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->SetWindowText("ֹͣ");
	((CButton *)GetDlgItem(IDC_UNIQUETAG_STATIC))->SetWindowText("����ǩ");
	((CButton *)GetDlgItem(IDC_SINGLEREAD_RADIO))->SetWindowText("��ȡ");
	((CButton *)GetDlgItem(IDC_SINGLEWRITE_RADIO))->SetWindowText("д��");
	((CButton *)GetDlgItem(IDC_SINGLELOCK_RADIO))->SetWindowText("����");
	((CButton *)GetDlgItem(IDC_ASKADDR_STATIC))->SetWindowText("���ʵ�ַ:");
	((CButton *)GetDlgItem(IDC_ASKID_STATIC))->SetWindowText("����ID:");
	((CButton *)GetDlgItem(IDC_RESULT_STATIC))->SetWindowText("���");
	((CButton *)GetDlgItem(IDC_VALUE_STATIC))->SetWindowText("����:");
	((CButton *)GetDlgItem(IDC_CLEARRESULT_BUTTON))->SetWindowText("���");
}

void CISO180006B::LanguageEnglish()
{
	((CButton *)GetDlgItem(IDC_TAGIDENTIFY_STATIC))->SetWindowText("TagIdentfy");
	((CButton *)GetDlgItem(IDC_MUTITAGIDENTIFY_RADIO))->SetWindowText("MutiTagIdentify");
	((CButton *)GetDlgItem(IDC_MUTITAGREAD_RADIO))->SetWindowText("MutiTagRead");
	((CButton *)GetDlgItem(IDC_READADDR_STATIC))->SetWindowText("ReadAddr");
	((CButton *)GetDlgItem(IDC_CLEARBUTTON))->SetWindowText("Clear");
	((CButton *)GetDlgItem(IDC_TIME1_STATIC))->SetWindowText("Time");
	((CButton *)GetDlgItem(IDC_NUM_STATIC))->SetWindowText("Num");
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->SetWindowText("Stop");
	((CButton *)GetDlgItem(IDC_UNIQUETAG_STATIC))->SetWindowText("UniqueTag");
	((CButton *)GetDlgItem(IDC_SINGLEREAD_RADIO))->SetWindowText("Read");
	((CButton *)GetDlgItem(IDC_SINGLEWRITE_RADIO))->SetWindowText("Write");
	((CButton *)GetDlgItem(IDC_SINGLELOCK_RADIO))->SetWindowText("Lock");
	((CButton *)GetDlgItem(IDC_ASKADDR_STATIC))->SetWindowText("AskAddr:");
	((CButton *)GetDlgItem(IDC_ASKID_STATIC))->SetWindowText("AskID:");
	((CButton *)GetDlgItem(IDC_RESULT_STATIC))->SetWindowText("Result");
	((CButton *)GetDlgItem(IDC_VALUE_STATIC))->SetWindowText("Value:");
	((CButton *)GetDlgItem(IDC_CLEARRESULT_BUTTON))->SetWindowText("Clear");
}

void CISO180006B::OnNMClickTagdataList(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LPNMITEMACTIVATE pNMItemActivate = (LPNMITEMACTIVATE)pNMHDR;

	
	int index = pNMItemActivate->iItem;
	CString sID = m_data.GetItemText(index, 1);

	SetDlgItemText(IDC_TAGID_EDIT, sID);


	*pResult = 0;
}
