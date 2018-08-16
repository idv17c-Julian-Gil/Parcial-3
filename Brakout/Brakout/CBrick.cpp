#include "stdafx.h"
#include "CBrick.h"

CBrick::CBrick()
{

}

CBrick::CBrick(CDC* pDC)
{
	hBitmapBrick = (HBITMAP)LoadImage(0, TEXT("BloqueRojo.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bmp.Attach(reinterpret_cast<HBITMAP>(hBitmapBrick));
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);

	bmp.GetBitmap(&m_BrickSizes);
	m_BrickHeight = m_BrickSizes.bmHeight;
	m_BrickWidth = m_BrickSizes.bmWidth;

	hBitmapBrick2 = (HBITMAP)LoadImage(0, TEXT("BloqueAzul.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bmp2.Attach(reinterpret_cast<HBITMAP>(hBitmapBrick2));
	bmDC2.CreateCompatibleDC(pDC);
	CBitmap* oldBMP2 = bmDC2.SelectObject(&bmp2);
	
	hBitmapBrick3 = (HBITMAP)LoadImage(0, TEXT("BloqueVerde.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bmp3.Attach(reinterpret_cast<HBITMAP>(hBitmapBrick3));
	bmDC3.CreateCompatibleDC(pDC);
	CBitmap* oldBMP3 = bmDC3.SelectObject(&bmp3);

	hBitmapBrick4 = (HBITMAP)LoadImage(0, TEXT("BloqueAmarillo.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bmp4.Attach(reinterpret_cast<HBITMAP>(hBitmapBrick4));
	bmDC4.CreateCompatibleDC(pDC);
	CBitmap* oldBMP4 = bmDC4.SelectObject(&bmp4);

	m_IsAlive = true;
}


CBrick::~CBrick()
{
}

void CBrick::PaintBrick(CDC * pDC, int BrickHeight, int BrickWidth, int MouseX,int MouseY, int m_Color)
{
	if (m_Color == 1)
		pDC->BitBlt(MouseX, MouseY, m_BrickWidth, m_BrickHeight, &bmDC, 0, 0, SRCCOPY); //Rojo
	else if (m_Color == 2)
		pDC->BitBlt(MouseX, MouseY, m_BrickWidth, m_BrickHeight, &bmDC2, 0, 0, SRCCOPY); //Azul
	else if (m_Color == 3)
		pDC->BitBlt(MouseX, MouseY, m_BrickWidth, m_BrickHeight, &bmDC3, 0, 0, SRCCOPY); //Verde
	else if (m_Color == 4)
		pDC->BitBlt(MouseX, MouseY, m_BrickWidth, m_BrickHeight, &bmDC4, 0, 0, SRCCOPY); //Amarillo
}
