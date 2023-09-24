// Dlglmage.cpp: 구현 파일
//

#include "pch.h"
#include "MfcStart_Main.h"
#include "afxdialogex.h"
#include "Dlglmage.h"
#include "MfcStart_MainDlg.h"
#include <iostream>


// CDlglmage 대화 상자

IMPLEMENT_DYNAMIC(CDlglmage, CDialogEx)

CDlglmage::CDlglmage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlglmage, pParent)
{
	// m_pParent의 주소가 해당 함수로 들어온 this가 가리키는 CMfcStartMainDlg의 주소값이 되는 것 + 부모윈도우설정
	m_pParent = pParent;
}

CDlglmage::~CDlglmage()
{
}

void CDlglmage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlglmage, CDialogEx)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlglmage 메시지 처리기
BOOL CDlglmage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 640, 480);
	CMfcStartMainDlg* pDlg = (CMfcStartMainDlg*)m_pParent;

	// 대화 상자 배경 색상 설정 (흰색)
	SetBackgroundColor(RGB(255, 255, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

#define COLOR_YELLO RGB(255,255,0)
#define COLOR_BLACK RGB(0,0,0)
void CDlglmage::DrawCircle(int x, int y, int radius) {
	CClientDC dc(this);

	CRect rect;
	GetClientRect(&rect);

    dc.SetBkMode(TRANSPARENT);						 // 배경을 투명하게 설정
    dc.FillSolidRect(&rect, RGB(255, 255, 255));     // 화면을 흰색으로 칠하기

	// 위 두줄을 주석처리하면 투명한 배경을 설정하지 않고 바로 노란색 테두리의 원을 그리게 됌.
	// 이전 노란원이 그려진 상태가 다음 노란원의 배경이미지가 되버린다. -> 노란원 누적 그리기

	int penWidth = 5;

	// 검은 원 그리기
	DrawCircleColor(dc, x, y, radius, penWidth, COLOR_BLACK);

	// 노란색 테두리 그리기
	CPen yellowPen(PS_SOLID, 5, COLOR_YELLO);
	dc.SelectObject(&yellowPen);
	dc.Ellipse(x - radius, y - radius, x + radius, y + radius);

	// 검은색 십자 마크 그리기
	int crossSize = 10; // 십자 마크의 크기

	// 검은색 펜으로 변경
	CPen blackPen2(PS_SOLID, 5, RGB(0, 0, 0));
	dc.SelectObject(&blackPen2);
	dc.MoveTo(x - crossSize, y);
	dc.LineTo(x + crossSize, y);
	dc.MoveTo(x, y - crossSize);
	dc.LineTo(x, y + crossSize);
}

void CDlglmage::DrawCircleColor(CDC& dc, int x, int y, int radius, int penWidth, COLORREF color) {

	CPen pen(PS_SOLID, penWidth, color);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush brush(color);
	CBrush* oldBrush = dc.SelectObject(&brush);
	dc.Ellipse(x - radius, y - radius, x + radius, y + radius);
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);
}
