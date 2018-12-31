// Capture2.h : main header file for the CAPTURE2 application
//

#if !defined(AFX_CAPTURE2_H__7A32FCF4_83A1_4DE3_886A_D433B6B57165__INCLUDED_)
#define AFX_CAPTURE2_H__7A32FCF4_83A1_4DE3_886A_D433B6B57165__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCapture2App:
// See Capture2.cpp for the implementation of this class
//

class CCapture2App : public CWinApp
{
public:
	CCapture2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCapture2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCapture2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTURE2_H__7A32FCF4_83A1_4DE3_886A_D433B6B57165__INCLUDED_)
