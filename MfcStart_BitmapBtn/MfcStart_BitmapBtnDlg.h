
// MfcStart_BitmapBtnDlg.h: 헤더 파일
//

#pragma once


// CMfcStartBitmapBtnDlg 대화 상자
class CMfcStartBitmapBtnDlg : public CDialogEx
{
// 생성입니다.
public:
	CMfcStartBitmapBtnDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_BITMAPBTN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	CBitmapButton* m_pBtnOnOff;  // m_pBtnOnOff 변수에 대한 포인터(*)를 사용하여 메모리주소값만 만들었다. 
	void InitButtons();

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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnOnOff();
};
