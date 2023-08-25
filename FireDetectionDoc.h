
// FireDetectionDoc.h : interface of the CFireDetectionDoc class
//

//           ******************************************************
//          **   course         : Advanced Programming            **
//         ***   HomeWork       : 09                              ***
//        ****   Topic          : Image Processing                ****
//        ****   AUTHOR         : Reza Adinepour                  ****
//         ***   Student ID:    : 9814303                         ***
//          **   Github         : github.com/rezaAdinepour/       **
//           ******************************************************


#pragma once

#include <opencv.hpp>

#if _DEBUG
	#pragma comment(lib, "opencv_world470d.lib")
#else
	#pragma comment(lib, "opencv_world470.lib")
#endif // _DEBUG

using namespace cv;
using namespace std;

class CFireDetectionDoc : public CDocument
{
protected: // create from serialization only
	CFireDetectionDoc() noexcept;
	DECLARE_DYNCREATE(CFireDetectionDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CFireDetectionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();

	Mat left_out_frame, right_out_frame;
};
