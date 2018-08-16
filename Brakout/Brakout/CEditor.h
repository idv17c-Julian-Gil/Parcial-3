#pragma once
//funciones, un vector de 
#include "CBrick.h"
#include <vector>
#include <fstream>
#include <string>

class CEditor
{
public:
	CEditor();
	~CEditor();
public:
	CBrick Brick;
	vector <CBrick*> Bricks;
	vector <string> LevelList;
	int m_Levels = 0;
	int m_BrickAmount;
	string m_Name;
	int count = 0;
	void CreateSave(string n_Name);
	void LoadLevel(string n_Name);
	void ModifySave(string n_Name);
	void ChangeLevel(string n_Name);
};

