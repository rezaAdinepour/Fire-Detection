
// FireDetectionView.cpp : implementation of the CFireDetectionView class
//

//           ******************************************************
//          **   course         : Advanced Programming            **
//         ***   HomeWork       : 09                              ***
//        ****   Topic          : Image Processing                ****
//        ****   AUTHOR         : Reza Adinepour                  ****
//         ***   Student ID:    : 9814303                         ***
//          **   Github         : github.com/rezaAdinepour/       **
//           ******************************************************

#include "pch.h"
#include "framework.h"

#include "Utils.h"

// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FireDetection.h"
#endif

#include "FireDetectionDoc.h"
#include "FireDetectionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFireDetectionView

IMPLEMENT_DYNCREATE(CFireDetectionView, CView)

BEGIN_MESSAGE_MAP(CFireDetectionView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFireDetectionView construction/destruction

CFireDetectionView::CFireDetectionView() noexcept
{
	// TODO: add construction code here

}

CFireDetectionView::~CFireDetectionView()
{
}

BOOL CFireDetectionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFireDetectionView drawing

void CFireDetectionView::OnDraw(CDC* pDC)
{
	CFireDetectionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (!pDoc->left_out_frame.empty()) {
		HDC hdc = pDC->GetSafeHdc();

		CImage img;

		CRect cli_rc, left_rc, right_rc;

		GetClientRect(&cli_rc);

		int max_width = (cli_rc.Width() - 30) / 2;
		int max_height = cli_rc.Height() - 20;

		int w, h;


		// Draw Left Image
		double left_out_frame_ratio = (double)pDoc->left_out_frame.rows / pDoc->left_out_frame.cols;

		if (left_out_frame_ratio * max_width <= max_height) {
			w = max_width;
			h = w * left_out_frame_ratio;
		}
		else {
			h = cli_rc.Height() - 20;
			w = h / left_out_frame_ratio;
		}

		left_rc.SetRect(10, 10, 10 + w, 10 + h);

		Mat2CImage(pDoc->left_out_frame, img);

		img.Draw(hdc, left_rc, Gdiplus::InterpolationModeBilinear);


		// Draw Right Image
		double right_out_frame_ratio = (double)pDoc->right_out_frame.rows / pDoc->right_out_frame.cols;

		if (right_out_frame_ratio * max_width <= max_height) {
			w = max_width;
			h = w * right_out_frame_ratio;
		}
		else {
			h = cli_rc.Height() - 20;
			w = h / right_out_frame_ratio;
		}

		right_rc.SetRect(20 + max_width, 10, 20 + max_width + w, 10 + h);

		Mat2CImage(pDoc->right_out_frame, img);

		img.Draw(hdc, right_rc, Gdiplus::InterpolationModeBilinear);
	}
}


// CFireDetectionView printing

BOOL CFireDetectionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFireDetectionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFireDetectionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFireDetectionView diagnostics

#ifdef _DEBUG
void CFireDetectionView::AssertValid() const
{
	CView::AssertValid();
}

void CFireDetectionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFireDetectionDoc* CFireDetectionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFireDetectionDoc)));
	return (CFireDetectionDoc*)m_pDocument;
}
#endif //_DEBUG


// CFireDetectionView message handlers
