
// MfcStartDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MfcStart.h"
#include "MfcStartDlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG //_DEBUG가 정의(def)되어있으면
#define new DEBUG_NEW
#undef THIS_FILE
static const char THIS_FILE[] = __FILE__;
#pragma comment(linker, "/entry.WinMainCRTStartup /subsystem:console")  // 콘솔 창을 띄운다.
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

// CMfcStartDlg 대화 상자
CMfcStartDlg::CMfcStartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_DIALOG, pParent)
	, m_EditDisplay(_T(""))
	, m_EditExpress(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, Btn_Result);
	DDX_Text(pDX, IDC_EDIT2, m_EditDisplay);
	DDX_Text(pDX, IDC_EDIT3, m_EditExpress);
}

BEGIN_MESSAGE_MAP(CMfcStartDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btn_CANCEL, &CMfcStartDlg::OnBnClickedBtnCancel)
	ON_BN_CLICKED(IDC_BTN_BACK, &CMfcStartDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN0, &CMfcStartDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN1, &CMfcStartDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN2, &CMfcStartDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN3, &CMfcStartDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN4, &CMfcStartDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN5, &CMfcStartDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN6, &CMfcStartDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN7, &CMfcStartDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN8, &CMfcStartDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN9, &CMfcStartDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_divide, &CMfcStartDlg::OnBnClickedBtndivide)
	ON_BN_CLICKED(IDC_BTN_Multiply, &CMfcStartDlg::OnBnClickedBtnMultiply)
	ON_BN_CLICKED(IDC_BTN_Minus, &CMfcStartDlg::OnBnClickedBtnMinus)
	ON_BN_CLICKED(IDC_BTN_Plus, &CMfcStartDlg::OnBnClickedBtnPlus)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CMfcStartDlg::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_BTN_Dot, &CMfcStartDlg::OnBnClickedBtnDot)
END_MESSAGE_MAP()


// CMfcStartDlg 메시지 처리기

BOOL CMfcStartDlg::OnInitDialog()
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
	Btn_Result.EnableWindowsTheming(FALSE); //윈도우 테마 제거
	Btn_Result.SetTextColor(RGB(255, 255, 255)); //글자색 변경
	Btn_Result.SetFaceColor(RGB(19, 18, 255)); //배경색 변경

	//헤더파일에 클래스 내부에 선언해준 멤버 변수의 초기화 루틴
	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMfcStartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMfcStartDlg::OnPaint()
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
HCURSOR CMfcStartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcStartDlg::OnBnClickedBtnCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nFirstOperand = 0;
	m_nSecondOperand = PLUS;
	m_dResult = 0;
	m_EditDisplay = "0";
	UpdateData(false);
}


void CMfcStartDlg::OnBnClickedBtnBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strText;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT3);

	if (pEdit != NULL)
	{
		pEdit->GetWindowText(strText);

		int length = strText.GetLength();
		if (length > 0) 
		{
			strText.Delete(length - 1, 1); // 가장 뒤의 문자를 삭제
			pEdit->SetWindowText(strText); // 수정된 문자열 setWindowText
		}
		if (length == 0)
		{
			strText = "0";
			pEdit->SetWindowText(strText); // 수정된 문자열 setWindowText
		}
	}
}


void CMfcStartDlg::OnBnClickedBtn0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);				     // 컨트롤값을 멤버 변수로 전달 : Edit 컨트롤의 값을 가져온다.
	m_EditDisplay = m_EditDisplay + '0'; // 기존 문자열의 맨 오른쪽에 0을 붙인다.
	UpdateData(FALSE);					 //  멤버 변수의 값을 컨트롤로 전송
}


void CMfcStartDlg::OnBnClickedBtn1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '1';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '2';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '3';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '4';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '5';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '6';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '7';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '8';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtn9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '9';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtndivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditExpress = _T(" / ") + m_EditDisplay;
	m_selectedOP = DIVIDE;                     //헤더파일 클래스 외부에서 선언된 enum 변수
	m_nFirstOperand = _ttof(m_EditDisplay);   //m_EditDisplay 문자열을 정수로 변경 (_ttoi) -> 첫번째 연산자에 저장
	m_EditDisplay = ' ';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtnMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditExpress = _T(" x ") + m_EditDisplay;
	m_selectedOP = MULTIPLY;                     //헤더파일 클래스 외부에서 선언된 enum 변수
	m_nFirstOperand = _ttof(m_EditDisplay);   //m_EditDisplay 문자열을 정수로 변경 (_ttoi) -> 첫번째 연산자에 저장
	m_EditDisplay = ' ';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtnMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditExpress = _T(" - ") + m_EditDisplay;
	m_selectedOP = MINUS;                     //헤더파일 클래스 외부에서 선언된 enum 변수
	m_nFirstOperand = _ttof(m_EditDisplay);   //m_EditDisplay 문자열을 정수로 변경 (_ttoi) -> 첫번째 연산자에 저장
	m_EditDisplay = ' ';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedBtnPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditExpress = _T(" + ") + m_EditDisplay; // 문자열 연결은 왼쪽 -> 오른쪽임을 명심하자
	m_selectedOP = PLUS;                     //헤더파일 클래스 외부에서 선언된 enum 변수
	m_nFirstOperand = _ttof(m_EditDisplay);   //m_EditDisplay 문자열을 double로 변경 (_ttof) -> 첫번째 피연산자에 저장
	m_EditDisplay = ' ';
	UpdateData(FALSE);
}


void CMfcStartDlg::OnBnClickedMfcbutton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditExpress = m_EditDisplay + m_EditExpress;
	m_nSecondOperand = _ttof(m_EditDisplay);

	switch (m_selectedOP) { // 해당 버튼을 누르기 직전의 선택에 따른 CASE 구분
	case PLUS:
		m_dResult = m_nFirstOperand + m_nSecondOperand;
		break;

	case MINUS:
		m_dResult = m_nFirstOperand - m_nSecondOperand;
		break;

	case MULTIPLY:
		m_dResult = m_nFirstOperand * m_nSecondOperand;
		break;

	case DIVIDE:
		m_dResult = m_nFirstOperand / m_nSecondOperand;
		break;
	default:
		m_dResult = 0;
	}

	m_EditDisplay.Format(_T("%f"), m_dResult);
	std::cout << m_EditDisplay << std::endl;
	
	UpdateData(FALSE);
}

void CMfcStartDlg::OnBnClickedBtnDot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditDisplay = m_EditDisplay + '.';
	UpdateData(FALSE);
}
