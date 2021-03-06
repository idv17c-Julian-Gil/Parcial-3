
// BrakoutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Brakout.h"
#include "BrakoutDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBrakoutDlg dialog



CBrakoutDlg::CBrakoutDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BRAKOUT_DIALOG, pParent)
	, m_Txt(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBrakoutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_BtnPlay);
	DDX_Control(pDX, IDC_AREA, m_PlayArea);
	//DDX_Control(pDX, IDC_AREAjuego, m_GameAreaWind);
	//DDX_Control(pDX, IDC_StcZONADEJUEGO, m_Zonadejuego);
	//DDX_Control(pDX, IDC_ADD, m_BtnAdd);
	DDX_Control(pDX, IDC_UNDO, m_BtnUndo);
	DDX_Control(pDX, IDC_EDITORTXT, m_EditorTxt);
	DDX_Text(pDX, IDC_EDITORTXT, m_Txt);
	DDX_Control(pDX, IDC_BLUE, m_CreateBlueBrick);
	DDX_Control(pDX, IDC_YELLOW, m_CreateYellowBrick);
	DDX_Control(pDX, IDC_GREEN, m_CreateGreenBrick);
	DDX_Control(pDX, IDC_RED, m_CreateRedBrick);
	DDX_Control(pDX, IDC_RETURN, m_BtnReturn);
	DDX_Control(pDX, IDC_EDITOR, m_BtnEditor);
	DDX_Control(pDX, IDC_SAVE, m_BtnSave);
	//DDX_Control(pDX, IDC_LIVES, m_Lives);
}

BEGIN_MESSAGE_MAP(CBrakoutDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBrakoutDlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_STN_CLICKED(IDC_AREA, &CBrakoutDlg::OnStnClickedArea)
	ON_STN_CLICKED(IDC_StcZONADEJUEGO, &CBrakoutDlg::OnStnClickedStczonadejuego)
	ON_BN_CLICKED(IDC_BUTTON1, &CBrakoutDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_ADD, &CBrakoutDlg::OnBnClickedAdd)
	ON_EN_CHANGE(IDC_EDITORTXT, &CBrakoutDlg::OnEnChangeEdit1)
//	ON_BN_CLICKED(IDC_BUTTON4, &CBrakoutDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BLUE, &CBrakoutDlg::OnBnClickedBlue)
	ON_BN_CLICKED(IDC_YELLOW, &CBrakoutDlg::OnBnClickedYellow)
	ON_BN_CLICKED(IDC_UNDO, &CBrakoutDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_RED, &CBrakoutDlg::OnBnClickedRed)
	ON_BN_CLICKED(IDC_GREEN, &CBrakoutDlg::OnBnClickedGreen)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_RETURN, &CBrakoutDlg::OnBnClickedReturn)
	ON_BN_CLICKED(IDC_EDITOR, &CBrakoutDlg::OnBnClickedEditor)
	ON_BN_CLICKED(IDC_SAVE, &CBrakoutDlg::OnBnClickedSave)
END_MESSAGE_MAP()

// CBrakoutDlg message handlers

BOOL CBrakoutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_PlayArea.GetClientRect(&Level->m_mySize);
	pDC = m_PlayArea.GetDC();

	//Creacion de objetos
	Level = new CLevel(pDC);
	Bar = new CBar(pDC);
	Ball = new CBall(pDC);
	Brick = new CBrick(pDC);
	Editor = new CEditor();

	//Obtener tamaño del area de juego
	m_PlayArea.GetClientRect(&Level->m_mySize);
	
	//Asignacion de variables
	Bar->m_BarHeight = Bar->m_BarSizes.bmHeight;
	Bar->m_BarWidth = Bar->m_BarSizes.bmWidth;
	Ball->m_BallHeight = Ball->m_BallSizes.bmHeight;
	Ball->m_BallWidth = Ball->m_BallSizes.bmWidth;
	Level->m_PosX = Level->m_mySize.right;
	Level->m_PosY = Level->m_mySize.bottom;
	IsEditing = false;

	//Esconder Botones
	//m_BtnAdd.ShowWindow(SW_HIDE);
	m_BtnSave.ShowWindow(SW_HIDE);
	m_EditorTxt.ShowWindow(SW_HIDE);
	m_BtnUndo.ShowWindow(SW_HIDE);
	m_CreateBlueBrick.ShowWindow(SW_HIDE);
	m_CreateYellowBrick.ShowWindow(SW_HIDE);
	m_CreateGreenBrick.ShowWindow(SW_HIDE);
	m_CreateRedBrick.ShowWindow(SW_HIDE);
	m_BtnReturn.ShowWindow(SW_HIDE);

	//GetBitmapDimension()
	
	//Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBrakoutDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		m_PlayArea.GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBrakoutDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBrakoutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//OnTimer(1);
	m_BtnPlay.ShowWindow(SW_HIDE);
	m_BtnEditor.ShowWindow(SW_HIDE);
	//Aqui se debe cargar el nivel
	Editor->LoadLevel(Editor->LevelList[Editor->count]);
	SetTimer(1, 50, NULL);
}

void CBrakoutDlg::MoveBall()
{
	if (Ball->m_PosX >= Level->m_mySize.right - Ball->m_BallWidth)
	{
		Ball->m_PosX = Level->m_mySize.right - Ball->m_BallWidth;
		ModifyWidth = -ModifyWidth;
	}
	else if (Ball->m_PosX < 0)
	{
		Level->m_PosX = 0;
		ModifyWidth = -ModifyWidth;
	}
	if (Ball->m_PosY >= Level->m_mySize.bottom - Ball->m_BallHeight)
	{
		Ball->m_PosY = Level->m_mySize.bottom - Ball->m_BallHeight;
		ModifyHeight = -ModifyHeight;
	}
	else if (Ball->m_PosY < 0)
	{
		Ball->m_PosY = 0;
		ModifyHeight = -ModifyHeight;
	}

	for (int i = 0; i < Editor->Bricks.size(); i++)
	{
		if (Editor->Bricks.size()>0)
		{
			if (Ball->m_PosX + Ball->m_BallWidth > Editor->Bricks[i]->m_PosX + DirX&& Ball->m_PosX < Editor->Bricks[i]->m_PosX + NewBrick->m_BrickWidth - DirX)
			{
				if (Ball->m_PosY + Ball->m_BallHeight > Editor->Bricks[i]->m_PosY&&Ball->m_PosY < Editor->Bricks[i]->m_PosY + NewBrick->m_BrickHeight)
				{
					ModifyHeight = -ModifyWidth;
					Editor->Bricks[i]->m_IsAlive = false;
					delete(Editor->Bricks[i]);
					Editor->Bricks.erase(Editor->Bricks.begin() + i);
					break;
				}
			}
			if (Ball->m_PosY + Ball->m_BallHeight > Editor->Bricks[i]->m_PosY&&Ball->m_PosY < Editor->Bricks[i]->m_PosY + NewBrick->m_BrickHeight)
			{
				if (Ball->m_PosX + Ball->m_BallWidth > Editor->Bricks[i]->m_PosX +DirX && Ball->m_PosX< Editor->Bricks[i]->m_PosX + NewBrick->m_BrickWidth - DirX)
				{
					ModifyWidth = -ModifyHeight;
					Editor->Bricks[i]->m_IsAlive = false;
					delete(Editor->Bricks[i]);
					Editor->Bricks.erase(Editor->Bricks.begin() + i);
					break;
				}
			}
		}

	}
	if (Ball->m_PosY + Ball->m_BallWidth >= (Level->m_mySize.bottom - Bar->m_BarHeight))
	{
		if (Ball->m_PosX + Ball->m_BallHeight > MouseX && Ball->m_PosX < MouseX + Bar->m_BarWidth)
		{
			ModifyHeight = -ModifyHeight;
		}
	}
	if (Ball->m_PosY + Ball->m_BallHeight >= Level->m_mySize.bottom)
	{
		Ball->m_PosX = 0;
		Ball->m_PosY = 0;
		Lives--;
	}
	Ball->m_PosX += DirX*ModifyWidth;
	Ball->m_PosY += DirY*ModifyHeight;
}

void CBrakoutDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	//
	if (nIDEvent == 1)
	{
		//Editor->m_BrickAmount = Editor->Bricks.size();
		pDC->Rectangle(0, 0, Level->m_mySize.right, Level->m_mySize.bottom);
		for (int i = 0; i < Editor->Bricks.size(); i++)
		{
			if (Editor->Bricks[i]->m_IsAlive)
				NewBrick->PaintBrick(pDC, Editor->Bricks[i]->m_BrickHeight, Editor->Bricks[i]->m_BrickWidth, Editor->Bricks[i]->m_PosX, Editor->Bricks[i]->m_PosY, Editor->Bricks[i]->m_Color);
		}
		Bar->PaintBar(pDC, Bar->m_BarWidth, Bar->m_BarHeight, MouseX, Level->m_PosY, Level->m_PosX);
		Ball->PaintBall(pDC,Ball->m_BallHeight,Ball->m_BallWidth,Ball->m_PosX,Ball->m_PosY); 
		MoveBall();
		if (Lives == 0)
		{
			KillTimer(1);
			Defeat();
		}
		if (Editor->Bricks.empty())
		{
			Editor->count += 1;
			//Editor->m_Name = to_string(Editor->m_Levels) + ".txt";
			if (!(Editor->count > Editor->LevelList.size() - 1))
			{
				Editor->LoadLevel(Editor->LevelList[Editor->count]);
			}
			else
			{
				KillTimer(1);
				Victory();
			}
		}
	}
	else if (nIDEvent == 2)
	{
		pDC->Rectangle(0, 0, Level->m_mySize.right, Level->m_mySize.bottom);
		for (int i = 0; i < Editor->Bricks.size(); i++)
		{
			NewBrick->PaintBrick(pDC, Editor->Bricks[i]->m_BrickHeight, Editor->Bricks[i]->m_BrickWidth,Editor->Bricks[i]->m_PosX, Editor->Bricks[i]->m_PosY, Editor->Bricks[i]->m_Color);
		}
		Brick->PaintBrick(pDC, Brick->m_BrickHeight, Brick->m_BrickWidth, MouseX, MouseY,Brick->m_Color);
	}
	//Brick->PaintBrick(pDC, Brick->m_BrickHeight, Brick->m_BrickWidth, MouseX, MouseY);
	CDialogEx::OnTimer(nIDEvent);
}

void CBrakoutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	MouseX = point.x;
	MouseY = point.y;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CBrakoutDlg::OnStnClickedArea()
{
	// TODO: Add your control notification handler code here
}


void CBrakoutDlg::OnStnClickedStczonadejuego()
{
	// TODO: Add your control notification handler code here
}


void CBrakoutDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	SetTimer(2, 50, NULL);
	m_Txt = "Colores";
	IsEditing = true;
	//m_BtnSave.ShowWindow(SW_SHOW);
	m_EditorTxt.ShowWindow(SW_SHOW);
	//m_BtnUndo.ShowWindow(SW_SHOW);
	m_CreateBlueBrick.ShowWindow(SW_SHOW);
	m_CreateYellowBrick.ShowWindow(SW_SHOW);
	m_CreateGreenBrick.ShowWindow(SW_SHOW);
	m_CreateRedBrick.ShowWindow(SW_SHOW);
	m_BtnPlay.ShowWindow(SW_HIDE);
	m_BtnReturn.ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}


void CBrakoutDlg::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
}


void CBrakoutDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CBrakoutDlg::OnBnClickedUndo()
{
	// TODO: Add your control notification handler code here
	Editor->Bricks.pop_back();
}


void CBrakoutDlg::OnBnClickedRed()
{
	// TODO: Add your control notification handler code here
	m_BtnSave.ShowWindow(SW_SHOW);
	m_BtnReturn.ShowWindow(SW_HIDE);
	m_BtnUndo.ShowWindow(SW_SHOW);
	Brick->m_Color = 1;
	SetTimer(2, 50, NULL);
}


void CBrakoutDlg::OnBnClickedBlue()
{
	// TODO: Add your control notification handler code here
	m_BtnSave.ShowWindow(SW_SHOW);
	m_BtnReturn.ShowWindow(SW_HIDE);
	m_BtnUndo.ShowWindow(SW_SHOW);
	Brick->m_Color = 2;
	SetTimer(2, 50, NULL);
}


void CBrakoutDlg::OnBnClickedGreen()
{
	// TODO: Add your control notification handler code here
	m_BtnSave.ShowWindow(SW_SHOW);
	m_BtnReturn.ShowWindow(SW_HIDE);
	m_BtnUndo.ShowWindow(SW_SHOW);
	Brick->m_Color = 3;
	SetTimer(2, 50, NULL);
}


void CBrakoutDlg::OnBnClickedYellow()
{
	// TODO: Add your control notification handler code here
	m_BtnSave.ShowWindow(SW_SHOW);
	m_BtnReturn.ShowWindow(SW_HIDE);
	m_BtnUndo.ShowWindow(SW_SHOW);
	Brick->m_Color = 4;
	SetTimer(2, 50, NULL);
}

void CBrakoutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//pDC->Rectangle(0, 0, Level->m_mySize.right, Level->m_mySize.bottom);
	if (IsEditing)
	{
		NewBrick = new CBrick(pDC);
		NewBrick->m_PosX = MouseX;
		NewBrick->m_PosY = MouseY;
		NewBrick->m_Color = Brick->m_Color;
		Editor->Bricks.push_back(NewBrick);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CBrakoutDlg::OnBnClickedReturn()
{
	// TODO: Add your control notification handler code here
	m_EditorTxt.ShowWindow(SW_HIDE);
	m_BtnSave.ShowWindow(SW_HIDE);
	m_BtnUndo.ShowWindow(SW_HIDE);
	m_CreateBlueBrick.ShowWindow(SW_HIDE);
	m_CreateYellowBrick.ShowWindow(SW_HIDE);
	m_CreateGreenBrick.ShowWindow(SW_HIDE);
	m_CreateRedBrick.ShowWindow(SW_HIDE);
	m_BtnPlay.ShowWindow(SW_SHOW);
	m_BtnReturn.ShowWindow(SW_HIDE);
	IsEditing = false;
	//Editor->m_Levels += 1;

	KillTimer(2);
}


void CBrakoutDlg::OnBnClickedEditor()
{
	// TODO: Add your control notification handler code here
	//m_BtnSave.ShowWindow(SW_HIDE);
}


void CBrakoutDlg::OnBnClickedSave()
{
	// TODO: Add your control notification handler code here
	m_BtnUndo.ShowWindow(SW_HIDE);
	m_BtnReturn.ShowWindow(SW_SHOW);
	Editor->m_Levels += 1;
	Editor->m_Name = to_string(Editor->m_Levels) + ".txt";
	Editor->LevelList.push_back(Editor->m_Name);
	Editor->CreateSave(Editor->m_Name);
	while (Editor->Bricks.size()>0)
	{
		Editor->Bricks.pop_back();
	}
	pDC->Rectangle(0, 0, Level->m_mySize.right, Level->m_mySize.bottom);
	KillTimer(2);
}

void CBrakoutDlg::Victory()
{
	MessageBox(TEXT("Felicidades!\nPulsa 'OK' para salir"), TEXT("Has ganado"), MB_OK);
	EndDialog(-1);
}

void CBrakoutDlg::Defeat()
{
	MessageBox(TEXT("Te has quedado sin vidas\nPulsa 'OK' para salir"), TEXT("Has perdido"), MB_OK);
	EndDialog(-1);
}

