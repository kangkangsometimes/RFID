; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSystemConfig
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mr61reader.h"
LastPage=0

ClassCount=11
Class1=CInternetConnect
Class2=CMR61ReaderApp
Class3=CAboutDlg
Class4=CMR61ReaderDlg
Class5=CSerialConnect

ResourceCount=9
Resource1=IDD_EPCGEN2_DIALOG
Resource2=IDD_ISO180006B_DIALOG
Resource3=IDD_MR61READER_DIALOG
Resource4=IDD_FREQPOINTS_DIALOG
Resource5=IDD_SYSCONFIG_DIALOG
Resource6=IDD_UHFREADER_DIALOG
Class6=CSystemConfig
Class7=CISO180006B
Class8=CEPCGEN2
Class9=CFreqPoints
Class10=CCertificationDlg
Resource7=IDD_ABOUTBOX
Resource8=IDD_CERTIFICATION_DIALOG
Class11=CAntConfigDlg
Resource9=IDD_ANTCONFIG_DIALOG

[CLS:CInternetConnect]
Type=0
BaseClass=CDialog
HeaderFile=InternetConnect.h
ImplementationFile=InternetConnect.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_LOGINIP

[CLS:CMR61ReaderApp]
Type=0
BaseClass=CWinApp
HeaderFile=MR61Reader.h
ImplementationFile=MR61Reader.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MR61ReaderDlg.cpp
ImplementationFile=MR61ReaderDlg.cpp

[CLS:CMR61ReaderDlg]
Type=0
BaseClass=CDialog
HeaderFile=MR61ReaderDlg.h
ImplementationFile=MR61ReaderDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_CONNECT_TAB

[CLS:CSerialConnect]
Type=0
BaseClass=CDialog
HeaderFile=SerialConnect.h
ImplementationFile=SerialConnect.cpp
LastObject=IDC_COM_CONNECT_BUTTON
Filter=D
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MR61READER_DIALOG]
Type=1
Class=CMR61ReaderDlg
ControlCount=25
Control1=IDC_STATIC_CONNECTTYPE,button,1342177287
Control2=IDC_STATIC_SYSTEM,button,1342177287
Control3=IDC_LIST,listbox,1352728833
Control4=IDC_SYSTEM_TAB,SysTabControl32,1350566144
Control5=IDC_STATIC,button,1342177287
Control6=IDC_CLEARSYSMSG_BUTTON,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_VERSION_STATIC,static,1342308353
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SERIALNO_STATIC,static,1342308353
Control11=IDC_STATIC,static,1342308352
Control12=IDC_COMBO_LANGUAGE,combobox,1344339971
Control13=IDC_SWITCH_BUTTON,button,1342242816
Control14=IDC_IP_RADIO,button,1342177289
Control15=IDC_SP_RADIO,button,1342177289
Control16=IDC_IP_ADDR_STATIC,static,1342308352
Control17=IDC_IP_PORT_STATIC,static,1342308352
Control18=IDC_IP_PORT_EDIT,edit,1350631552
Control19=IDC_SP_NUM_STATIC,static,1342308352
Control20=IDC_SP_BAUD_STATIC,static,1342308352
Control21=IDC_IP_ADDR_IPADDRESS,SysIPAddress32,1342242816
Control22=IDC_SP_NUM_COMBO,combobox,1344339971
Control23=IDC_SP_BAUD_COMBO,combobox,1344339971
Control24=IDC_CONNECT_BUTTON,button,1342242816
Control25=IDC_DISCONNECT_BUTTON,button,1342242816

[DLG:IDD_SYSCONFIG_DIALOG]
Type=1
Class=CSystemConfig
ControlCount=90
Control1=IDC_STATIC,button,1342177287
Control2=IDC_ANT1_CHECK,button,1342242819
Control3=IDC_ANT1_BITMAP,static,1342177294
Control4=IDC_ANT2_CHECK,button,1342242819
Control5=IDC_ANT2_BITMAP,static,1342177294
Control6=IDC_ANT3_CHECK,button,1342242819
Control7=IDC_ANT3_BITMAP,static,1342177294
Control8=IDC_ANT4_CHECK,button,1342242819
Control9=IDC_ANT4_BITMAP,static,1342177294
Control10=IDC_SETANTENNA_BUTTON,button,1342242816
Control11=IDC_GETANTENNA_BUTTON,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_ANTENNA1_EDIT,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_ANTENNA2_EDIT,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_ANTENNA3_EDIT,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_ANTENNA4_EDIT,edit,1350631552
Control24=IDC_STATIC,static,1342308352
Control25=IDC_SETRFPOWER_BUTTON,button,1342242816
Control26=IDC_GETRFPOWER_BUTTON,button,1342242816
Control27=IDC_INTERNET_STATIC,button,1342177287
Control28=IDC_STATIC,static,1342308352
Control29=IDC_IPADDRESS,SysIPAddress32,1342242816
Control30=IDC_PORT_STATIC,static,1342308352
Control31=IDC_INTERNETPORT_EDIT,edit,1350631552
Control32=IDC_GATWAY_STATIC,static,1342308352
Control33=IDC_GATEWAY,SysIPAddress32,1342242816
Control34=IDC_MASK_STATIC,static,1342308352
Control35=IDC_MASKCODE,SysIPAddress32,1342242816
Control36=IDC_SETINTERNET_BUTTON,button,1342242816
Control37=IDC_GETINTERNET_BUTTON,button,1342242816
Control38=IDC_RATEFREQ_STATIC,button,1342177287
Control39=IDC_CHINA_RADIO,button,1342308361
Control40=IDC_NORTHAMERICA_RADIO,button,1342177289
Control41=IDC_EUROPE_RADIO,button,1342177289
Control42=IDC_OTHERS_RADIO,button,1342177289
Control43=IDC_SETFREQUENCY_BUTTON,button,1342242816
Control44=IDC_GETFREQUENCY_BUTTON,button,1342242816
Control45=IDC_STATIC,button,1342177287
Control46=IDC_STATIC,static,1342308352
Control47=IDC_IOPORT1_RADIO,button,1342308361
Control48=IDC_IOPORT2_RADIO,button,1342177289
Control49=IDC_RELAY_RADIO,button,1342177289
Control50=IDC_OUTPUT_STATIC,static,1342308352
Control51=IDC_LOWLEVE_RADIO,button,1342308361
Control52=IDC_HIGHLEVE_RADIO,button,1342177289
Control53=IDC_OUTPORT_BUTTON,button,1342242816
Control54=IDC_GETOUTPORT_BUTTON,button,1342242816
Control55=IDC_STATIC,button,1342177287
Control56=IDC_MODEL_STATIC,static,1342308352
Control57=IDC_LITERTAG_RADIO,button,1342308361
Control58=IDC_MORETAG_RADIO,button,1342177289
Control59=IDC_NOWMODEL_STATIC,static,1342308352
Control60=IDC_TAGMODE_EDIT,edit,1484849280
Control61=IDC_SETSFTM_BUTTON,button,1342242816
Control62=IDC_GETSFTM_BUTTON,button,1342242816
Control63=IDC_MODELINTERFACE_STATIC,button,1342177287
Control64=IDC_CMD_RADIO,button,1342308361
Control65=IDC_ANIMATION_RADIO,button,1342177289
Control66=IDC_RS485_CHECK,button,1342242819
Control67=IDC_WEIGEN_CHECK,button,1342242819
Control68=IDC_TRIGGER_RADIO,button,1342177289
Control69=IDC_RS232_CHECK,button,1342242819
Control70=IDC_TRIGGERTIME_EDIT,edit,1350631552
Control71=IDC_IP_CHECK,button,1342242819
Control72=IDC_TRIGGERTIME_STATIC,static,1342308352
Control73=IDC_RELAY_CHECK,button,1342242819
Control74=IDC_WEIGENSTYLE_COMBO,combobox,1344339971
Control75=IDC_STYLE_STATIC,static,1342308352
Control76=IDC_DELAYTIME_EDIT,edit,1350631552
Control77=IDC_DELAYTIME_STATIC,static,1342308352
Control78=IDC_SETINTRFACE_BUTTON,button,1342242816
Control79=IDC_QUERYINTERFACE_BUTTON,button,1342242816
Control80=IDC_BUTTON_CERTIFICATION,button,1342242816
Control81=IDC_RESET_BUTTON,button,1342242816
Control82=IDC_MAC_EDIT,edit,1350631552
Control83=IDC_STATIC_MAC,static,1342308352
Control84=IDC_STATIC_SNO,static,1342308352
Control85=IDC_SNO_EDIT,edit,1350631552
Control86=IDC_CHECK_MAC,button,1342242819
Control87=IDC_CHECK_SNO,button,1342242819
Control88=IDC_SETSNOMAC_BUTTON,button,1342242816
Control89=IDC_QUERYSNOMAC_BUTTON,button,1342242816
Control90=IDC_STATIC,static,1342308352

[CLS:CSystemConfig]
Type=0
HeaderFile=SystemConfig.h
ImplementationFile=SystemConfig.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_MAC_EDIT
VirtualFilter=dWC

[DLG:IDD_ISO180006B_DIALOG]
Type=1
Class=CISO180006B
ControlCount=31
Control1=IDC_TAGIDENTIFY_STATIC,button,1342177287
Control2=IDC_START_BUTTON,button,1342242816
Control3=IDC_STOP_BUTTON,button,1342242816
Control4=IDC_UNIQUETAG_STATIC,button,1342177287
Control5=IDC_ASKADDR_STATIC,static,1342308352
Control6=IDC_TAGADDR_COMBO,combobox,1344340995
Control7=IDC_ASKID_STATIC,static,1342308352
Control8=IDC_TAGID_EDIT,edit,1484849280
Control9=IDC_SINGLEREAD_RADIO,button,1342308361
Control10=IDC_SINGLEWRITE_RADIO,button,1342177289
Control11=IDC_SINGLELOCK_RADIO,button,1342177289
Control12=IDC_STATIC,button,1342177287
Control13=IDC_OPERATION_BUTTON,button,1342242816
Control14=IDC_UID_CHECK,button,1342242819
Control15=IDC_TAGDATA_LIST,SysListView32,1350631425
Control16=IDC_MUTITAGIDENTIFY_RADIO,button,1342308361
Control17=IDC_MUTITAGREAD_RADIO,button,1342177289
Control18=IDC_CLEARBUTTON,button,1342242816
Control19=IDC_READADDR_COMBO,combobox,1344340995
Control20=IDC_READADDR_STATIC,static,1342308352
Control21=IDC_QUERYLOCK_BUTTON,button,1342242816
Control22=IDC_RESULT_LIST,listbox,1353777409
Control23=IDC_RESULT_STATIC,button,1342177287
Control24=IDC_CLEARRESULT_BUTTON,button,1342242816
Control25=IDC_VALUE_EDIT,edit,1350631552
Control26=IDC_VALUE_STATIC,static,1342308352
Control27=IDC_TIME1_STATIC,static,1342308352
Control28=IDC_NUM_STATIC,static,1342308352
Control29=IDC_NUMBER_STATIC,static,1342308352
Control30=IDC_TIME_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352

[DLG:IDD_EPCGEN2_DIALOG]
Type=1
Class=CEPCGEN2
ControlCount=64
Control1=IDC_MULTITAG_STATIC,button,1342177287
Control2=IDC_START_BUTTON,button,1342242816
Control3=IDC_UNIQUETAG_STATIC,button,1342177287
Control4=IDC_EXECUTE_BUTTON,button,1342242816
Control5=IDC_SECREAD_RADIO,button,1342308361
Control6=IDC_SECWRITE_RADIO,button,1342177289
Control7=IDC_SECLOCK_RADIO,button,1342177289
Control8=IDC_KILLTAG_RADIO,button,1342177289
Control9=IDC_CONFIGTAG_RADIO,button,1342177289
Control10=IDC_STATIC,button,1342177287
Control11=IDC_MULTI_TAG_INVENTORY_RADIO,button,1342308361
Control12=IDC_MULTI_TAG_READ_RADIO,button,1342177289
Control13=IDC_MULTI_TAG_WRITE_RADIO,button,1342177289
Control14=IDC_SELECTMEMBANK_STATIC,static,1073872896
Control15=IDC_RESERVE_CHECK,button,1073807363
Control16=IDC_USER_CHECK,button,1073807363
Control17=IDC_TID_CHECK,button,1073807363
Control18=IDC_RESERVE_STARTADDR_COMBO,combobox,1075905539
Control19=IDC_STARTADDR_STATIC,static,1073872896
Control20=IDC_EPC_STARTADDR_COMBO,combobox,1075905539
Control21=IDC_WORDCNTNUM_STATIC,static,1073872896
Control22=IDC_TID_STARTADDR_COMBO,combobox,1075905539
Control23=IDC_USER_STARTADDR_COMBO,combobox,1075905539
Control24=IDC_RESERVE_CNTNUM_COMBO,combobox,1075905539
Control25=IDC_EPC_CNTNUM_COMBO,combobox,1075905539
Control26=IDC_TID_CNTNUM_COMBO,combobox,1075905539
Control27=IDC_USER_CNTNUM_COMBO,combobox,1075905539
Control28=IDC_WRITEWORDADDR_STATIC,static,1073872896
Control29=IDC_WRITEMEMBANK_STATIC,static,1073872896
Control30=IDC_WRITEWORDADDR_COMBO,combobox,1075905539
Control31=IDC_WRITEWORDNUM_STATIC,static,1073872896
Control32=IDC_WRITEWORDNUM_COMBO,combobox,1075905539
Control33=IDC_WRITEVALUE_EDIT,edit,1082196096
Control34=IDC_WRITEMEMBANK_COMBO,combobox,1075905539
Control35=IDC_SHOWDATA_STATIC,button,1342177287
Control36=IDC_WRITEVALUE_STATIC,static,1073872896
Control37=IDC_ONCEINVENTORY_BUTTON,button,1342242816
Control38=IDC_BUTTON_CLEAR,button,1342242816
Control39=IDC_STOP_BUTTON,button,1342242816
Control40=IDC_TAGDATA_LIST,SysListView32,1350631425
Control41=IDC_MEMBANK_SINGLE_COMBO,combobox,1344340995
Control42=IDC_MEMBANK_SINGLE_STATIC,static,1342308352
Control43=IDC_STARTADDR_SINGLE_COMBO,combobox,1344340995
Control44=IDC_LENGTH_SINGLE_COMBO,combobox,1344340995
Control45=IDC_STARTADDR_SINGLE_STATIC,static,1342308352
Control46=IDC_VALUE_SINGLE_EDIT,edit,1350631552
Control47=IDC_VALUE_SINGLE_STATIC,static,1342308352
Control48=IDC_STATIC,button,1342177287
Control49=IDC_LENGTH_SINGLE_STATIC,static,1342308352
Control50=IDC_LOCKLEVEL_SINGLE_STATIC,static,1342308352
Control51=IDC_ASKPASSWORD_SINGLE_EDIT,edit,1350631584
Control52=IDC_MATCH_SINGLE_COMBO,combobox,1344340995
Control53=IDC_TIMES_STATIC,static,1342308352
Control54=IDC_ASKPASSWPRD_SINGLE_STATIC,static,1342308352
Control55=IDC_NUM_STATIC,static,1342308352
Control56=IDC_MATCH_SINGLE_STATIC,static,1342308352
Control57=IDC_LOCKLEVEL_SINGLE_COMBO,combobox,1344340995
Control58=IDC_NUMBER_STATIC,static,1342308352
Control59=IDC_TIME_STATIC,static,1342308353
Control60=IDC_STATIC,static,1342308352
Control61=IDC_SPEED_STATIC,static,1342308352
Control62=IDC_SPEED_COMBO,combobox,1344340995
Control63=IDC_LOCKMEMBANK_COMBO,combobox,1344339971
Control64=IDC_EPC_CHECK,button,1073807363

[CLS:CISO180006B]
Type=0
HeaderFile=ISO180006B.h
ImplementationFile=ISO180006B.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TAGID_EDIT
VirtualFilter=dWC

[CLS:CEPCGEN2]
Type=0
HeaderFile=EPCGEN2.h
ImplementationFile=EPCGEN2.cpp
BaseClass=CDialog
Filter=D
LastObject=CEPCGEN2
VirtualFilter=dWC

[DLG:IDD_FREQPOINTS_DIALOG]
Type=1
Class=CFreqPoints
ControlCount=3
Control1=IDC_ENTER_BUTTON,button,1342242816
Control2=IDC_CANCEL_BUTTON,button,1342242816
Control3=IDC_TREE,SysTreeView32,1350637863

[CLS:CFreqPoints]
Type=0
HeaderFile=FreqPoints.h
ImplementationFile=FreqPoints.cpp
BaseClass=CDialog
Filter=D
LastObject=CFreqPoints
VirtualFilter=dWC

[DLG:IDD_CERTIFICATION_DIALOG]
Type=1
Class=CCertificationDlg
ControlCount=13
Control1=IDC_STATIC_MTITLE,static,1342308353
Control2=IDC_EDIT_MPW,edit,1350631585
Control3=IDC_STATIC_LOGIN,static,1342308352
Control4=IDC_STATIC_CERTIFICATION,static,1342308352
Control5=IDC_EDIT_PW,edit,1350631553
Control6=IDC_EDIT_CTF,edit,1350631553
Control7=IDC_STATIC_SIX,static,1342308352
Control8=IDC_STATIC_TBYTE,static,1342308352
Control9=IDC_BUTTON_SET,button,1342242816
Control10=IDC_BUTTON_QUERY,button,1342242816
Control11=IDC_BUTTON_MANAGER,button,1342242816
Control12=IDC_STATIC_INFO,static,1342308353
Control13=IDC_STATIC_SIX2,static,1342308352

[CLS:CCertificationDlg]
Type=0
HeaderFile=CertificationDlg.h
ImplementationFile=CertificationDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CCertificationDlg
VirtualFilter=dWC

[DLG:IDD_UHFREADER_DIALOG]
Type=1
Class=?
ControlCount=25
Control1=IDC_STATIC_CONNECTTYPE,button,1342177287
Control2=IDC_STATIC_SYSTEM,button,1342177287
Control3=IDC_LIST,listbox,1352728833
Control4=IDC_SYSTEM_TAB,SysTabControl32,1350566144
Control5=IDC_STATIC,button,1342177287
Control6=IDC_CLEARSYSMSG_BUTTON,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_VERSION_STATIC,static,1342308353
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SERIALNO_STATIC,static,1342308353
Control11=IDC_STATIC,static,1342308352
Control12=IDC_COMBO_LANGUAGE,combobox,1344339971
Control13=IDC_SWITCH_BUTTON,button,1342242816
Control14=IDC_IP_RADIO,button,1342177289
Control15=IDC_SP_RADIO,button,1342177289
Control16=IDC_IP_ADDR_STATIC,static,1342308352
Control17=IDC_IP_PORT_STATIC,static,1342308352
Control18=IDC_IP_PORT_EDIT,edit,1350631552
Control19=IDC_SP_NUM_STATIC,static,1342308352
Control20=IDC_SP_BAUD_STATIC,static,1342308352
Control21=IDC_IP_ADDR_IPADDRESS,SysIPAddress32,1342242816
Control22=IDC_SP_NUM_COMBO,combobox,1344339971
Control23=IDC_SP_BAUD_COMBO,combobox,1344339971
Control24=IDC_CONNECT_BUTTON,button,1342242816
Control25=IDC_DISCONNECT_BUTTON,button,1342242816

[DLG:IDD_ANTCONFIG_DIALOG]
Type=1
Class=CAntConfigDlg
ControlCount=38
Control1=IDC_RESTART_BUTTON,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_ANT2_BITMAP,static,1342177294
Control4=IDC_ANT1_BITMAP,static,1342177294
Control5=IDC_ANT3_BITMAP,static,1342177294
Control6=IDC_ANT4_BITMAP,static,1342177294
Control7=IDC_ANT2_CHECK,button,1342242819
Control8=IDC_ANT1_CHECK,button,1342242819
Control9=IDC_ANT3_CHECK,button,1342242819
Control10=IDC_ANT4_CHECK,button,1342242819
Control11=IDC_ANT6_BITMAP,static,1342177294
Control12=IDC_ANT5_BITMAP,static,1342177294
Control13=IDC_ANT7_BITMAP,static,1342177294
Control14=IDC_ANT8_BITMAP,static,1342177294
Control15=IDC_ANT6_CHECK,button,1342242819
Control16=IDC_ANT5_CHECK,button,1342242819
Control17=IDC_ANT7_CHECK,button,1342242819
Control18=IDC_ANT8_CHECK,button,1342242819
Control19=IDC_ANT10_BITMAP,static,1342177294
Control20=IDC_ANT9_BITMAP,static,1342177294
Control21=IDC_ANT11_BITMAP,static,1342177294
Control22=IDC_ANT12_BITMAP,static,1342177294
Control23=IDC_ANT10_CHECK,button,1342242819
Control24=IDC_ANT9_CHECK,button,1342242819
Control25=IDC_ANT11_CHECK,button,1342242819
Control26=IDC_ANT12_CHECK,button,1342242819
Control27=IDC_ANT14_BITMAP,static,1342177294
Control28=IDC_ANT13_BITMAP,static,1342177294
Control29=IDC_ANT15_BITMAP,static,1342177294
Control30=IDC_ANT16_BITMAP,static,1342177294
Control31=IDC_ANT14_CHECK,button,1342242819
Control32=IDC_ANT13_CHECK,button,1342242819
Control33=IDC_ANT15_CHECK,button,1342242819
Control34=IDC_ANT16_CHECK,button,1342242819
Control35=IDC_STATIC,static,1342308352
Control36=IDC_POWER_COMBO,combobox,1344339971
Control37=IDC_SETANT_BUTTON,button,1342242816
Control38=IDC_GETANT_BUTTON,button,1342242816

[CLS:CAntConfigDlg]
Type=0
HeaderFile=AntConfigDlg.h
ImplementationFile=AntConfigDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_POWER_COMBO
VirtualFilter=dWC

