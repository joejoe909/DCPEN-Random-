
// DCPEN testing.h : main header file for the DCPEN testing application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDCPENtestingApp:
// See DCPEN testing.cpp for the implementation of this class
//

class CDCPENtestingApp : public CWinApp
{
public:
	CDCPENtestingApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDCPENtestingApp theApp;
