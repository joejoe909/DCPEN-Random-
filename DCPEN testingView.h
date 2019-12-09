
// DCPEN testingView.h : interface of the CDCPENtestingView class
//

#pragma once
#include <random>
#include <windows.h>

class CDCPENtestingView : public CView
{
protected: // create from serialization only
	CDCPENtestingView();
	DECLARE_DYNCREATE(CDCPENtestingView)

// Attributes
public:
	CDCPENtestingDoc* GetDocument() const;
	virtual int rnd();
	virtual int rnd_corTB(CRect &rRect);
	virtual int rnd_LR(CRect &rRect);
	CRect limitRect(CRect *pnt_aRect, CRect *pnt_rect);
	

	BOOL WINAPI GetWindowRect(_In_  HWND   hWnd,_Out_ LPRECT lpRect);

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
	virtual ~CDCPENtestingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRedraw();
};

#ifndef _DEBUG  // debug version in DCPEN testingView.cpp
inline CDCPENtestingDoc* CDCPENtestingView::GetDocument() const
   { return reinterpret_cast<CDCPENtestingDoc*>(m_pDocument); }
#endif

