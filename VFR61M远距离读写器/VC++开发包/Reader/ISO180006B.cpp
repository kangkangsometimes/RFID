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
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("开始识别");
	else
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("StartIdentify");
	
	//初始化List初始化Listctrl控件 //initialize list initialize liststrl ActiveX
	InitListCtrl();
	//设置新风格//set new style
	if(0 == Language)
	{
		m_data.InsertColumn(0, "序号", LVCFMT_CENTER, 60);
		m_data.InsertColumn(1, "IsoI80006B识别ID", LVCFMT_CENTER, 450);
		m_data.InsertColumn(2, "次数", LVCFMT_CENTER, 70);
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
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("开始读取");
	else
		((CButton *)GetDlgItem(IDC_START_BUTTON))->SetWindowText("StartRead");
	
	//初始化List初始化Listctrl控件//initialize list initialize liststrl ActiveX
	InitListCtrl();
	//设置新风格//set new style
	if(0 == Language)
	{
		m_data.InsertColumn(0, "序号", LVCFMT_CENTER, 60);
		m_data.InsertColumn(1, "IsoI80006B读取数据", LVCFMT_CENTER, 450);
		m_data.InsertColumn(2, "次数", LVCFMT_CENTER, 70);
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
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("读取");
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
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("写入");
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
		((CButton *)GetDlgItem(IDC_OPERATION_BUTTON))->SetWindowText("锁定");
		((CButton *)GetDlgItem(IDC_QUERYLOCK_BUTTON))->SetWindowText("查询");
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
	if(Text == "开始识别" || Text == "StartIdentify")
	{
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("开始识别");
		else
			CUHFReaderDlg::ListBoxAdd("start identify");
		
		SetTimer(3, 1000, NULL);
		SetTimer(1, 50, NULL);
	}
	if(Text == "开始读取" || Text == "StartRead")
	{
		SetTimer(3, 1000, NULL);
		SetTimer(2, 50, NULL);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("开始读取");
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
	if(Text == "开始识别" || Text == "StartIdentify")
	{
		KillTimer(1);
		KillTimer(3);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("停止识别");
		else
			CUHFReaderDlg::ListBoxAdd("stop identify");
		
	}
	if(Text == "开始读取" || Text == "StartRead")
	{
		KillTimer(2);
		KillTimer(3);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("停止读取");
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
	if(Text == "读取" || Text == "Read")
	{
		SingleTagRead();
	}
	if(Text == "写入" || Text == "Write")
	{
		SingleTagWrite();
	}
	if(Text == "锁定" || Text == "Lock")
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

//多标签识别//multi-tag identify
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
		if(0 != TagCount)		//标签识别成功//tag identify success
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("识别到的标签数量为0!");//identify tag quantity is 0
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt6B; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf6B[j], SIXBLEN) == 0)	//相同//same
							{
								Cnt = (int)(DisplayBuf6B[j][12] << 8) + (int)DisplayBuf6B[j][13];
								Cnt ++;
								DisplayBuf6B[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf6B[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);								// 重复次数加1//times ofrepetition add 1
								m_data.SetItemText(j, 2, SNo);						// 更新显示//update display
								break;
							}
						}
						if(j == DisplayCnt6B)										//不相同//not same
						{
							memcpy(DisplayBuf6B[j], Data[i].Data, SIXBLEN);
							DisplayBuf6B[j][13] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, SIXBLEN);
							DisplayNewTag(Tempstr);									// 显示//display
							DisplayCnt6B++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else			//取数据失败//get data failed
				{
					;
					//CUHFReaderDlg::ListBoxAdd("IsoI8000取数据失败!");get dat failed
					//CUHFReaderDlg::ListBoxAdd("停止识别");//stop identify
					//KillTimer(1);
				}
			}
		}
	}
	else		//识别失败//identify failed	
	{
		;
		//CUHFReaderDlg::ListBoxAdd("IsoI8000标签识别失败!");//tag identify failed
		//CUHFReaderDlg::ListBoxAdd("停止识别");//stop identify
		//KillTimer(1);
	}
}

//多标签读取//multi-tag read
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
		if(0 != TagCount)										//标签读取成功//Multi-tag read success
		{
			while(1)
			{
				status = BufferM_GetTagData(CS, GetCount, Data, 0xFF);
				if(0x00 == status)
				{
					if(0 == GetCount)
					{
						//CUHFReaderDlg::ListBoxAdd("读取到的标签数量为0!");//read tag quantity is 0
						break;
					}
					Count +=  GetCount;
					for(i = 0; i < GetCount; i++)
					{
						for(j = 0; j < DisplayCnt6B; j++)
						{
							if(memcmp(Data[i].Data, DisplayBuf6B[j], SIXBLEN) == 0)				//相同//same
							{
								Cnt = (int)(DisplayBuf6B[j][12] << 8) + (int)DisplayBuf6B[j][13];
								Cnt ++;
								DisplayBuf6B[j][12] = (unsigned char)(Cnt >> 8);
								DisplayBuf6B[j][13] = (unsigned char)(Cnt & 0xFF);
								SNo.Format("%d", Cnt);											// 重复次数加1//times of repitions add one
								m_data.SetItemText(j, 2, SNo);									// 更新显示//update display
								break;
							}
						}
						if(j == DisplayCnt6B)													//不相同//not same
						{
							memcpy(DisplayBuf6B[j], Data[i].Data, SIXBLEN);
							DisplayBuf6B[j][13] = 1;
							Tempstr = CUHFReaderDlg::ByteToHexStr(Data[i].Data, SIXBLEN);
							DisplayNewTag(Tempstr);												// 显示//display
							DisplayCnt6B++;
							UpdateData(false);
						}
					}
					memset( Data, 0, sizeof(BufferData)*16 );
					if(0 == (TagCount - Count))
						break;
				}
				else			//取数据失败//get data failed
				{
					;
					//CUHFReaderDlg::ListBoxAdd("IsoI8000取数据失败!");
					//CUHFReaderDlg::ListBoxAdd("停止读取");
					//KillTimer(1);
				}
			}
		}
	}
	else		//读取失败//read failed	
	{
		;
		//CUHFReaderDlg::ListBoxAdd("IsoI8000标签读取失败!");//tag read failed
		//CUHFReaderDlg::ListBoxAdd("停止读取");//stop read
		//KillTimer(1);
	}
}

//单标签读取//single tag read
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
			CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签读取成功!");
		else
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag read success!");
		
	}
	else		//读取失败//read failed	
	{
		ReadData = "Read fail, please again...";
		ResultAddString(ReadData);
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签读取失败!");
		else
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag read failed!");
		
	}
}

//单标签写入//single tag write
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
				ResultAddString("写入数据成功");
				CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签写入成功!");
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
				ResultAddString("写入数据失败");
				CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签写入失败!");
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
			ResultAddString("写入数据为空!");
			CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签写入数据为空!");
		}
		else
		{
			ResultAddString("write data is null!");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag write data is null!");
		}
	}
}

//单标签锁定设置//single tag lock set
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
			ResultAddString("标签数据锁定失败");
			CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签数据锁定失败!");
		}
		else
		{
			ResultAddString("tag data lock failed");
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock failed!");
		}
	}
}

//单标签锁定查询//single tag lock query
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
				ResultAddString("当前地址未锁定!");
			else
				ResultAddString("current address unlock!");
		}
		else if(1 == LockStatus)
		{
			if(0 == Language)
				ResultAddString("当前地址已被锁定!");
			else
				ResultAddString("current address locked!");
			
		}
		if(0 == Language)
			CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签数据锁查询成功!");
		else
			CUHFReaderDlg::ListBoxAdd("IsoI8000 single tag data lock query success!");
		
	}
	else
	{
		if(0 == Language)
		{
			ResultAddString("标签数据锁查询失败");
			CUHFReaderDlg::ListBoxAdd("IsoI8000单标签标签数据锁查询失败!");
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
	//初始化List初始化Listctrl控件//initialize list initialize Listrtrl ActiveX
	//清除原有风格// clear original style
	m_data.DeleteAllItems();		//清除所有内容//clear all content
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
	//设置新风格//set new style
	DWORD dwStyle = m_data.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）//Select an exercise of the entire line highlighted(only apply in report style listctrl)
    dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）//Gridline (only apply in report style listctrl)
	//dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件//front item generate checkbox ActiveX
	m_data.SetExtendedStyle(dwStyle); //设置扩展风格//set expand style
}

//界面更新//interface update
void CISO180006B::DisplayNewTag(CString SixBStr)
{
	CString SN = "";
	CString Text = "";
	((CButton *)GetDlgItem(IDC_START_BUTTON))->GetWindowText(Text);
	if(Text == "开始识别" || Text == "StartIdentify")
	{
		SN.Format("%d", (DisplayCnt6B + 1));

		m_data.InsertItem(DisplayCnt6B, SN);
		m_data.SetItemText(DisplayCnt6B, 1, SixBStr);
		m_data.SetItemText(DisplayCnt6B, 2, "1");
	}
	if(Text == "开始读取" || Text == "StartRead")
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

/*******************************工具函数//tool function***************************************/
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
	((CButton *)GetDlgItem(IDC_TAGIDENTIFY_STATIC))->SetWindowText("标签操作");
	((CButton *)GetDlgItem(IDC_MUTITAGIDENTIFY_RADIO))->SetWindowText("多标签识别");
	((CButton *)GetDlgItem(IDC_MUTITAGREAD_RADIO))->SetWindowText("多标签读取");
	((CButton *)GetDlgItem(IDC_READADDR_STATIC))->SetWindowText("读取地址");
	((CButton *)GetDlgItem(IDC_CLEARBUTTON))->SetWindowText("清空");
	((CButton *)GetDlgItem(IDC_TIME1_STATIC))->SetWindowText("时间");
	((CButton *)GetDlgItem(IDC_NUM_STATIC))->SetWindowText("数量");
	((CButton *)GetDlgItem(IDC_STOP_BUTTON))->SetWindowText("停止");
	((CButton *)GetDlgItem(IDC_UNIQUETAG_STATIC))->SetWindowText("单标签");
	((CButton *)GetDlgItem(IDC_SINGLEREAD_RADIO))->SetWindowText("读取");
	((CButton *)GetDlgItem(IDC_SINGLEWRITE_RADIO))->SetWindowText("写入");
	((CButton *)GetDlgItem(IDC_SINGLELOCK_RADIO))->SetWindowText("锁定");
	((CButton *)GetDlgItem(IDC_ASKADDR_STATIC))->SetWindowText("访问地址:");
	((CButton *)GetDlgItem(IDC_ASKID_STATIC))->SetWindowText("访问ID:");
	((CButton *)GetDlgItem(IDC_RESULT_STATIC))->SetWindowText("结果");
	((CButton *)GetDlgItem(IDC_VALUE_STATIC))->SetWindowText("数据:");
	((CButton *)GetDlgItem(IDC_CLEARRESULT_BUTTON))->SetWindowText("清空");
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
	// TODO: 在此添加控件通知处理程序代码
	LPNMITEMACTIVATE pNMItemActivate = (LPNMITEMACTIVATE)pNMHDR;

	
	int index = pNMItemActivate->iItem;
	CString sID = m_data.GetItemText(index, 1);

	SetDlgItemText(IDC_TAGID_EDIT, sID);


	*pResult = 0;
}
