
// NoncreditSorterView.cpp : implementation of the CNoncreditSorterView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NoncreditSorter.h"
#endif

#include "NoncreditSorterDoc.h"
#include "NoncreditSorterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNoncreditSorterView

IMPLEMENT_DYNCREATE(CNoncreditSorterView, CFormView)

BEGIN_MESSAGE_MAP(CNoncreditSorterView, CFormView)
END_MESSAGE_MAP()

// CNoncreditSorterView construction/destruction

CNoncreditSorterView::CNoncreditSorterView()
	: CFormView(IDD_NONCREDITSORTER_FORM)
{
	// TODO: add construction code here

}

CNoncreditSorterView::~CNoncreditSorterView()
{
}

void CNoncreditSorterView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CNoncreditSorterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CNoncreditSorterView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CNoncreditSorterView diagnostics

#ifdef _DEBUG
void CNoncreditSorterView::AssertValid() const
{
	CFormView::AssertValid();
}

void CNoncreditSorterView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CNoncreditSorterDoc* CNoncreditSorterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNoncreditSorterDoc)));
	return (CNoncreditSorterDoc*)m_pDocument;
}
#endif //_DEBUG


// CNoncreditSorterView message handlers
