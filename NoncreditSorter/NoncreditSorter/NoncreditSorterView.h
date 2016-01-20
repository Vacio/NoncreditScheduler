
// NoncreditSorterView.h : interface of the CNoncreditSorterView class
//

#pragma once


class CNoncreditSorterView : public CFormView
{
protected: // create from serialization only
	CNoncreditSorterView();
	DECLARE_DYNCREATE(CNoncreditSorterView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_NONCREDITSORTER_FORM };
#endif

// Attributes
public:
	CNoncreditSorterDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CNoncreditSorterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NoncreditSorterView.cpp
inline CNoncreditSorterDoc* CNoncreditSorterView::GetDocument() const
   { return reinterpret_cast<CNoncreditSorterDoc*>(m_pDocument); }
#endif

