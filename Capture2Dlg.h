// Capture2Dlg.h : header file
//

#if !defined(AFX_CAPTURE2DLG_H__C791E960_23D3_499E_A0DF_59DF43A0A14B__INCLUDED_)
#define AFX_CAPTURE2DLG_H__C791E960_23D3_499E_A0DF_59DF43A0A14B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCapture2Dlg dialog

class CCapture2Dlg : public CDialog
{
// Construction
public:
	void capture();
    static	UINT video (LPVOID param);
	CCapture2Dlg(CWnd* pParent = NULL);	// standard constructor

	//自定义
	HWND m_hCapWnd;// 预示窗口
	BOOL m_bInit;// 捕捉器初始化
	CAPDRIVERCAPS m_CapDrvCap; // CAPDRIVERCAPS 结构，定义驱动器性能
	CAPSTATUS m_CapStatus; // CAPSTATUS 结构，定义捕捉窗口当前状态
    CAPTUREPARMS m_Parms;  // CAPTURE PARMS 结构，定义捕捉参数
    CString m_CapFileName; // 捕捉文件名称

// Dialog Data
	//{{AFX_DATA(CCapture2Dlg)
	enum { IDD = IDD_CAPTURE2_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCapture2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCapture2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFormat();
	afx_msg void OnSource();
	afx_msg void OnCompress();
	afx_msg void OnPhoto();
	afx_msg void OnBtnVideo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTURE2DLG_H__C791E960_23D3_499E_A0DF_59DF43A0A14B__INCLUDED_)
