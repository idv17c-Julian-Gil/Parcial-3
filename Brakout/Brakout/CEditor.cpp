#include "stdafx.h"
#include "CEditor.h"


CEditor::CEditor()
{
}


CEditor::~CEditor()
{
}

void CEditor::CreateSave(string n_Name)
{
	ofstream n_File(n_Name.c_str(), ios::out);
	n_File.open(n_Name.c_str());
	ModifySave(n_Name);
}

void CEditor::LoadLevel(string n_Name)
{
	fstream *ist = new fstream(n_Name);
	string buffer = "x";
	int x, y;
	while (buffer != "\0")
	{
		string PosX, PosY, Color;
		CBrick *LevelLoad = new CBrick();
		getline(*ist, buffer);
		for (int i = 0; i < buffer.size(); i++)
		{
			while (buffer[i] != ' ')
			{
				PosX += buffer[i];
				i++;
			}
			i++;
			while (buffer[i] != ' ')
			{
				PosY += buffer[i];
				i++;
			}
			i++;
			Color = buffer[i];
		}
		if (buffer != "\0")
		{
			LevelLoad->m_PosX = atoi(PosX.c_str());
			LevelLoad->m_PosY = atoi(PosY.c_str());
			LevelLoad->m_Color = atoi(Color.c_str());
			Bricks.push_back(LevelLoad);
		}
	}
	m_BrickAmount = Bricks.size();
}

void CEditor::ModifySave(string n_Name)
{
	ofstream m_Modify(n_Name.c_str(), ios::out);
	for (int i = 0; i < Bricks.size(); i++)
	{
		m_Modify << Bricks[i]->m_PosX << " " << Bricks[i]->m_PosY << " " << Bricks[i]->m_Color << '\n';
	}
	m_Modify.close();
}

void CEditor::ChangeLevel(string n_Name)
{
	ofstream n_File(n_Name.c_str(), ios::out);
	n_File.open(n_Name.c_str());
}


