
// MfcStartDlg.h: 헤더 파일
//

#pragma once


// CMfcStartDlg 대화 상자
// A : B의 형태 -> B에 있는 속성을 상속받아 A를 생성할 것 이다.
class CMfcStartDlg : public CDialogEx
{
// 생성입니다.
public:
	// 해당 다이얼로그의 부모는 없다.
	CMfcStartDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	//멤버 변수 선언
	enum FourOP m_selectedOP; //사용자가 +,-,X,/ 중 무엇을 선택했는지 저장하는 변수
	double m_nFirstOperand;      //사용자가 입력한 첫번째 연산자
	double m_nSecondOperand;     //사용자가 입력한 두번째 연산자
	double m_dResult;         //계산결과


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_DIALOG };
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

public:
	// 헝가리안 표기+자료형 표기
	CString m_EditDisplay;
	CString m_EditExpress;
	CMFCButton Btn_Result;
	afx_msg void OnBnClickedBtnCancel();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtndivide();
	afx_msg void OnBnClickedBtnMultiply();
	afx_msg void OnBnClickedBtnMinus();
	afx_msg void OnBnClickedBtnPlus();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedBtnDot();
};

enum FourOP {
	PLUS = 1001,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NONE
};
