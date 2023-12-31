#pragma once


// CDlgImage 대화 상자입니다.

# define MAX_POINT 1000
class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	//CDlgImage의 멤버변수
	CImage m_Image;
	CWnd* m_pParent;
	int m_nDataCount = 0;
	CPoint m_ptData[MAX_POINT];


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	void drawData(CDC *pDC);

public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();
	void InitImage();
	afx_msg void OnPaint();
};
