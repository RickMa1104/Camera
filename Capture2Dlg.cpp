// Capture2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Capture2.h"
#include "Capture2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCapture2Dlg dialog

CCapture2Dlg::CCapture2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCapture2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCapture2Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCapture2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCapture2Dlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCapture2Dlg, CDialog)
	//{{AFX_MSG_MAP(CCapture2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_FORMAT, OnFormat)
	//ON_BN_CLICKED(IDC_SOURCE, OnSource)
//	ON_BN_CLICKED(IDC_COMPRESS, OnCompress)
	ON_BN_CLICKED(IDC_PHOTO, OnPhoto)
//	ON_BN_CLICKED(IDC_BTN_VIDEO, OnBtnVideo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCapture2Dlg message handlers

BOOL CCapture2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	///*
	m_bInit=FALSE;
	CWnd *pWnd=AfxGetMainWnd()->GetDlgItem(IDC_VIDEO);//得到预示窗口指针
	CRect rect;
	pWnd->GetWindowRect(&rect); // 得到窗口大小
	m_hCapWnd=capCreateCaptureWindow((LPTSTR)TEXT("视频捕捉测试程序"),
		WS_CHILD|WS_VISIBLE|WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME,
		0,0,rect.Width(),rect.Width(),
		pWnd->GetSafeHwnd(),0); // 设置预示窗口
	ASSERT(m_hCapWnd);
	
	if(capDriverConnect(m_hCapWnd,0))
	{
		// 连接第0 号驱动器
		m_bInit=TRUE;
		
		//得到驱动器的性能
		capDriverGetCaps(m_hCapWnd,sizeof(CAPDRIVERCAPS), &m_CapDrvCap);
		
		if(m_CapDrvCap.fCaptureInitialized)
		{// 如果初始化成功
			capGetStatus(m_hCapWnd, &m_CapStatus,sizeof(m_CapStatus)); // 得到驱动器状态
			capPreviewRate(m_hCapWnd,30); // 设置预示帧频
			capPreview(m_hCapWnd,TRUE); // 设置预示方式
		}
		else{// 初始化未成功
			AfxMessageBox("视频捕捉卡初始化失败!");
			AfxGetMainWnd()->PostMessage(WM_CLOSE);
		}
	}
	else{// 未能连接到驱动器
		AfxMessageBox("与视频捕捉卡连接失败!");
		//	AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}

	//m_CapFileName="c:\\Capture.avi";// 设置捕获文件
	//capFileSetCaptureFile(m_hCapWnd,m_CapFileName.GetBuffer(255));
	
	//*/
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCapture2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCapture2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCapture2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCapture2Dlg::OnFormat() 
{
	// TODO: Add your control notification handler code here
	capDlgVideoFormat(m_hCapWnd);
}

void CCapture2Dlg::OnSource() 
{
	capDlgVideoSource(m_hCapWnd);	
}

void CCapture2Dlg::OnCompress() 
{
	capDlgVideoCompression(m_hCapWnd);
}

UINT CCapture2Dlg::video(LPVOID param)
{
   CCapture2Dlg * pTaskMain = (CCapture2Dlg *) param; 
   pTaskMain->capture();
   return 0 ;
}

void CCapture2Dlg::capture()
{
    SetCursor(LoadCursor(NULL, IDC_ARROW));
	capCaptureSequence(m_hCapWnd); // 捕捉到文件
}

void CCapture2Dlg::OnPhoto() 
{
	// TODO: Add your control notification handler code here
	char szNewFile[256]="";
	//GetDlgItem(IDC_EDIT)->GetWindowText(szNewFile,256);
	//if(strlen(szNewFile)==0)
	//{
		memcpy(szNewFile,"E:\NewFile.bmp",strlen("E:\NewFile.bmp"));
	//}
	capCaptureSingleFrame(m_hCapWnd);
	capFileSaveDIB(m_hCapWnd,szNewFile);
}

void CCapture2Dlg::OnBtnVideo() 
{
	// TODO: Add your control notification handler code here
	CString str;
	char szNewFile[256]="";
	GetDlgItem(IDC_EDIT)->GetWindowText(szNewFile,256);
	if(strlen(szNewFile)==0)
	{
		memcpy(szNewFile,"NewFile.avi",strlen("NewFile.avi"));
	}
	if(GetDlgItemText(IDC_BTN_VIDEO,str),str=="录像")
	{
		AfxBeginThread(video, this );
		SetDlgItemText(IDC_BTN_VIDEO,"停止");
	}
	else
	{
		capFileSaveAs(m_hCapWnd,szNewFile);	
		SetDlgItemText(IDC_BTN_VIDEO,"录像");
	}

}
