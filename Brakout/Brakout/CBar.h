#pragma once
#include "CLevel.h"

class CBar
{
public:
	CBar();
	CBar(CDC* pDC);
	~CBar();
public:
	CLevel Level;
	CDC bmDC;
	BITMAP m_BarSizes;
	int m_BarHeight = m_BarSizes.bmHeight;
	int m_BarWidth = m_BarSizes.bmWidth;
	int Space = 40;
	HANDLE hBitmapBar;

public:
	void PaintBar(CDC* pDC, int BarWidth, int BarHeight, int MouseX, int WndDwn, int WndRght);
};

