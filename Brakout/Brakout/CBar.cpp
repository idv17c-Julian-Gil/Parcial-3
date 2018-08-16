#include "stdafx.h"
#include "CBar.h"


CBar::CBar()
{
}

CBar::CBar(CDC * pDC)
{
	hBitmapBar = (HBITMAP)LoadImage(0, TEXT("Barra.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBitmapBar));
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
	bmp.GetBitmap(&m_BarSizes);
	
}


CBar::~CBar()
{
}

void CBar::PaintBar(CDC * pDC, int BarWidth, int BarHeight, int MouseX, int WndDwn, int WndRght)
{
	pDC->BitBlt(MouseX, WndDwn - Space, BarWidth, BarHeight, &bmDC, 0, 0, SRCCOPY); //Conocer tamanio del bitmap
}
