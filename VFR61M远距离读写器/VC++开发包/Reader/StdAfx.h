// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__5B02688D_9BD8_4BFF_8356_4E2633BECF00__INCLUDED_)
#define AFX_STDAFX_H__5B02688D_9BD8_4BFF_8356_4E2633BECF00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

/////////////////////////////////////////////////////////////////////////////
/*****************************¶¯Ì¬¿âDLL*************************************/
#include <math.h>
#include <winsock2.h>
#include <windows.h>
#define EPCLEN 12
#define SIXBLEN 8
#pragma   comment(lib,"Ws2_32.lib")
//struct hComSocket
//{
//	HANDLE hCom;
//	SOCKET sockClient;
//};

struct GetData
{
	int Len;
	int Ant;
	unsigned char data[32];
};

//struct BufferData
//{
//	int Len;
//	int Ant;
//	unsigned char Data[512];
//};

//struct WordptrAndLength
//{
//	int MembankMask;
//	int ReserveWordPtr;
//	int ReserveWordCnt;
//	int EpcWordPtr;
//	int EpcWordCnt;
//	int TidWordPtr;
//	int TidWordCnt;
//	int UserWordPtr;
//	int UserWordCnt;
//};

//struct MutiWriteParam
//{
//	int MemBank;
//	int StartAddr;;
//	int WriteLen;
//	unsigned char WriteValue[20];
//};

//struct ReaderTime
//{
//	unsigned char YearH;
//	unsigned char YearL;
//	unsigned char Month;
//	unsigned char Day;
//	unsigned char Hour;
//	unsigned char Minute;
//	unsigned char Second;
//};

#include "RFID_StandardProtocol.h"
#pragma comment(lib,"RFID_StandardProtocol.lib")
#include <vector>
using namespace std;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_STDAFX_H__5B02688D_9BD8_4BFF_8356_4E2633BECF00__INCLUDED_)
