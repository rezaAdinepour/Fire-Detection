
// FireDetectionView.h : interface of the CFireDetectionView class
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


class CFireDetectionView : public CView
{
protected: // create from serialization only
	CFireDetectionView() noexcept;
	DECLARE_DYNCREATE(CFireDetectionView)

// Attributes
public:
	CFireDetectionDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CFireDetectionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FireDetectionView.cpp
inline CFireDetectionDoc* CFireDetectionView::GetDocument() const
   { return reinterpret_cast<CFireDetectionDoc*>(m_pDocument); }
#endif

