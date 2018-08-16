#include "stdafx.h"
#include "CBall.h"


CBall::CBall()
{
}

CBall::CBall(CDC* Dc)
{
	hBitmapBall = LoadImage(0, TEXT("Pelotita.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBitmapBall));
	bmDC.CreateCompatibleDC(Dc);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
	bmp.GetBitmap(&m_BallSizes);
	m_PosX = 0;
	m_PosY = 0;
}

CBall::~CBall()
{
}

void CBall::PaintBall(CDC* Dc,int Height,int Width, int WndTop, int WndLeft)
{
	Dc->BitBlt(WndTop, WndLeft, Height, Width, &bmDC, 0, 0, SRCCOPY);
}
