namespace MR6100Demo
{
    partial class mainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.gbConnect = new System.Windows.Forms.GroupBox();
            this.tbPort = new System.Windows.Forms.TextBox();
            this.tbIP = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnDiscon = new System.Windows.Forms.Button();
            this.btnConnect = new System.Windows.Forms.Button();
            this.libInfo = new System.Windows.Forms.ListBox();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tabPage_EPCMultiTag = new System.Windows.Forms.TabPage();
            this.panelIdentity = new System.Windows.Forms.Panel();
            this.btnIdentify_Once = new System.Windows.Forms.Button();
            this.livGen2Identify = new MR6100Demo.ListViewNF();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader21 = new System.Windows.Forms.ColumnHeader();
            this.gbEPCDataAnalysis = new System.Windows.Forms.GroupBox();
            this.lbTestDuration = new System.Windows.Forms.Label();
            this.lbReadTimes = new System.Windows.Forms.Label();
            this.lbAverageRate = new System.Windows.Forms.Label();
            this.lbPeakRate = new System.Windows.Forms.Label();
            this.lbTotalReads = new System.Windows.Forms.Label();
            this.lbUniqueTags = new System.Windows.Forms.Label();
            this.lbTD = new System.Windows.Forms.Label();
            this.lbRT = new System.Windows.Forms.Label();
            this.lbAR = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnIdentify = new System.Windows.Forms.Button();
            this.panelGen2MultiTagRead = new System.Windows.Forms.Panel();
            this.lbMultiTagReadDuration = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.lbMultiTagReadCnt = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.livEPCMultiTagRead = new MR6100Demo.ListViewNF();
            this.columnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader7 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader9 = new System.Windows.Forms.ColumnHeader();
            this.btnMultiTagRead = new System.Windows.Forms.Button();
            this.cbUserWordCnt = new System.Windows.Forms.ComboBox();
            this.cbUserStartAddr = new System.Windows.Forms.ComboBox();
            this.cbEPCWordCnt = new System.Windows.Forms.ComboBox();
            this.cbEPCStartAddr = new System.Windows.Forms.ComboBox();
            this.cbTIDWordCnt = new System.Windows.Forms.ComboBox();
            this.cbTIDStartAddr = new System.Windows.Forms.ComboBox();
            this.cbResWordCnt = new System.Windows.Forms.ComboBox();
            this.cbResStartAddr = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.chbUser = new System.Windows.Forms.CheckBox();
            this.chbEPC = new System.Windows.Forms.CheckBox();
            this.chbTID = new System.Windows.Forms.CheckBox();
            this.label4 = new System.Windows.Forms.Label();
            this.chbReserve = new System.Windows.Forms.CheckBox();
            this.panelMultiTagWrite = new System.Windows.Forms.Panel();
            this.tbWriteValue_Gen2 = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.lbMultiTagWriteDuration = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.lbMultiTagWriteCount = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.livEPCMultiTagWrite = new MR6100Demo.ListViewNF();
            this.columnHeader10 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader11 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader12 = new System.Windows.Forms.ColumnHeader();
            this.btnMultiTagWrite = new System.Windows.Forms.Button();
            this.cbMEPCWrite_WordLen = new System.Windows.Forms.ComboBox();
            this.label13 = new System.Windows.Forms.Label();
            this.cbMEPCWrite_WordAddr = new System.Windows.Forms.ComboBox();
            this.label12 = new System.Windows.Forms.Label();
            this.cbMEPCWrite_MemBank = new System.Windows.Forms.ComboBox();
            this.label10 = new System.Windows.Forms.Label();
            this.linLGen2MultiTagWrite = new System.Windows.Forms.LinkLabel();
            this.linLGen2Identify = new System.Windows.Forms.LinkLabel();
            this.linLGen2MultiTagRead = new System.Windows.Forms.LinkLabel();
            this.tabPage_EPCSingleTag = new System.Windows.Forms.TabPage();
            this.gbGen2kill = new System.Windows.Forms.GroupBox();
            this.btnGen2Kill = new System.Windows.Forms.Button();
            this.tbGen2Kill_PWD = new System.Windows.Forms.TextBox();
            this.label30 = new System.Windows.Forms.Label();
            this.gbGen2SecuredLock = new System.Windows.Forms.GroupBox();
            this.btnGen2SecLock = new System.Windows.Forms.Button();
            this.cbGen2SecLock_Membank = new System.Windows.Forms.ComboBox();
            this.cbGen2SecLock_Level = new System.Windows.Forms.ComboBox();
            this.tbGen2SecLock_PWD = new System.Windows.Forms.TextBox();
            this.label26 = new System.Windows.Forms.Label();
            this.label27 = new System.Windows.Forms.Label();
            this.label28 = new System.Windows.Forms.Label();
            this.gbGen2SecuredWrite = new System.Windows.Forms.GroupBox();
            this.btnGen2SecWrite = new System.Windows.Forms.Button();
            this.cbGen2SecWrite_Membank = new System.Windows.Forms.ComboBox();
            this.cbGen2SecWrite_WordAdr = new System.Windows.Forms.ComboBox();
            this.tbGen2SecWrite_Value = new System.Windows.Forms.TextBox();
            this.tbGen2SecWrite_PWD = new System.Windows.Forms.TextBox();
            this.label21 = new System.Windows.Forms.Label();
            this.label22 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.label24 = new System.Windows.Forms.Label();
            this.gbGen2SelectConfig = new System.Windows.Forms.GroupBox();
            this.rbMatch = new System.Windows.Forms.RadioButton();
            this.rbDisMatch = new System.Windows.Forms.RadioButton();
            this.btnGen2SelectConfig = new System.Windows.Forms.Button();
            this.cbGen2SelectConfig_BitLength = new System.Windows.Forms.ComboBox();
            this.cbGen2SelectConfig_BitAddr = new System.Windows.Forms.ComboBox();
            this.cbGen2SelectConfig_Membank = new System.Windows.Forms.ComboBox();
            this.tbGen2SelectConfig_Value = new System.Windows.Forms.TextBox();
            this.label25 = new System.Windows.Forms.Label();
            this.label33 = new System.Windows.Forms.Label();
            this.label29 = new System.Windows.Forms.Label();
            this.label31 = new System.Windows.Forms.Label();
            this.label32 = new System.Windows.Forms.Label();
            this.gbGen2SecuredRead = new System.Windows.Forms.GroupBox();
            this.btnGen2SecRead = new System.Windows.Forms.Button();
            this.cbGen2SecRead_WordCnt = new System.Windows.Forms.ComboBox();
            this.cbGen2SecRead_WordAddr = new System.Windows.Forms.ComboBox();
            this.tbGen2SecRead_Value = new System.Windows.Forms.TextBox();
            this.cbGen2SecRead_Membank = new System.Windows.Forms.ComboBox();
            this.tbGen2SecRead_PWD = new System.Windows.Forms.TextBox();
            this.label34 = new System.Windows.Forms.Label();
            this.label20 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.label19 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.tabPage_6B = new System.Windows.Forms.TabPage();
            this.panelIsoMultiTagRead = new System.Windows.Forms.Panel();
            this.livIsoMultiTagRead = new System.Windows.Forms.ListView();
            this.columnHeader17 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader18 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader19 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader20 = new System.Windows.Forms.ColumnHeader();
            this.btnIsoMultiTagRead = new System.Windows.Forms.Button();
            this.cbIsoMultiTagRead_StartAddr = new System.Windows.Forms.ComboBox();
            this.label35 = new System.Windows.Forms.Label();
            this.panelISOIdentify = new System.Windows.Forms.Panel();
            this.btnISOIdentify = new System.Windows.Forms.Button();
            this.livISOIdentify = new MR6100Demo.ListViewNF();
            this.columnHeader13 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader14 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader15 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader16 = new System.Windows.Forms.ColumnHeader();
            this.panelIsoSingleTag = new System.Windows.Forms.Panel();
            this.gbIsoQueryLock = new System.Windows.Forms.GroupBox();
            this.numIsoQueryLock_Addr = new System.Windows.Forms.NumericUpDown();
            this.btnIsoQueryLockWithUID = new System.Windows.Forms.Button();
            this.btnIsoQueryLock = new System.Windows.Forms.Button();
            this.tbIsoQueryLock_UID = new System.Windows.Forms.TextBox();
            this.tbIsoQueryLock_Res = new System.Windows.Forms.TextBox();
            this.label43 = new System.Windows.Forms.Label();
            this.label46 = new System.Windows.Forms.Label();
            this.label45 = new System.Windows.Forms.Label();
            this.gbIsoLock = new System.Windows.Forms.GroupBox();
            this.numIsoLock_Addr = new System.Windows.Forms.NumericUpDown();
            this.btnIsoLockWithUID = new System.Windows.Forms.Button();
            this.btnIsoLock = new System.Windows.Forms.Button();
            this.tbIsoLock_UID = new System.Windows.Forms.TextBox();
            this.tbIsoLock_Res = new System.Windows.Forms.TextBox();
            this.label42 = new System.Windows.Forms.Label();
            this.label47 = new System.Windows.Forms.Label();
            this.label44 = new System.Windows.Forms.Label();
            this.gbIsoRead = new System.Windows.Forms.GroupBox();
            this.numIsoRead_Addr = new System.Windows.Forms.NumericUpDown();
            this.btnIsoReadWithUID = new System.Windows.Forms.Button();
            this.btnIsoRead = new System.Windows.Forms.Button();
            this.tbIsoRead_UID = new System.Windows.Forms.TextBox();
            this.tbIsoRead_Result = new System.Windows.Forms.TextBox();
            this.label39 = new System.Windows.Forms.Label();
            this.label40 = new System.Windows.Forms.Label();
            this.label41 = new System.Windows.Forms.Label();
            this.gbIsoWrite = new System.Windows.Forms.GroupBox();
            this.numIsoWrite_Addr = new System.Windows.Forms.NumericUpDown();
            this.btnWriteWithUID = new System.Windows.Forms.Button();
            this.btnIsoWrite = new System.Windows.Forms.Button();
            this.tbIsoWrite_UID = new System.Windows.Forms.TextBox();
            this.tbIsoWrite_Value = new System.Windows.Forms.TextBox();
            this.label38 = new System.Windows.Forms.Label();
            this.label37 = new System.Windows.Forms.Label();
            this.label36 = new System.Windows.Forms.Label();
            this.linLISOMultiTagRead = new System.Windows.Forms.LinkLabel();
            this.linLISOIdentify = new System.Windows.Forms.LinkLabel();
            this.linLISOSingleTag = new System.Windows.Forms.LinkLabel();
            this.tabPage_Settings = new System.Windows.Forms.TabPage();
            this.groupBox10 = new System.Windows.Forms.GroupBox();
            this.rbBuzzerOFF = new System.Windows.Forms.RadioButton();
            this.btnSetBuzzer = new System.Windows.Forms.Button();
            this.btnGetBuzzer = new System.Windows.Forms.Button();
            this.rbBuzzerON = new System.Windows.Forms.RadioButton();
            this.groupBox9 = new System.Windows.Forms.GroupBox();
            this.rbFreq_Others = new System.Windows.Forms.RadioButton();
            this.rbFreq_Europe = new System.Windows.Forms.RadioButton();
            this.rbFreq_NAmerica = new System.Windows.Forms.RadioButton();
            this.rbFreq_China = new System.Windows.Forms.RadioButton();
            this.checkedlibFrePoint = new System.Windows.Forms.CheckedListBox();
            this.label66 = new System.Windows.Forms.Label();
            this.btnGetFrequency = new System.Windows.Forms.Button();
            this.lbFreqPoints = new System.Windows.Forms.Label();
            this.btnSetFrequency = new System.Windows.Forms.Button();
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.tbTCPPara_GateWay = new System.Windows.Forms.TextBox();
            this.tbTCPPara_Mask = new System.Windows.Forms.TextBox();
            this.btnGetTCPPara = new System.Windows.Forms.Button();
            this.btnSetTCPPara = new System.Windows.Forms.Button();
            this.tbTCPPara_IP = new System.Windows.Forms.TextBox();
            this.label63 = new System.Windows.Forms.Label();
            this.label62 = new System.Windows.Forms.Label();
            this.label61 = new System.Windows.Forms.Label();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.cbIOLevel = new System.Windows.Forms.ComboBox();
            this.cbIOPort = new System.Windows.Forms.ComboBox();
            this.btnSetOutPort = new System.Windows.Forms.Button();
            this.label60 = new System.Windows.Forms.Label();
            this.label59 = new System.Windows.Forms.Label();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.rbMultiFastTagMode = new System.Windows.Forms.RadioButton();
            this.rbSingleFastTagMode = new System.Windows.Forms.RadioButton();
            this.btnGetTagMode = new System.Windows.Forms.Button();
            this.btnSetTagMode = new System.Windows.Forms.Button();
            this.btnResetReader = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnGetFirmVersion = new System.Windows.Forms.Button();
            this.lbFirmVersion = new System.Windows.Forms.Label();
            this.label51 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.pbGreen = new System.Windows.Forms.PictureBox();
            this.pbRed = new System.Windows.Forms.PictureBox();
            this.pbAnteStatus4 = new System.Windows.Forms.PictureBox();
            this.pbAnteStatus3 = new System.Windows.Forms.PictureBox();
            this.pbAnteStatus2 = new System.Windows.Forms.PictureBox();
            this.pbAnteStatus1 = new System.Windows.Forms.PictureBox();
            this.chbAnte4 = new System.Windows.Forms.CheckBox();
            this.chbAnte3 = new System.Windows.Forms.CheckBox();
            this.chbAnte2 = new System.Windows.Forms.CheckBox();
            this.chbAnte1 = new System.Windows.Forms.CheckBox();
            this.btnSetAnte = new System.Windows.Forms.Button();
            this.btnGetAnte = new System.Windows.Forms.Button();
            this.label65 = new System.Windows.Forms.Label();
            this.label64 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.tbPower4 = new System.Windows.Forms.TextBox();
            this.tbPower2 = new System.Windows.Forms.TextBox();
            this.tbPower3 = new System.Windows.Forms.TextBox();
            this.tbPower1 = new System.Windows.Forms.TextBox();
            this.btnSetPower = new System.Windows.Forms.Button();
            this.btnGetPower = new System.Windows.Forms.Button();
            this.label58 = new System.Windows.Forms.Label();
            this.label57 = new System.Windows.Forms.Label();
            this.label54 = new System.Windows.Forms.Label();
            this.label56 = new System.Windows.Forms.Label();
            this.label53 = new System.Windows.Forms.Label();
            this.label55 = new System.Windows.Forms.Label();
            this.label50 = new System.Windows.Forms.Label();
            this.label52 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnSetBaudRate = new System.Windows.Forms.Button();
            this.label49 = new System.Windows.Forms.Label();
            this.label48 = new System.Windows.Forms.Label();
            this.cbSettings_BaudRate = new System.Windows.Forms.ComboBox();
            this.timerGen2Identify = new System.Windows.Forms.Timer(this.components);
            this.timerRate = new System.Windows.Forms.Timer(this.components);
            this.timerMultiTagRead = new System.Windows.Forms.Timer(this.components);
            this.timerMultiTagWrite = new System.Windows.Forms.Timer(this.components);
            this.timerIsoIdentify = new System.Windows.Forms.Timer(this.components);
            this.timerIsoMultiTagRead = new System.Windows.Forms.Timer(this.components);
            this.btnClear = new System.Windows.Forms.Button();
            this.timerReconnect = new System.Windows.Forms.Timer(this.components);
            this.gbConnect.SuspendLayout();
            this.tabControl.SuspendLayout();
            this.tabPage_EPCMultiTag.SuspendLayout();
            this.panelIdentity.SuspendLayout();
            this.gbEPCDataAnalysis.SuspendLayout();
            this.panelGen2MultiTagRead.SuspendLayout();
            this.panelMultiTagWrite.SuspendLayout();
            this.tabPage_EPCSingleTag.SuspendLayout();
            this.gbGen2kill.SuspendLayout();
            this.gbGen2SecuredLock.SuspendLayout();
            this.gbGen2SecuredWrite.SuspendLayout();
            this.gbGen2SelectConfig.SuspendLayout();
            this.gbGen2SecuredRead.SuspendLayout();
            this.tabPage_6B.SuspendLayout();
            this.panelIsoMultiTagRead.SuspendLayout();
            this.panelISOIdentify.SuspendLayout();
            this.panelIsoSingleTag.SuspendLayout();
            this.gbIsoQueryLock.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoQueryLock_Addr)).BeginInit();
            this.gbIsoLock.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoLock_Addr)).BeginInit();
            this.gbIsoRead.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoRead_Addr)).BeginInit();
            this.gbIsoWrite.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoWrite_Addr)).BeginInit();
            this.tabPage_Settings.SuspendLayout();
            this.groupBox10.SuspendLayout();
            this.groupBox9.SuspendLayout();
            this.groupBox8.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbGreen)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus1)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbConnect
            // 
            this.gbConnect.Controls.Add(this.tbPort);
            this.gbConnect.Controls.Add(this.tbIP);
            this.gbConnect.Controls.Add(this.label2);
            this.gbConnect.Controls.Add(this.label1);
            this.gbConnect.Controls.Add(this.btnDiscon);
            this.gbConnect.Controls.Add(this.btnConnect);
            this.gbConnect.Location = new System.Drawing.Point(4, 6);
            this.gbConnect.Name = "gbConnect";
            this.gbConnect.Size = new System.Drawing.Size(246, 136);
            this.gbConnect.TabIndex = 1;
            this.gbConnect.TabStop = false;
            this.gbConnect.Text = "TCP Connect";
            // 
            // tbPort
            // 
            this.tbPort.Enabled = false;
            this.tbPort.Location = new System.Drawing.Point(60, 58);
            this.tbPort.Name = "tbPort";
            this.tbPort.Size = new System.Drawing.Size(127, 21);
            this.tbPort.TabIndex = 2;
            this.tbPort.Text = "100";
            // 
            // tbIP
            // 
            this.tbIP.Location = new System.Drawing.Point(60, 24);
            this.tbIP.Name = "tbIP";
            this.tbIP.Size = new System.Drawing.Size(127, 21);
            this.tbIP.TabIndex = 2;
            this.tbIP.Text = "192.168.1.200";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "Port:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = " IP:";
            // 
            // btnDiscon
            // 
            this.btnDiscon.BackColor = System.Drawing.Color.LightPink;
            this.btnDiscon.Enabled = false;
            this.btnDiscon.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnDiscon.Location = new System.Drawing.Point(129, 90);
            this.btnDiscon.Name = "btnDiscon";
            this.btnDiscon.Size = new System.Drawing.Size(85, 35);
            this.btnDiscon.TabIndex = 0;
            this.btnDiscon.Text = "Disconnect";
            this.btnDiscon.UseVisualStyleBackColor = false;
            this.btnDiscon.Click += new System.EventHandler(this.btnDiscon_Click);
            // 
            // btnConnect
            // 
            this.btnConnect.BackColor = System.Drawing.Color.Aquamarine;
            this.btnConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnect.Location = new System.Drawing.Point(23, 90);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(85, 35);
            this.btnConnect.TabIndex = 0;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = false;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // libInfo
            // 
            this.libInfo.FormattingEnabled = true;
            this.libInfo.HorizontalScrollbar = true;
            this.libInfo.ItemHeight = 12;
            this.libInfo.Location = new System.Drawing.Point(2, 152);
            this.libInfo.Name = "libInfo";
            this.libInfo.Size = new System.Drawing.Size(246, 436);
            this.libInfo.TabIndex = 2;
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tabPage_EPCMultiTag);
            this.tabControl.Controls.Add(this.tabPage_EPCSingleTag);
            this.tabControl.Controls.Add(this.tabPage_6B);
            this.tabControl.Controls.Add(this.tabPage_Settings);
            this.tabControl.Enabled = false;
            this.tabControl.Location = new System.Drawing.Point(252, 0);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(935, 620);
            this.tabControl.TabIndex = 3;
            this.tabControl.Deselected += new System.Windows.Forms.TabControlEventHandler(this.tabControl_Deselected);
            // 
            // tabPage_EPCMultiTag
            // 
            this.tabPage_EPCMultiTag.Controls.Add(this.panelIdentity);
            this.tabPage_EPCMultiTag.Controls.Add(this.panelGen2MultiTagRead);
            this.tabPage_EPCMultiTag.Controls.Add(this.panelMultiTagWrite);
            this.tabPage_EPCMultiTag.Controls.Add(this.linLGen2MultiTagWrite);
            this.tabPage_EPCMultiTag.Controls.Add(this.linLGen2Identify);
            this.tabPage_EPCMultiTag.Controls.Add(this.linLGen2MultiTagRead);
            this.tabPage_EPCMultiTag.Location = new System.Drawing.Point(4, 21);
            this.tabPage_EPCMultiTag.Name = "tabPage_EPCMultiTag";
            this.tabPage_EPCMultiTag.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage_EPCMultiTag.Size = new System.Drawing.Size(927, 595);
            this.tabPage_EPCMultiTag.TabIndex = 0;
            this.tabPage_EPCMultiTag.Text = "Gen2 EPC MultiTag";
            this.tabPage_EPCMultiTag.UseVisualStyleBackColor = true;
            // 
            // panelIdentity
            // 
            this.panelIdentity.Controls.Add(this.btnIdentify_Once);
            this.panelIdentity.Controls.Add(this.livGen2Identify);
            this.panelIdentity.Controls.Add(this.gbEPCDataAnalysis);
            this.panelIdentity.Controls.Add(this.btnIdentify);
            this.panelIdentity.Location = new System.Drawing.Point(111, 4);
            this.panelIdentity.Name = "panelIdentity";
            this.panelIdentity.Size = new System.Drawing.Size(814, 582);
            this.panelIdentity.TabIndex = 3;
            // 
            // btnIdentify_Once
            // 
            this.btnIdentify_Once.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIdentify_Once.Location = new System.Drawing.Point(679, 515);
            this.btnIdentify_Once.Name = "btnIdentify_Once";
            this.btnIdentify_Once.Size = new System.Drawing.Size(93, 40);
            this.btnIdentify_Once.TabIndex = 3;
            this.btnIdentify_Once.Text = "Once";
            this.btnIdentify_Once.UseVisualStyleBackColor = true;
            this.btnIdentify_Once.Click += new System.EventHandler(this.btnIdentify_Once_Click);
            // 
            // livGen2Identify
            // 
            this.livGen2Identify.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader21});
            this.livGen2Identify.FullRowSelect = true;
            this.livGen2Identify.Location = new System.Drawing.Point(29, 12);
            this.livGen2Identify.Name = "livGen2Identify";
            this.livGen2Identify.Size = new System.Drawing.Size(738, 414);
            this.livGen2Identify.TabIndex = 0;
            this.livGen2Identify.UseCompatibleStateImageBehavior = false;
            this.livGen2Identify.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "NO.";
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "AnteNo.";
            this.columnHeader2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader2.Width = 62;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "EPC";
            this.columnHeader3.Width = 365;
            // 
            // columnHeader21
            // 
            this.columnHeader21.Text = "Times";
            this.columnHeader21.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // gbEPCDataAnalysis
            // 
            this.gbEPCDataAnalysis.Controls.Add(this.lbTestDuration);
            this.gbEPCDataAnalysis.Controls.Add(this.lbReadTimes);
            this.gbEPCDataAnalysis.Controls.Add(this.lbAverageRate);
            this.gbEPCDataAnalysis.Controls.Add(this.lbPeakRate);
            this.gbEPCDataAnalysis.Controls.Add(this.lbTotalReads);
            this.gbEPCDataAnalysis.Controls.Add(this.lbUniqueTags);
            this.gbEPCDataAnalysis.Controls.Add(this.lbTD);
            this.gbEPCDataAnalysis.Controls.Add(this.lbRT);
            this.gbEPCDataAnalysis.Controls.Add(this.lbAR);
            this.gbEPCDataAnalysis.Controls.Add(this.label9);
            this.gbEPCDataAnalysis.Controls.Add(this.label5);
            this.gbEPCDataAnalysis.Controls.Add(this.label3);
            this.gbEPCDataAnalysis.Location = new System.Drawing.Point(33, 432);
            this.gbEPCDataAnalysis.Name = "gbEPCDataAnalysis";
            this.gbEPCDataAnalysis.Size = new System.Drawing.Size(640, 117);
            this.gbEPCDataAnalysis.TabIndex = 2;
            this.gbEPCDataAnalysis.TabStop = false;
            this.gbEPCDataAnalysis.Text = "Data Analysis";
            // 
            // lbTestDuration
            // 
            this.lbTestDuration.AutoSize = true;
            this.lbTestDuration.Location = new System.Drawing.Point(469, 73);
            this.lbTestDuration.Name = "lbTestDuration";
            this.lbTestDuration.Size = new System.Drawing.Size(11, 12);
            this.lbTestDuration.TabIndex = 1;
            this.lbTestDuration.Text = "0";
            // 
            // lbReadTimes
            // 
            this.lbReadTimes.AutoSize = true;
            this.lbReadTimes.Location = new System.Drawing.Point(469, 28);
            this.lbReadTimes.Name = "lbReadTimes";
            this.lbReadTimes.Size = new System.Drawing.Size(11, 12);
            this.lbReadTimes.TabIndex = 1;
            this.lbReadTimes.Text = "0";
            // 
            // lbAverageRate
            // 
            this.lbAverageRate.AutoSize = true;
            this.lbAverageRate.Location = new System.Drawing.Point(288, 73);
            this.lbAverageRate.Name = "lbAverageRate";
            this.lbAverageRate.Size = new System.Drawing.Size(11, 12);
            this.lbAverageRate.TabIndex = 1;
            this.lbAverageRate.Text = "0";
            // 
            // lbPeakRate
            // 
            this.lbPeakRate.AutoSize = true;
            this.lbPeakRate.Location = new System.Drawing.Point(288, 28);
            this.lbPeakRate.Name = "lbPeakRate";
            this.lbPeakRate.Size = new System.Drawing.Size(11, 12);
            this.lbPeakRate.TabIndex = 1;
            this.lbPeakRate.Text = "0";
            // 
            // lbTotalReads
            // 
            this.lbTotalReads.AutoSize = true;
            this.lbTotalReads.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbTotalReads.ForeColor = System.Drawing.Color.Fuchsia;
            this.lbTotalReads.Location = new System.Drawing.Point(110, 68);
            this.lbTotalReads.Name = "lbTotalReads";
            this.lbTotalReads.Size = new System.Drawing.Size(20, 20);
            this.lbTotalReads.TabIndex = 1;
            this.lbTotalReads.Text = "0";
            // 
            // lbUniqueTags
            // 
            this.lbUniqueTags.AutoSize = true;
            this.lbUniqueTags.Font = new System.Drawing.Font("宋体", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbUniqueTags.ForeColor = System.Drawing.Color.Red;
            this.lbUniqueTags.Location = new System.Drawing.Point(111, 21);
            this.lbUniqueTags.Name = "lbUniqueTags";
            this.lbUniqueTags.Size = new System.Drawing.Size(23, 24);
            this.lbUniqueTags.TabIndex = 1;
            this.lbUniqueTags.Text = "0";
            // 
            // lbTD
            // 
            this.lbTD.AutoSize = true;
            this.lbTD.Location = new System.Drawing.Point(378, 73);
            this.lbTD.Name = "lbTD";
            this.lbTD.Size = new System.Drawing.Size(89, 12);
            this.lbTD.TabIndex = 0;
            this.lbTD.Text = "Test Duration:";
            // 
            // lbRT
            // 
            this.lbRT.AutoSize = true;
            this.lbRT.Location = new System.Drawing.Point(378, 28);
            this.lbRT.Name = "lbRT";
            this.lbRT.Size = new System.Drawing.Size(71, 12);
            this.lbRT.TabIndex = 0;
            this.lbRT.Text = "Read Times:";
            // 
            // lbAR
            // 
            this.lbAR.AutoSize = true;
            this.lbAR.Location = new System.Drawing.Point(198, 73);
            this.lbAR.Name = "lbAR";
            this.lbAR.Size = new System.Drawing.Size(83, 12);
            this.lbAR.TabIndex = 0;
            this.lbAR.Text = "Average Rate:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(34, 73);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(77, 12);
            this.label9.TabIndex = 0;
            this.label9.Text = "Total Reads:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(198, 28);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(65, 12);
            this.label5.TabIndex = 0;
            this.label5.Text = "Peak Rate:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(34, 28);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 12);
            this.label3.TabIndex = 0;
            this.label3.Text = "Unique Tags:";
            // 
            // btnIdentify
            // 
            this.btnIdentify.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btnIdentify.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIdentify.Location = new System.Drawing.Point(679, 435);
            this.btnIdentify.Name = "btnIdentify";
            this.btnIdentify.Size = new System.Drawing.Size(93, 62);
            this.btnIdentify.TabIndex = 1;
            this.btnIdentify.Text = "Identify";
            this.btnIdentify.UseVisualStyleBackColor = false;
            this.btnIdentify.Click += new System.EventHandler(this.btnIdentify_Click);
            // 
            // panelGen2MultiTagRead
            // 
            this.panelGen2MultiTagRead.Controls.Add(this.lbMultiTagReadDuration);
            this.panelGen2MultiTagRead.Controls.Add(this.label11);
            this.panelGen2MultiTagRead.Controls.Add(this.lbMultiTagReadCnt);
            this.panelGen2MultiTagRead.Controls.Add(this.label8);
            this.panelGen2MultiTagRead.Controls.Add(this.livEPCMultiTagRead);
            this.panelGen2MultiTagRead.Controls.Add(this.btnMultiTagRead);
            this.panelGen2MultiTagRead.Controls.Add(this.cbUserWordCnt);
            this.panelGen2MultiTagRead.Controls.Add(this.cbUserStartAddr);
            this.panelGen2MultiTagRead.Controls.Add(this.cbEPCWordCnt);
            this.panelGen2MultiTagRead.Controls.Add(this.cbEPCStartAddr);
            this.panelGen2MultiTagRead.Controls.Add(this.cbTIDWordCnt);
            this.panelGen2MultiTagRead.Controls.Add(this.cbTIDStartAddr);
            this.panelGen2MultiTagRead.Controls.Add(this.cbResWordCnt);
            this.panelGen2MultiTagRead.Controls.Add(this.cbResStartAddr);
            this.panelGen2MultiTagRead.Controls.Add(this.label7);
            this.panelGen2MultiTagRead.Controls.Add(this.label6);
            this.panelGen2MultiTagRead.Controls.Add(this.chbUser);
            this.panelGen2MultiTagRead.Controls.Add(this.chbEPC);
            this.panelGen2MultiTagRead.Controls.Add(this.chbTID);
            this.panelGen2MultiTagRead.Controls.Add(this.label4);
            this.panelGen2MultiTagRead.Controls.Add(this.chbReserve);
            this.panelGen2MultiTagRead.Location = new System.Drawing.Point(110, 4);
            this.panelGen2MultiTagRead.Name = "panelGen2MultiTagRead";
            this.panelGen2MultiTagRead.Size = new System.Drawing.Size(822, 585);
            this.panelGen2MultiTagRead.TabIndex = 4;
            // 
            // lbMultiTagReadDuration
            // 
            this.lbMultiTagReadDuration.AutoSize = true;
            this.lbMultiTagReadDuration.Location = new System.Drawing.Point(527, 537);
            this.lbMultiTagReadDuration.Name = "lbMultiTagReadDuration";
            this.lbMultiTagReadDuration.Size = new System.Drawing.Size(11, 12);
            this.lbMultiTagReadDuration.TabIndex = 4;
            this.lbMultiTagReadDuration.Text = "0";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(392, 537);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(89, 12);
            this.label11.TabIndex = 4;
            this.label11.Text = "Time Duration:";
            // 
            // lbMultiTagReadCnt
            // 
            this.lbMultiTagReadCnt.AutoSize = true;
            this.lbMultiTagReadCnt.Location = new System.Drawing.Point(122, 537);
            this.lbMultiTagReadCnt.Name = "lbMultiTagReadCnt";
            this.lbMultiTagReadCnt.Size = new System.Drawing.Size(11, 12);
            this.lbMultiTagReadCnt.TabIndex = 4;
            this.lbMultiTagReadCnt.Text = "0";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(45, 537);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(47, 12);
            this.label8.TabIndex = 4;
            this.label8.Text = "TagCnt:";
            // 
            // livEPCMultiTagRead
            // 
            this.livEPCMultiTagRead.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9});
            this.livEPCMultiTagRead.FullRowSelect = true;
            this.livEPCMultiTagRead.Location = new System.Drawing.Point(14, 115);
            this.livEPCMultiTagRead.Name = "livEPCMultiTagRead";
            this.livEPCMultiTagRead.Size = new System.Drawing.Size(801, 394);
            this.livEPCMultiTagRead.TabIndex = 3;
            this.livEPCMultiTagRead.UseCompatibleStateImageBehavior = false;
            this.livEPCMultiTagRead.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "No.";
            this.columnHeader4.Width = 44;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "AnteNo.";
            this.columnHeader5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "RESERVE";
            this.columnHeader6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader6.Width = 147;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "EPC";
            this.columnHeader7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader7.Width = 227;
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "TID";
            this.columnHeader8.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader8.Width = 155;
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "USER";
            this.columnHeader9.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader9.Width = 157;
            // 
            // btnMultiTagRead
            // 
            this.btnMultiTagRead.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btnMultiTagRead.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMultiTagRead.Location = new System.Drawing.Point(698, 35);
            this.btnMultiTagRead.Name = "btnMultiTagRead";
            this.btnMultiTagRead.Size = new System.Drawing.Size(105, 61);
            this.btnMultiTagRead.TabIndex = 1;
            this.btnMultiTagRead.Text = "MultiTagRead";
            this.btnMultiTagRead.UseVisualStyleBackColor = false;
            this.btnMultiTagRead.Click += new System.EventHandler(this.btnMultiTagRead_Click);
            // 
            // cbUserWordCnt
            // 
            this.cbUserWordCnt.FormattingEnabled = true;
            this.cbUserWordCnt.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16"});
            this.cbUserWordCnt.Location = new System.Drawing.Point(604, 81);
            this.cbUserWordCnt.Name = "cbUserWordCnt";
            this.cbUserWordCnt.Size = new System.Drawing.Size(72, 20);
            this.cbUserWordCnt.TabIndex = 2;
            // 
            // cbUserStartAddr
            // 
            this.cbUserStartAddr.FormattingEnabled = true;
            this.cbUserStartAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15"});
            this.cbUserStartAddr.Location = new System.Drawing.Point(604, 45);
            this.cbUserStartAddr.Name = "cbUserStartAddr";
            this.cbUserStartAddr.Size = new System.Drawing.Size(72, 20);
            this.cbUserStartAddr.TabIndex = 2;
            // 
            // cbEPCWordCnt
            // 
            this.cbEPCWordCnt.FormattingEnabled = true;
            this.cbEPCWordCnt.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8"});
            this.cbEPCWordCnt.Location = new System.Drawing.Point(312, 81);
            this.cbEPCWordCnt.Name = "cbEPCWordCnt";
            this.cbEPCWordCnt.Size = new System.Drawing.Size(72, 20);
            this.cbEPCWordCnt.TabIndex = 2;
            // 
            // cbEPCStartAddr
            // 
            this.cbEPCStartAddr.FormattingEnabled = true;
            this.cbEPCStartAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7"});
            this.cbEPCStartAddr.Location = new System.Drawing.Point(312, 45);
            this.cbEPCStartAddr.Name = "cbEPCStartAddr";
            this.cbEPCStartAddr.Size = new System.Drawing.Size(72, 20);
            this.cbEPCStartAddr.TabIndex = 2;
            // 
            // cbTIDWordCnt
            // 
            this.cbTIDWordCnt.FormattingEnabled = true;
            this.cbTIDWordCnt.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4"});
            this.cbTIDWordCnt.Location = new System.Drawing.Point(458, 81);
            this.cbTIDWordCnt.Name = "cbTIDWordCnt";
            this.cbTIDWordCnt.Size = new System.Drawing.Size(72, 20);
            this.cbTIDWordCnt.TabIndex = 2;
            // 
            // cbTIDStartAddr
            // 
            this.cbTIDStartAddr.FormattingEnabled = true;
            this.cbTIDStartAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3"});
            this.cbTIDStartAddr.Location = new System.Drawing.Point(458, 45);
            this.cbTIDStartAddr.Name = "cbTIDStartAddr";
            this.cbTIDStartAddr.Size = new System.Drawing.Size(72, 20);
            this.cbTIDStartAddr.TabIndex = 2;
            // 
            // cbResWordCnt
            // 
            this.cbResWordCnt.FormattingEnabled = true;
            this.cbResWordCnt.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4"});
            this.cbResWordCnt.Location = new System.Drawing.Point(142, 81);
            this.cbResWordCnt.Name = "cbResWordCnt";
            this.cbResWordCnt.Size = new System.Drawing.Size(72, 20);
            this.cbResWordCnt.TabIndex = 2;
            // 
            // cbResStartAddr
            // 
            this.cbResStartAddr.FormattingEnabled = true;
            this.cbResStartAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3"});
            this.cbResStartAddr.Location = new System.Drawing.Point(142, 45);
            this.cbResStartAddr.Name = "cbResStartAddr";
            this.cbResStartAddr.Size = new System.Drawing.Size(72, 20);
            this.cbResStartAddr.TabIndex = 2;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(41, 84);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 1;
            this.label7.Text = "WordCnt:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(41, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(65, 12);
            this.label6.TabIndex = 1;
            this.label6.Text = "StartAddr:";
            // 
            // chbUser
            // 
            this.chbUser.AutoSize = true;
            this.chbUser.Location = new System.Drawing.Point(613, 12);
            this.chbUser.Name = "chbUser";
            this.chbUser.Size = new System.Drawing.Size(48, 16);
            this.chbUser.TabIndex = 0;
            this.chbUser.Text = "USER";
            this.chbUser.UseVisualStyleBackColor = true;
            // 
            // chbEPC
            // 
            this.chbEPC.AutoSize = true;
            this.chbEPC.Location = new System.Drawing.Point(321, 12);
            this.chbEPC.Name = "chbEPC";
            this.chbEPC.Size = new System.Drawing.Size(42, 16);
            this.chbEPC.TabIndex = 0;
            this.chbEPC.Text = "EPC";
            this.chbEPC.UseVisualStyleBackColor = true;
            // 
            // chbTID
            // 
            this.chbTID.AutoSize = true;
            this.chbTID.Location = new System.Drawing.Point(467, 12);
            this.chbTID.Name = "chbTID";
            this.chbTID.Size = new System.Drawing.Size(42, 16);
            this.chbTID.TabIndex = 0;
            this.chbTID.Text = "TID";
            this.chbTID.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(41, 12);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 1;
            this.label4.Text = "Selection:";
            // 
            // chbReserve
            // 
            this.chbReserve.AutoSize = true;
            this.chbReserve.Location = new System.Drawing.Point(151, 12);
            this.chbReserve.Name = "chbReserve";
            this.chbReserve.Size = new System.Drawing.Size(66, 16);
            this.chbReserve.TabIndex = 0;
            this.chbReserve.Text = "RESERVE";
            this.chbReserve.UseVisualStyleBackColor = true;
            // 
            // panelMultiTagWrite
            // 
            this.panelMultiTagWrite.Controls.Add(this.tbWriteValue_Gen2);
            this.panelMultiTagWrite.Controls.Add(this.label15);
            this.panelMultiTagWrite.Controls.Add(this.lbMultiTagWriteDuration);
            this.panelMultiTagWrite.Controls.Add(this.label16);
            this.panelMultiTagWrite.Controls.Add(this.lbMultiTagWriteCount);
            this.panelMultiTagWrite.Controls.Add(this.label14);
            this.panelMultiTagWrite.Controls.Add(this.livEPCMultiTagWrite);
            this.panelMultiTagWrite.Controls.Add(this.btnMultiTagWrite);
            this.panelMultiTagWrite.Controls.Add(this.cbMEPCWrite_WordLen);
            this.panelMultiTagWrite.Controls.Add(this.label13);
            this.panelMultiTagWrite.Controls.Add(this.cbMEPCWrite_WordAddr);
            this.panelMultiTagWrite.Controls.Add(this.label12);
            this.panelMultiTagWrite.Controls.Add(this.cbMEPCWrite_MemBank);
            this.panelMultiTagWrite.Controls.Add(this.label10);
            this.panelMultiTagWrite.Location = new System.Drawing.Point(112, 3);
            this.panelMultiTagWrite.Name = "panelMultiTagWrite";
            this.panelMultiTagWrite.Size = new System.Drawing.Size(817, 587);
            this.panelMultiTagWrite.TabIndex = 3;
            // 
            // tbWriteValue_Gen2
            // 
            this.tbWriteValue_Gen2.Location = new System.Drawing.Point(134, 61);
            this.tbWriteValue_Gen2.Name = "tbWriteValue_Gen2";
            this.tbWriteValue_Gen2.Size = new System.Drawing.Size(263, 21);
            this.tbWriteValue_Gen2.TabIndex = 6;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(55, 63);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(71, 12);
            this.label15.TabIndex = 5;
            this.label15.Text = "WriteValue:";
            // 
            // lbMultiTagWriteDuration
            // 
            this.lbMultiTagWriteDuration.AutoSize = true;
            this.lbMultiTagWriteDuration.Location = new System.Drawing.Point(525, 553);
            this.lbMultiTagWriteDuration.Name = "lbMultiTagWriteDuration";
            this.lbMultiTagWriteDuration.Size = new System.Drawing.Size(11, 12);
            this.lbMultiTagWriteDuration.TabIndex = 4;
            this.lbMultiTagWriteDuration.Text = "0";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(420, 553);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(59, 12);
            this.label16.TabIndex = 4;
            this.label16.Text = "Duration:";
            // 
            // lbMultiTagWriteCount
            // 
            this.lbMultiTagWriteCount.AutoSize = true;
            this.lbMultiTagWriteCount.Location = new System.Drawing.Point(150, 553);
            this.lbMultiTagWriteCount.Name = "lbMultiTagWriteCount";
            this.lbMultiTagWriteCount.Size = new System.Drawing.Size(11, 12);
            this.lbMultiTagWriteCount.TabIndex = 4;
            this.lbMultiTagWriteCount.Text = "0";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(55, 553);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(89, 12);
            this.label14.TabIndex = 4;
            this.label14.Text = "WriteTagCount:";
            // 
            // livEPCMultiTagWrite
            // 
            this.livEPCMultiTagWrite.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader10,
            this.columnHeader11,
            this.columnHeader12});
            this.livEPCMultiTagWrite.FullRowSelect = true;
            this.livEPCMultiTagWrite.Location = new System.Drawing.Point(30, 100);
            this.livEPCMultiTagWrite.Name = "livEPCMultiTagWrite";
            this.livEPCMultiTagWrite.Size = new System.Drawing.Size(771, 439);
            this.livEPCMultiTagWrite.TabIndex = 3;
            this.livEPCMultiTagWrite.UseCompatibleStateImageBehavior = false;
            this.livEPCMultiTagWrite.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader10
            // 
            this.columnHeader10.Text = "No.";
            // 
            // columnHeader11
            // 
            this.columnHeader11.Text = "AnteNo.";
            this.columnHeader11.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // columnHeader12
            // 
            this.columnHeader12.Text = "EPC";
            this.columnHeader12.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader12.Width = 337;
            // 
            // btnMultiTagWrite
            // 
            this.btnMultiTagWrite.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btnMultiTagWrite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMultiTagWrite.Location = new System.Drawing.Point(653, 24);
            this.btnMultiTagWrite.Name = "btnMultiTagWrite";
            this.btnMultiTagWrite.Size = new System.Drawing.Size(89, 52);
            this.btnMultiTagWrite.TabIndex = 2;
            this.btnMultiTagWrite.Text = "Write";
            this.btnMultiTagWrite.UseVisualStyleBackColor = false;
            this.btnMultiTagWrite.Click += new System.EventHandler(this.btnMultiTagWrite_Click);
            // 
            // cbMEPCWrite_WordLen
            // 
            this.cbMEPCWrite_WordLen.FormattingEnabled = true;
            this.cbMEPCWrite_WordLen.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8"});
            this.cbMEPCWrite_WordLen.Location = new System.Drawing.Point(505, 27);
            this.cbMEPCWrite_WordLen.Name = "cbMEPCWrite_WordLen";
            this.cbMEPCWrite_WordLen.Size = new System.Drawing.Size(92, 20);
            this.cbMEPCWrite_WordLen.TabIndex = 1;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(436, 29);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(53, 12);
            this.label13.TabIndex = 0;
            this.label13.Text = "WordLen:";
            // 
            // cbMEPCWrite_WordAddr
            // 
            this.cbMEPCWrite_WordAddr.FormattingEnabled = true;
            this.cbMEPCWrite_WordAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16"});
            this.cbMEPCWrite_WordAddr.Location = new System.Drawing.Point(311, 25);
            this.cbMEPCWrite_WordAddr.Name = "cbMEPCWrite_WordAddr";
            this.cbMEPCWrite_WordAddr.Size = new System.Drawing.Size(92, 20);
            this.cbMEPCWrite_WordAddr.TabIndex = 1;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(242, 27);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(59, 12);
            this.label12.TabIndex = 0;
            this.label12.Text = "WordAddr:";
            // 
            // cbMEPCWrite_MemBank
            // 
            this.cbMEPCWrite_MemBank.FormattingEnabled = true;
            this.cbMEPCWrite_MemBank.Items.AddRange(new object[] {
            "RESERVE",
            "EPC",
            "TID",
            "USER"});
            this.cbMEPCWrite_MemBank.Location = new System.Drawing.Point(124, 24);
            this.cbMEPCWrite_MemBank.Name = "cbMEPCWrite_MemBank";
            this.cbMEPCWrite_MemBank.Size = new System.Drawing.Size(92, 20);
            this.cbMEPCWrite_MemBank.TabIndex = 1;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(55, 26);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(53, 12);
            this.label10.TabIndex = 0;
            this.label10.Text = "MemBank:";
            // 
            // linLGen2MultiTagWrite
            // 
            this.linLGen2MultiTagWrite.AutoSize = true;
            this.linLGen2MultiTagWrite.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.linLGen2MultiTagWrite.Location = new System.Drawing.Point(0, 191);
            this.linLGen2MultiTagWrite.Name = "linLGen2MultiTagWrite";
            this.linLGen2MultiTagWrite.Size = new System.Drawing.Size(111, 14);
            this.linLGen2MultiTagWrite.TabIndex = 5;
            this.linLGen2MultiTagWrite.TabStop = true;
            this.linLGen2MultiTagWrite.Text = "MultiTagWrite";
            this.linLGen2MultiTagWrite.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabelMultiTagWrite_LinkClicked);
            // 
            // linLGen2Identify
            // 
            this.linLGen2Identify.AutoSize = true;
            this.linLGen2Identify.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.linLGen2Identify.Location = new System.Drawing.Point(13, 39);
            this.linLGen2Identify.Name = "linLGen2Identify";
            this.linLGen2Identify.Size = new System.Drawing.Size(71, 14);
            this.linLGen2Identify.TabIndex = 5;
            this.linLGen2Identify.TabStop = true;
            this.linLGen2Identify.Text = "Identify";
            this.linLGen2Identify.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabelIdentify_LinkClicked);
            // 
            // linLGen2MultiTagRead
            // 
            this.linLGen2MultiTagRead.AutoSize = true;
            this.linLGen2MultiTagRead.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.linLGen2MultiTagRead.Location = new System.Drawing.Point(0, 115);
            this.linLGen2MultiTagRead.Name = "linLGen2MultiTagRead";
            this.linLGen2MultiTagRead.Size = new System.Drawing.Size(103, 14);
            this.linLGen2MultiTagRead.TabIndex = 5;
            this.linLGen2MultiTagRead.TabStop = true;
            this.linLGen2MultiTagRead.Text = "MultiTagRead";
            this.linLGen2MultiTagRead.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabelMultiTagRead_LinkClicked);
            // 
            // tabPage_EPCSingleTag
            // 
            this.tabPage_EPCSingleTag.Controls.Add(this.gbGen2kill);
            this.tabPage_EPCSingleTag.Controls.Add(this.gbGen2SecuredLock);
            this.tabPage_EPCSingleTag.Controls.Add(this.gbGen2SecuredWrite);
            this.tabPage_EPCSingleTag.Controls.Add(this.gbGen2SelectConfig);
            this.tabPage_EPCSingleTag.Controls.Add(this.gbGen2SecuredRead);
            this.tabPage_EPCSingleTag.Location = new System.Drawing.Point(4, 21);
            this.tabPage_EPCSingleTag.Name = "tabPage_EPCSingleTag";
            this.tabPage_EPCSingleTag.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage_EPCSingleTag.Size = new System.Drawing.Size(927, 595);
            this.tabPage_EPCSingleTag.TabIndex = 1;
            this.tabPage_EPCSingleTag.Text = "Gen2 EPC SingleTag";
            this.tabPage_EPCSingleTag.UseVisualStyleBackColor = true;
            // 
            // gbGen2kill
            // 
            this.gbGen2kill.Controls.Add(this.btnGen2Kill);
            this.gbGen2kill.Controls.Add(this.tbGen2Kill_PWD);
            this.gbGen2kill.Controls.Add(this.label30);
            this.gbGen2kill.Location = new System.Drawing.Point(18, 371);
            this.gbGen2kill.Name = "gbGen2kill";
            this.gbGen2kill.Size = new System.Drawing.Size(475, 62);
            this.gbGen2kill.TabIndex = 0;
            this.gbGen2kill.TabStop = false;
            this.gbGen2kill.Text = " Gen2 Kill";
            // 
            // btnGen2Kill
            // 
            this.btnGen2Kill.BackColor = System.Drawing.Color.DarkKhaki;
            this.btnGen2Kill.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGen2Kill.Location = new System.Drawing.Point(368, 15);
            this.btnGen2Kill.Name = "btnGen2Kill";
            this.btnGen2Kill.Size = new System.Drawing.Size(85, 40);
            this.btnGen2Kill.TabIndex = 3;
            this.btnGen2Kill.Text = "Gen2Kill";
            this.btnGen2Kill.UseVisualStyleBackColor = false;
            this.btnGen2Kill.Click += new System.EventHandler(this.btnGen2Kill_Click);
            // 
            // tbGen2Kill_PWD
            // 
            this.tbGen2Kill_PWD.Location = new System.Drawing.Point(74, 25);
            this.tbGen2Kill_PWD.Name = "tbGen2Kill_PWD";
            this.tbGen2Kill_PWD.Size = new System.Drawing.Size(100, 21);
            this.tbGen2Kill_PWD.TabIndex = 1;
            this.tbGen2Kill_PWD.Text = "00000000";
            // 
            // label30
            // 
            this.label30.AutoSize = true;
            this.label30.Location = new System.Drawing.Point(9, 32);
            this.label30.Name = "label30";
            this.label30.Size = new System.Drawing.Size(53, 12);
            this.label30.TabIndex = 0;
            this.label30.Text = "Acc PWD:";
            // 
            // gbGen2SecuredLock
            // 
            this.gbGen2SecuredLock.Controls.Add(this.btnGen2SecLock);
            this.gbGen2SecuredLock.Controls.Add(this.cbGen2SecLock_Membank);
            this.gbGen2SecuredLock.Controls.Add(this.cbGen2SecLock_Level);
            this.gbGen2SecuredLock.Controls.Add(this.tbGen2SecLock_PWD);
            this.gbGen2SecuredLock.Controls.Add(this.label26);
            this.gbGen2SecuredLock.Controls.Add(this.label27);
            this.gbGen2SecuredLock.Controls.Add(this.label28);
            this.gbGen2SecuredLock.Location = new System.Drawing.Point(18, 261);
            this.gbGen2SecuredLock.Name = "gbGen2SecuredLock";
            this.gbGen2SecuredLock.Size = new System.Drawing.Size(475, 90);
            this.gbGen2SecuredLock.TabIndex = 0;
            this.gbGen2SecuredLock.TabStop = false;
            this.gbGen2SecuredLock.Text = " Gen2 Secured Lock";
            // 
            // btnGen2SecLock
            // 
            this.btnGen2SecLock.BackColor = System.Drawing.Color.DarkKhaki;
            this.btnGen2SecLock.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGen2SecLock.Location = new System.Drawing.Point(368, 34);
            this.btnGen2SecLock.Name = "btnGen2SecLock";
            this.btnGen2SecLock.Size = new System.Drawing.Size(85, 40);
            this.btnGen2SecLock.TabIndex = 3;
            this.btnGen2SecLock.Text = "SecLock";
            this.btnGen2SecLock.UseVisualStyleBackColor = false;
            this.btnGen2SecLock.Click += new System.EventHandler(this.btnGen2SecLock_Click);
            // 
            // cbGen2SecLock_Membank
            // 
            this.cbGen2SecLock_Membank.FormattingEnabled = true;
            this.cbGen2SecLock_Membank.Items.AddRange(new object[] {
            "User",
            "TID",
            "EPC",
            "Access Pwd",
            "Kill Pwd"});
            this.cbGen2SecLock_Membank.Location = new System.Drawing.Point(74, 24);
            this.cbGen2SecLock_Membank.Name = "cbGen2SecLock_Membank";
            this.cbGen2SecLock_Membank.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecLock_Membank.TabIndex = 2;
            // 
            // cbGen2SecLock_Level
            // 
            this.cbGen2SecLock_Level.FormattingEnabled = true;
            this.cbGen2SecLock_Level.Items.AddRange(new object[] {
            "Unlock",
            "Unlock Forever",
            "Secure Lock",
            "Lock Forever"});
            this.cbGen2SecLock_Level.Location = new System.Drawing.Point(74, 61);
            this.cbGen2SecLock_Level.Name = "cbGen2SecLock_Level";
            this.cbGen2SecLock_Level.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecLock_Level.TabIndex = 2;
            // 
            // tbGen2SecLock_PWD
            // 
            this.tbGen2SecLock_PWD.Location = new System.Drawing.Point(247, 24);
            this.tbGen2SecLock_PWD.Name = "tbGen2SecLock_PWD";
            this.tbGen2SecLock_PWD.Size = new System.Drawing.Size(100, 21);
            this.tbGen2SecLock_PWD.TabIndex = 1;
            this.tbGen2SecLock_PWD.Text = "00000000";
            // 
            // label26
            // 
            this.label26.AutoSize = true;
            this.label26.Location = new System.Drawing.Point(9, 29);
            this.label26.Name = "label26";
            this.label26.Size = new System.Drawing.Size(53, 12);
            this.label26.TabIndex = 0;
            this.label26.Text = "Membank:";
            // 
            // label27
            // 
            this.label27.AutoSize = true;
            this.label27.Location = new System.Drawing.Point(9, 63);
            this.label27.Name = "label27";
            this.label27.Size = new System.Drawing.Size(41, 12);
            this.label27.TabIndex = 0;
            this.label27.Text = "Level:";
            // 
            // label28
            // 
            this.label28.AutoSize = true;
            this.label28.Location = new System.Drawing.Point(183, 29);
            this.label28.Name = "label28";
            this.label28.Size = new System.Drawing.Size(53, 12);
            this.label28.TabIndex = 0;
            this.label28.Text = "Acc PWD:";
            // 
            // gbGen2SecuredWrite
            // 
            this.gbGen2SecuredWrite.Controls.Add(this.btnGen2SecWrite);
            this.gbGen2SecuredWrite.Controls.Add(this.cbGen2SecWrite_Membank);
            this.gbGen2SecuredWrite.Controls.Add(this.cbGen2SecWrite_WordAdr);
            this.gbGen2SecuredWrite.Controls.Add(this.tbGen2SecWrite_Value);
            this.gbGen2SecuredWrite.Controls.Add(this.tbGen2SecWrite_PWD);
            this.gbGen2SecuredWrite.Controls.Add(this.label21);
            this.gbGen2SecuredWrite.Controls.Add(this.label22);
            this.gbGen2SecuredWrite.Controls.Add(this.label23);
            this.gbGen2SecuredWrite.Controls.Add(this.label24);
            this.gbGen2SecuredWrite.Location = new System.Drawing.Point(18, 150);
            this.gbGen2SecuredWrite.Name = "gbGen2SecuredWrite";
            this.gbGen2SecuredWrite.Size = new System.Drawing.Size(475, 91);
            this.gbGen2SecuredWrite.TabIndex = 0;
            this.gbGen2SecuredWrite.TabStop = false;
            this.gbGen2SecuredWrite.Text = " Gen2 Secured Write";
            // 
            // btnGen2SecWrite
            // 
            this.btnGen2SecWrite.BackColor = System.Drawing.Color.DarkKhaki;
            this.btnGen2SecWrite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGen2SecWrite.Location = new System.Drawing.Point(368, 15);
            this.btnGen2SecWrite.Name = "btnGen2SecWrite";
            this.btnGen2SecWrite.Size = new System.Drawing.Size(85, 40);
            this.btnGen2SecWrite.TabIndex = 3;
            this.btnGen2SecWrite.Text = "SecWrite";
            this.btnGen2SecWrite.UseVisualStyleBackColor = false;
            this.btnGen2SecWrite.Click += new System.EventHandler(this.btnGen2SecWrite_Click);
            // 
            // cbGen2SecWrite_Membank
            // 
            this.cbGen2SecWrite_Membank.FormattingEnabled = true;
            this.cbGen2SecWrite_Membank.Items.AddRange(new object[] {
            "RESERVE",
            "EPC",
            "TID",
            "USER"});
            this.cbGen2SecWrite_Membank.Location = new System.Drawing.Point(74, 25);
            this.cbGen2SecWrite_Membank.Name = "cbGen2SecWrite_Membank";
            this.cbGen2SecWrite_Membank.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecWrite_Membank.TabIndex = 2;
            // 
            // cbGen2SecWrite_WordAdr
            // 
            this.cbGen2SecWrite_WordAdr.FormattingEnabled = true;
            this.cbGen2SecWrite_WordAdr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8"});
            this.cbGen2SecWrite_WordAdr.Location = new System.Drawing.Point(74, 62);
            this.cbGen2SecWrite_WordAdr.Name = "cbGen2SecWrite_WordAdr";
            this.cbGen2SecWrite_WordAdr.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecWrite_WordAdr.TabIndex = 2;
            // 
            // tbGen2SecWrite_Value
            // 
            this.tbGen2SecWrite_Value.Location = new System.Drawing.Point(247, 60);
            this.tbGen2SecWrite_Value.Name = "tbGen2SecWrite_Value";
            this.tbGen2SecWrite_Value.Size = new System.Drawing.Size(206, 21);
            this.tbGen2SecWrite_Value.TabIndex = 1;
            this.tbGen2SecWrite_Value.TextChanged += new System.EventHandler(this.tbGen2SecWrite_Value_TextChanged);
            // 
            // tbGen2SecWrite_PWD
            // 
            this.tbGen2SecWrite_PWD.Location = new System.Drawing.Point(247, 25);
            this.tbGen2SecWrite_PWD.Name = "tbGen2SecWrite_PWD";
            this.tbGen2SecWrite_PWD.Size = new System.Drawing.Size(100, 21);
            this.tbGen2SecWrite_PWD.TabIndex = 1;
            this.tbGen2SecWrite_PWD.Text = "00000000";
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Location = new System.Drawing.Point(183, 66);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(41, 12);
            this.label21.TabIndex = 0;
            this.label21.Text = "Value:";
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(9, 28);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(53, 12);
            this.label22.TabIndex = 0;
            this.label22.Text = "Membank:";
            // 
            // label23
            // 
            this.label23.AutoSize = true;
            this.label23.Location = new System.Drawing.Point(9, 66);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(65, 12);
            this.label23.TabIndex = 0;
            this.label23.Text = "Word Addr:";
            // 
            // label24
            // 
            this.label24.AutoSize = true;
            this.label24.Location = new System.Drawing.Point(183, 28);
            this.label24.Name = "label24";
            this.label24.Size = new System.Drawing.Size(53, 12);
            this.label24.TabIndex = 0;
            this.label24.Text = "Acc PWD:";
            // 
            // gbGen2SelectConfig
            // 
            this.gbGen2SelectConfig.Controls.Add(this.rbMatch);
            this.gbGen2SelectConfig.Controls.Add(this.rbDisMatch);
            this.gbGen2SelectConfig.Controls.Add(this.btnGen2SelectConfig);
            this.gbGen2SelectConfig.Controls.Add(this.cbGen2SelectConfig_BitLength);
            this.gbGen2SelectConfig.Controls.Add(this.cbGen2SelectConfig_BitAddr);
            this.gbGen2SelectConfig.Controls.Add(this.cbGen2SelectConfig_Membank);
            this.gbGen2SelectConfig.Controls.Add(this.tbGen2SelectConfig_Value);
            this.gbGen2SelectConfig.Controls.Add(this.label25);
            this.gbGen2SelectConfig.Controls.Add(this.label33);
            this.gbGen2SelectConfig.Controls.Add(this.label29);
            this.gbGen2SelectConfig.Controls.Add(this.label31);
            this.gbGen2SelectConfig.Controls.Add(this.label32);
            this.gbGen2SelectConfig.Location = new System.Drawing.Point(18, 453);
            this.gbGen2SelectConfig.Name = "gbGen2SelectConfig";
            this.gbGen2SelectConfig.Size = new System.Drawing.Size(475, 124);
            this.gbGen2SelectConfig.TabIndex = 0;
            this.gbGen2SelectConfig.TabStop = false;
            this.gbGen2SelectConfig.Text = "Gen2 Select Config";
            // 
            // rbMatch
            // 
            this.rbMatch.AutoSize = true;
            this.rbMatch.Checked = true;
            this.rbMatch.Location = new System.Drawing.Point(69, 26);
            this.rbMatch.Name = "rbMatch";
            this.rbMatch.Size = new System.Drawing.Size(53, 16);
            this.rbMatch.TabIndex = 4;
            this.rbMatch.TabStop = true;
            this.rbMatch.Text = "Match";
            this.rbMatch.UseVisualStyleBackColor = true;
            // 
            // rbDisMatch
            // 
            this.rbDisMatch.AutoSize = true;
            this.rbDisMatch.Location = new System.Drawing.Point(185, 26);
            this.rbDisMatch.Name = "rbDisMatch";
            this.rbDisMatch.Size = new System.Drawing.Size(71, 16);
            this.rbDisMatch.TabIndex = 4;
            this.rbDisMatch.Text = "DisMatch";
            this.rbDisMatch.UseVisualStyleBackColor = true;
            // 
            // btnGen2SelectConfig
            // 
            this.btnGen2SelectConfig.BackColor = System.Drawing.Color.DarkKhaki;
            this.btnGen2SelectConfig.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGen2SelectConfig.Location = new System.Drawing.Point(368, 36);
            this.btnGen2SelectConfig.Name = "btnGen2SelectConfig";
            this.btnGen2SelectConfig.Size = new System.Drawing.Size(85, 40);
            this.btnGen2SelectConfig.TabIndex = 3;
            this.btnGen2SelectConfig.Text = "Config";
            this.btnGen2SelectConfig.UseVisualStyleBackColor = false;
            this.btnGen2SelectConfig.Click += new System.EventHandler(this.btnGen2SelectConfig_Click);
            // 
            // cbGen2SelectConfig_BitLength
            // 
            this.cbGen2SelectConfig_BitLength.FormattingEnabled = true;
            this.cbGen2SelectConfig_BitLength.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16"});
            this.cbGen2SelectConfig_BitLength.Location = new System.Drawing.Point(76, 93);
            this.cbGen2SelectConfig_BitLength.Name = "cbGen2SelectConfig_BitLength";
            this.cbGen2SelectConfig_BitLength.Size = new System.Drawing.Size(98, 20);
            this.cbGen2SelectConfig_BitLength.TabIndex = 2;
            // 
            // cbGen2SelectConfig_BitAddr
            // 
            this.cbGen2SelectConfig_BitAddr.FormattingEnabled = true;
            this.cbGen2SelectConfig_BitAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8"});
            this.cbGen2SelectConfig_BitAddr.Location = new System.Drawing.Point(247, 58);
            this.cbGen2SelectConfig_BitAddr.Name = "cbGen2SelectConfig_BitAddr";
            this.cbGen2SelectConfig_BitAddr.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SelectConfig_BitAddr.TabIndex = 2;
            // 
            // cbGen2SelectConfig_Membank
            // 
            this.cbGen2SelectConfig_Membank.FormattingEnabled = true;
            this.cbGen2SelectConfig_Membank.Items.AddRange(new object[] {
            "RESERVE",
            "EPC",
            "TID",
            "USER"});
            this.cbGen2SelectConfig_Membank.Location = new System.Drawing.Point(76, 59);
            this.cbGen2SelectConfig_Membank.Name = "cbGen2SelectConfig_Membank";
            this.cbGen2SelectConfig_Membank.Size = new System.Drawing.Size(98, 20);
            this.cbGen2SelectConfig_Membank.TabIndex = 2;
            // 
            // tbGen2SelectConfig_Value
            // 
            this.tbGen2SelectConfig_Value.Location = new System.Drawing.Point(247, 91);
            this.tbGen2SelectConfig_Value.Name = "tbGen2SelectConfig_Value";
            this.tbGen2SelectConfig_Value.Size = new System.Drawing.Size(206, 21);
            this.tbGen2SelectConfig_Value.TabIndex = 1;
            this.tbGen2SelectConfig_Value.Text = "0";
            this.tbGen2SelectConfig_Value.TextChanged += new System.EventHandler(this.tbGen2SelectConfig_Value_TextChanged);
            // 
            // label25
            // 
            this.label25.AutoSize = true;
            this.label25.Location = new System.Drawing.Point(9, 95);
            this.label25.Name = "label25";
            this.label25.Size = new System.Drawing.Size(71, 12);
            this.label25.TabIndex = 0;
            this.label25.Text = "WordLength:";
            // 
            // label33
            // 
            this.label33.AutoSize = true;
            this.label33.Location = new System.Drawing.Point(9, 26);
            this.label33.Name = "label33";
            this.label33.Size = new System.Drawing.Size(47, 12);
            this.label33.TabIndex = 0;
            this.label33.Text = "Action:";
            // 
            // label29
            // 
            this.label29.AutoSize = true;
            this.label29.Location = new System.Drawing.Point(9, 61);
            this.label29.Name = "label29";
            this.label29.Size = new System.Drawing.Size(53, 12);
            this.label29.TabIndex = 0;
            this.label29.Text = "Membank:";
            // 
            // label31
            // 
            this.label31.AutoSize = true;
            this.label31.Location = new System.Drawing.Point(183, 61);
            this.label31.Name = "label31";
            this.label31.Size = new System.Drawing.Size(65, 12);
            this.label31.TabIndex = 0;
            this.label31.Text = "Word Addr:";
            // 
            // label32
            // 
            this.label32.AutoSize = true;
            this.label32.Location = new System.Drawing.Point(183, 95);
            this.label32.Name = "label32";
            this.label32.Size = new System.Drawing.Size(41, 12);
            this.label32.TabIndex = 0;
            this.label32.Text = "Value:";
            // 
            // gbGen2SecuredRead
            // 
            this.gbGen2SecuredRead.Controls.Add(this.btnGen2SecRead);
            this.gbGen2SecuredRead.Controls.Add(this.cbGen2SecRead_WordCnt);
            this.gbGen2SecuredRead.Controls.Add(this.cbGen2SecRead_WordAddr);
            this.gbGen2SecuredRead.Controls.Add(this.tbGen2SecRead_Value);
            this.gbGen2SecuredRead.Controls.Add(this.cbGen2SecRead_Membank);
            this.gbGen2SecuredRead.Controls.Add(this.tbGen2SecRead_PWD);
            this.gbGen2SecuredRead.Controls.Add(this.label34);
            this.gbGen2SecuredRead.Controls.Add(this.label20);
            this.gbGen2SecuredRead.Controls.Add(this.label18);
            this.gbGen2SecuredRead.Controls.Add(this.label19);
            this.gbGen2SecuredRead.Controls.Add(this.label17);
            this.gbGen2SecuredRead.Location = new System.Drawing.Point(18, 8);
            this.gbGen2SecuredRead.Name = "gbGen2SecuredRead";
            this.gbGen2SecuredRead.Size = new System.Drawing.Size(475, 122);
            this.gbGen2SecuredRead.TabIndex = 0;
            this.gbGen2SecuredRead.TabStop = false;
            this.gbGen2SecuredRead.Text = " Gen2 Secured Read";
            // 
            // btnGen2SecRead
            // 
            this.btnGen2SecRead.BackColor = System.Drawing.Color.DarkKhaki;
            this.btnGen2SecRead.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGen2SecRead.Location = new System.Drawing.Point(368, 31);
            this.btnGen2SecRead.Name = "btnGen2SecRead";
            this.btnGen2SecRead.Size = new System.Drawing.Size(85, 40);
            this.btnGen2SecRead.TabIndex = 3;
            this.btnGen2SecRead.Text = "SecRead";
            this.btnGen2SecRead.UseVisualStyleBackColor = false;
            this.btnGen2SecRead.Click += new System.EventHandler(this.btnGen2SecRead_Click);
            // 
            // cbGen2SecRead_WordCnt
            // 
            this.cbGen2SecRead_WordCnt.FormattingEnabled = true;
            this.cbGen2SecRead_WordCnt.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8"});
            this.cbGen2SecRead_WordCnt.Location = new System.Drawing.Point(247, 61);
            this.cbGen2SecRead_WordCnt.Name = "cbGen2SecRead_WordCnt";
            this.cbGen2SecRead_WordCnt.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecRead_WordCnt.TabIndex = 2;
            // 
            // cbGen2SecRead_WordAddr
            // 
            this.cbGen2SecRead_WordAddr.FormattingEnabled = true;
            this.cbGen2SecRead_WordAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8"});
            this.cbGen2SecRead_WordAddr.Location = new System.Drawing.Point(247, 24);
            this.cbGen2SecRead_WordAddr.Name = "cbGen2SecRead_WordAddr";
            this.cbGen2SecRead_WordAddr.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecRead_WordAddr.TabIndex = 2;
            // 
            // tbGen2SecRead_Value
            // 
            this.tbGen2SecRead_Value.Location = new System.Drawing.Point(73, 92);
            this.tbGen2SecRead_Value.Name = "tbGen2SecRead_Value";
            this.tbGen2SecRead_Value.Size = new System.Drawing.Size(274, 21);
            this.tbGen2SecRead_Value.TabIndex = 1;
            // 
            // cbGen2SecRead_Membank
            // 
            this.cbGen2SecRead_Membank.FormattingEnabled = true;
            this.cbGen2SecRead_Membank.Items.AddRange(new object[] {
            "RESERVE",
            "EPC",
            "TID",
            "USER"});
            this.cbGen2SecRead_Membank.Location = new System.Drawing.Point(74, 60);
            this.cbGen2SecRead_Membank.Name = "cbGen2SecRead_Membank";
            this.cbGen2SecRead_Membank.Size = new System.Drawing.Size(100, 20);
            this.cbGen2SecRead_Membank.TabIndex = 2;
            // 
            // tbGen2SecRead_PWD
            // 
            this.tbGen2SecRead_PWD.Location = new System.Drawing.Point(74, 24);
            this.tbGen2SecRead_PWD.Name = "tbGen2SecRead_PWD";
            this.tbGen2SecRead_PWD.Size = new System.Drawing.Size(100, 21);
            this.tbGen2SecRead_PWD.TabIndex = 1;
            this.tbGen2SecRead_PWD.Text = "00000000";
            // 
            // label34
            // 
            this.label34.AutoSize = true;
            this.label34.Location = new System.Drawing.Point(9, 98);
            this.label34.Name = "label34";
            this.label34.Size = new System.Drawing.Size(41, 12);
            this.label34.TabIndex = 0;
            this.label34.Text = "Value:";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(183, 64);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(53, 12);
            this.label20.TabIndex = 0;
            this.label20.Text = "WordCnt:";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(9, 64);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(53, 12);
            this.label18.TabIndex = 0;
            this.label18.Text = "Membank:";
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(183, 27);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(65, 12);
            this.label19.TabIndex = 0;
            this.label19.Text = "Word Addr:";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(9, 27);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(53, 12);
            this.label17.TabIndex = 0;
            this.label17.Text = "Acc PWD:";
            // 
            // tabPage_6B
            // 
            this.tabPage_6B.Controls.Add(this.panelIsoMultiTagRead);
            this.tabPage_6B.Controls.Add(this.panelISOIdentify);
            this.tabPage_6B.Controls.Add(this.panelIsoSingleTag);
            this.tabPage_6B.Controls.Add(this.linLISOMultiTagRead);
            this.tabPage_6B.Controls.Add(this.linLISOIdentify);
            this.tabPage_6B.Controls.Add(this.linLISOSingleTag);
            this.tabPage_6B.Location = new System.Drawing.Point(4, 21);
            this.tabPage_6B.Name = "tabPage_6B";
            this.tabPage_6B.Size = new System.Drawing.Size(927, 595);
            this.tabPage_6B.TabIndex = 2;
            this.tabPage_6B.Text = "ISO 6B";
            this.tabPage_6B.UseVisualStyleBackColor = true;
            // 
            // panelIsoMultiTagRead
            // 
            this.panelIsoMultiTagRead.Controls.Add(this.livIsoMultiTagRead);
            this.panelIsoMultiTagRead.Controls.Add(this.btnIsoMultiTagRead);
            this.panelIsoMultiTagRead.Controls.Add(this.cbIsoMultiTagRead_StartAddr);
            this.panelIsoMultiTagRead.Controls.Add(this.label35);
            this.panelIsoMultiTagRead.Location = new System.Drawing.Point(103, 8);
            this.panelIsoMultiTagRead.Name = "panelIsoMultiTagRead";
            this.panelIsoMultiTagRead.Size = new System.Drawing.Size(820, 578);
            this.panelIsoMultiTagRead.TabIndex = 2;
            // 
            // livIsoMultiTagRead
            // 
            this.livIsoMultiTagRead.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader17,
            this.columnHeader18,
            this.columnHeader19,
            this.columnHeader20});
            this.livIsoMultiTagRead.Location = new System.Drawing.Point(24, 61);
            this.livIsoMultiTagRead.Name = "livIsoMultiTagRead";
            this.livIsoMultiTagRead.Size = new System.Drawing.Size(789, 471);
            this.livIsoMultiTagRead.TabIndex = 3;
            this.livIsoMultiTagRead.UseCompatibleStateImageBehavior = false;
            this.livIsoMultiTagRead.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader17
            // 
            this.columnHeader17.Text = "No.";
            // 
            // columnHeader18
            // 
            this.columnHeader18.Text = "AnteNo.";
            this.columnHeader18.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // columnHeader19
            // 
            this.columnHeader19.Text = "Data";
            this.columnHeader19.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader19.Width = 403;
            // 
            // columnHeader20
            // 
            this.columnHeader20.Text = "Times";
            this.columnHeader20.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // btnIsoMultiTagRead
            // 
            this.btnIsoMultiTagRead.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btnIsoMultiTagRead.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoMultiTagRead.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnIsoMultiTagRead.Location = new System.Drawing.Point(239, 14);
            this.btnIsoMultiTagRead.Name = "btnIsoMultiTagRead";
            this.btnIsoMultiTagRead.Size = new System.Drawing.Size(114, 38);
            this.btnIsoMultiTagRead.TabIndex = 2;
            this.btnIsoMultiTagRead.Text = "Read";
            this.btnIsoMultiTagRead.UseVisualStyleBackColor = false;
            this.btnIsoMultiTagRead.Click += new System.EventHandler(this.btnIsoMultiTagRead_Click);
            // 
            // cbIsoMultiTagRead_StartAddr
            // 
            this.cbIsoMultiTagRead_StartAddr.FormattingEnabled = true;
            this.cbIsoMultiTagRead_StartAddr.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16"});
            this.cbIsoMultiTagRead_StartAddr.Location = new System.Drawing.Point(93, 26);
            this.cbIsoMultiTagRead_StartAddr.Name = "cbIsoMultiTagRead_StartAddr";
            this.cbIsoMultiTagRead_StartAddr.Size = new System.Drawing.Size(93, 20);
            this.cbIsoMultiTagRead_StartAddr.TabIndex = 1;
            // 
            // label35
            // 
            this.label35.AutoSize = true;
            this.label35.Location = new System.Drawing.Point(22, 29);
            this.label35.Name = "label35";
            this.label35.Size = new System.Drawing.Size(65, 12);
            this.label35.TabIndex = 0;
            this.label35.Text = "StartAddr:";
            // 
            // panelISOIdentify
            // 
            this.panelISOIdentify.Controls.Add(this.btnISOIdentify);
            this.panelISOIdentify.Controls.Add(this.livISOIdentify);
            this.panelISOIdentify.Location = new System.Drawing.Point(104, 10);
            this.panelISOIdentify.Name = "panelISOIdentify";
            this.panelISOIdentify.Size = new System.Drawing.Size(812, 572);
            this.panelISOIdentify.TabIndex = 0;
            // 
            // btnISOIdentify
            // 
            this.btnISOIdentify.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btnISOIdentify.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnISOIdentify.Location = new System.Drawing.Point(687, 502);
            this.btnISOIdentify.Name = "btnISOIdentify";
            this.btnISOIdentify.Size = new System.Drawing.Size(105, 53);
            this.btnISOIdentify.TabIndex = 1;
            this.btnISOIdentify.Text = "Identify";
            this.btnISOIdentify.UseVisualStyleBackColor = false;
            this.btnISOIdentify.Click += new System.EventHandler(this.btnISOIdentify_Click);
            // 
            // livISOIdentify
            // 
            this.livISOIdentify.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader13,
            this.columnHeader14,
            this.columnHeader15,
            this.columnHeader16});
            this.livISOIdentify.Location = new System.Drawing.Point(23, 18);
            this.livISOIdentify.Name = "livISOIdentify";
            this.livISOIdentify.Size = new System.Drawing.Size(769, 480);
            this.livISOIdentify.TabIndex = 0;
            this.livISOIdentify.UseCompatibleStateImageBehavior = false;
            this.livISOIdentify.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader13
            // 
            this.columnHeader13.Text = "NO.";
            // 
            // columnHeader14
            // 
            this.columnHeader14.Text = "AnteNo.";
            this.columnHeader14.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // columnHeader15
            // 
            this.columnHeader15.Text = "ID";
            this.columnHeader15.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader15.Width = 349;
            // 
            // columnHeader16
            // 
            this.columnHeader16.Text = "Times";
            this.columnHeader16.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // panelIsoSingleTag
            // 
            this.panelIsoSingleTag.Controls.Add(this.gbIsoQueryLock);
            this.panelIsoSingleTag.Controls.Add(this.gbIsoLock);
            this.panelIsoSingleTag.Controls.Add(this.gbIsoRead);
            this.panelIsoSingleTag.Controls.Add(this.gbIsoWrite);
            this.panelIsoSingleTag.Location = new System.Drawing.Point(103, 7);
            this.panelIsoSingleTag.Name = "panelIsoSingleTag";
            this.panelIsoSingleTag.Size = new System.Drawing.Size(820, 575);
            this.panelIsoSingleTag.TabIndex = 4;
            // 
            // gbIsoQueryLock
            // 
            this.gbIsoQueryLock.Controls.Add(this.numIsoQueryLock_Addr);
            this.gbIsoQueryLock.Controls.Add(this.btnIsoQueryLockWithUID);
            this.gbIsoQueryLock.Controls.Add(this.btnIsoQueryLock);
            this.gbIsoQueryLock.Controls.Add(this.tbIsoQueryLock_UID);
            this.gbIsoQueryLock.Controls.Add(this.tbIsoQueryLock_Res);
            this.gbIsoQueryLock.Controls.Add(this.label43);
            this.gbIsoQueryLock.Controls.Add(this.label46);
            this.gbIsoQueryLock.Controls.Add(this.label45);
            this.gbIsoQueryLock.Location = new System.Drawing.Point(8, 332);
            this.gbIsoQueryLock.Name = "gbIsoQueryLock";
            this.gbIsoQueryLock.Size = new System.Drawing.Size(419, 88);
            this.gbIsoQueryLock.TabIndex = 0;
            this.gbIsoQueryLock.TabStop = false;
            this.gbIsoQueryLock.Text = "ISO Query Lock";
            // 
            // numIsoQueryLock_Addr
            // 
            this.numIsoQueryLock_Addr.Location = new System.Drawing.Point(61, 20);
            this.numIsoQueryLock_Addr.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.numIsoQueryLock_Addr.Name = "numIsoQueryLock_Addr";
            this.numIsoQueryLock_Addr.Size = new System.Drawing.Size(48, 21);
            this.numIsoQueryLock_Addr.TabIndex = 1;
            this.numIsoQueryLock_Addr.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // btnIsoQueryLockWithUID
            // 
            this.btnIsoQueryLockWithUID.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoQueryLockWithUID.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoQueryLockWithUID.Location = new System.Drawing.Point(308, 15);
            this.btnIsoQueryLockWithUID.Name = "btnIsoQueryLockWithUID";
            this.btnIsoQueryLockWithUID.Size = new System.Drawing.Size(97, 27);
            this.btnIsoQueryLockWithUID.TabIndex = 3;
            this.btnIsoQueryLockWithUID.Text = "QueryWithUID";
            this.btnIsoQueryLockWithUID.UseVisualStyleBackColor = false;
            this.btnIsoQueryLockWithUID.Visible = false;
            this.btnIsoQueryLockWithUID.Click += new System.EventHandler(this.btnIsoQueryLockWithUID_Click);
            // 
            // btnIsoQueryLock
            // 
            this.btnIsoQueryLock.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoQueryLock.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoQueryLock.Location = new System.Drawing.Point(308, 52);
            this.btnIsoQueryLock.Name = "btnIsoQueryLock";
            this.btnIsoQueryLock.Size = new System.Drawing.Size(97, 27);
            this.btnIsoQueryLock.TabIndex = 3;
            this.btnIsoQueryLock.Text = "Query";
            this.btnIsoQueryLock.UseVisualStyleBackColor = false;
            this.btnIsoQueryLock.Click += new System.EventHandler(this.btnIsoQueryLock_Click);
            // 
            // tbIsoQueryLock_UID
            // 
            this.tbIsoQueryLock_UID.Location = new System.Drawing.Point(145, 22);
            this.tbIsoQueryLock_UID.Name = "tbIsoQueryLock_UID";
            this.tbIsoQueryLock_UID.Size = new System.Drawing.Size(134, 21);
            this.tbIsoQueryLock_UID.TabIndex = 2;
            // 
            // tbIsoQueryLock_Res
            // 
            this.tbIsoQueryLock_Res.Location = new System.Drawing.Point(61, 61);
            this.tbIsoQueryLock_Res.Name = "tbIsoQueryLock_Res";
            this.tbIsoQueryLock_Res.Size = new System.Drawing.Size(218, 21);
            this.tbIsoQueryLock_Res.TabIndex = 2;
            // 
            // label43
            // 
            this.label43.AutoSize = true;
            this.label43.Location = new System.Drawing.Point(119, 25);
            this.label43.Name = "label43";
            this.label43.Size = new System.Drawing.Size(29, 12);
            this.label43.TabIndex = 0;
            this.label43.Text = "UID:";
            // 
            // label46
            // 
            this.label46.AutoSize = true;
            this.label46.Location = new System.Drawing.Point(7, 64);
            this.label46.Name = "label46";
            this.label46.Size = new System.Drawing.Size(47, 12);
            this.label46.TabIndex = 0;
            this.label46.Text = "Result:";
            // 
            // label45
            // 
            this.label45.AutoSize = true;
            this.label45.Location = new System.Drawing.Point(7, 25);
            this.label45.Name = "label45";
            this.label45.Size = new System.Drawing.Size(53, 12);
            this.label45.TabIndex = 0;
            this.label45.Text = "Address:";
            // 
            // gbIsoLock
            // 
            this.gbIsoLock.Controls.Add(this.numIsoLock_Addr);
            this.gbIsoLock.Controls.Add(this.btnIsoLockWithUID);
            this.gbIsoLock.Controls.Add(this.btnIsoLock);
            this.gbIsoLock.Controls.Add(this.tbIsoLock_UID);
            this.gbIsoLock.Controls.Add(this.tbIsoLock_Res);
            this.gbIsoLock.Controls.Add(this.label42);
            this.gbIsoLock.Controls.Add(this.label47);
            this.gbIsoLock.Controls.Add(this.label44);
            this.gbIsoLock.Location = new System.Drawing.Point(8, 223);
            this.gbIsoLock.Name = "gbIsoLock";
            this.gbIsoLock.Size = new System.Drawing.Size(419, 88);
            this.gbIsoLock.TabIndex = 0;
            this.gbIsoLock.TabStop = false;
            this.gbIsoLock.Text = "ISO Lock";
            // 
            // numIsoLock_Addr
            // 
            this.numIsoLock_Addr.Location = new System.Drawing.Point(61, 23);
            this.numIsoLock_Addr.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.numIsoLock_Addr.Name = "numIsoLock_Addr";
            this.numIsoLock_Addr.Size = new System.Drawing.Size(48, 21);
            this.numIsoLock_Addr.TabIndex = 1;
            this.numIsoLock_Addr.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // btnIsoLockWithUID
            // 
            this.btnIsoLockWithUID.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoLockWithUID.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoLockWithUID.Location = new System.Drawing.Point(308, 15);
            this.btnIsoLockWithUID.Name = "btnIsoLockWithUID";
            this.btnIsoLockWithUID.Size = new System.Drawing.Size(97, 27);
            this.btnIsoLockWithUID.TabIndex = 3;
            this.btnIsoLockWithUID.Text = "LockWithUID";
            this.btnIsoLockWithUID.UseVisualStyleBackColor = false;
            this.btnIsoLockWithUID.Visible = false;
            this.btnIsoLockWithUID.Click += new System.EventHandler(this.btnIsoLockWithUID_Click);
            // 
            // btnIsoLock
            // 
            this.btnIsoLock.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoLock.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoLock.Location = new System.Drawing.Point(308, 52);
            this.btnIsoLock.Name = "btnIsoLock";
            this.btnIsoLock.Size = new System.Drawing.Size(97, 27);
            this.btnIsoLock.TabIndex = 3;
            this.btnIsoLock.Text = "Lock";
            this.btnIsoLock.UseVisualStyleBackColor = false;
            this.btnIsoLock.Click += new System.EventHandler(this.btnIsoLock_Click);
            // 
            // tbIsoLock_UID
            // 
            this.tbIsoLock_UID.Location = new System.Drawing.Point(145, 25);
            this.tbIsoLock_UID.Name = "tbIsoLock_UID";
            this.tbIsoLock_UID.Size = new System.Drawing.Size(134, 21);
            this.tbIsoLock_UID.TabIndex = 2;
            // 
            // tbIsoLock_Res
            // 
            this.tbIsoLock_Res.Location = new System.Drawing.Point(61, 61);
            this.tbIsoLock_Res.Name = "tbIsoLock_Res";
            this.tbIsoLock_Res.Size = new System.Drawing.Size(218, 21);
            this.tbIsoLock_Res.TabIndex = 2;
            // 
            // label42
            // 
            this.label42.AutoSize = true;
            this.label42.Location = new System.Drawing.Point(119, 28);
            this.label42.Name = "label42";
            this.label42.Size = new System.Drawing.Size(29, 12);
            this.label42.TabIndex = 0;
            this.label42.Text = "UID:";
            // 
            // label47
            // 
            this.label47.AutoSize = true;
            this.label47.Location = new System.Drawing.Point(7, 64);
            this.label47.Name = "label47";
            this.label47.Size = new System.Drawing.Size(47, 12);
            this.label47.TabIndex = 0;
            this.label47.Text = "Result:";
            // 
            // label44
            // 
            this.label44.AutoSize = true;
            this.label44.Location = new System.Drawing.Point(7, 25);
            this.label44.Name = "label44";
            this.label44.Size = new System.Drawing.Size(53, 12);
            this.label44.TabIndex = 0;
            this.label44.Text = "Address:";
            // 
            // gbIsoRead
            // 
            this.gbIsoRead.Controls.Add(this.numIsoRead_Addr);
            this.gbIsoRead.Controls.Add(this.btnIsoReadWithUID);
            this.gbIsoRead.Controls.Add(this.btnIsoRead);
            this.gbIsoRead.Controls.Add(this.tbIsoRead_UID);
            this.gbIsoRead.Controls.Add(this.tbIsoRead_Result);
            this.gbIsoRead.Controls.Add(this.label39);
            this.gbIsoRead.Controls.Add(this.label40);
            this.gbIsoRead.Controls.Add(this.label41);
            this.gbIsoRead.Location = new System.Drawing.Point(8, 110);
            this.gbIsoRead.Name = "gbIsoRead";
            this.gbIsoRead.Size = new System.Drawing.Size(419, 88);
            this.gbIsoRead.TabIndex = 0;
            this.gbIsoRead.TabStop = false;
            this.gbIsoRead.Text = "ISO Read";
            // 
            // numIsoRead_Addr
            // 
            this.numIsoRead_Addr.Location = new System.Drawing.Point(61, 22);
            this.numIsoRead_Addr.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.numIsoRead_Addr.Name = "numIsoRead_Addr";
            this.numIsoRead_Addr.Size = new System.Drawing.Size(48, 21);
            this.numIsoRead_Addr.TabIndex = 1;
            this.numIsoRead_Addr.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // btnIsoReadWithUID
            // 
            this.btnIsoReadWithUID.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoReadWithUID.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoReadWithUID.Location = new System.Drawing.Point(308, 15);
            this.btnIsoReadWithUID.Name = "btnIsoReadWithUID";
            this.btnIsoReadWithUID.Size = new System.Drawing.Size(97, 27);
            this.btnIsoReadWithUID.TabIndex = 3;
            this.btnIsoReadWithUID.Text = "ReadWithUID";
            this.btnIsoReadWithUID.UseVisualStyleBackColor = false;
            this.btnIsoReadWithUID.Click += new System.EventHandler(this.btnIsoReadWithUID_Click);
            // 
            // btnIsoRead
            // 
            this.btnIsoRead.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoRead.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoRead.Location = new System.Drawing.Point(308, 52);
            this.btnIsoRead.Name = "btnIsoRead";
            this.btnIsoRead.Size = new System.Drawing.Size(97, 27);
            this.btnIsoRead.TabIndex = 3;
            this.btnIsoRead.Text = "Read";
            this.btnIsoRead.UseVisualStyleBackColor = false;
            this.btnIsoRead.Click += new System.EventHandler(this.btnIsoRead_Click);
            // 
            // tbIsoRead_UID
            // 
            this.tbIsoRead_UID.Location = new System.Drawing.Point(145, 21);
            this.tbIsoRead_UID.Name = "tbIsoRead_UID";
            this.tbIsoRead_UID.Size = new System.Drawing.Size(134, 21);
            this.tbIsoRead_UID.TabIndex = 2;
            // 
            // tbIsoRead_Result
            // 
            this.tbIsoRead_Result.Location = new System.Drawing.Point(61, 58);
            this.tbIsoRead_Result.Name = "tbIsoRead_Result";
            this.tbIsoRead_Result.Size = new System.Drawing.Size(218, 21);
            this.tbIsoRead_Result.TabIndex = 2;
            // 
            // label39
            // 
            this.label39.AutoSize = true;
            this.label39.Location = new System.Drawing.Point(119, 25);
            this.label39.Name = "label39";
            this.label39.Size = new System.Drawing.Size(29, 12);
            this.label39.TabIndex = 0;
            this.label39.Text = "UID:";
            // 
            // label40
            // 
            this.label40.AutoSize = true;
            this.label40.Location = new System.Drawing.Point(7, 61);
            this.label40.Name = "label40";
            this.label40.Size = new System.Drawing.Size(47, 12);
            this.label40.TabIndex = 0;
            this.label40.Text = "Result:";
            // 
            // label41
            // 
            this.label41.AutoSize = true;
            this.label41.Location = new System.Drawing.Point(7, 25);
            this.label41.Name = "label41";
            this.label41.Size = new System.Drawing.Size(53, 12);
            this.label41.TabIndex = 0;
            this.label41.Text = "Address:";
            // 
            // gbIsoWrite
            // 
            this.gbIsoWrite.Controls.Add(this.numIsoWrite_Addr);
            this.gbIsoWrite.Controls.Add(this.btnWriteWithUID);
            this.gbIsoWrite.Controls.Add(this.btnIsoWrite);
            this.gbIsoWrite.Controls.Add(this.tbIsoWrite_UID);
            this.gbIsoWrite.Controls.Add(this.tbIsoWrite_Value);
            this.gbIsoWrite.Controls.Add(this.label38);
            this.gbIsoWrite.Controls.Add(this.label37);
            this.gbIsoWrite.Controls.Add(this.label36);
            this.gbIsoWrite.Location = new System.Drawing.Point(8, 1);
            this.gbIsoWrite.Name = "gbIsoWrite";
            this.gbIsoWrite.Size = new System.Drawing.Size(419, 88);
            this.gbIsoWrite.TabIndex = 0;
            this.gbIsoWrite.TabStop = false;
            this.gbIsoWrite.Text = "ISO Write";
            // 
            // numIsoWrite_Addr
            // 
            this.numIsoWrite_Addr.Location = new System.Drawing.Point(61, 23);
            this.numIsoWrite_Addr.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.numIsoWrite_Addr.Name = "numIsoWrite_Addr";
            this.numIsoWrite_Addr.Size = new System.Drawing.Size(48, 21);
            this.numIsoWrite_Addr.TabIndex = 1;
            this.numIsoWrite_Addr.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // btnWriteWithUID
            // 
            this.btnWriteWithUID.BackColor = System.Drawing.Color.LightSalmon;
            this.btnWriteWithUID.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnWriteWithUID.Location = new System.Drawing.Point(308, 15);
            this.btnWriteWithUID.Name = "btnWriteWithUID";
            this.btnWriteWithUID.Size = new System.Drawing.Size(97, 27);
            this.btnWriteWithUID.TabIndex = 3;
            this.btnWriteWithUID.Text = "WriteWithUID";
            this.btnWriteWithUID.UseVisualStyleBackColor = false;
            this.btnWriteWithUID.Click += new System.EventHandler(this.btnWriteWithUID_Click);
            // 
            // btnIsoWrite
            // 
            this.btnIsoWrite.BackColor = System.Drawing.Color.LightSalmon;
            this.btnIsoWrite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnIsoWrite.Location = new System.Drawing.Point(308, 52);
            this.btnIsoWrite.Name = "btnIsoWrite";
            this.btnIsoWrite.Size = new System.Drawing.Size(97, 27);
            this.btnIsoWrite.TabIndex = 3;
            this.btnIsoWrite.Text = "Write";
            this.btnIsoWrite.UseVisualStyleBackColor = false;
            this.btnIsoWrite.Click += new System.EventHandler(this.btnIsoWrite_Click);
            // 
            // tbIsoWrite_UID
            // 
            this.tbIsoWrite_UID.Location = new System.Drawing.Point(145, 21);
            this.tbIsoWrite_UID.Name = "tbIsoWrite_UID";
            this.tbIsoWrite_UID.Size = new System.Drawing.Size(134, 21);
            this.tbIsoWrite_UID.TabIndex = 2;
            // 
            // tbIsoWrite_Value
            // 
            this.tbIsoWrite_Value.Location = new System.Drawing.Point(61, 58);
            this.tbIsoWrite_Value.Name = "tbIsoWrite_Value";
            this.tbIsoWrite_Value.Size = new System.Drawing.Size(218, 21);
            this.tbIsoWrite_Value.TabIndex = 2;
            this.tbIsoWrite_Value.TextChanged += new System.EventHandler(this.tbIsoWrite_Value_TextChanged);
            // 
            // label38
            // 
            this.label38.AutoSize = true;
            this.label38.Location = new System.Drawing.Point(119, 25);
            this.label38.Name = "label38";
            this.label38.Size = new System.Drawing.Size(29, 12);
            this.label38.TabIndex = 0;
            this.label38.Text = "UID:";
            // 
            // label37
            // 
            this.label37.AutoSize = true;
            this.label37.Location = new System.Drawing.Point(7, 61);
            this.label37.Name = "label37";
            this.label37.Size = new System.Drawing.Size(41, 12);
            this.label37.TabIndex = 0;
            this.label37.Text = "Value:";
            // 
            // label36
            // 
            this.label36.AutoSize = true;
            this.label36.Location = new System.Drawing.Point(7, 25);
            this.label36.Name = "label36";
            this.label36.Size = new System.Drawing.Size(53, 12);
            this.label36.TabIndex = 0;
            this.label36.Text = "Address:";
            // 
            // linLISOMultiTagRead
            // 
            this.linLISOMultiTagRead.AutoSize = true;
            this.linLISOMultiTagRead.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.linLISOMultiTagRead.Location = new System.Drawing.Point(1, 245);
            this.linLISOMultiTagRead.Name = "linLISOMultiTagRead";
            this.linLISOMultiTagRead.Size = new System.Drawing.Size(103, 14);
            this.linLISOMultiTagRead.TabIndex = 1;
            this.linLISOMultiTagRead.TabStop = true;
            this.linLISOMultiTagRead.Text = "MultiTagRead";
            this.linLISOMultiTagRead.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linLISOMultiTagRead_LinkClicked);
            // 
            // linLISOIdentify
            // 
            this.linLISOIdentify.AutoSize = true;
            this.linLISOIdentify.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.linLISOIdentify.Location = new System.Drawing.Point(11, 65);
            this.linLISOIdentify.Name = "linLISOIdentify";
            this.linLISOIdentify.Size = new System.Drawing.Size(71, 14);
            this.linLISOIdentify.TabIndex = 1;
            this.linLISOIdentify.TabStop = true;
            this.linLISOIdentify.Text = "Identify";
            this.linLISOIdentify.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linLISOIdentify_LinkClicked);
            // 
            // linLISOSingleTag
            // 
            this.linLISOSingleTag.AutoSize = true;
            this.linLISOSingleTag.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.linLISOSingleTag.Location = new System.Drawing.Point(3, 155);
            this.linLISOSingleTag.Name = "linLISOSingleTag";
            this.linLISOSingleTag.Size = new System.Drawing.Size(79, 14);
            this.linLISOSingleTag.TabIndex = 1;
            this.linLISOSingleTag.TabStop = true;
            this.linLISOSingleTag.Text = "SingleTag";
            this.linLISOSingleTag.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linLISOSingleTag_LinkClicked);
            // 
            // tabPage_Settings
            // 
            this.tabPage_Settings.Controls.Add(this.groupBox10);
            this.tabPage_Settings.Controls.Add(this.groupBox9);
            this.tabPage_Settings.Controls.Add(this.groupBox8);
            this.tabPage_Settings.Controls.Add(this.groupBox7);
            this.tabPage_Settings.Controls.Add(this.groupBox5);
            this.tabPage_Settings.Controls.Add(this.btnResetReader);
            this.tabPage_Settings.Controls.Add(this.groupBox2);
            this.tabPage_Settings.Controls.Add(this.groupBox4);
            this.tabPage_Settings.Controls.Add(this.groupBox3);
            this.tabPage_Settings.Controls.Add(this.groupBox1);
            this.tabPage_Settings.Location = new System.Drawing.Point(4, 21);
            this.tabPage_Settings.Name = "tabPage_Settings";
            this.tabPage_Settings.Size = new System.Drawing.Size(927, 595);
            this.tabPage_Settings.TabIndex = 3;
            this.tabPage_Settings.Text = "Settings";
            this.tabPage_Settings.UseVisualStyleBackColor = true;
            // 
            // groupBox10
            // 
            this.groupBox10.Controls.Add(this.rbBuzzerOFF);
            this.groupBox10.Controls.Add(this.btnSetBuzzer);
            this.groupBox10.Controls.Add(this.btnGetBuzzer);
            this.groupBox10.Controls.Add(this.rbBuzzerON);
            this.groupBox10.Location = new System.Drawing.Point(15, 477);
            this.groupBox10.Name = "groupBox10";
            this.groupBox10.Size = new System.Drawing.Size(429, 107);
            this.groupBox10.TabIndex = 8;
            this.groupBox10.TabStop = false;
            this.groupBox10.Text = "Buzzer and LED Setting";
            // 
            // rbBuzzerOFF
            // 
            this.rbBuzzerOFF.AutoSize = true;
            this.rbBuzzerOFF.Location = new System.Drawing.Point(263, 15);
            this.rbBuzzerOFF.Name = "rbBuzzerOFF";
            this.rbBuzzerOFF.Size = new System.Drawing.Size(41, 16);
            this.rbBuzzerOFF.TabIndex = 0;
            this.rbBuzzerOFF.Text = "OFF";
            this.rbBuzzerOFF.UseVisualStyleBackColor = true;
            // 
            // btnSetBuzzer
            // 
            this.btnSetBuzzer.BackColor = System.Drawing.Color.Tan;
            this.btnSetBuzzer.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetBuzzer.Location = new System.Drawing.Point(250, 56);
            this.btnSetBuzzer.Name = "btnSetBuzzer";
            this.btnSetBuzzer.Size = new System.Drawing.Size(86, 42);
            this.btnSetBuzzer.TabIndex = 2;
            this.btnSetBuzzer.Text = "Set";
            this.btnSetBuzzer.UseVisualStyleBackColor = false;
            this.btnSetBuzzer.Click += new System.EventHandler(this.btnSetBuzzer_Click);
            // 
            // btnGetBuzzer
            // 
            this.btnGetBuzzer.BackColor = System.Drawing.Color.Tan;
            this.btnGetBuzzer.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetBuzzer.Location = new System.Drawing.Point(94, 56);
            this.btnGetBuzzer.Name = "btnGetBuzzer";
            this.btnGetBuzzer.Size = new System.Drawing.Size(86, 42);
            this.btnGetBuzzer.TabIndex = 2;
            this.btnGetBuzzer.Text = "Get";
            this.btnGetBuzzer.UseVisualStyleBackColor = false;
            this.btnGetBuzzer.Click += new System.EventHandler(this.btnGetBuzzer_Click);
            // 
            // rbBuzzerON
            // 
            this.rbBuzzerON.AutoSize = true;
            this.rbBuzzerON.Checked = true;
            this.rbBuzzerON.Location = new System.Drawing.Point(123, 20);
            this.rbBuzzerON.Name = "rbBuzzerON";
            this.rbBuzzerON.Size = new System.Drawing.Size(35, 16);
            this.rbBuzzerON.TabIndex = 0;
            this.rbBuzzerON.TabStop = true;
            this.rbBuzzerON.Text = "ON";
            this.rbBuzzerON.UseVisualStyleBackColor = true;
            // 
            // groupBox9
            // 
            this.groupBox9.Controls.Add(this.rbFreq_Others);
            this.groupBox9.Controls.Add(this.rbFreq_Europe);
            this.groupBox9.Controls.Add(this.rbFreq_NAmerica);
            this.groupBox9.Controls.Add(this.rbFreq_China);
            this.groupBox9.Controls.Add(this.checkedlibFrePoint);
            this.groupBox9.Controls.Add(this.label66);
            this.groupBox9.Controls.Add(this.btnGetFrequency);
            this.groupBox9.Controls.Add(this.lbFreqPoints);
            this.groupBox9.Controls.Add(this.btnSetFrequency);
            this.groupBox9.Location = new System.Drawing.Point(481, 14);
            this.groupBox9.Name = "groupBox9";
            this.groupBox9.Size = new System.Drawing.Size(382, 205);
            this.groupBox9.TabIndex = 7;
            this.groupBox9.TabStop = false;
            this.groupBox9.Text = "Frequency Setting";
            // 
            // rbFreq_Others
            // 
            this.rbFreq_Others.AutoSize = true;
            this.rbFreq_Others.Location = new System.Drawing.Point(8, 149);
            this.rbFreq_Others.Name = "rbFreq_Others";
            this.rbFreq_Others.Size = new System.Drawing.Size(59, 16);
            this.rbFreq_Others.TabIndex = 4;
            this.rbFreq_Others.Text = "Others";
            this.rbFreq_Others.UseVisualStyleBackColor = true;
            this.rbFreq_Others.CheckedChanged += new System.EventHandler(this.rbFreq_Others_CheckedChanged);
            // 
            // rbFreq_Europe
            // 
            this.rbFreq_Europe.AutoSize = true;
            this.rbFreq_Europe.Location = new System.Drawing.Point(7, 113);
            this.rbFreq_Europe.Name = "rbFreq_Europe";
            this.rbFreq_Europe.Size = new System.Drawing.Size(59, 16);
            this.rbFreq_Europe.TabIndex = 4;
            this.rbFreq_Europe.Text = "Europe";
            this.rbFreq_Europe.UseVisualStyleBackColor = true;
            // 
            // rbFreq_NAmerica
            // 
            this.rbFreq_NAmerica.AutoSize = true;
            this.rbFreq_NAmerica.Location = new System.Drawing.Point(7, 79);
            this.rbFreq_NAmerica.Name = "rbFreq_NAmerica";
            this.rbFreq_NAmerica.Size = new System.Drawing.Size(101, 16);
            this.rbFreq_NAmerica.TabIndex = 4;
            this.rbFreq_NAmerica.Text = "North America";
            this.rbFreq_NAmerica.UseVisualStyleBackColor = true;
            // 
            // rbFreq_China
            // 
            this.rbFreq_China.AutoSize = true;
            this.rbFreq_China.Checked = true;
            this.rbFreq_China.Location = new System.Drawing.Point(7, 44);
            this.rbFreq_China.Name = "rbFreq_China";
            this.rbFreq_China.Size = new System.Drawing.Size(53, 16);
            this.rbFreq_China.TabIndex = 4;
            this.rbFreq_China.TabStop = true;
            this.rbFreq_China.Text = "China";
            this.rbFreq_China.UseVisualStyleBackColor = true;
            // 
            // checkedlibFrePoint
            // 
            this.checkedlibFrePoint.FormattingEnabled = true;
            this.checkedlibFrePoint.Items.AddRange(new object[] {
            "900",
            "900.5",
            "901",
            "901.5",
            "902",
            "902.5",
            "903",
            "903.5",
            "904",
            "904.5",
            "905",
            "905.5",
            "906",
            "906.5",
            "907",
            "907.5",
            "908",
            "908.5",
            "909",
            "909.5",
            "910",
            "910.5",
            "911",
            "911.5",
            "912",
            "912.5",
            "913",
            "913.5",
            "914",
            "914.5",
            "915",
            "915.5",
            "916",
            "916.5",
            "917",
            "917.5",
            "918",
            "918.5",
            "919",
            "919.5",
            "920",
            "920.5",
            "921",
            "921.5",
            "922",
            "922.5",
            "923",
            "923.5",
            "924",
            "924.5",
            "925",
            "925.5",
            "926",
            "926.5",
            "927",
            "927.5",
            "928",
            "928.5",
            "929",
            "929.5",
            "930"});
            this.checkedlibFrePoint.Location = new System.Drawing.Point(109, 35);
            this.checkedlibFrePoint.Name = "checkedlibFrePoint";
            this.checkedlibFrePoint.Size = new System.Drawing.Size(94, 164);
            this.checkedlibFrePoint.TabIndex = 3;
            this.checkedlibFrePoint.Visible = false;
            // 
            // label66
            // 
            this.label66.AutoSize = true;
            this.label66.Location = new System.Drawing.Point(5, 17);
            this.label66.Name = "label66";
            this.label66.Size = new System.Drawing.Size(95, 12);
            this.label66.TabIndex = 1;
            this.label66.Text = "Frequency Type:";
            // 
            // btnGetFrequency
            // 
            this.btnGetFrequency.BackColor = System.Drawing.Color.Tan;
            this.btnGetFrequency.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetFrequency.Location = new System.Drawing.Point(253, 44);
            this.btnGetFrequency.Name = "btnGetFrequency";
            this.btnGetFrequency.Size = new System.Drawing.Size(86, 42);
            this.btnGetFrequency.TabIndex = 2;
            this.btnGetFrequency.Text = "Get";
            this.btnGetFrequency.UseVisualStyleBackColor = false;
            this.btnGetFrequency.Click += new System.EventHandler(this.btnGetFrequency_Click);
            // 
            // lbFreqPoints
            // 
            this.lbFreqPoints.AutoSize = true;
            this.lbFreqPoints.Location = new System.Drawing.Point(118, 19);
            this.lbFreqPoints.Name = "lbFreqPoints";
            this.lbFreqPoints.Size = new System.Drawing.Size(77, 12);
            this.lbFreqPoints.TabIndex = 1;
            this.lbFreqPoints.Text = "Freq Points:";
            this.lbFreqPoints.Visible = false;
            // 
            // btnSetFrequency
            // 
            this.btnSetFrequency.BackColor = System.Drawing.Color.Tan;
            this.btnSetFrequency.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetFrequency.Location = new System.Drawing.Point(253, 115);
            this.btnSetFrequency.Name = "btnSetFrequency";
            this.btnSetFrequency.Size = new System.Drawing.Size(86, 42);
            this.btnSetFrequency.TabIndex = 2;
            this.btnSetFrequency.Text = "Set";
            this.btnSetFrequency.UseVisualStyleBackColor = false;
            this.btnSetFrequency.Click += new System.EventHandler(this.btnSetFrequency_Click);
            // 
            // groupBox8
            // 
            this.groupBox8.Controls.Add(this.tbTCPPara_GateWay);
            this.groupBox8.Controls.Add(this.tbTCPPara_Mask);
            this.groupBox8.Controls.Add(this.btnGetTCPPara);
            this.groupBox8.Controls.Add(this.btnSetTCPPara);
            this.groupBox8.Controls.Add(this.tbTCPPara_IP);
            this.groupBox8.Controls.Add(this.label63);
            this.groupBox8.Controls.Add(this.label62);
            this.groupBox8.Controls.Add(this.label61);
            this.groupBox8.Location = new System.Drawing.Point(481, 239);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Size = new System.Drawing.Size(382, 149);
            this.groupBox8.TabIndex = 6;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "TCP Parameter Setting";
            // 
            // tbTCPPara_GateWay
            // 
            this.tbTCPPara_GateWay.Location = new System.Drawing.Point(89, 109);
            this.tbTCPPara_GateWay.Name = "tbTCPPara_GateWay";
            this.tbTCPPara_GateWay.Size = new System.Drawing.Size(138, 21);
            this.tbTCPPara_GateWay.TabIndex = 2;
            // 
            // tbTCPPara_Mask
            // 
            this.tbTCPPara_Mask.Location = new System.Drawing.Point(89, 71);
            this.tbTCPPara_Mask.Name = "tbTCPPara_Mask";
            this.tbTCPPara_Mask.Size = new System.Drawing.Size(138, 21);
            this.tbTCPPara_Mask.TabIndex = 2;
            // 
            // btnGetTCPPara
            // 
            this.btnGetTCPPara.BackColor = System.Drawing.Color.Tan;
            this.btnGetTCPPara.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetTCPPara.Location = new System.Drawing.Point(253, 33);
            this.btnGetTCPPara.Name = "btnGetTCPPara";
            this.btnGetTCPPara.Size = new System.Drawing.Size(86, 42);
            this.btnGetTCPPara.TabIndex = 2;
            this.btnGetTCPPara.Text = "Get";
            this.btnGetTCPPara.UseVisualStyleBackColor = false;
            this.btnGetTCPPara.Click += new System.EventHandler(this.btnGetTCPPara_Click);
            // 
            // btnSetTCPPara
            // 
            this.btnSetTCPPara.BackColor = System.Drawing.Color.Tan;
            this.btnSetTCPPara.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetTCPPara.Location = new System.Drawing.Point(253, 90);
            this.btnSetTCPPara.Name = "btnSetTCPPara";
            this.btnSetTCPPara.Size = new System.Drawing.Size(86, 42);
            this.btnSetTCPPara.TabIndex = 2;
            this.btnSetTCPPara.Text = "Set";
            this.btnSetTCPPara.UseVisualStyleBackColor = false;
            this.btnSetTCPPara.Click += new System.EventHandler(this.btnSetTCPPara_Click);
            // 
            // tbTCPPara_IP
            // 
            this.tbTCPPara_IP.Location = new System.Drawing.Point(89, 33);
            this.tbTCPPara_IP.MaxLength = 16;
            this.tbTCPPara_IP.Name = "tbTCPPara_IP";
            this.tbTCPPara_IP.Size = new System.Drawing.Size(138, 21);
            this.tbTCPPara_IP.TabIndex = 2;
            // 
            // label63
            // 
            this.label63.AutoSize = true;
            this.label63.Location = new System.Drawing.Point(30, 114);
            this.label63.Name = "label63";
            this.label63.Size = new System.Drawing.Size(53, 12);
            this.label63.TabIndex = 1;
            this.label63.Text = "GateWay:";
            // 
            // label62
            // 
            this.label62.AutoSize = true;
            this.label62.Location = new System.Drawing.Point(6, 76);
            this.label62.Name = "label62";
            this.label62.Size = new System.Drawing.Size(77, 12);
            this.label62.TabIndex = 1;
            this.label62.Text = "Subnet Mask:";
            // 
            // label61
            // 
            this.label61.AutoSize = true;
            this.label61.Location = new System.Drawing.Point(60, 37);
            this.label61.Name = "label61";
            this.label61.Size = new System.Drawing.Size(23, 12);
            this.label61.TabIndex = 1;
            this.label61.Text = "IP:";
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.cbIOLevel);
            this.groupBox7.Controls.Add(this.cbIOPort);
            this.groupBox7.Controls.Add(this.btnSetOutPort);
            this.groupBox7.Controls.Add(this.label60);
            this.groupBox7.Controls.Add(this.label59);
            this.groupBox7.Location = new System.Drawing.Point(481, 408);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(382, 100);
            this.groupBox7.TabIndex = 5;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "OutPort Setting";
            // 
            // cbIOLevel
            // 
            this.cbIOLevel.FormattingEnabled = true;
            this.cbIOLevel.Items.AddRange(new object[] {
            "Low/OFF",
            "High/ON"});
            this.cbIOLevel.Location = new System.Drawing.Point(89, 63);
            this.cbIOLevel.Name = "cbIOLevel";
            this.cbIOLevel.Size = new System.Drawing.Size(76, 20);
            this.cbIOLevel.TabIndex = 3;
            // 
            // cbIOPort
            // 
            this.cbIOPort.FormattingEnabled = true;
            this.cbIOPort.Items.AddRange(new object[] {
            "0",
            "1",
            "2"});
            this.cbIOPort.Location = new System.Drawing.Point(89, 26);
            this.cbIOPort.Name = "cbIOPort";
            this.cbIOPort.Size = new System.Drawing.Size(76, 20);
            this.cbIOPort.TabIndex = 3;
            // 
            // btnSetOutPort
            // 
            this.btnSetOutPort.BackColor = System.Drawing.Color.Tan;
            this.btnSetOutPort.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetOutPort.Location = new System.Drawing.Point(253, 35);
            this.btnSetOutPort.Name = "btnSetOutPort";
            this.btnSetOutPort.Size = new System.Drawing.Size(86, 42);
            this.btnSetOutPort.TabIndex = 2;
            this.btnSetOutPort.Text = "Set";
            this.btnSetOutPort.UseVisualStyleBackColor = false;
            this.btnSetOutPort.Click += new System.EventHandler(this.btnSetOutPort_Click);
            // 
            // label60
            // 
            this.label60.AutoSize = true;
            this.label60.Location = new System.Drawing.Point(42, 65);
            this.label60.Name = "label60";
            this.label60.Size = new System.Drawing.Size(41, 12);
            this.label60.TabIndex = 1;
            this.label60.Text = "Level:";
            // 
            // label59
            // 
            this.label59.AutoSize = true;
            this.label59.Location = new System.Drawing.Point(30, 29);
            this.label59.Name = "label59";
            this.label59.Size = new System.Drawing.Size(53, 12);
            this.label59.TabIndex = 1;
            this.label59.Text = "IO Port:";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.rbMultiFastTagMode);
            this.groupBox5.Controls.Add(this.rbSingleFastTagMode);
            this.groupBox5.Controls.Add(this.btnGetTagMode);
            this.groupBox5.Controls.Add(this.btnSetTagMode);
            this.groupBox5.Location = new System.Drawing.Point(15, 366);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(429, 105);
            this.groupBox5.TabIndex = 4;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Working Mode Setting";
            // 
            // rbMultiFastTagMode
            // 
            this.rbMultiFastTagMode.AutoSize = true;
            this.rbMultiFastTagMode.Location = new System.Drawing.Point(195, 26);
            this.rbMultiFastTagMode.Name = "rbMultiFastTagMode";
            this.rbMultiFastTagMode.Size = new System.Drawing.Size(107, 16);
            this.rbMultiFastTagMode.TabIndex = 0;
            this.rbMultiFastTagMode.Text = "Favor quantity";
            this.rbMultiFastTagMode.UseVisualStyleBackColor = true;
            // 
            // rbSingleFastTagMode
            // 
            this.rbSingleFastTagMode.AutoSize = true;
            this.rbSingleFastTagMode.Checked = true;
            this.rbSingleFastTagMode.Location = new System.Drawing.Point(29, 26);
            this.rbSingleFastTagMode.Name = "rbSingleFastTagMode";
            this.rbSingleFastTagMode.Size = new System.Drawing.Size(89, 16);
            this.rbSingleFastTagMode.TabIndex = 0;
            this.rbSingleFastTagMode.TabStop = true;
            this.rbSingleFastTagMode.Text = "Favor speed";
            this.rbSingleFastTagMode.UseVisualStyleBackColor = true;
            // 
            // btnGetTagMode
            // 
            this.btnGetTagMode.BackColor = System.Drawing.Color.Tan;
            this.btnGetTagMode.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetTagMode.Location = new System.Drawing.Point(94, 50);
            this.btnGetTagMode.Name = "btnGetTagMode";
            this.btnGetTagMode.Size = new System.Drawing.Size(86, 42);
            this.btnGetTagMode.TabIndex = 2;
            this.btnGetTagMode.Text = "Get";
            this.btnGetTagMode.UseVisualStyleBackColor = false;
            this.btnGetTagMode.Click += new System.EventHandler(this.btnGetTagMode_Click);
            // 
            // btnSetTagMode
            // 
            this.btnSetTagMode.BackColor = System.Drawing.Color.Tan;
            this.btnSetTagMode.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetTagMode.Location = new System.Drawing.Point(250, 50);
            this.btnSetTagMode.Name = "btnSetTagMode";
            this.btnSetTagMode.Size = new System.Drawing.Size(86, 42);
            this.btnSetTagMode.TabIndex = 2;
            this.btnSetTagMode.Text = "Set";
            this.btnSetTagMode.UseVisualStyleBackColor = false;
            this.btnSetTagMode.Click += new System.EventHandler(this.btnSetTagMode_Click);
            // 
            // btnResetReader
            // 
            this.btnResetReader.BackColor = System.Drawing.Color.Tan;
            this.btnResetReader.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnResetReader.Location = new System.Drawing.Point(634, 523);
            this.btnResetReader.Name = "btnResetReader";
            this.btnResetReader.Size = new System.Drawing.Size(120, 52);
            this.btnResetReader.TabIndex = 2;
            this.btnResetReader.Text = "ReSet Reader";
            this.btnResetReader.UseVisualStyleBackColor = false;
            this.btnResetReader.Click += new System.EventHandler(this.btnResetReader_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnGetFirmVersion);
            this.groupBox2.Controls.Add(this.lbFirmVersion);
            this.groupBox2.Controls.Add(this.label51);
            this.groupBox2.Location = new System.Drawing.Point(13, 14);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(431, 68);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Get Firmware Version";
            // 
            // btnGetFirmVersion
            // 
            this.btnGetFirmVersion.BackColor = System.Drawing.Color.Tan;
            this.btnGetFirmVersion.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetFirmVersion.Location = new System.Drawing.Point(250, 17);
            this.btnGetFirmVersion.Name = "btnGetFirmVersion";
            this.btnGetFirmVersion.Size = new System.Drawing.Size(86, 42);
            this.btnGetFirmVersion.TabIndex = 2;
            this.btnGetFirmVersion.Text = "Get";
            this.btnGetFirmVersion.UseVisualStyleBackColor = false;
            this.btnGetFirmVersion.Click += new System.EventHandler(this.btnGetFirmVersion_Click);
            // 
            // lbFirmVersion
            // 
            this.lbFirmVersion.AutoSize = true;
            this.lbFirmVersion.Location = new System.Drawing.Point(120, 31);
            this.lbFirmVersion.Name = "lbFirmVersion";
            this.lbFirmVersion.Size = new System.Drawing.Size(23, 12);
            this.lbFirmVersion.TabIndex = 1;
            this.lbFirmVersion.Text = "1.0";
            // 
            // label51
            // 
            this.label51.AutoSize = true;
            this.label51.Location = new System.Drawing.Point(40, 31);
            this.label51.Name = "label51";
            this.label51.Size = new System.Drawing.Size(77, 12);
            this.label51.TabIndex = 1;
            this.label51.Text = "FirmVersion:";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.pbGreen);
            this.groupBox4.Controls.Add(this.pbRed);
            this.groupBox4.Controls.Add(this.pbAnteStatus4);
            this.groupBox4.Controls.Add(this.pbAnteStatus3);
            this.groupBox4.Controls.Add(this.pbAnteStatus2);
            this.groupBox4.Controls.Add(this.pbAnteStatus1);
            this.groupBox4.Controls.Add(this.chbAnte4);
            this.groupBox4.Controls.Add(this.chbAnte3);
            this.groupBox4.Controls.Add(this.chbAnte2);
            this.groupBox4.Controls.Add(this.chbAnte1);
            this.groupBox4.Controls.Add(this.btnSetAnte);
            this.groupBox4.Controls.Add(this.btnGetAnte);
            this.groupBox4.Controls.Add(this.label65);
            this.groupBox4.Controls.Add(this.label64);
            this.groupBox4.Location = new System.Drawing.Point(13, 210);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(431, 143);
            this.groupBox4.TabIndex = 0;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Antennas  Setting";
            // 
            // pbGreen
            // 
            this.pbGreen.BackgroundImage = global::MR6100Demo.Properties.Resources.green;
            this.pbGreen.Location = new System.Drawing.Point(388, 91);
            this.pbGreen.Name = "pbGreen";
            this.pbGreen.Size = new System.Drawing.Size(27, 26);
            this.pbGreen.TabIndex = 4;
            this.pbGreen.TabStop = false;
            this.pbGreen.Visible = false;
            // 
            // pbRed
            // 
            this.pbRed.BackgroundImage = global::MR6100Demo.Properties.Resources.red;
            this.pbRed.Location = new System.Drawing.Point(355, 91);
            this.pbRed.Name = "pbRed";
            this.pbRed.Size = new System.Drawing.Size(27, 26);
            this.pbRed.TabIndex = 4;
            this.pbRed.TabStop = false;
            this.pbRed.Visible = false;
            // 
            // pbAnteStatus4
            // 
            this.pbAnteStatus4.BackgroundImage = global::MR6100Demo.Properties.Resources.red;
            this.pbAnteStatus4.Location = new System.Drawing.Point(355, 51);
            this.pbAnteStatus4.Name = "pbAnteStatus4";
            this.pbAnteStatus4.Size = new System.Drawing.Size(27, 26);
            this.pbAnteStatus4.TabIndex = 4;
            this.pbAnteStatus4.TabStop = false;
            // 
            // pbAnteStatus3
            // 
            this.pbAnteStatus3.BackgroundImage = global::MR6100Demo.Properties.Resources.red;
            this.pbAnteStatus3.Location = new System.Drawing.Point(265, 51);
            this.pbAnteStatus3.Name = "pbAnteStatus3";
            this.pbAnteStatus3.Size = new System.Drawing.Size(27, 26);
            this.pbAnteStatus3.TabIndex = 4;
            this.pbAnteStatus3.TabStop = false;
            // 
            // pbAnteStatus2
            // 
            this.pbAnteStatus2.BackgroundImage = global::MR6100Demo.Properties.Resources.red;
            this.pbAnteStatus2.Location = new System.Drawing.Point(176, 51);
            this.pbAnteStatus2.Name = "pbAnteStatus2";
            this.pbAnteStatus2.Size = new System.Drawing.Size(27, 26);
            this.pbAnteStatus2.TabIndex = 4;
            this.pbAnteStatus2.TabStop = false;
            // 
            // pbAnteStatus1
            // 
            this.pbAnteStatus1.BackgroundImage = global::MR6100Demo.Properties.Resources.red;
            this.pbAnteStatus1.Location = new System.Drawing.Point(89, 51);
            this.pbAnteStatus1.Name = "pbAnteStatus1";
            this.pbAnteStatus1.Size = new System.Drawing.Size(27, 26);
            this.pbAnteStatus1.TabIndex = 4;
            this.pbAnteStatus1.TabStop = false;
            // 
            // chbAnte4
            // 
            this.chbAnte4.AutoSize = true;
            this.chbAnte4.Location = new System.Drawing.Point(350, 27);
            this.chbAnte4.Name = "chbAnte4";
            this.chbAnte4.Size = new System.Drawing.Size(54, 16);
            this.chbAnte4.TabIndex = 3;
            this.chbAnte4.Text = "Ante4";
            this.chbAnte4.UseVisualStyleBackColor = true;
            // 
            // chbAnte3
            // 
            this.chbAnte3.AutoSize = true;
            this.chbAnte3.Location = new System.Drawing.Point(263, 27);
            this.chbAnte3.Name = "chbAnte3";
            this.chbAnte3.Size = new System.Drawing.Size(54, 16);
            this.chbAnte3.TabIndex = 3;
            this.chbAnte3.Text = "Ante3";
            this.chbAnte3.UseVisualStyleBackColor = true;
            // 
            // chbAnte2
            // 
            this.chbAnte2.AutoSize = true;
            this.chbAnte2.Location = new System.Drawing.Point(176, 27);
            this.chbAnte2.Name = "chbAnte2";
            this.chbAnte2.Size = new System.Drawing.Size(54, 16);
            this.chbAnte2.TabIndex = 3;
            this.chbAnte2.Text = "Ante2";
            this.chbAnte2.UseVisualStyleBackColor = true;
            // 
            // chbAnte1
            // 
            this.chbAnte1.AutoSize = true;
            this.chbAnte1.Location = new System.Drawing.Point(89, 27);
            this.chbAnte1.Name = "chbAnte1";
            this.chbAnte1.Size = new System.Drawing.Size(54, 16);
            this.chbAnte1.TabIndex = 3;
            this.chbAnte1.Text = "Ante1";
            this.chbAnte1.UseVisualStyleBackColor = true;
            // 
            // btnSetAnte
            // 
            this.btnSetAnte.BackColor = System.Drawing.Color.Tan;
            this.btnSetAnte.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetAnte.Location = new System.Drawing.Point(250, 85);
            this.btnSetAnte.Name = "btnSetAnte";
            this.btnSetAnte.Size = new System.Drawing.Size(86, 42);
            this.btnSetAnte.TabIndex = 2;
            this.btnSetAnte.Text = "Set";
            this.btnSetAnte.UseVisualStyleBackColor = false;
            this.btnSetAnte.Click += new System.EventHandler(this.btnSetAnte_Click);
            // 
            // btnGetAnte
            // 
            this.btnGetAnte.BackColor = System.Drawing.Color.Tan;
            this.btnGetAnte.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetAnte.Location = new System.Drawing.Point(94, 85);
            this.btnGetAnte.Name = "btnGetAnte";
            this.btnGetAnte.Size = new System.Drawing.Size(86, 42);
            this.btnGetAnte.TabIndex = 2;
            this.btnGetAnte.Text = "Get";
            this.btnGetAnte.UseVisualStyleBackColor = false;
            this.btnGetAnte.Click += new System.EventHandler(this.btnGetAnte_Click);
            // 
            // label65
            // 
            this.label65.AutoSize = true;
            this.label65.Location = new System.Drawing.Point(4, 61);
            this.label65.Name = "label65";
            this.label65.Size = new System.Drawing.Size(77, 12);
            this.label65.TabIndex = 1;
            this.label65.Text = "Ante Status:";
            // 
            // label64
            // 
            this.label64.AutoSize = true;
            this.label64.Location = new System.Drawing.Point(16, 31);
            this.label64.Name = "label64";
            this.label64.Size = new System.Drawing.Size(65, 12);
            this.label64.TabIndex = 1;
            this.label64.Text = "Work Ante:";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.tbPower4);
            this.groupBox3.Controls.Add(this.tbPower2);
            this.groupBox3.Controls.Add(this.tbPower3);
            this.groupBox3.Controls.Add(this.tbPower1);
            this.groupBox3.Controls.Add(this.btnSetPower);
            this.groupBox3.Controls.Add(this.btnGetPower);
            this.groupBox3.Controls.Add(this.label58);
            this.groupBox3.Controls.Add(this.label57);
            this.groupBox3.Controls.Add(this.label54);
            this.groupBox3.Controls.Add(this.label56);
            this.groupBox3.Controls.Add(this.label53);
            this.groupBox3.Controls.Add(this.label55);
            this.groupBox3.Controls.Add(this.label50);
            this.groupBox3.Controls.Add(this.label52);
            this.groupBox3.Location = new System.Drawing.Point(13, 88);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(431, 109);
            this.groupBox3.TabIndex = 0;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Power Setting";
            // 
            // tbPower4
            // 
            this.tbPower4.Location = new System.Drawing.Point(360, 20);
            this.tbPower4.Name = "tbPower4";
            this.tbPower4.Size = new System.Drawing.Size(38, 21);
            this.tbPower4.TabIndex = 3;
            // 
            // tbPower2
            // 
            this.tbPower2.Location = new System.Drawing.Point(150, 20);
            this.tbPower2.Name = "tbPower2";
            this.tbPower2.Size = new System.Drawing.Size(38, 21);
            this.tbPower2.TabIndex = 3;
            // 
            // tbPower3
            // 
            this.tbPower3.Location = new System.Drawing.Point(254, 20);
            this.tbPower3.Name = "tbPower3";
            this.tbPower3.Size = new System.Drawing.Size(38, 21);
            this.tbPower3.TabIndex = 3;
            // 
            // tbPower1
            // 
            this.tbPower1.Location = new System.Drawing.Point(42, 20);
            this.tbPower1.Name = "tbPower1";
            this.tbPower1.Size = new System.Drawing.Size(38, 21);
            this.tbPower1.TabIndex = 3;
            // 
            // btnSetPower
            // 
            this.btnSetPower.BackColor = System.Drawing.Color.Tan;
            this.btnSetPower.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetPower.Location = new System.Drawing.Point(250, 54);
            this.btnSetPower.Name = "btnSetPower";
            this.btnSetPower.Size = new System.Drawing.Size(86, 42);
            this.btnSetPower.TabIndex = 2;
            this.btnSetPower.Text = "Set";
            this.btnSetPower.UseVisualStyleBackColor = false;
            this.btnSetPower.Click += new System.EventHandler(this.btnSetPower_Click);
            // 
            // btnGetPower
            // 
            this.btnGetPower.BackColor = System.Drawing.Color.Tan;
            this.btnGetPower.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetPower.Location = new System.Drawing.Point(94, 54);
            this.btnGetPower.Name = "btnGetPower";
            this.btnGetPower.Size = new System.Drawing.Size(86, 42);
            this.btnGetPower.TabIndex = 2;
            this.btnGetPower.Text = "Get";
            this.btnGetPower.UseVisualStyleBackColor = false;
            this.btnGetPower.Click += new System.EventHandler(this.btnGetPower_Click);
            // 
            // label58
            // 
            this.label58.AutoSize = true;
            this.label58.Location = new System.Drawing.Point(400, 24);
            this.label58.Name = "label58";
            this.label58.Size = new System.Drawing.Size(23, 12);
            this.label58.TabIndex = 1;
            this.label58.Text = "dBm";
            // 
            // label57
            // 
            this.label57.AutoSize = true;
            this.label57.Location = new System.Drawing.Point(322, 24);
            this.label57.Name = "label57";
            this.label57.Size = new System.Drawing.Size(41, 12);
            this.label57.TabIndex = 1;
            this.label57.Text = "Ante4:";
            // 
            // label54
            // 
            this.label54.AutoSize = true;
            this.label54.Location = new System.Drawing.Point(187, 24);
            this.label54.Name = "label54";
            this.label54.Size = new System.Drawing.Size(23, 12);
            this.label54.TabIndex = 1;
            this.label54.Text = "dBm";
            // 
            // label56
            // 
            this.label56.AutoSize = true;
            this.label56.Location = new System.Drawing.Point(292, 24);
            this.label56.Name = "label56";
            this.label56.Size = new System.Drawing.Size(23, 12);
            this.label56.TabIndex = 1;
            this.label56.Text = "dBm";
            // 
            // label53
            // 
            this.label53.AutoSize = true;
            this.label53.Location = new System.Drawing.Point(113, 24);
            this.label53.Name = "label53";
            this.label53.Size = new System.Drawing.Size(41, 12);
            this.label53.TabIndex = 1;
            this.label53.Text = "Ante2:";
            // 
            // label55
            // 
            this.label55.AutoSize = true;
            this.label55.Location = new System.Drawing.Point(216, 24);
            this.label55.Name = "label55";
            this.label55.Size = new System.Drawing.Size(41, 12);
            this.label55.TabIndex = 1;
            this.label55.Text = "Ante3:";
            // 
            // label50
            // 
            this.label50.AutoSize = true;
            this.label50.Location = new System.Drawing.Point(83, 24);
            this.label50.Name = "label50";
            this.label50.Size = new System.Drawing.Size(23, 12);
            this.label50.TabIndex = 1;
            this.label50.Text = "dBm";
            // 
            // label52
            // 
            this.label52.AutoSize = true;
            this.label52.Location = new System.Drawing.Point(5, 24);
            this.label52.Name = "label52";
            this.label52.Size = new System.Drawing.Size(41, 12);
            this.label52.TabIndex = 1;
            this.label52.Text = "Ante1:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnSetBaudRate);
            this.groupBox1.Controls.Add(this.label49);
            this.groupBox1.Controls.Add(this.label48);
            this.groupBox1.Controls.Add(this.cbSettings_BaudRate);
            this.groupBox1.Enabled = false;
            this.groupBox1.Location = new System.Drawing.Point(13, 14);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(220, 68);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "BaudRate Setting";
            this.groupBox1.Visible = false;
            // 
            // btnSetBaudRate
            // 
            this.btnSetBaudRate.BackColor = System.Drawing.Color.Tan;
            this.btnSetBaudRate.Enabled = false;
            this.btnSetBaudRate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSetBaudRate.Location = new System.Drawing.Point(148, 16);
            this.btnSetBaudRate.Name = "btnSetBaudRate";
            this.btnSetBaudRate.Size = new System.Drawing.Size(62, 42);
            this.btnSetBaudRate.TabIndex = 2;
            this.btnSetBaudRate.Text = "Set";
            this.btnSetBaudRate.UseVisualStyleBackColor = false;
            this.btnSetBaudRate.Click += new System.EventHandler(this.btnSetBaudRate_Click);
            // 
            // label49
            // 
            this.label49.AutoSize = true;
            this.label49.Location = new System.Drawing.Point(123, 31);
            this.label49.Name = "label49";
            this.label49.Size = new System.Drawing.Size(23, 12);
            this.label49.TabIndex = 1;
            this.label49.Text = "bps";
            // 
            // label48
            // 
            this.label48.AutoSize = true;
            this.label48.Location = new System.Drawing.Point(6, 31);
            this.label48.Name = "label48";
            this.label48.Size = new System.Drawing.Size(59, 12);
            this.label48.TabIndex = 1;
            this.label48.Text = "BaudRate:";
            // 
            // cbSettings_BaudRate
            // 
            this.cbSettings_BaudRate.FormattingEnabled = true;
            this.cbSettings_BaudRate.Items.AddRange(new object[] {
            "9600",
            "19200",
            "38400",
            "57600",
            "115200"});
            this.cbSettings_BaudRate.Location = new System.Drawing.Point(65, 28);
            this.cbSettings_BaudRate.Name = "cbSettings_BaudRate";
            this.cbSettings_BaudRate.Size = new System.Drawing.Size(58, 20);
            this.cbSettings_BaudRate.TabIndex = 0;
            // 
            // timerGen2Identify
            // 
            this.timerGen2Identify.Interval = 10;
            this.timerGen2Identify.Tick += new System.EventHandler(this.timerInventory_Tick);
            // 
            // timerRate
            // 
            this.timerRate.Interval = 1000;
            this.timerRate.Tick += new System.EventHandler(this.timerRate_Tick);
            // 
            // timerMultiTagRead
            // 
            this.timerMultiTagRead.Tick += new System.EventHandler(this.timerMultiTagRead_Tick);
            // 
            // timerMultiTagWrite
            // 
            this.timerMultiTagWrite.Tick += new System.EventHandler(this.timerMultiTagWrite_Tick);
            // 
            // timerIsoIdentify
            // 
            this.timerIsoIdentify.Interval = 50;
            this.timerIsoIdentify.Tick += new System.EventHandler(this.timerIsoIdentify_Tick);
            // 
            // timerIsoMultiTagRead
            // 
            this.timerIsoMultiTagRead.Tick += new System.EventHandler(this.timerIsoMultiTagRead_Tick);
            // 
            // btnClear
            // 
            this.btnClear.BackColor = System.Drawing.Color.LightBlue;
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnClear.Location = new System.Drawing.Point(70, 601);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(103, 36);
            this.btnClear.TabIndex = 4;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = false;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // timerReconnect
            // 
            this.timerReconnect.Interval = 3000;
            this.timerReconnect.Tick += new System.EventHandler(this.timerReconnect_Tick);
            // 
            // mainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1193, 645);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.tabControl);
            this.Controls.Add(this.libInfo);
            this.Controls.Add(this.gbConnect);
            this.Name = "mainForm";
            this.Text = "MR6100 Demo V1.0";
            this.Load += new System.EventHandler(this.mainForm_Load);
            this.gbConnect.ResumeLayout(false);
            this.gbConnect.PerformLayout();
            this.tabControl.ResumeLayout(false);
            this.tabPage_EPCMultiTag.ResumeLayout(false);
            this.tabPage_EPCMultiTag.PerformLayout();
            this.panelIdentity.ResumeLayout(false);
            this.gbEPCDataAnalysis.ResumeLayout(false);
            this.gbEPCDataAnalysis.PerformLayout();
            this.panelGen2MultiTagRead.ResumeLayout(false);
            this.panelGen2MultiTagRead.PerformLayout();
            this.panelMultiTagWrite.ResumeLayout(false);
            this.panelMultiTagWrite.PerformLayout();
            this.tabPage_EPCSingleTag.ResumeLayout(false);
            this.gbGen2kill.ResumeLayout(false);
            this.gbGen2kill.PerformLayout();
            this.gbGen2SecuredLock.ResumeLayout(false);
            this.gbGen2SecuredLock.PerformLayout();
            this.gbGen2SecuredWrite.ResumeLayout(false);
            this.gbGen2SecuredWrite.PerformLayout();
            this.gbGen2SelectConfig.ResumeLayout(false);
            this.gbGen2SelectConfig.PerformLayout();
            this.gbGen2SecuredRead.ResumeLayout(false);
            this.gbGen2SecuredRead.PerformLayout();
            this.tabPage_6B.ResumeLayout(false);
            this.tabPage_6B.PerformLayout();
            this.panelIsoMultiTagRead.ResumeLayout(false);
            this.panelIsoMultiTagRead.PerformLayout();
            this.panelISOIdentify.ResumeLayout(false);
            this.panelIsoSingleTag.ResumeLayout(false);
            this.gbIsoQueryLock.ResumeLayout(false);
            this.gbIsoQueryLock.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoQueryLock_Addr)).EndInit();
            this.gbIsoLock.ResumeLayout(false);
            this.gbIsoLock.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoLock_Addr)).EndInit();
            this.gbIsoRead.ResumeLayout(false);
            this.gbIsoRead.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoRead_Addr)).EndInit();
            this.gbIsoWrite.ResumeLayout(false);
            this.gbIsoWrite.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numIsoWrite_Addr)).EndInit();
            this.tabPage_Settings.ResumeLayout(false);
            this.groupBox10.ResumeLayout(false);
            this.groupBox10.PerformLayout();
            this.groupBox9.ResumeLayout(false);
            this.groupBox9.PerformLayout();
            this.groupBox8.ResumeLayout(false);
            this.groupBox8.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbGreen)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbAnteStatus1)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbConnect;
        private System.Windows.Forms.TextBox tbIP;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox tbPort;
        private System.Windows.Forms.Button btnDiscon;
        private System.Windows.Forms.ListBox libInfo;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tabPage_EPCMultiTag;
        private System.Windows.Forms.TabPage tabPage_EPCSingleTag;
        private System.Windows.Forms.TabPage tabPage_6B;
        private System.Windows.Forms.Button btnIdentify;
        private ListViewNF livGen2Identify;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.Timer timerGen2Identify;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.GroupBox gbEPCDataAnalysis;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lbTestDuration;
        private System.Windows.Forms.Label lbReadTimes;
        private System.Windows.Forms.Label lbAverageRate;
        private System.Windows.Forms.Label lbPeakRate;
        private System.Windows.Forms.Label lbTotalReads;
        private System.Windows.Forms.Label lbUniqueTags;
        private System.Windows.Forms.Label lbTD;
        private System.Windows.Forms.Label lbRT;
        private System.Windows.Forms.Label lbAR;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Timer timerRate;
        private System.Windows.Forms.Panel panelIdentity;
        private System.Windows.Forms.Panel panelGen2MultiTagRead;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.CheckBox chbUser;
        private System.Windows.Forms.CheckBox chbEPC;
        private System.Windows.Forms.CheckBox chbTID;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.CheckBox chbReserve;
        private ListViewNF livEPCMultiTagRead;
        private System.Windows.Forms.ComboBox cbUserWordCnt;
        private System.Windows.Forms.ComboBox cbUserStartAddr;
        private System.Windows.Forms.ComboBox cbEPCWordCnt;
        private System.Windows.Forms.ComboBox cbEPCStartAddr;
        private System.Windows.Forms.ComboBox cbTIDWordCnt;
        private System.Windows.Forms.ComboBox cbTIDStartAddr;
        private System.Windows.Forms.ComboBox cbResWordCnt;
        private System.Windows.Forms.ComboBox cbResStartAddr;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.Button btnMultiTagRead;
        private System.Windows.Forms.Timer timerMultiTagRead;
        private System.Windows.Forms.Label lbMultiTagReadDuration;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label lbMultiTagReadCnt;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.LinkLabel linLGen2MultiTagRead;
        private System.Windows.Forms.LinkLabel linLGen2MultiTagWrite;
        private System.Windows.Forms.LinkLabel linLGen2Identify;
        private System.Windows.Forms.Panel panelMultiTagWrite;
        private System.Windows.Forms.Button btnMultiTagWrite;
        private System.Windows.Forms.ComboBox cbMEPCWrite_WordLen;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.ComboBox cbMEPCWrite_WordAddr;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.ComboBox cbMEPCWrite_MemBank;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Timer timerMultiTagWrite;
        private ListViewNF livEPCMultiTagWrite;
        private System.Windows.Forms.Label lbMultiTagWriteDuration;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label lbMultiTagWriteCount;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox tbWriteValue_Gen2;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.ColumnHeader columnHeader10;
        private System.Windows.Forms.ColumnHeader columnHeader11;
        private System.Windows.Forms.ColumnHeader columnHeader12;
        private System.Windows.Forms.Button btnIdentify_Once;
        private System.Windows.Forms.GroupBox gbGen2SecuredRead;
        private System.Windows.Forms.ComboBox cbGen2SecRead_WordCnt;
        private System.Windows.Forms.ComboBox cbGen2SecRead_WordAddr;
        private System.Windows.Forms.ComboBox cbGen2SecRead_Membank;
        private System.Windows.Forms.TextBox tbGen2SecRead_PWD;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.GroupBox gbGen2SecuredWrite;
        private System.Windows.Forms.Button btnGen2SecWrite;
        private System.Windows.Forms.ComboBox cbGen2SecWrite_Membank;
        private System.Windows.Forms.ComboBox cbGen2SecWrite_WordAdr;
        private System.Windows.Forms.TextBox tbGen2SecWrite_Value;
        private System.Windows.Forms.TextBox tbGen2SecWrite_PWD;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.Button btnGen2SecRead;
        private System.Windows.Forms.GroupBox gbGen2SecuredLock;
        private System.Windows.Forms.Button btnGen2SecLock;
        private System.Windows.Forms.ComboBox cbGen2SecLock_Membank;
        private System.Windows.Forms.ComboBox cbGen2SecLock_Level;
        private System.Windows.Forms.TextBox tbGen2SecLock_PWD;
        private System.Windows.Forms.Label label26;
        private System.Windows.Forms.Label label27;
        private System.Windows.Forms.Label label28;
        private System.Windows.Forms.GroupBox gbGen2kill;
        private System.Windows.Forms.Button btnGen2Kill;
        private System.Windows.Forms.TextBox tbGen2Kill_PWD;
        private System.Windows.Forms.Label label30;
        private System.Windows.Forms.GroupBox gbGen2SelectConfig;
        private System.Windows.Forms.Button btnGen2SelectConfig;
        private System.Windows.Forms.ComboBox cbGen2SelectConfig_BitLength;
        private System.Windows.Forms.ComboBox cbGen2SelectConfig_BitAddr;
        private System.Windows.Forms.ComboBox cbGen2SelectConfig_Membank;
        private System.Windows.Forms.TextBox tbGen2SelectConfig_Value;
        private System.Windows.Forms.Label label25;
        private System.Windows.Forms.Label label29;
        private System.Windows.Forms.Label label31;
        private System.Windows.Forms.Label label32;
        private System.Windows.Forms.RadioButton rbMatch;
        private System.Windows.Forms.RadioButton rbDisMatch;
        private System.Windows.Forms.Label label33;
        private System.Windows.Forms.TextBox tbGen2SecRead_Value;
        private System.Windows.Forms.Label label34;
        private System.Windows.Forms.Panel panelISOIdentify;
        private ListViewNF livISOIdentify;
        private System.Windows.Forms.ColumnHeader columnHeader13;
        private System.Windows.Forms.ColumnHeader columnHeader14;
        private System.Windows.Forms.ColumnHeader columnHeader15;
        private System.Windows.Forms.ColumnHeader columnHeader16;
        private System.Windows.Forms.LinkLabel linLISOMultiTagRead;
        private System.Windows.Forms.LinkLabel linLISOIdentify;
        private System.Windows.Forms.LinkLabel linLISOSingleTag;
        private System.Windows.Forms.Button btnISOIdentify;
        private System.Windows.Forms.Timer timerIsoIdentify;
        private System.Windows.Forms.Panel panelIsoMultiTagRead;
        private System.Windows.Forms.Button btnIsoMultiTagRead;
        private System.Windows.Forms.ComboBox cbIsoMultiTagRead_StartAddr;
        private System.Windows.Forms.Label label35;
        private System.Windows.Forms.ListView livIsoMultiTagRead;
        private System.Windows.Forms.ColumnHeader columnHeader17;
        private System.Windows.Forms.ColumnHeader columnHeader18;
        private System.Windows.Forms.ColumnHeader columnHeader19;
        private System.Windows.Forms.ColumnHeader columnHeader20;
        private System.Windows.Forms.Timer timerIsoMultiTagRead;
        private System.Windows.Forms.Panel panelIsoSingleTag;
        private System.Windows.Forms.GroupBox gbIsoWrite;
        private System.Windows.Forms.TextBox tbIsoWrite_Value;
        private System.Windows.Forms.Label label37;
        private System.Windows.Forms.Label label36;
        private System.Windows.Forms.Button btnIsoWrite;
        private System.Windows.Forms.Button btnWriteWithUID;
        private System.Windows.Forms.TextBox tbIsoWrite_UID;
        private System.Windows.Forms.Label label38;
        private System.Windows.Forms.GroupBox gbIsoRead;
        private System.Windows.Forms.Button btnIsoReadWithUID;
        private System.Windows.Forms.Button btnIsoRead;
        private System.Windows.Forms.TextBox tbIsoRead_UID;
        private System.Windows.Forms.TextBox tbIsoRead_Result;
        private System.Windows.Forms.Label label39;
        private System.Windows.Forms.Label label40;
        private System.Windows.Forms.Label label41;
        private System.Windows.Forms.GroupBox gbIsoLock;
        private System.Windows.Forms.Button btnIsoLockWithUID;
        private System.Windows.Forms.Button btnIsoLock;
        private System.Windows.Forms.TextBox tbIsoLock_UID;
        private System.Windows.Forms.Label label42;
        private System.Windows.Forms.Label label44;
        private System.Windows.Forms.GroupBox gbIsoQueryLock;
        private System.Windows.Forms.Button btnIsoQueryLockWithUID;
        private System.Windows.Forms.Button btnIsoQueryLock;
        private System.Windows.Forms.TextBox tbIsoQueryLock_UID;
        private System.Windows.Forms.TextBox tbIsoQueryLock_Res;
        private System.Windows.Forms.Label label43;
        private System.Windows.Forms.Label label46;
        private System.Windows.Forms.Label label45;
        private System.Windows.Forms.TextBox tbIsoLock_Res;
        private System.Windows.Forms.Label label47;
        private System.Windows.Forms.NumericUpDown numIsoWrite_Addr;
        private System.Windows.Forms.NumericUpDown numIsoLock_Addr;
        private System.Windows.Forms.NumericUpDown numIsoRead_Addr;
        private System.Windows.Forms.NumericUpDown numIsoQueryLock_Addr;
        private System.Windows.Forms.TabPage tabPage_Settings;
        private System.Windows.Forms.CheckedListBox checkedlibFrePoint;
        private System.Windows.Forms.Button btnResetReader;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnGetFirmVersion;
        private System.Windows.Forms.Label lbFirmVersion;
        private System.Windows.Forms.Label label51;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button btnSetAnte;
        private System.Windows.Forms.Button btnGetAnte;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox tbPower4;
        private System.Windows.Forms.TextBox tbPower2;
        private System.Windows.Forms.TextBox tbPower3;
        private System.Windows.Forms.TextBox tbPower1;
        private System.Windows.Forms.Button btnSetPower;
        private System.Windows.Forms.Button btnGetPower;
        private System.Windows.Forms.Label label58;
        private System.Windows.Forms.Label label57;
        private System.Windows.Forms.Label label54;
        private System.Windows.Forms.Label label56;
        private System.Windows.Forms.Label label53;
        private System.Windows.Forms.Label label55;
        private System.Windows.Forms.Label label50;
        private System.Windows.Forms.Label label52;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnSetBaudRate;
        private System.Windows.Forms.Label label49;
        private System.Windows.Forms.Label label48;
        private System.Windows.Forms.ComboBox cbSettings_BaudRate;
        private System.Windows.Forms.CheckBox chbAnte4;
        private System.Windows.Forms.CheckBox chbAnte3;
        private System.Windows.Forms.CheckBox chbAnte2;
        private System.Windows.Forms.CheckBox chbAnte1;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.RadioButton rbMultiFastTagMode;
        private System.Windows.Forms.RadioButton rbSingleFastTagMode;
        private System.Windows.Forms.Button btnGetTagMode;
        private System.Windows.Forms.Button btnSetTagMode;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.ComboBox cbIOLevel;
        private System.Windows.Forms.ComboBox cbIOPort;
        private System.Windows.Forms.Button btnSetOutPort;
        private System.Windows.Forms.Label label60;
        private System.Windows.Forms.Label label59;
        private System.Windows.Forms.GroupBox groupBox8;
        private System.Windows.Forms.Label label62;
        private System.Windows.Forms.Label label61;
        private System.Windows.Forms.TextBox tbTCPPara_GateWay;
        private System.Windows.Forms.TextBox tbTCPPara_Mask;
        private System.Windows.Forms.Button btnGetTCPPara;
        private System.Windows.Forms.Button btnSetTCPPara;
        private System.Windows.Forms.TextBox tbTCPPara_IP;
        private System.Windows.Forms.Label label63;
        private System.Windows.Forms.GroupBox groupBox9;
        private System.Windows.Forms.Label lbFreqPoints;
        private System.Windows.Forms.Label label66;
        private System.Windows.Forms.Button btnGetFrequency;
        private System.Windows.Forms.Button btnSetFrequency;
        private System.Windows.Forms.RadioButton rbFreq_Others;
        private System.Windows.Forms.RadioButton rbFreq_Europe;
        private System.Windows.Forms.RadioButton rbFreq_NAmerica;
        private System.Windows.Forms.RadioButton rbFreq_China;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label label65;
        private System.Windows.Forms.Label label64;
        private System.Windows.Forms.PictureBox pbAnteStatus1;
        private System.Windows.Forms.PictureBox pbAnteStatus4;
        private System.Windows.Forms.PictureBox pbAnteStatus3;
        private System.Windows.Forms.PictureBox pbAnteStatus2;
        private System.Windows.Forms.PictureBox pbGreen;
        private System.Windows.Forms.PictureBox pbRed;
        private System.Windows.Forms.ColumnHeader columnHeader21;
        private System.Windows.Forms.GroupBox groupBox10;
        private System.Windows.Forms.RadioButton rbBuzzerOFF;
        private System.Windows.Forms.Button btnSetBuzzer;
        private System.Windows.Forms.RadioButton rbBuzzerON;
        private System.Windows.Forms.Button btnGetBuzzer;
        private System.Windows.Forms.Timer timerReconnect;
    }
}

