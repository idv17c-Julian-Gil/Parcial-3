
// BrakoutDlg.h : header file
//

#pragma once
#include "CBall.h"
#include "CBar.h"
#include "CBrick.h"
#include "CEditor.h"
//#include "afxwin.h"


// CBrakoutDlg dialog
class CBrakoutDlg : public CDialogEx
{
// Construction
public:
	CBrakoutDlg(CWnd* pParent = nullptr);	// standard constructor

public: //Variables
	bool IsEditing;
	CBall *Ball;
	CLevel *Level;
	CBar *Bar;
	CBrick *Brick;
	CEditor *Editor;
	CDC *pDC;
	CBrick* NewBrick;
	CStatic m_PlayArea;
	CEdit m_EditorTxt;
	CString m_Txt;
	int Lives = 3;

	//Buttons
	CButton m_BtnSave;
	CButton m_BtnEditor;
	CButton m_BtnReturn;
	CButton m_BtnAdd;
	CButton m_BtnPlay;
	CButton m_BtnUndo;
	CButton m_CreateBlueBrick;
	CButton m_CreateYellowBrick;
	CButton m_CreateGreenBrick;
	CButton m_CreateRedBrick;

	int DirX = 15; //Velocidad pelota
	int DirY = 15; //Velocidad pelota
	int MouseX;
	int MouseY;
	int ModifyWidth = 1;
	int ModifyHeight = 1;
	int BarHeight;
	int BarWidth;

	void Victory();
	void Defeat();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BRAKOUT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void MoveBall();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	// Area de juego	// Area de juego
	afx_msg void OnStnClickedArea();
	//CStatic m_Zonadejuego;
	afx_msg void OnStnClickedStczonadejuego();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnEnChangeEdit1();
	//afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedBlue();
	afx_msg void OnBnClickedYellow();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedRed();
	afx_msg void OnBnClickedGreen();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedReturn();
	afx_msg void OnBnClickedEditor();
	afx_msg void OnBnClickedSave();
};
