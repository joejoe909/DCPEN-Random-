#include <random>
// DCPEN testingView.cpp : implementation of the CDCPENtestingView class
//

#include "stdafx.h"ra
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DCPEN testing.h"
#endif

#include "DCPEN testingDoc.h"
#include "DCPEN testingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
RECT windowRect;

// CDCPENtestingView

IMPLEMENT_DYNCREATE(CDCPENtestingView, CView)

BEGIN_MESSAGE_MAP(CDCPENtestingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_REDRAW, &CDCPENtestingView::OnRedraw)
END_MESSAGE_MAP()

// CDCPENtestingView construction/destruction

CDCPENtestingView::CDCPENtestingView()
{
	// TODO: add construction code here

}

CDCPENtestingView::~CDCPENtestingView()
{
}

BOOL CDCPENtestingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDCPENtestingView drawing

void CDCPENtestingView::OnDraw(CDC* pDC)
{
	CDCPENtestingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	CGdiObject* pOldPen = pDC->SelectStockObject(DC_PEN);
	CGdiObject* pOldBrush = pDC->SelectStockObject(NULL_BRUSH);
	
	unsigned char  R, G, B;
	int t, l, r, b;
	
	//Draw 100 circles with random size and color.

	CRect aRect;
	GetClientRect(&aRect);
	CRect *pRect = &aRect;
	
	
	/*
	aRect.top = aRect.top + 20;
	aRect.bottom = aRect.bottom - 20;
	aRect.left = aRect.left + 20;
	aRect.right = aRect.right - 20;
	*/
	for (int i = 1; i<200; i++)
	{
		
		pDC->Rectangle(&aRect);
		//pDC->SetWidth(3);


		t = rnd_corTB(aRect);
		l = rnd_LR(aRect);
		r = rnd_LR(aRect);
		b = rnd_corTB(aRect);
		
		R = rand();
		G = rand();
		B = rand();

		CRect rect(t, l, r, b);
		CRect *Prect = &rect;
		rect.NormalizeRect();
		//limitRect(Prect, pRect);
		//turn this into a function that return a true if it was done correctly
		
		//if (rect.right > aRect.right) rect.right = aRect.right - 20;
		//if (rect.bottom > aRect.bottom) rect.bottom = aRect.bottom - 20;
		//if (rect.top  < aRect.top) rect.top = aRect.top + 20;
		//if (rect.left < aRect.left) rect.left = aRect.left + 20;
		
		limitRect(pRect, Prect);

		pDC->SetDCPenColor(RGB(R, G, B));
		pDC->Rectangle(rect);
		//pDC->SetDCPenColor(RGB(255, 255, 255));
		//pDC->Rectangle(tst_Rect);

		//for (float g = 0; g < 1000000; g++);

	}

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	// TODO: add draw code for native data here
}


// CDCPENtestingView printing

BOOL CDCPENtestingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDCPENtestingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDCPENtestingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

int CDCPENtestingView::rnd()
{
	int randomize_col;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 255);
	return (randomize_col = dist(mt));


}

int CDCPENtestingView::rnd_corTB(CRect &rRect)
{
	int randomize_cord;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(rRect.top + 20, rRect.bottom-20); //call function to get window size here.
	return(randomize_cord = dist(mt));
}

int CDCPENtestingView::rnd_LR(CRect &rRect)
{
	int randomize_cord;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(rRect.left + 20, rRect.right -20); //call function to get window size here.
	return(randomize_cord = dist(mt));
}

CRect CDCPENtestingView::limitRect(CRect *pnt_aRect, CRect *pnt_rect)
{
	//turn this into a function that return a true if it was done correctly
	if (pnt_rect->left < pnt_aRect->left) pnt_rect->left = pnt_aRect->left + 20;
	if (pnt_rect->top < pnt_aRect->top) pnt_rect->top = pnt_aRect->top + 20;
	if (pnt_rect->right > pnt_aRect->right) pnt_rect->right = pnt_aRect->right - 20;
	if (pnt_rect->bottom > pnt_aRect->bottom) pnt_rect->bottom = pnt_aRect->bottom - 20;
	
	
	return *pnt_rect;
}


// CDCPENtestingView diagnostics

#ifdef _DEBUG
void CDCPENtestingView::AssertValid() const
{
	CView::AssertValid();
}

void CDCPENtestingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDCPENtestingDoc* CDCPENtestingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDCPENtestingDoc)));
	return (CDCPENtestingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDCPENtestingView message handlers


void CDCPENtestingView::OnRedraw()
{
	// TODO: Add your command handler code here
	RedrawWindow();
}
