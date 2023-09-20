
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
	ON_BN_CLICKED(IDC_BTN_SAVE, &CMfcStartCImageDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CMfcStartCImageDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CMfcStartCImageDlg::OnBnClickedBtnAction)
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
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;                             // color를 display 하기 위한 설정

	// m_image.Create(640, 480, 8); 
	m_image.Create(nWidth, -nHeight, nBpp);  
	if (nBpp == 8) {						 // 흑백 이미지인지 확인
											 // 비트맵 이미지의 색상 테이블을 설정
		static RGBQUAD rgb[256];		     // 비트맵 이미지의 색상 테이블을 저장
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;  // 흑백 이미지에 각 픽셀에 대한 색상 정보를 제공
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();          // 이미지의 한 행을 나타내는 너비

	// fm = field image, 이미지 포인터를 가리킬 때 일반적으로 사용하는 변수명
	// 생성된 m_image의 첫번째 포인터 값을 가져와 fm 변수에 저장하겠다.
    // 이미지의 행 너비를 가져와 nPitch 변수에 저장 -> 이미지의 한 행을 픽셀 단위로 탐색할 때 사용한다.
	unsigned char* fm = (unsigned char*)m_image.GetBits();   

	memset(fm, 0xff, sizeof(unsigned char)*nWidth*nHeight);

	//for (int j = 0; j < nHeight; j++) {       // 이미지의 모든 픽셀을 순회
	//	for (int i = 0; i < nWidth; i++) {    // 각 픽셀에 대해 fm 배열을 사용하여 값을 설정 
	//		fm[j * nPitch + i] = (j % 0xff);     // 모든 픽셀을 255로 설정
	//	} 
	//}

	// 행(row) 좌표 * nPitch + 열(column) 좌표
	//fm[0 * nPitch + 0] = 128;  // 특정 좌표의 픽셀의 색상을 변경한다.

	UpdateDisplay();
}

CString g_strFileImage = _T("c:\\image\\save.bmp");

void CMfcStartCImageDlg::OnBnClickedBtnSave()
{
	m_image.Save(g_strFileImage);
}

void CMfcStartCImageDlg::OnBnClickedBtnLoad()
{
	if (m_image != NULL) {     // m_image 객체가 있는지 확인
		m_image.Destroy();     // 있다면 m_image 객체 파괴
							   // 이렇게 함으로써 이전의 로드 이미지를 제거하고 새로운 이미지 로드를 준비한다.
	}
	m_image.Load(g_strFileImage);

	UpdateDisplay();
}

// 자주 호출되는 코드의 함수화 작업
void CMfcStartCImageDlg::UpdateDisplay()   //Dlg.h에서 선언한 public 함수를 CMfcStartClmageDlg 클래스 내부 선언
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CMfcStartCImageDlg::moveRect() 
{
	// int nSttX = 0 으로 선언할 시 함수를 탈때마다 0으로 초기화되어버림
	// static 정적변수로 만들어서 초기화를 한번만 한다.
	static int nSttX = 0;
	static int nSttY = 0;

	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();    
	int nRadius = 10;					// 원의 반지름

	unsigned char* fm = (unsigned char*)m_image.GetBits();

	//memset(fm, 0xff, nWidth * nHeight);

	// 이전 원을 지우려면 이전 좌표에 반전 색상(m_image와 동일한 흰색)의 원을 그립니다.
	drawCircle(fm, nSttX, nSttY, nRadius, 0xff);

	// 새로운 좌표로 원을 그립니다.
	//nSttX++;
	//nSttY++;
	//drawCircle(fm, nSttX, nSttY, nRadius, nGray);

	//또는 전위연산자를 통해 먼저 nSttX 값을 증가시킨 후 drawCircle을 실행한다.
	drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray);

	UpdateDisplay();
}

void CMfcStartCImageDlg::OnBnClickedBtnAction()
{
	for (int i = 0; i < 400; i++)
	{
		moveRect();
		Sleep(10);
	}
}

BOOL CMfcStartCImageDlg::validImgPos(int x, int y)
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	CRect rect(0, 0, nWidth, nHeight);    // CRect - MFC에서 제공하는 사각형 좌표를 저장하기 위한 C++ 클래스 (영역을 생성함)
	return rect.PtInRect(CPoint(x, y));   // 어떤 포인트가 해당 영역에 들어가냐 안들어가냐를 BOOL 값으로 반환함
										  // 인수인 X,Y는 CPoint 형태로 넣어주어야한다.
}

void CMfcStartCImageDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {       // nRadius 반지름이므로 원의 총 높이는 nRadius * 2다.
		for (int i = x; i < x + nRadius * 2; i++) {
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius))
				fm[j * nPitch + i] = nGray;
		}
	}
}

BOOL CMfcStartCImageDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;   // 좌표 (i, j)와 원의 중심 좌표 (nCenterX, nCenterY) 간의 거리 (by 피타고라스 정리)

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}
