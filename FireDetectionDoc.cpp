
// FireDetectionDoc.cpp : implementation of the CFireDetectionDoc class
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
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FireDetection.h"
#endif

#include "FireDetectionDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFireDetectionDoc

IMPLEMENT_DYNCREATE(CFireDetectionDoc, CDocument)

BEGIN_MESSAGE_MAP(CFireDetectionDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CFireDetectionDoc::OnFileOpen)
END_MESSAGE_MAP()


// CFireDetectionDoc construction/destruction

CFireDetectionDoc::CFireDetectionDoc() noexcept
{
	// TODO: add one-time construction code here

}

CFireDetectionDoc::~CFireDetectionDoc()
{
}

BOOL CFireDetectionDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CFireDetectionDoc serialization

void CFireDetectionDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CFireDetectionDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CFireDetectionDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFireDetectionDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CFireDetectionDoc diagnostics

#ifdef _DEBUG
void CFireDetectionDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFireDetectionDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFireDetectionDoc commands


void CFireDetectionDoc::OnFileOpen()
{
	CFileDialog fdlg(true, L"", 0, 6, L"All Supported Formats(jpg, png)|*.jpg;*.jpeg;*.png|");

	if (fdlg.DoModal() == IDOK) {
		string tmp_path;

		tmp_path = CW2A(fdlg.GetPathName());

		Mat tmp_img;
		tmp_img = imread(tmp_path);

		if (tmp_img.empty()) {
			AfxMessageBox(L"Can't open file!", MB_ICONERROR);
		}
		else {
			left_out_frame = tmp_img.clone();

			Mat img_hsv;
			cvtColor(left_out_frame, img_hsv, COLOR_BGR2HSV);

			Mat mask;

			inRange(tmp_img, Scalar(0, 100, 100), Scalar(100, 255, 255), mask);

			bitwise_and(tmp_img, tmp_img, right_out_frame, mask);

			UpdateAllViews(0);
		}

		tmp_img.release();
	}
}
