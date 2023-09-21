// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage �޽��� ó�����Դϴ�.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	MoveWindow(0,0,640,480);
	InitImage();

	return TRUE;    // return TRUE unless you set the focus to a control
					// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this);	// device context for painting
						// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
						// �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	if (m_Image) {
		m_Image.Draw(dc, 0, 0);
	}
	
	drawData(&dc);
}

void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;								// color�� display �ϱ� ���� ����

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {							// ��� �̹������� Ȯ��
		// ��Ʈ�� �̹����� ���� ���̺��� ����
		static RGBQUAD rgb[256];				// ��Ʈ�� �̹����� ���� ���̺��� ����
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_Image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}

void CDlgImage::drawData(CDC *pDC)
{
	CRect rect;

	CPen pen;											// ������ �����ϱ� ���� CPen ��ü ����
	pen.CreatePen(PS_SOLID, 5, COLOR_GREEN);		
	CPen* pOldPen = pDC->SelectObject(&pen);			// ������ ���� ������ ������

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(2,2);							//�簢������ �׷��� rect ũ�� ���� (�ʺ�, ����) 
		pDC->Ellipse(rect);
	}
	pDC->SelectObject(pOldPen);							// �����ߴ� ���� ������ ������
}