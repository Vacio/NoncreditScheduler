
// NoncreditSorter.h : main header file for the NoncreditSorter application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CNoncreditSorterApp:
// See NoncreditSorter.cpp for the implementation of this class
//

class CNoncreditSorterApp : public CWinApp
{
public:
	CNoncreditSorterApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNoncreditSorterApp theApp;
