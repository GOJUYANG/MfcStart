
// MFCStart_Calculator_2Dlg.h: 헤더 파일
//

#pragma once


// CMFCStartCalculator2Dlg 대화 상자
class CMFCStartCalculator2Dlg : public CDialogEx
{
// 생성입니다.
private:
	char m_operater_flag = 0;   // plus:0 / minus:1 / multiply:2 / divide:3
	char m_step = 0;			// 연산자 확인 변수
	int m_count = 0;			// 연산자 카운트 변수
	double m_value = 0;			// 숫자값을 저장하는 변수
	
public:
	CMFCStartCalculator2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	void M_Operate(double m_value_two);					// 사칙연산을 위한 추가함수입니다.
	CFont m_font;
	LOGFONT logfont;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_CALCULATOR_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMultyply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedClear();
};
