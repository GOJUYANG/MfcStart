#pragma once
#include "afxdialogex.h"


// CDlglmage 대화 상자

class CDlglmage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlglmage)

public:
	CDlglmage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlglmage();

	// CImage 멤버 변수 생성
	CImage m_pImage;
	// CWindow의 형태를 m_pParent 형태로 멤버변수를 생성합니다.
	CWnd* m_pParent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlglmage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void DrawCircle(int x, int y, int radius);
	void DrawCircleColor(CDC& dc, int x, int y, int radius, int penWidth, COLORREF color);
};
