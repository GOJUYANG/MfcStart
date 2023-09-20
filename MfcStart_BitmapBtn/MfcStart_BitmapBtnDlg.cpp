
// MfcStart_BitmapBtnDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MfcStart_BitmapBtn.h"
#include "MfcStart_BitmapBtnDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMfcStartBitmapBtnDlg 대화 상자



CMfcStartBitmapBtnDlg::CMfcStartBitmapBtnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_BITMAPBTN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcStartBitmapBtnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcStartBitmapBtnDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_ON_OFF, &CMfcStartBitmapBtnDlg::OnBnClickedBtnOnOff)
END_MESSAGE_MAP()


// CMfcStartBitmapBtnDlg 메시지 처리기

BOOL CMfcStartBitmapBtnDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다. 
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.


	InitButtons();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMfcStartBitmapBtnDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMfcStartBitmapBtnDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMfcStartBitmapBtnDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CMfcStartBitmapBtnDlg::OnEraseBkgnd(CDC* pDC)
{
	CPngImage image;				// PNG 이미지를 처리할 image 객체를 선언
	image.Load(IDB_BASE, nullptr);  // IDB_BASE에 image 객체에 로드합니다. 이미지 파일을 메모리로 불러옴

	CDC dc;							// 이미지를 그리는 임시 그래픽 디바이스 컨텍스트 dc를 생성
	dc.CreateCompatibleDC(pDC);     // 이미지를 그리기 위한 임시 컨텍스트 생성
	CBitmap* pOldBitmap = dc.SelectObject(&image); // dc를 통해 해당 이미지를 그림

	pDC->BitBlt(0, 0, 640, 480, &dc, 0, 0, SRCCOPY); // pDC로 이미지를 복사 (다이얼로그의 배경이 해당 이미지로 설정)
	dc.SelectObject(pOldBitmap);					 //  dc를 정리하고 비트맵 자원을 해제할
	return TRUE;									 //  함수가 성공적으로 처리되었음 반환

	return CDialogEx::OnEraseBkgnd(pDC);
}

void CMfcStartBitmapBtnDlg::InitButtons()
{
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CRect rect(0, 0, 100, 50);

	GetDlgItem(IDC_BTN_ON_OFF)->GetWindowRect(&rect);  // 현재 IDC_BTN_ON_OFF의 WINDOW에 해당하는 좌표값을 가져온다.
	//GetDlgItem(IDC_BTN_ON_OFF)->GetClientRect(&rect);  // 현재 IDC_BTN_ON_OFF의 Client에 해당하는 좌표값을 가져온다.

	m_pBtnOnOff = new CBitmapButton;            // new 가 있으면 delete를 해줘야한다.
	m_pBtnOnOff->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rect, this, IDC_BTN_ON_OFF);
	m_pBtnOnOff->LoadBitmaps(IDB_ON, IDB_OFF);	// Default, Selected 를 IDB_ON 이라는 ID값을 가진 Bitmap으로 설정하겠다.
	m_pBtnOnOff->SizeToContent();
}

void CMfcStartBitmapBtnDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pBtnOnOff) delete m_pBtnOnOff;
}


void CMfcStartBitmapBtnDlg::OnBnClickedBtnOnOff()
{
	static bool bOn = false;
	if (bOn) {
		m_pBtnOnOff->LoadBitmaps(IDB_ON);
	}
	else {
		m_pBtnOnOff->LoadBitmaps(IDB_OFF);
	}
	bOn = !bOn;
}
