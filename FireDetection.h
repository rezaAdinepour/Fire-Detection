
// FireDetection.h : main header file for the FireDetection application
//

//           ******************************************************
//          **   course         : Advanced Programming            **
//         ***   HomeWork       : 09                              ***
//        ****   Topic          : Image Processing                ****
//        ****   AUTHOR         : Reza Adinepour                  ****
//         ***   Student ID:    : 9814303                         ***
//          **   Github         : github.com/rezaAdinepour/       **
//           ******************************************************

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFireDetectionApp:
// See FireDetection.cpp for the implementation of this class
//

class CFireDetectionApp : public CWinApp
{
public:
	CFireDetectionApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFireDetectionApp theApp;
