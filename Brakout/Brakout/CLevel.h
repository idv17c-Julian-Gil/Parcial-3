#pragma once
//#include "BrakoutDlg.h"
class CLevel
{
public:
	CLevel();
	CLevel(CDC* pDC);
	~CLevel();

public: 
	RECT m_mySize;
	int m_PosX = m_mySize.top; //Posicion donde inicia la bola
	int m_PosY = m_mySize.left;
};

