
// MfcStart_CImageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MfcStart_CImage.h"
#include "MfcStart_CImageDlg.h"
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


// CMfcStartCImageDlg 대화 상자



CMfcStartCImageDlg::CMfcStartCImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_CIMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcStartCImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcStartCImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CMfcStartCImageDlg::OnBnClickedBtnImage)
END_MESSAGE_MAP()


// CMfcStartCImageDlg 메시지 처리기

BOOL CMfcStartCImageDlg::OnInitDialog()
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMfcStartCImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMfcStartCImageDlg::OnPaint()
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
// 이 함수를 호출합니다.
HCURSOR CMfcStartCImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcStartCImageDlg::OnBnClickedBtnImage()
{
	int nWidth = 32;
	int nHeight = 24;
	int nBpp = 8;                             // color를 display 하기 위한 설정

	// m_image.Create(640, 480, 8); 
	m_image.Create(nWidth, nHeight, nBpp);   // 프로그램을 만들때 중요한 것은 함수 내에 인수를 숫자로 지정하지 않는것이다.
	if (nBpp == 8) {						 // 흑백 이미지인지 확인
											 // 비트맵 이미지의 색상 테이블을 설정
		static RGBQUAD rgb[256];		     // 비트맵 이미지의 색상 테이블을 저장
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;  // 흑백 이미지에 각 픽셀에 대한 색상 정보를 제공
		m_image.SetColorTable(0, 256, rgb);
	}

	// fm = field image, 이미지 포인터를 가리킬 때 일반적으로 사용하는 변수명
	// 생성된 m_image의 첫번째 포인터 값을 가져와 fm 변수에 저장하겠다.
    // 이미지의 행 너비를 가져와 nPitch 변수에 저장 -> 이미지의 한 행을 픽셀 단위로 탐색할 때 사용한다.
	unsigned char* fm = (unsigned char*)m_image.GetBits();   


	int nPitch = m_image.GetPitch();          // 이미지의 한 행을 나타내는 너비
	for (int j = 0; j < nHeight; j++) {       // 이미지의 모든 픽셀을 순회
		for (int i = 0; i < nWidth; i++) {    // 각 픽셀에 대해 fm 배열을 사용하여 값을 설정 
			fm[j * nPitch + i] = j % 255;     // 모든 픽셀을 255로 설정
		} 
	}

	// 행(row) 좌표 * nPitch + 열(column) 좌표
	//fm[0 * nPitch + 0] = 128;  // 특정 좌표의 픽셀의 색상을 변경한다.


	CClientDC dc(this);		  // this = 현재 다이얼로그. dc 변수를 초기화하겠다.
	m_image.Draw(dc, 0, 0);   // 이미지가 그려질 좌표를 설정한다.

	m_image.Save(_T("c:\\image\\save.bmp"));

}

// 효율적 프로그래밍
// 변수는 최소화
// 함수는 최대화


