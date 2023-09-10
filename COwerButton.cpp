#include "pch.h"
#include "COwerButton.h"
IMPLEMENT_DYNAMIC(COwerButton, CButton)

COwerButton::COwerButton()
{
	m_bgColor = RGB(239, 233, 235);
	m_textColor = RGB(0, 0, 0);
	m_bPressed = FALSE;
}

COwerButton::~COwerButton()
{
}


BEGIN_MESSAGE_MAP(COwerButton, CButton)
	ON_WM_DRAWITEM()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// COwerButton 消息处理程序

void COwerButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect;
	GetClientRect(rect);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	UINT state = lpDrawItemStruct->itemState;
	CRect focusRect(rect);
	focusRect.DeflateRect(4, 4, 4, 4);
	if ((state & ODS_SELECTED) || (state & ODS_FOCUS)) {
		CPen pen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
		CBrush brush;
		brush.CreateStockObject(NULL_BRUSH);
		dc.SelectObject(&brush);
		dc.SelectObject(&pen);
		dc.FillSolidRect(rect, m_bgColor);
		dc.DrawFocusRect(focusRect);
		dc.Draw3dRect(rect, RGB(51, 51, 51), RGB(0, 0, 0));
	}
	else {
		CPen pen(PS_DOT, 1, m_bgColor);
		CBrush brush;
		brush.CreateStockObject(NULL_BRUSH);
		dc.SelectObject(&brush);
		dc.SelectObject(&pen);
		dc.FillSolidRect(rect, m_bgColor);
		dc.Rectangle(focusRect);
	}
	dc.DrawEdge(rect, BDR_RAISEDINNER | BDR_RAISEDOUTER, BF_BOTTOMLEFT | BF_TOPRIGHT);
	if (m_bPressed) {
		dc.DrawFocusRect(focusRect);
		dc.DrawEdge(rect, BDR_RAISEDINNER | BDR_SUNKENOUTER, BF_BOTTOMLEFT | BF_TOPRIGHT);
		dc.Draw3dRect(rect, RGB(51, 51, 51), RGB(0, 0, 0));
	}
	CString strText;
	GetWindowText(strText);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(m_textColor);
	if (state & ODS_DISABLED) {
		dc.SetTextColor(RGB(172, 168, 153));
	}
	dc.DrawText(strText, rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	dc.Detach();
}
//按钮被按下
void COwerButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bPressed = TRUE;

	CButton::OnLButtonDown(nFlags, point);
}

//按钮被释放
void COwerButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bPressed = FALSE;

	CButton::OnLButtonDown(nFlags, point);
}
//设置按钮背景的颜色 
void COwerButton::SetButtonBgColor(COLORREF color)
{
	m_bgColor = color;
}

//设置按钮字体的颜色
void COwerButton::SetButtonTextColor(COLORREF color)
{
	m_textColor = color;
}