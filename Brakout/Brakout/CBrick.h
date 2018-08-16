#pragma once
using namespace std;
class CBrick
{
public:
	CBrick();
	CBrick(CDC* pDC);
	~CBrick();
public:
	int m_PosX;
	int m_PosY;
	bool m_IsAlive;
	BITMAP m_BrickSizes;
	int m_BrickHeight;
	int m_BrickWidth;
	HANDLE hBitmapBrick, hBitmapBrick2,hBitmapBrick3, hBitmapBrick4;
	CBitmap bmp, bmp2, bmp3, bmp4;
	CDC bmDC, bmDC2, bmDC3, bmDC4;
	CBitmap* oldBMP, oldBMP2, oldBMP3, oldBMP4;
	int m_Color = 0;

public:
	void PaintBrick(CDC* pDC, int BrickHeight, int BrickWidth, int MouseX, int MouseY, int m_Color);
};

