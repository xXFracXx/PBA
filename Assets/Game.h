/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	Game.h																				  *
 *	Copyright 2012 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Sound.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <string>

class Game
{
public:
	Game( HWND hWnd, KeyboardServer& kServer,const MouseServer& mServer );
	void Go();
private:
	void ComposeFrame();
	/********************************/
	/*  User Functions              */

	void Initialize(int &X, int &Y);
	void DrawEntity(int X, int Y, int Character, int Type);
	void DrawMenu(int X, int Y, int Menu, int Type);
	void DrawNext(int X, int Y);
	void DrawNextRed(int X, int Y);
	void LoadSaveFile();
	void SaveToSaveFile();
	void DelSaveFile();
	void SelectPokemon(int no, int type);
	void Fight();
	void xAttackd(int xMove);
	void yAttackd();
	void resetBattleInits();
	void Win();
	void Lose();
	void TrainerWin();
	void TrainerLose();
	void End();

	void State0();
	void State1();
	void State2();
	void State3();
	void State4();
	void State5();

	/********************************/
private:
	D3DGraphics gfx;
	KeyboardClient kbd;
	MouseClient mouse;
	DSound audio;
	/********************************/
	/*  User Variables  */

	Font fixedSys;

	Sprite Blank;
	Sprite Map;
	Sprite Map2;
	Sprite Next;
	Sprite NextRed;
	Sprite Select;

	Sprite Start1;
	Sprite Start2;
	Sprite Start3;

	Sprite Intro1;
	Sprite Intro2;
	Sprite Intro3;
	Sprite Intro4;
	Sprite Intro5;
	Sprite Intro6;
	Sprite Intro7;
	Sprite Intro8;
	Sprite Intro9;
	Sprite Intro10;
	Sprite Intro11;
	Sprite Intro12;
	Sprite Intro13;

	Sprite Menu1a;
	Sprite Menu1b;
	Sprite Menu1c;
	Sprite Menu1d;
	Sprite Menu1e;

	Sprite Menu2a;
	Sprite Menu2b;
	Sprite Menu2c;

	Sprite Menu3a;
	Sprite Menu3b;
	Sprite Menu3c;

	Sprite RedNormal;
	Sprite RedUp;
	Sprite RedDown;
	Sprite RedLeft;
	Sprite RedRight;

	Sprite BlueNormal;
	Sprite BlueUp;
	Sprite BlueDown;
	Sprite BlueLeft;
	Sprite BlueRight;

	Sprite Trainer1Normal;
	Sprite Trainer1Up;
	Sprite Trainer1Down;
	Sprite Trainer1Left;
	Sprite Trainer1Right;

	Sprite Trainer2Normal;
	Sprite Trainer2Up;
	Sprite Trainer2Down;
	Sprite Trainer2Left;
	Sprite Trainer2Right;

	Sprite Trainer3Normal;
	Sprite Trainer3Up;
	Sprite Trainer3Down;
	Sprite Trainer3Left;
	Sprite Trainer3Right;

	Sprite Trainer4Normal;
	Sprite Trainer4Up;
	Sprite Trainer4Down;
	Sprite Trainer4Left;
	Sprite Trainer4Right;

	Sprite Battle;
	Sprite Moves;
	Sprite Selector;
	Sprite Text;

	Sprite Pokemon1;
	Sprite Pokemon2;

	Sprite End1;
	Sprite End2a;
	Sprite End2b;
	Sprite End2c;
	Sprite End3;

	int GameState;
	int MapChecker;
	int AreaID;

	int PlayerPosX;
	int PlayerPosY;
	int Red;
	int RedType;

	int BluePosX;
	int BluePosY;
	int Blue;
	int BlueType;

	int Checker;
	int Checker2;
	int Checker3;
	int Checker4;
	int Checker5;
	int Checker6;
	int Checker7;
	int C0, C1, C2, C3, C4, C5, C6, C7;

	int introIndex;
	int startIndex;
	int startIndex2;
	int S1, S2, S3;

	int Trainer1PosX;
	int Trainer1PosY;
	int Trainer1;
	int Trainer1Type;

	int Trainer2PosX;
	int Trainer2PosY;
	int Trainer2;
	int Trainer2Type;

	int Trainer3PosX;
	int Trainer3PosY;
	int Trainer3;
	int Trainer3Type;

	int Trainer4PosX;
	int Trainer4PosY;
	int Trainer4;
	int Trainer4Type;

	int MousePosX;
	int MousePosY;

	_pokemon x, y;
	_battle battle;

	int BattleIndex;
	int BattleIndex2;
	int BattleIndex3;
	int BattleIndex4;
	int BattleIndex5;
	int BattleIndex6;
	int BattleIndex7w;
	int BattleIndex7l;
	int BattleIndex8w;
	int BattleIndex8l;
	int BattleIndex9;

	int level;
	int species;
	char Olevel1[3];
	char Olevel2[3];

	float nx;
	float ny;
	int inx;
	int iny;
	int xhpct[3];
	int xhpcb[3];
	int yhpct[3];
	int yhpcb[3];
	char nxc;
	char nyc;
	char xhp[4];
	char ixhp[4];

	char yhp[4];
	char iyhp[4];

	int xNameLen;
	int yNameLen;
	int xMoveNameLen;
	int yMoveNameLen;

	int tHPcal;
	int tHPcal2;
	int yAttack;
	int BattleState;
	int T1;
	int xMove;

	int Trainer1Status;
	int Trainer2Status;
	int Trainer3Status;
	int Trainer4Status;
	int BlueStatus;

	int TrainerID;

	int Wins;
	int Losses;
	char tWins[3];
	char tLosses[3];

	int endIndex;
	/********************************/
};