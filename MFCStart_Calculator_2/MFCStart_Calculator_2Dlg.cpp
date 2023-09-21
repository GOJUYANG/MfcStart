
// MFCStart_Calculator_2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCStart_Calculator_2.h"
#include "MFCStart_Calculator_2Dlg.h"
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


// CMFCStartCalculator2Dlg 대화 상자



CMFCStartCalculator2Dlg::CMFCStartCalculator2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_CALCULATOR_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStartCalculator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCStartCalculator2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN_PLUS, &CMFCStartCalculator2Dlg::OnBnClickedPlus)
	ON_BN_CLICKED(BTN_MINUS, &CMFCStartCalculator2Dlg::OnBnClickedMinus)
	ON_BN_CLICKED(BTN_MULTYPLY, &CMFCStartCalculator2Dlg::OnBnClickedMultyply)
	ON_BN_CLICKED(BTN_DIVIDE, &CMFCStartCalculator2Dlg::OnBnClickedDivide)
	ON_BN_CLICKED(BTN_EQUAL, &CMFCStartCalculator2Dlg::OnBnClickedEqual)
	ON_BN_CLICKED(BTN_DOT, &CMFCStartCalculator2Dlg::OnBnClickedDot)
	ON_BN_CLICKED(BTN_BACKSPACE, &CMFCStartCalculator2Dlg::OnBnClickedBackspace)
	ON_BN_CLICKED(BTN_CLEAR, &CMFCStartCalculator2Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// CMFCStartCalculator2Dlg 메시지 처리기

BOOL CMFCStartCalculator2Dlg::OnInitDialog()
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
	m_font.CreatePointFont(150, TEXT("굴림"));
	GetDlgItem(IDC_EDIT1)->SetFont(&m_font);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCStartCalculator2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCStartCalculator2Dlg::OnPaint()
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
HCURSOR CMFCStartCalculator2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CMFCStartCalculator2Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	// 솔루션 탐색기 -> Resource.h -> 숫자버튼 매크로 확인
	// 숫자 버튼 0-9가 눌렀을 때만 작동한다.
	if (BTN_NUMBER0 <= wParam && wParam <= BTN_NUMBER9) 
	{
		CString str, number_str, str2; //문자열 변수 생성
		number_str.Format(L"%d", wParam - BTN_NUMBER0);  // 입력 값이 문자열 number_str에 저장된다.(숫자 0 기준)

		if (m_step == 0) // 연산자가 눌리지 않는 경우
		{
			GetDlgItemText(IDC_EDIT1, str2); // 사용자 입력값 가져오기
		}
		else if (m_step == 1)
		{
			GetDlgItemText(IDC_EDIT1, str);
			m_step = 0;
			m_value = _wtof(str);  // CString <-> Double (자료형변환)
		}
		SetDlgItemText(IDC_EDIT1, str2 + number_str);
	}

	return CDialogEx::OnCommand(wParam, lParam);
}


void CMFCStartCalculator2Dlg::OnBnClickedPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(IDC_EDIT1);
	GetDlgItemText(IDC_EDIT1, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1) //연산자 선택 1회
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 0; //덧셈일 때
	m_step = 1;          //연산자가 한번 눌러졌음

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + '+');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");             // 0이 사라질때까지 오른쪽 방향으로 가면서 지운다.
	omg.TrimRight(L".");             // .이 사라질때까지 오른쪽 방향으로 가면서 지운다. 소수점 이하 0 삭제
	SetDlgItemText(IDC_EDIT1, omg);
}


void CMFCStartCalculator2Dlg::OnBnClickedMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(IDC_EDIT1);
	GetDlgItemText(IDC_EDIT1, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1) //연산자 선택 1회
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 1; 
	m_step = 1;         

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + '-');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");             // 0이 사라질때까지 오른쪽 방향으로 가면서 지운다.
	omg.TrimRight(L".");             // .이 사라질때까지 오른쪽 방향으로 가면서 지운다. 소수점 이하 0 삭제
	SetDlgItemText(IDC_EDIT1, omg);
}


void CMFCStartCalculator2Dlg::OnBnClickedMultyply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(IDC_EDIT1);
	GetDlgItemText(IDC_EDIT1, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1) //연산자 선택 1회
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 2;
	m_step = 1;

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + "x");

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");             // 0이 사라질때까지 오른쪽 방향으로 가면서 지운다.
	omg.TrimRight(L".");             // .이 사라질때까지 오른쪽 방향으로 가면서 지운다. 소수점 이하 0 삭제
	SetDlgItemText(IDC_EDIT1, omg);
}


void CMFCStartCalculator2Dlg::OnBnClickedDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(IDC_EDIT1);
	GetDlgItemText(IDC_EDIT1, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1) //연산자 선택 1회
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 3;
	m_step = 1;

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + '/');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(IDC_EDIT1, omg);
}


void CMFCStartCalculator2Dlg::OnBnClickedEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	double m_value_two = GetDlgItemInt(IDC_EDIT1);
	GetDlgItemText(IDC_EDIT1, str);
	m_value_two = _wtof(str);

	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit2->SetWindowTextW(L" ");

	M_Operate(m_value_two);
	m_count = 0;

	str.Format(L"%f", m_value);
	str.TrimRight(L"0");             // 0이 사라질때까지 오른쪽 방향으로 가면서 지운다.
	str.TrimRight(L".");             // .이 사라질때까지 오른쪽 방향으로 가면서 지운다. 소수점 이하 0 삭제
	SetDlgItemText(IDC_EDIT1, str);
	m_step = 1;
	
}

void CMFCStartCalculator2Dlg::M_Operate(double m_value_two)
{
	switch (m_operater_flag)
	{
	case 0: // PLUS
		m_value += m_value_two;
		break;
	case 1: // MINUS
		m_value -= m_value_two;
		break;
	case 2: // MULTIPLY
		m_value *= m_value_two;
		break;
	case 3: // DIVIDE
		if (m_value_two != 0)
		{
			m_value /= m_value_two;
		}
		else
		{
			m_value = 0;
		}
		break;
	}
}

void CMFCStartCalculator2Dlg::OnBnClickedDot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + '.');
}


void CMFCStartCalculator2Dlg::OnBnClickedBackspace()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	str.Delete(0, 1);
	SetDlgItemText(IDC_EDIT1, str);
}

void CMFCStartCalculator2Dlg::OnBnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	//멤버 변수 초기화 
	m_value = 0;
	m_step = 0;
	m_operater_flag = 0;
	m_count = 0;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowTextW(L" ");

	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit2->SetWindowTextW(L" ");

	UpdateData(FALSE);
}