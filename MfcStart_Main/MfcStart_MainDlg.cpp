﻿
// MfcStart_MainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MfcStart_Main.h"
#include "MfcStart_MainDlg.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

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


// CMfcStartMainDlg 대화 상자



CMfcStartMainDlg::CMfcStartMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_MAIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcStartMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}

BEGIN_MESSAGE_MAP(CMfcStartMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CREATE, &CMfcStartMainDlg::OnBnClickedBtnCreate)
END_MESSAGE_MAP()


// CMfcStartMainDlg 메시지 처리기

BOOL CMfcStartMainDlg::OnInitDialog()
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

void CMfcStartMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMfcStartMainDlg::OnPaint()
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
HCURSOR CMfcStartMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#define COLOR_YELLO RGB(255,255,0)
#define COLOR_BLACK RGB(0,0,0)
void CMfcStartMainDlg::OnBnClickedBtnCreate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);


	// 라인에딧 값 가져오기 = 원의 반지름 가져오기
	CString mText;
	m_Edit.GetWindowText(mText);
	int r = _wtoi(mText.GetBuffer()); // 반지름
	mText.ReleaseBuffer();

	cout << r << endl; // 출력 확인용

	// 다이얼로그의 클라이언트 영역의 크기와 위치를 얻기
	CRect rect;
	GetClientRect(&rect);

	// 원의 중심을 다이얼로그의 중앙으로 설정
	int centerX = rand() % rect.Width();
	int centerY = rand() % rect.Height();
	int radius = r;

	// 화면 칠하기
	dc.FillSolidRect(&rect, RGB(255, 255, 255));

	// 테두리 두께를 설정
	int penWidth = 5;

	// 검은 원 그리기
	CPen blackPen(PS_SOLID, penWidth, RGB(0, 0, 0)); // 검은색 펜
	CPen* OldPen = dc.SelectObject(&blackPen);
	CBrush blackBrush(RGB(0, 0, 0));
	CBrush* oldBrush = dc.SelectObject(&blackBrush);
	dc.Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	dc.SelectObject(oldBrush);
	dc.SelectObject(OldPen); // 검은색 펜으로 돌아갑니다.

	// 노란색 테두리 그리기
	CPen yellowPen(PS_SOLID, penWidth, COLOR_YELLO);
	dc.SelectObject(&yellowPen);
	dc.Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);

	// 검은색 십자 마크 그리기
	int crossSize = 10; // 십자 마크의 크기

	// 검은색 펜으로 변경
	CPen blackPen2(PS_SOLID, penWidth, RGB(0, 0, 0));
	dc.SelectObject(&blackPen2);
	dc.MoveTo(centerX - crossSize, centerY);
	dc.LineTo(centerX + crossSize, centerY);
	dc.MoveTo(centerX, centerY - crossSize);
	dc.LineTo(centerX, centerY + crossSize);
}
