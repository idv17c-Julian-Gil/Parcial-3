#pragma once
#include"CLevel.h"

class CBall
{
private:
	CBall();
public:
	CBall(CDC* Dc);
	~CBall();

public:
	int m_PosX;
	int m_PosY;
	CLevel Level;
	CDC bmDC;
	BITMAP m_BallSizes;
	int m_BallHeight = m_BallSizes.bmHeight;
	int m_BallWidth = m_BallSizes.bmWidth;
	HANDLE hBitmapBall;

public:
	void PaintBall(CDC* Dc,int Width, int Heigth, int WndTop, int WndLeft);
};