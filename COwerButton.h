#pragma once
#include <afxwin.h>
class COwerButton :
    public CButton
{
	DECLARE_DYNAMIC(COwerButton)
public:
	COwerButton();
	virtual ~COwerButton();
	void SetButtonBgColor(COLORREF color);
	void SetButtonTextColor(COLORREF color);

private:
	COLORREF m_bgColor;
	COLORREF m_textColor;
	BOOL m_bPressed;

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

