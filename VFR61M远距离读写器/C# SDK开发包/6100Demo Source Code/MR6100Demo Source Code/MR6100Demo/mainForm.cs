using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using MR6100Api;
namespace MR6100Demo
{
    public partial class mainForm : Form
    {
        MR6100Api.MR6100Api Api = new MR6100Api.MR6100Api();
        ArrayList idList = new ArrayList();
        byte[,] tagData = null;
        int tagCount = 0;
        System.Diagnostics.Stopwatch stopwatch = new System.Diagnostics.Stopwatch();
        int port = 0;
        byte v1 = 0;
        byte v2 = 0;
        string strIP = "";
        int status = 0;
        public mainForm()
        {
            InitializeComponent();
        }

        private void mainForm_Load(object sender, EventArgs e)
        {
            cbEPCStartAddr.SelectedIndex = 0;
            cbEPCWordCnt.SelectedIndex = 1;
            cbMEPCWrite_MemBank.SelectedIndex = 3;
            cbMEPCWrite_WordAddr.SelectedIndex = 0;
            cbMEPCWrite_WordLen.SelectedIndex = 1;
            cbResStartAddr.SelectedIndex = 0;
            cbResWordCnt.SelectedIndex = 1;
            cbTIDStartAddr.SelectedIndex = 0;
            cbTIDWordCnt.SelectedIndex = 1;
            cbUserStartAddr.SelectedIndex = 0;
            cbUserWordCnt.SelectedIndex = 1;
            cbIsoMultiTagRead_StartAddr.SelectedIndex = 0;
            tabControl.SelectedTab = tabPage_Settings;
        }
        private void btnConnect_Click(object sender, EventArgs e)
        {
            int status = 1;
            string strTemp = "";
                try
                {
                    port = int.Parse(tbPort.Text.Trim());
                    strIP = tbIP.Text.Trim();
                }
                catch (Exception)
                {
                    libInfo.Items.Add("Please input the ip address and port !");
                    return;
                }
                if (!Api.isNetWorkConnect(strIP))
                {
                    libInfo.Items.Add("The input ip is not exist.");
                    return;
                }
                status = Api.TcpConnectReader(strIP, port);
            if (status != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {                
                libInfo.Items.Add("Connect Reader Failed!  ");
                return;
            }
            status = Api.GetFirmwareVersion(255, ref v1, ref v2);
            if (status != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Can not connect with the reader!  ");
                return;
            }
            libInfo.Items.Add("Connect the reader success! ");
            strTemp = string.Format("Firmware version :V{0:d2}.{1:d2}   ", v1, v2);
            libInfo.Items.Add(strTemp);
            btnConnect.Enabled = false;
            btnConnect.BackColor = System.Drawing.Color.LightPink;
            btnDiscon.Enabled = true;
            btnDiscon.BackColor = System.Drawing.Color.Aquamarine;
            tabControl.Enabled = true;
            btnGetFirmVersion_Click(sender, e);
            btnGetFrequency_Click(sender, e);
            btnGetPower_Click(sender, e);
            btnGetTagMode_Click(sender, e);
            btnGetTCPPara_Click(sender, e);
            btnGetAnte_Click(sender, e);
        }

        private void btnDiscon_Click(object sender, EventArgs e)
        {
            timerRate.Enabled = false;
            if (timerGen2Identify.Enabled)
                timerGen2Identify.Enabled = false;
            if (timerIsoIdentify.Enabled)
                timerIsoIdentify.Enabled = false;
            if (timerIsoMultiTagRead.Enabled)
                timerIsoMultiTagRead.Enabled = false;
            if (timerMultiTagRead.Enabled)
                timerMultiTagRead.Enabled = false;
            if (timerMultiTagWrite.Enabled)
                timerMultiTagWrite.Enabled = false;
                Api.TcpCloseConnect();
            stopwatch.Reset();
            btnConnect.Enabled = true;
            btnDiscon.Enabled = false;
            tabControl.Enabled = false;
            btnConnect.BackColor = System.Drawing.Color.Aquamarine;
            btnDiscon.BackColor = System.Drawing.Color.LightPink;
        }

        private void btnIdentify_Click(object sender, EventArgs e)
        {
            if (btnIdentify.Text == "Identify")
            {
                libInfo.Items.Add("Start Gen2 EPC Identify...");
                tagData = new byte[500, 14];
                ClearLabel();
                livGen2Identify.Items.Clear();
                btnIdentify.Text = "Stop";
                idList.Clear();
                timerGen2Identify.Enabled = true;
                timerReconnect.Enabled = true;
                timerRate.Enabled = true;
                stopwatch.Start();
            }
            else
            {
                libInfo.Items.Add("Stop Gen2 EPC Identify.");
                btnIdentify.Text = "Identify";
                stopwatch.Reset();
                timerReconnect.Enabled = false;
                timerGen2Identify.Enabled = false;
                timerRate.Enabled = false;
            }

        }

        private void timerInventory_Tick(object sender, EventArgs e)
        {
            lbTestDuration.Text = stopwatch.Elapsed.Days.ToString() + "d " + stopwatch.Elapsed.Hours.ToString() + ":" + stopwatch.Elapsed.Minutes.ToString() + ":" + stopwatch.Elapsed.Seconds.ToString();// +"." + ((stopwatch.Elapsed.Milliseconds) / 10).ToString();
            byte tag_flag = 0;
            tagCount = 0;
            status = Api.EpcMultiTagIdentify(255, ref tagData, ref tagCount, ref tag_flag);
            if (status == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                string strAnteNo = "", strID = "", strTemp = "";
                for (int i = 0; i < tagCount; i++)
                {
                    int j = 0;
                    strID = "";
                    strAnteNo = string.Format("{0:X2}", tagData[i, 1]);
                    for (j = 2; j < 14; j++) // update: 0->2, 12->14
                    {
                        strTemp = string.Format("{0:X2}", tagData[i, j]);
                        strID += strTemp;
                    }
                    if (strID == "000000000000000000000000")
                    {
                        //libInfo.Items.Add("000");
                        continue;
                    }
                    if (!idList.Contains(strID))
                    {
                        idList.Add(strID);
                        ListViewItem nItem = new ListViewItem();
                        nItem.SubItems[0].Text = (livGen2Identify.Items.Count + 1).ToString();
                        try
                        {
                            nItem.SubItems.Add((int.Parse(strAnteNo) + 1).ToString());
                        }
                        catch { nItem.SubItems.Add("1"); }
                        nItem.SubItems.Add(strID);
                        nItem.SubItems.Add("1");
                        livGen2Identify.Items.Add(nItem);
                    }
                    else
                    {
                        for (j = 0; j < livGen2Identify.Items.Count; j++)
                        {
                            if (strID == livGen2Identify.Items[j].SubItems[2].Text)
                            {
                                try
                                {
                                    livGen2Identify.Items[j].SubItems[1].Text = (int.Parse(strAnteNo) + 1).ToString();
                                    livGen2Identify.Items[j].SubItems[3].Text = (int.Parse(livGen2Identify.Items[j].SubItems[3].Text) + 1).ToString();
                                }
                                catch { break; }
                            }
                        }
                    }
                }
                try
                {
                    lbUniqueTags.Text = (livGen2Identify.Items.Count).ToString();
                    lbReadTimes.Text = (int.Parse(lbReadTimes.Text) + 1).ToString();
                    lbTotalReads.Text = (int.Parse(lbTotalReads.Text) + tagCount).ToString();
                }
                catch { };
            }
            if (stopwatch.ElapsedMilliseconds / 1000 > 0)
                lbAverageRate.Text = (int.Parse(lbTotalReads.Text) / (stopwatch.ElapsedMilliseconds / 1000)).ToString();
        }

        int readSeconds = 0, rate = 0, peakRate = 0, totalReads = 0, lastTotalReads = 0;
        private void timerRate_Tick(object sender, EventArgs e)
        {
            readSeconds++;
            totalReads = int.Parse(lbTotalReads.Text);
            if (readSeconds <= 0)
                return;
            //rate =totalReads / readSeconds;
            if ((totalReads - lastTotalReads) > peakRate)
                peakRate = totalReads - lastTotalReads;
            lbPeakRate.Text = peakRate.ToString();
            //lbAverageRate.Text = rate.ToString();
            lastTotalReads = totalReads;
        }
        private void ClearLabel()
        {
            lbUniqueTags.Text = "0";
            lbTotalReads.Text = "0";
            lbPeakRate.Text = "0";
            lbAverageRate.Text = "0";
            lbReadTimes.Text = "0";
            lbTestDuration.Text = "0";
            readSeconds = 0;
        }

        int iMembankMask = 0, iStartAddr_Reserve = 0, iStartAddr_EPC, iStartAddr_TID, iStartAddr_User, reserveLen, epcLen, tidLen, userLen, readCnt, wordLen = 0;
        private void btnMultiTagRead_Click(object sender, EventArgs e)
        {
            iStartAddr_Reserve = iStartAddr_EPC = iStartAddr_TID = iStartAddr_User = reserveLen = epcLen = tidLen = userLen = readCnt = 0;
            iMembankMask = 0;
            wordLen = 6;
            if (chbReserve.Checked)
            {
                iMembankMask += 1;
                wordLen += int.Parse(cbResWordCnt.SelectedItem.ToString());
                iStartAddr_Reserve = int.Parse(cbResStartAddr.SelectedItem.ToString());
                reserveLen = int.Parse(cbResWordCnt.SelectedItem.ToString());
            }
            if (chbEPC.Checked)
            {
                iMembankMask += 2;
                wordLen += int.Parse(cbEPCWordCnt.SelectedItem.ToString());
                iStartAddr_EPC = int.Parse(cbEPCStartAddr.SelectedItem.ToString());
                epcLen = int.Parse(cbEPCWordCnt.SelectedItem.ToString());
            }
            if (chbTID.Checked)
            {
                iMembankMask += 4;
                wordLen += int.Parse(cbTIDWordCnt.SelectedItem.ToString());
                iStartAddr_TID = int.Parse(cbTIDStartAddr.SelectedItem.ToString());
                tidLen = int.Parse(cbTIDWordCnt.SelectedItem.ToString());
            }
            if (chbUser.Checked)
            {
                iMembankMask += 8;
                wordLen += int.Parse(cbUserWordCnt.SelectedItem.ToString());
                iStartAddr_User = int.Parse(cbUserStartAddr.SelectedItem.ToString());
                userLen = int.Parse(cbUserWordCnt.SelectedItem.ToString());
            }
            lbMultiTagReadCnt.Text = "0";
            if (btnMultiTagRead.Text == "MultiTagRead")
            {
                libInfo.Items.Add("Start MultiTagRead...");
                tagData = new byte[500, wordLen * 4];
                livEPCMultiTagRead.Items.Clear();
                btnMultiTagRead.Text = "Stop";
                idList.Clear();
                timerMultiTagRead.Enabled = true;
                timerReconnect.Enabled = true;
                stopwatch.Start();
            }
            else
            {
                libInfo.Items.Add("Stop MultiTagRead.");
                btnMultiTagRead.Text = "MultiTagRead";
                stopwatch.Reset();
                timerMultiTagRead.Enabled = false;
                timerReconnect.Enabled = false;
            }
        }

        private void timerMultiTagRead_Tick(object sender, EventArgs e)
        {
            readCnt = 0;
            int getCount = 0;
            string strTemp = "", strAnteNo = "", strEPC = "", strSubEPC = "", strTID = "", strReserve = "", strUser = "";
            lbMultiTagReadDuration.Text = (stopwatch.Elapsed.Hours / 10).ToString() + (stopwatch.Elapsed.Hours % 10).ToString() + ":" + (stopwatch.Elapsed.Minutes / 10).ToString() + (stopwatch.Elapsed.Minutes % 10).ToString() + ":" + (stopwatch.Elapsed.Seconds / 10).ToString() + (stopwatch.Elapsed.Seconds % 10).ToString();// +"." + ((stopwatch.Elapsed.Milliseconds) / 10).ToString();
            status = Api.Gen2MultiTagRead(255, (byte)iMembankMask, (byte)iStartAddr_Reserve, (byte)reserveLen, (byte)iStartAddr_EPC, (byte)epcLen, (byte)iStartAddr_TID, (byte)tidLen, (byte)iStartAddr_User, (byte)userLen, ref readCnt);
            if (status == MR6100Api.MR6100Api.SUCCESS_RETURN && readCnt > 0)
            {
                if (Api.GetTagData(255, ref tagData, readCnt, ref getCount) == MR6100Api.MR6100Api.SUCCESS_RETURN && getCount > 0)
                {
                    for (int loop = 0; loop < getCount; loop++)
                    {
                        strTemp = "";
                        for (int j = 1; j <= (int)tagData[loop, 0]; j++)
                            strTemp += string.Format("{0:X2}", tagData[loop, j]);
                        if (strTemp.Length - 2 == wordLen * 4)
                        {
                            strAnteNo = (int.Parse(strTemp.Substring(0, 2)) + 1).ToString();
                            strEPC = strTemp.Substring(2, 24);
                            strReserve = strTemp.Substring(26, reserveLen * 4);
                            strSubEPC = strTemp.Substring(26 + reserveLen * 4, epcLen * 4);
                            strTID = strTemp.Substring(26 + reserveLen * 4 + epcLen * 4, tidLen * 4);
                            strUser = strTemp.Substring(26 + reserveLen * 4 + epcLen * 4 + tidLen * 4, userLen * 4);
                        }
                        else
                            continue;
                        if (!idList.Contains(strEPC))
                        {
                            idList.Add(strEPC);
                            ListViewItem nItem = new ListViewItem();
                            nItem.SubItems[0].Text = (livEPCMultiTagRead.Items.Count + 1).ToString();
                            nItem.SubItems.Add(strAnteNo);
                            nItem.SubItems.Add(strReserve);
                            nItem.SubItems.Add(strSubEPC);
                            nItem.SubItems.Add(strTID);
                            nItem.SubItems.Add(strUser);
                            livEPCMultiTagRead.Items.Add(nItem);
                        }
                        else
                        {
                            for (int j = 0; j < livEPCMultiTagRead.Items.Count; j++)
                            {
                                if (strSubEPC == livEPCMultiTagRead.Items[j].SubItems[3].Text)
                                {
                                    if (strReserve != "")
                                        livEPCMultiTagRead.Items[j].SubItems[2].Text = strReserve;
                                    if (strTID != "")
                                        livEPCMultiTagRead.Items[j].SubItems[4].Text = strTID;
                                    if (strUser != "")
                                        livEPCMultiTagRead.Items[j].SubItems[5].Text = strUser;
                                }
                            }
                        }
                    }
                    lbMultiTagReadCnt.Text = (livEPCMultiTagRead.Items.Count).ToString();
                }
            }
        }

        private void linkLabelMultiTagRead_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            panelIdentity.Visible = false;
            panelGen2MultiTagRead.Visible = true;
            panelMultiTagWrite.Visible = false;
            if (btnIdentify.Text == "Stop")
                btnIdentify_Click(sender, e);
            if (btnMultiTagWrite.Text == "Stop")
                btnMultiTagWrite_Click(sender, e);

        }

        private void linkLabelIdentify_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            panelIdentity.Visible = true;
            panelGen2MultiTagRead.Visible = false;
            panelMultiTagWrite.Visible = false;
            if (btnMultiTagRead.Text == "Stop")
                btnMultiTagRead_Click(sender, e);
            if (btnMultiTagWrite.Text == "Stop")
                btnMultiTagWrite_Click(sender, e);
        }

        private void linkLabelMultiTagWrite_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            panelIdentity.Visible = false;
            panelGen2MultiTagRead.Visible = false;
            panelMultiTagWrite.Visible = true;
            if (btnIdentify.Text == "Stop")
                btnIdentify_Click(sender, e);
            if (btnMultiTagRead.Text == "Stop")
                btnMultiTagRead_Click(sender, e);
        }

        int iMultiTagWrite_MemBank = 0, iMultiTagWrite_WordAddr = 0, iMultiTagWrite_WordLen = 0;
        string strWriteValue_Gen2 = "";
        private void btnMultiTagWrite_Click(object sender, EventArgs e)
        {
            iMultiTagWrite_MemBank = cbMEPCWrite_MemBank.SelectedIndex;
            iMultiTagWrite_WordAddr = cbMEPCWrite_WordAddr.SelectedIndex;
            iMultiTagWrite_WordLen = cbMEPCWrite_WordLen.SelectedIndex + 1;
            strWriteValue_Gen2 = tbWriteValue_Gen2.Text.Trim();
            if (iMultiTagWrite_WordLen * 4 != strWriteValue_Gen2.Length)
            {
                libInfo.Items.Add("The Input write value is not fit for the selected word length,please check.");
                return;
            }
            if (btnMultiTagWrite.Text == "Write")
            {
                tagData = new byte[200, 14];
                btnMultiTagWrite.Text = "Stop";
                idList.Clear();
                livEPCMultiTagWrite.Items.Clear();
                stopwatch.Start();
                timerReconnect.Enabled = true;
                timerMultiTagWrite.Enabled = true;
                libInfo.Items.Add("Sart Gen2 EPC MultiTagWrite...");
            }
            else
            {
                btnMultiTagWrite.Text = "Write";
                stopwatch.Reset();
                timerMultiTagWrite.Enabled = false;
                timerReconnect.Enabled = false;
                libInfo.Items.Add("Gen2 EPC MultiTagWrite stop.");
            }
        }

        private void timerMultiTagWrite_Tick(object sender, EventArgs e)
        {
            readCnt = 0;
            int getCount = 0;
            string strTemp = "", strAnteNo = "", strEPC = "";
            lbMultiTagWriteDuration.Text = (stopwatch.Elapsed.Hours / 10).ToString() + (stopwatch.Elapsed.Hours % 10).ToString() + ":" + (stopwatch.Elapsed.Minutes / 10).ToString() + (stopwatch.Elapsed.Minutes % 10).ToString() + ":" + (stopwatch.Elapsed.Seconds / 10).ToString() + (stopwatch.Elapsed.Seconds % 10).ToString();// +"." + ((stopwatch.Elapsed.Milliseconds) / 10).ToString();
            status = Api.Gen2MultiTagWrite(255, iMultiTagWrite_MemBank, iMultiTagWrite_WordAddr, iMultiTagWrite_WordLen, strWriteValue_Gen2, ref readCnt);
            if (status == MR6100Api.MR6100Api.SUCCESS_RETURN && readCnt > 0)
            {
                if (Api.GetTagData(255, ref tagData, readCnt, ref getCount) == MR6100Api.MR6100Api.SUCCESS_RETURN && getCount > 0)
                {
                    for (int loop = 0; loop < getCount; loop++)
                    {
                        strTemp = "";
                        for (int j = 1; j <= 13; j++)
                            strTemp += string.Format("{0:X2}", tagData[loop, j]);
                        strAnteNo = (int.Parse(strTemp.Substring(0, 2)) + 1).ToString();
                        strEPC = strTemp.Substring(2, 24);
                        if (!idList.Contains(strEPC))
                        {
                            idList.Add(strEPC);
                            ListViewItem nItem = new ListViewItem();
                            nItem.SubItems[0].Text = (livEPCMultiTagWrite.Items.Count + 1).ToString();
                            nItem.SubItems.Add(strAnteNo);
                            nItem.SubItems.Add(strEPC);
                            livEPCMultiTagWrite.Items.Add(nItem);
                        }
                    }
                    lbMultiTagWriteCount.Text = (livEPCMultiTagWrite.Items.Count).ToString();
                }
            }
        }

        private void btnIdentify_Once_Click(object sender, EventArgs e)
        {
            tagData = new byte[500, 14];
            //Api.Gen2MultiTagInventory(255);
            ClearLabel();
            livGen2Identify.Items.Clear();
            idList.Clear();
            timerInventory_Tick(sender, e);
        }

        private void btnGen2SecRead_Click(object sender, EventArgs e)
        {
            uint pwd = 0;
            if (tbGen2SecRead_PWD.Text != "")
                pwd = Convert.ToUInt32(tbGen2SecRead_PWD.Text, 16);
            int iMembank = cbGen2SecRead_Membank.SelectedIndex;
            int iWordAddr = cbGen2SecRead_WordAddr.SelectedIndex;
            int iWordCnt = cbGen2SecRead_WordCnt.SelectedIndex + 1;
            string strTemp = "";
            byte[] res = new byte[iWordCnt * 2];
            if (Api.Gen2SecRead(255, pwd, (byte)iMembank, (byte)iWordAddr, (byte)iWordCnt, ref res) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                for (int i = 0; i < iWordCnt * 2; i++)
                {
                    strTemp += string.Format("{0:X2}", res[i]);
                }
                tbGen2SecRead_Value.Text = strTemp;
                libInfo.Items.Add("SecRead success.");
            }
            else
                libInfo.Items.Add("SecRead Fail.");
        }

        private void btnGen2SecWrite_Click(object sender, EventArgs e)
        {
            uint pwd = 0;
            if (tbGen2SecWrite_PWD.Text != "")
                pwd = Convert.ToUInt32(tbGen2SecWrite_PWD.Text, 16);
            int iMembank = cbGen2SecWrite_Membank.SelectedIndex;
            int iWordAddr = cbGen2SecWrite_WordAdr.SelectedIndex;
            string strValue = tbGen2SecWrite_Value.Text.Trim();
            string[] hexValuesSplit = strValue.Split(' ');
            int wordcnt = hexValuesSplit.Length;
            ushort[] value = new ushort[wordcnt];
            int i = 0;
            foreach (String hex in hexValuesSplit)
            {
                if (hex != "")
                {
                    int x = Convert.ToInt32(hex, 16);
                    value[i++] = (ushort)x;
                }
            }
            if (i != wordcnt)
            {
                libInfo.Items.Add("Please input data needed  ");
                return;
            }
            for (byte j = 0; j < wordcnt; j++)
            {
                int status = Api.Gen2SecWrite(255, pwd, (byte)iMembank, (byte)iWordAddr, value[j]);
                if (status != MR6100Api.MR6100Api.SUCCESS_RETURN)
                {
                    libInfo.Items.Add("Write Tag failed!  ");
                    return;
                }
                iWordAddr++;
            }
            libInfo.Items.Add("Write Tag success! ");
        }

        private void btnGen2SecLock_Click(object sender, EventArgs e)
        {
            uint pwd = 0;
            if (tbGen2SecLock_PWD.Text != "")
                pwd = Convert.ToUInt32(tbGen2SecLock_PWD.Text, 16);
            else
            {
                libInfo.Items.Add("Please input a SecLock password  ");
                return;
            }
            int iMembank = cbGen2SecLock_Membank.SelectedIndex;
            int level = cbGen2SecLock_Level.SelectedIndex;
            if (Api.Gen2SecLock(255, pwd, (byte)iMembank, (byte)level) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("SecLock Tag failed!  ");
                return;
            }
            libInfo.Items.Add("SecLock Tag success! ");
        }

        private void btnGen2Kill_Click(object sender, EventArgs e)
        {
            uint pwd = 0;
            if (tbGen2Kill_PWD.Text != "")
                pwd = Convert.ToUInt32(tbGen2Kill_PWD.Text, 16);
            else
            {
                libInfo.Items.Add("Please input the password.");
                return;
            }
            if (Api.Gen2KillTag(255, pwd) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Kill Tag failed!  ");
                return;
            }
            libInfo.Items.Add("Kill Tag success! ");
        }

        private void btnGen2SelectConfig_Click(object sender, EventArgs e)
        {
            int isMatch = 1;
            if (rbMatch.Checked)
                isMatch = 0;
            int iMembank = cbGen2SelectConfig_Membank.SelectedIndex;
            int iWordAddr = cbGen2SelectConfig_BitAddr.SelectedIndex;
            int iLength = cbGen2SelectConfig_BitLength.SelectedIndex;
            string strValue = tbGen2SelectConfig_Value.Text.Trim();
            string[] words = strValue.Split(' ');
            if (strValue != "" && iLength != words.Length)
            {
                libInfo.Items.Add("The input words' length is not fit for the selected length.");
                return;
            }
            if (Api.Gen2SelectConfig(255, isMatch, iMembank, iWordAddr, iLength, words) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Gen2 Tags Select Config failed!  ");
                return;
            }
            libInfo.Items.Add("Gen2 Tags Select Config success! ");
        }

        private void tbGen2SecWrite_Value_TextChanged(object sender, EventArgs e)
        {
            if (((tbGen2SecWrite_Value.Text.Length - 4) % 5) == 0)
            {
                tbGen2SecWrite_Value.Text += " ";
                tbGen2SecWrite_Value.Select(tbGen2SecWrite_Value.Text.Length, 0);
            }
        }
        private void tbGen2SelectConfig_Value_TextChanged(object sender, EventArgs e)
        {
            if (((tbGen2SelectConfig_Value.Text.Length - 4) % 5) == 0)
            {
                tbGen2SelectConfig_Value.Text += " ";
                tbGen2SelectConfig_Value.Select(tbGen2SelectConfig_Value.Text.Length, 0);
            }
        }

        private void linLISOSingleTag_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            panelISOIdentify.Visible = false;
            panelIsoSingleTag.Visible = true;
            panelIsoMultiTagRead.Visible = false;
            if (btnISOIdentify.Text == "Stop")
                btnISOIdentify_Click(sender, e);
            if (btnIsoMultiTagRead.Text == "Stop")
                btnIsoMultiTagRead_Click(sender, e);
        }

        private void linLISOIdentify_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            panelISOIdentify.Visible = true;
            panelIsoMultiTagRead.Visible = false;
            panelIsoSingleTag.Visible = false;
            if (btnIsoMultiTagRead.Text == "Stop")
                btnIsoMultiTagRead_Click(sender, e);

        }

        private void linLISOMultiTagRead_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            panelISOIdentify.Visible = false;
            panelIsoSingleTag.Visible = false;
            panelIsoMultiTagRead.Visible = true;
            if (btnISOIdentify.Text == "Stop")
                btnISOIdentify_Click(sender, e);
        }

        private void btnISOIdentify_Click(object sender, EventArgs e)
        {
            if (btnISOIdentify.Text == "Identify")
            {
                tagData = new byte[500, 10];
                livISOIdentify.Items.Clear();
                btnISOIdentify.Text = "Stop";
                idList.Clear();
                timerIsoIdentify.Enabled = true;
                timerReconnect.Enabled = true;
                stopwatch.Start();
                libInfo.Items.Add("Start Iso 6B Identify...");
            }
            else
            {
                btnISOIdentify.Text = "Identify";
                stopwatch.Reset();
                timerReconnect.Enabled = false;
                timerIsoIdentify.Enabled = false;
                libInfo.Items.Add("Iso 6B Identify stop.");
            }
        }

        private void timerIsoIdentify_Tick(object sender, EventArgs e)
        {
            int tag_cnt = 0;
            status = Api.IsoMultiTagIdentify(255, ref tagData, ref tag_cnt, ref tagCount);
            if (status == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                string strID = "", strTemp = "", strAnteNo = "";
                for (int i = 0; i < tagCount; i++)
                {
                    int j = 0;
                    strID = "";
                    strAnteNo = string.Format("{0:X2}", tagData[i, 1]);
                    for (j = 2; j < 10; j++) // update: 0->2, 12->14
                    {
                        strTemp = string.Format("{0:X2}", tagData[i, j]);
                        strID += strTemp;
                    }
                    if (!idList.Contains(strID))
                    {
                        idList.Add(strID);
                        ListViewItem nItem = new ListViewItem();
                        nItem.SubItems[0].Text = (livISOIdentify.Items.Count + 1).ToString();
                        nItem.SubItems.Add((int.Parse(strAnteNo) + 1).ToString());
                        nItem.SubItems.Add(strID);
                        nItem.SubItems.Add("1");
                        livISOIdentify.Items.Add(nItem);
                    }
                    else
                    {
                        for (j = 0; j < livISOIdentify.Items.Count; j++)
                        {
                            if (strID == livISOIdentify.Items[j].SubItems[2].Text)
                                livISOIdentify.Items[j].SubItems[3].Text = (int.Parse(livISOIdentify.Items[j].SubItems[3].Text) + 1).ToString();
                        }
                    }
                }
            }
        }

        int isoMultiTagReadAddr = 0;
        private void btnIsoMultiTagRead_Click(object sender, EventArgs e)
        {
            if (cbIsoMultiTagRead_StartAddr.SelectedItem.Equals(null))
            {
                libInfo.Items.Add("Please select the start address.");
                return;
            }
            if (btnIsoMultiTagRead.Text == "Read")
            {
                isoMultiTagReadAddr = cbIsoMultiTagRead_StartAddr.SelectedIndex;
                tagData = new byte[500, 10];
                livIsoMultiTagRead.Items.Clear();
                btnIsoMultiTagRead.Text = "Stop";
                idList.Clear();
                timerIsoMultiTagRead.Enabled = true;
                timerReconnect.Enabled = true;
                stopwatch.Start();
                libInfo.Items.Add("Start IsoMultiTagRead...");
            }
            else
            {
                btnIsoMultiTagRead.Text = "Read";
                stopwatch.Reset();
                timerIsoMultiTagRead.Enabled = false;
                timerReconnect.Enabled = false;
                libInfo.Items.Add("IsoMultiTagRead stop.");
            }
        }

        private void timerIsoMultiTagRead_Tick(object sender, EventArgs e)
        {
            int tag_cnt = 0;
            status = Api.IsoMultiTagRead(255, isoMultiTagReadAddr, ref tagData, ref tag_cnt, ref tagCount);
            if (status == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                string strID = "", strTemp = "", strAnteNo = "";
                for (int i = 0; i < tagCount; i++)
                {
                    int j = 0;
                    strID = "";
                    strAnteNo = string.Format("{0:X2}", tagData[i, 1]);
                    for (j = 2; j < 10; j++) // update: 0->2, 12->14
                    {
                        strTemp = string.Format("{0:X2}", tagData[i, j]);
                        strID += strTemp;
                    }
                    if (!idList.Contains(strID))
                    {
                        idList.Add(strID);
                        ListViewItem nItem = new ListViewItem();
                        nItem.SubItems[0].Text = (livIsoMultiTagRead.Items.Count + 1).ToString();
                        nItem.SubItems.Add((int.Parse(strAnteNo) + 1).ToString());
                        nItem.SubItems.Add(strID);
                        nItem.SubItems.Add("1");
                        livIsoMultiTagRead.Items.Add(nItem);
                    }
                    else
                    {
                        for (j = 0; j < livIsoMultiTagRead.Items.Count; j++)
                        {
                            if (strID == livIsoMultiTagRead.Items[j].SubItems[2].Text)
                                livIsoMultiTagRead.Items[j].SubItems[3].Text = (int.Parse(livIsoMultiTagRead.Items[j].SubItems[3].Text) + 1).ToString();
                        }
                    }
                }
            }
        }

        private void btnIsoWrite_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoWrite_Addr.Value;
            if (tbIsoWrite_Value.Text.Trim() == "")
            {
                libInfo.Items.Add("Please input a ISO Write value.");
                return;
            }
            string[] strValue = tbIsoWrite_Value.Text.Trim().Split(' ');
            for (int i = 0; i < strValue.Length; i++)
            {
                if (Api.IsoWrite(255, iAddr, Convert.ToByte(strValue[i], 16)) != MR6100Api.MR6100Api.SUCCESS_RETURN)
                {
                    libInfo.Items.Add("ISO Write failed,please try again.");
                    return;
                }
            }
            libInfo.Items.Add("ISO Write success.");
        }

        private void btnWriteWithUID_Click(object sender, EventArgs e)
        {

            byte iAddr = (byte)numIsoWrite_Addr.Value;
            string[] strValue = tbIsoWrite_Value.Text.Trim().Split(' ');
            string strID = tbIsoWrite_UID.Text.Trim();
            if (strID.Length != 16)
            {
                libInfo.Items.Add("Please input a correct UID.");
                return;
            }
            byte[] byteID = new byte[8];
            for (int i = 0; i < 8; i++)
            {
                byteID[i] = Convert.ToByte(strID.Substring(i * 2, 2), 16);
            }
            for (int i = 0; i < strValue.Length; i++)
            {
                if (Api.IsoWriteWithID(255, byteID, iAddr, Convert.ToByte(strValue[i], 16)) != MR6100Api.MR6100Api.SUCCESS_RETURN)
                {
                    libInfo.Items.Add("ISO Write with UID failed,please try again.");
                    return;
                }
            }
            libInfo.Items.Add("ISO Write with UID success.");
        }

        private void btnIsoRead_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoRead_Addr.Value;
            byte[] value = new byte[8];
            if (Api.IsoRead(255, iAddr, ref value) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                string strTemp = "";
                for (int i = 0; i < 8; i++)
                {
                    strTemp += string.Format("{0:X2}", value[i]);
                }
                tbIsoRead_Result.Text = strTemp;
                libInfo.Items.Add("ISO Read success.");
                return;
            }
            libInfo.Items.Add("ISO Read failed.");
        }

        private void btnIsoReadWithUID_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoRead_Addr.Value;
            string strID = tbIsoRead_UID.Text.Trim();
            if (strID.Length != 16)
            {
                libInfo.Items.Add("Please input a correct UID.");
                return;
            }
            byte[] byteID = new byte[8];
            for (int i = 0; i < 8; i++)
            {
                byteID[i] = Convert.ToByte(strID.Substring(i * 2, 2), 16);
            }
            byte[] value = new byte[8];
            byte byteAbteNo = 0;
            if (Api.IsoReadWithID(255, byteID, iAddr, ref value, ref byteAbteNo) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                string strTemp = "";
                for (int i = 0; i < 8; i++)
                {
                    strTemp += string.Format("{0:X2}", value[i]);
                }
                tbIsoRead_Result.Text = strTemp;
                libInfo.Items.Add("ISO Read tag success.");
                return;
            }
            libInfo.Items.Add("ISO Read tag failed.");
        }

        private void btnIsoLock_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoLock_Addr.Value;
            if (Api.IsoLock(255, iAddr) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("ISO Lock tag success.");
                tbIsoLock_Res.Text = "ISO Lock tag success.";
                return;
            }
            libInfo.Items.Add("ISO Lock tag failed.");
            tbIsoLock_Res.Text = "ISO Lock tag failed.";
        }

        private void btnIsoLockWithUID_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoLock_Addr.Value;
            string strID = tbIsoLock_UID.Text.Trim();
            if (strID.Length != 16)
            {
                libInfo.Items.Add("Please input a correct UID.");
                return;
            }
            byte[] byteID = new byte[8];
            for (int i = 0; i < 8; i++)
            {
                byteID[i] = Convert.ToByte(strID.Substring(i * 2, 2), 16);
            }
            if (Api.IsoLockWithID(255, byteID, iAddr) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                tbIsoLock_Res.Text = "ISO Lock with UID tag success.";
                libInfo.Items.Add("ISO Lock tag with UID success.");
                return;
            }
            tbIsoLock_Res.Text = "ISO Lock tag with UID failed.";
            libInfo.Items.Add("ISO Lock tag with UID failed.");
        }

        private void btnIsoQueryLock_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoQueryLock_Addr.Value;
            byte lockState = 0;
            if (Api.IsoQueryLock(255, iAddr, ref lockState) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                if (lockState == 0)
                    tbIsoQueryLock_Res.Text = "Not lock";
                else
                    tbIsoQueryLock_Res.Text = "Had locked";
                libInfo.Items.Add("ISO Query Lock tag success.");
                return;
            }
            libInfo.Items.Add("ISO Query Lock tag failed.");
        }

        private void btnIsoQueryLockWithUID_Click(object sender, EventArgs e)
        {
            byte iAddr = (byte)numIsoQueryLock_Addr.Value;
            string strID = tbIsoQueryLock_UID.Text.Trim();
            if (strID.Length != 16)
            {
                libInfo.Items.Add("Please input a correct UID.");
                return;
            }
            byte[] byteID = new byte[8];
            for (int i = 0; i < 8; i++)
            {
                byteID[i] = Convert.ToByte(strID.Substring(i * 2, 2), 16);
            }
            byte lockState = 0;
            if (Api.IsoQueryLockWithUID(255, byteID, iAddr, ref lockState) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                if (lockState == 0)
                    tbIsoQueryLock_Res.Text = "Not lock";
                else
                    tbIsoQueryLock_Res.Text = "Had locked";
                libInfo.Items.Add("ISO Query Lock with UID tag success.");
                return;
            }
            libInfo.Items.Add("ISO Query Lock tag with UID failed.");
        }

        private void tbIsoWrite_Value_TextChanged(object sender, EventArgs e)
        {
            if (((tbIsoWrite_Value.Text.Length - 2) % 3) == 0)
            {
                tbIsoWrite_Value.Text += " ";
                tbIsoWrite_Value.Select(tbIsoWrite_Value.Text.Length, 0);
            }
        }

        private void btnSetBaudRate_Click(object sender, EventArgs e)
        {
            int baudRate = cbSettings_BaudRate.SelectedIndex;
            if (Api.SetBaudRate(255, baudRate) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set baudrate success.");
                return;
            }
            libInfo.Items.Add("Set baudrate fail.");
        }

        private void btnGetFirmVersion_Click(object sender, EventArgs e)
        {
            lbFirmVersion.Text = "";
            if (Api.GetFirmwareVersion(255, ref v1, ref v2) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                lbFirmVersion.Text = string.Format("V{0:d2}.{1:d2}", v1, v2);
                libInfo.Items.Add("Get Firmware Version success.");
                return;
            }
            libInfo.Items.Add("Get Firmware Version fail.");
        }

        private void btnGetPower_Click(object sender, EventArgs e)
        {
            tbPower1.Text = "";
            tbPower2.Text = "";
            tbPower3.Text = "";
            tbPower4.Text = "";
            int[] power = new int[4];
            if (Api.GetRf(255, ref power) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                tbPower1.Text = power[0].ToString();
                tbPower2.Text = power[1].ToString();
                tbPower3.Text = power[2].ToString();
                tbPower4.Text = power[3].ToString();
                libInfo.Items.Add("Get Power success.");
                return;
            }
            libInfo.Items.Add("Get Power fail.");
        }

        private void btnSetPower_Click(object sender, EventArgs e)
        {
            int power1 = 0, power2 = 0, power3 = 0, power4 = 0;
            try
            {
                power1 = int.Parse(tbPower1.Text.Trim());
            }
            catch { power1 = 0; }
            try
            {
                power2 = int.Parse(tbPower2.Text.Trim());
            }
            catch { power2 = 0; }
            try
            {
                power3 = int.Parse(tbPower3.Text.Trim());
            }
            catch { power3 = 0; }
            try
            {
                power4 = int.Parse(tbPower4.Text.Trim());
            }
            catch { power4 = 0; }
            if (Api.SetRf(255, power1, power2, power3, power4) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set Power success.");
                return;
            }
            libInfo.Items.Add("Set Power fail.");
        }

        private void btnGetAnte_Click(object sender, EventArgs e)
        {
            byte workAnte = 0, anteState = 0;
            if (Api.GetAnt(255, ref workAnte, ref anteState) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Get Antennas fail.");
                chbAnte1.Checked = false;
                chbAnte2.Checked = false;
                chbAnte3.Checked = false;
                chbAnte4.Checked = false;
                pbAnteStatus1.BackgroundImage = pbRed.BackgroundImage;
                pbAnteStatus2.BackgroundImage = pbRed.BackgroundImage;
                pbAnteStatus3.BackgroundImage = pbRed.BackgroundImage;
                pbAnteStatus4.BackgroundImage = pbRed.BackgroundImage;
                return;
            }
            libInfo.Items.Add("Get Antennas success.");
            if (workAnte % 2 == 1)
                chbAnte1.Checked = true;
            else
                chbAnte1.Checked = false;
            if ((workAnte >> 1) % 2 == 1)
                chbAnte2.Checked = true;
            else
                chbAnte2.Checked = false;
            if ((workAnte >> 2) % 2 == 1)
                chbAnte3.Checked = true;
            else
                chbAnte3.Checked = false;
            if ((workAnte >> 3) % 2 == 1)
                chbAnte4.Checked = true;
            else
                chbAnte4.Checked = false;

            if (anteState % 2 == 1)
                pbAnteStatus1.BackgroundImage = pbGreen.BackgroundImage;
            else
                pbAnteStatus1.BackgroundImage = pbRed.BackgroundImage;
            if ((anteState >> 1) % 2 == 1)
                pbAnteStatus2.BackgroundImage = pbGreen.BackgroundImage;
            else
                pbAnteStatus2.BackgroundImage = pbRed.BackgroundImage;
            if ((anteState >> 2) % 2 == 1)
                pbAnteStatus3.BackgroundImage = pbGreen.BackgroundImage;
            else
                pbAnteStatus3.BackgroundImage = pbRed.BackgroundImage;
            if ((anteState >> 3) % 2 == 1)
                pbAnteStatus4.BackgroundImage = pbGreen.BackgroundImage;
            else
                pbAnteStatus4.BackgroundImage = pbRed.BackgroundImage;
        }

        private void btnSetAnte_Click(object sender, EventArgs e)
        {
            int iWorkAnte = 0;
            if (chbAnte1.Checked)
                iWorkAnte += 1;
            if (chbAnte2.Checked)
                iWorkAnte += 2;
            if (chbAnte3.Checked)
                iWorkAnte += 4;
            if (chbAnte4.Checked)
                iWorkAnte += 8;
            if (Api.SetAnt(255, (byte)iWorkAnte) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set Antennas fail.");
                return;
            }
            libInfo.Items.Add("Set Antennas success.");
        }

        private void btnGetTagMode_Click(object sender, EventArgs e)
        {
            int iMode = 0;
            if (Api.GetFastTagMode(255, ref iMode) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set Fast Tag Mode fail.");
                rbSingleFastTagMode.Checked = false;
                rbMultiFastTagMode.Checked = false;
                return;
            }
            libInfo.Items.Add("Set Fast Tag Mode success.");
            if (iMode == 0)
                rbSingleFastTagMode.Checked = true;
            else
                rbMultiFastTagMode.Checked = true;
        }

        private void btnSetTagMode_Click(object sender, EventArgs e)
        {
            int iMode = 0;
            if (rbMultiFastTagMode.Checked)
                iMode = 1;
            if (Api.SetFastTagMode(255, iMode) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set Fast Tag Mode success.");
                return;
            }
            libInfo.Items.Add("Set Fast Tag Mode fail.");

        }

        private void btnGetTestMode_Click(object sender, EventArgs e)
        {

        }

        private void btnSetOutPort_Click(object sender, EventArgs e)
        {
            int ioNum = cbIOPort.SelectedIndex;
            int iLevel = cbIOLevel.SelectedIndex;
            if (ioNum < 0 || iLevel < 0)
            {
                libInfo.Items.Add("Please select the IO port and level.");
                return;
            }
            if (Api.SetOutPort(255, (byte)ioNum, (byte)iLevel) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set  OutPort success.");
                return;
            }
            libInfo.Items.Add("Set  OutPort fail.");
        }

        private void btnResetReader_Click(object sender, EventArgs e)
        {
            if (Api.ResetParameter(255) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Reset Reader success.");
                btnDiscon_Click(sender, e);
                return;
            }
            libInfo.Items.Add("Reset Reader fail.");
        }

        private void btnGetTCPPara_Click(object sender, EventArgs e)
        {
            string strIP = "", strMask = "", strGateWay = "";
            int nPort = 0;
            if (Api.GetTcpParameter(255, ref strIP, ref strMask, ref strGateWay, ref nPort) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                tbTCPPara_IP.Text = strIP;
                tbTCPPara_Mask.Text = strMask;
                tbTCPPara_GateWay.Text = strGateWay;
                libInfo.Items.Add("Get Tcp Parameter success.");
                return;
            }
            tbTCPPara_IP.Text = strIP;
            tbTCPPara_Mask.Text = strMask;
            tbTCPPara_GateWay.Text = strGateWay;
            libInfo.Items.Add("Get Tcp Parameter fail.");
        }

        private void btnSetTCPPara_Click(object sender, EventArgs e)
        {
            string strIP = tbTCPPara_IP.Text.Trim();
            string strMask = tbTCPPara_Mask.Text.Trim();
            string strGateWay = tbTCPPara_GateWay.Text.Trim();

            if (CheckIPValid(strIP))
            {
                if (Api.SetTcpParameter(255, strIP, strMask, strGateWay, 0) == MR6100Api.MR6100Api.SUCCESS_RETURN)
                {
                    libInfo.Items.Add("Set Tcp Parameter success.");
                    btnResetReader_Click(sender, e);
                    return;
                }
                libInfo.Items.Add("Set Tcp Parameter fail.");
            }
            else
                libInfo.Items.Add("The input ip is incorrect.");
        }
        public Boolean CheckIPValid(String strIP)
        {
            //  Split string by ".", check that array length is 3
            char chrFullStop = '.';
            string[] arrOctets = strIP.Split(chrFullStop);
            if (arrOctets.Length != 4)
                return false;
            //  Check each substring checking that the int value is less than 255 and that is char[] length is !> 2
            Int16 MAXVALUE = 255;
            Int32 temp; // Parse returns Int32
            foreach (String strOctet in arrOctets)
            {
                if (strOctet.Length > 3)
                    return false;
                temp = int.Parse(strOctet);
                if (temp > MAXVALUE)
                    return false;
            }
            return true;

        }
        private void rbFreq_Others_CheckedChanged(object sender, EventArgs e)
        {
            if (rbFreq_Others.Checked)
            {
                checkedlibFrePoint.Visible = true;
                lbFreqPoints.Visible = true;
            }
            else
            {
                checkedlibFrePoint.Visible = false;
                lbFreqPoints.Visible = false;
            }
        }

        private void btnGetFrequency_Click(object sender, EventArgs e)
        {
            int freqNum = 0;
            int[] points = new int[120];
            if (Api.GetFrequency(255, ref freqNum, ref points) != MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Get Frequency Parameter fail.");
                rbFreq_China.Checked = false;
                rbFreq_NAmerica.Checked = false;
                rbFreq_Europe.Checked = false;
                rbFreq_Others.Checked = false;
                return;
            }
            libInfo.Items.Add("Get Frequency Parameter success.");
            if (freqNum == 0)
                switch (points[0])
                {
                    case 0:
                        rbFreq_China.Checked = true;
                        break;
                    case 1:
                        rbFreq_NAmerica.Checked = true;
                        break;
                    case 2:
                        rbFreq_Europe.Checked = true;
                        break;
                }
            else
            {
                rbFreq_Others.Checked = true;
                checkedlibFrePoint.Visible = true;
                lbFreqPoints.Visible = true;
                for (int j = 0; j < checkedlibFrePoint.Items.Count; j++)
                    checkedlibFrePoint.SetItemChecked(j, false);
                for (int i = 0; i < freqNum; i++)
                {
                    if (points[i] <= 120)
                        checkedlibFrePoint.SetItemChecked(points[i] / 2, true);
                    else
                    {
                        libInfo.Items.Add("The Frequency point is illegal.");
                        break;
                    }
                }
            }
        }

        private void btnSetFrequency_Click(object sender, EventArgs e)
        {
            int freqNum = 0;
            int[] points = new int[120];
            if (rbFreq_China.Checked)
                points[0] = 0;
            if (rbFreq_NAmerica.Checked)
                points[0] = 1;
            if (rbFreq_Europe.Checked)
                points[0] = 2;
            if (rbFreq_Others.Checked)
            {
                for (int j = 0; j < checkedlibFrePoint.Items.Count; j++)
                {
                    if (checkedlibFrePoint.GetItemChecked(j))
                    {
                        points[freqNum] = 2 * j;
                        freqNum++;
                    }
                }
            }
            if (Api.SetFrequency(255, freqNum, points) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set Frequency Parameter success.");
                return;
            }
            libInfo.Items.Add("Set Frequency Parameter fail.");
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            libInfo.Items.Clear();
        }

        private void tabControl_Deselected(object sender, TabControlEventArgs e)
        {
            if (tabControl.SelectedTab != tabPage_EPCMultiTag)
            {
                if (btnIdentify.Text == "Stop")
                    btnIdentify_Click(sender, e);
                if (btnMultiTagRead.Text == "Stop")
                    btnMultiTagRead_Click(sender, e);
                if (btnMultiTagWrite.Text == "Stop")
                    btnMultiTagWrite_Click(sender, e);
            }
            if (tabControl.SelectedTab != tabPage_6B)
            {
                if (btnISOIdentify.Text == "Stop")
                    btnISOIdentify_Click(sender, e);
                if (btnIsoMultiTagRead.Text == "Stop")
                    btnIsoMultiTagRead_Click(sender, e);
            }
        }

        private void btnGetBuzzer_Click(object sender, EventArgs e)
        {
            byte state = 1;
            if (Api.GetBuzzerLED(255, ref state) == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                if (state == 3)
                    rbBuzzerON.Checked = true;
                else if (state == 0)
                    rbBuzzerOFF.Checked = true;
                libInfo.Items.Add("Get Buzzer and LED success.");
            }
            else
            {
                libInfo.Items.Add("Get Buzzer and LED fail.");
                rbBuzzerON.Checked = false;
                rbBuzzerON.Checked = false;
            }
        }

        private void btnSetBuzzer_Click(object sender, EventArgs e)
        {
            int status = 0;
            if (rbBuzzerON.Checked)
                status = Api.BuzzerLEDON(255);
            else
                status = Api.BuzzerLEDOFF(255);
            if (status == MR6100Api.MR6100Api.SUCCESS_RETURN)
            {
                libInfo.Items.Add("Set Buzzer and LED success.");
                btnResetReader_Click(sender, e);
            }
            else
                libInfo.Items.Add("Set Buzzer and LED fail.");
        }
        int iReconnect = 0;
        private void timerReconnect_Tick(object sender, EventArgs e)
        {
            if (status == 2009)
            {
                libInfo.Items.Add("Disconnect at: " + DateTime.Now.ToString() + "." + DateTime.Now.Second + "." + DateTime.Now.Millisecond);
                if (MR6100Api.MR6100Api.PortType == 1)
                {
                    if (Api.isNetWorkConnect(strIP))
                    {
                        status = Api.TcpConnectReader(strIP, port);
                        if (status == MR6100Api.MR6100Api.SUCCESS_RETURN)
                        {
                            iReconnect = 0;
                            libInfo.Items.Add("Reconnect the reader success.");
                            libInfo.Items.Add(DateTime.Now.ToString() + "." + DateTime.Now.Second + "." + DateTime.Now.Millisecond);
                        }
                        else
                        {
                            iReconnect++;
                            libInfo.Items.Add("Aren't able to send command to the reader.");
                        }
                    }
                    else
                    {
                        iReconnect++;
                        libInfo.Items.Add("Can't find the reader ip,reader disconnect.");
                    }
                }
            }
            if (iReconnect > 25)
            {
                if (btnIdentify.Text == "Stop")
                    btnIdentify_Click(sender, e);
                if (btnMultiTagRead.Text == "Stop")
                    btnMultiTagRead_Click(sender, e);
                if (btnMultiTagWrite.Text == "Stop")
                    btnMultiTagWrite_Click(sender, e);
                if (btnISOIdentify.Text == "Stop")
                    btnISOIdentify_Click(sender, e);
                if (btnIsoMultiTagRead.Text == "Stop")
                    btnIsoMultiTagRead_Click(sender, e);
                timerReconnect.Enabled = false;
                btnDiscon_Click(sender, e);
                libInfo.Items.Add("Can't find the ip in the network,please check your reader.");
                iReconnect = 0;
            }
        }
    }
}
