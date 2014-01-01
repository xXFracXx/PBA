/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	Game.cpp																			  *
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
#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;

extern _battle battle;

Game::Game( HWND hWnd, KeyboardServer& kServer,const MouseServer& mServer )
:	gfx( hWnd ), audio( hWnd ), kbd( kServer ), mouse( mServer ),
	GameState(0), MapChecker(0), AreaID(0),
	Checker(0), Checker2(0), Checker3(0),
	Checker4(0), Checker5(0), Checker6(0), Checker7(0),
	C0(0), C1(0), C2(0), C3(0), C4(0), C5(0), C6(0), C7(0),
	introIndex(0), startIndex(0), startIndex2(0),
	S1(0), S2(0), S3(0),
	PlayerPosX(384), PlayerPosY(309),
	BluePosX(200), BluePosY(200),
	Trainer1PosX(100), Trainer1PosY(100),
	Trainer2PosX(100), Trainer2PosY(100),
	Trainer3PosX(100), Trainer3PosY(100),
	Trainer4PosX(100), Trainer4PosY(100),
	Red(1), RedType(0),
	Blue(0), BlueType(1),
	Trainer1(2), Trainer1Type(0),
	Trainer2(3), Trainer2Type(0),
	Trainer3(4), Trainer3Type(0),
	Trainer4(5), Trainer4Type(0),
	BattleIndex(0), BattleIndex2(0), BattleIndex3(0), BattleIndex4(0), 
	BattleIndex5(0), BattleIndex6(0), BattleIndex7w(0), BattleIndex8w(0), BattleIndex7l(0), BattleIndex8l(0), BattleIndex9(0),
	BattleState(0),
	T1(0),
	Trainer1Status(1), Trainer2Status(1), Trainer3Status(1), Trainer4Status(1), BlueStatus(0),
	Wins(0), Losses(0),
	endIndex(0)
{
	LoadFont( &fixedSys, "Resources\\Font\\Fixedsys16x28.bmp", 16, 28, 32);

	LoadSprite( &Blank, "Resources\\Blank.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Map, "Resources\\Map.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Map2, "Resources\\Map2.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Next, "Resources\\Next.bmp", 34, 20, D3DCOLOR_XRGB(255,255,255));
	LoadSprite( &NextRed, "Resources\\NextRed.bmp", 20, 34, D3DCOLOR_XRGB(255,255,255));
	LoadSprite( &Select, "Resources\\Select.bmp", 20, 34, D3DCOLOR_XRGB(0,0,0));

	LoadSprite( &Start1, "Resources\\Start\\1.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Start2, "Resources\\Start\\2.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Start3, "Resources\\Start\\3.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));

	LoadSprite( &Intro1, "Resources\\Intro\\1.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro2, "Resources\\Intro\\2.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro3, "Resources\\Intro\\3.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro4, "Resources\\Intro\\4.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro5, "Resources\\Intro\\5.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro6, "Resources\\Intro\\6.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro7, "Resources\\Intro\\7.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro8, "Resources\\Intro\\8.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro9, "Resources\\Intro\\9.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro10, "Resources\\Intro\\10.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro11, "Resources\\Intro\\11.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro12, "Resources\\Intro\\12.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Intro13, "Resources\\Intro\\13.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));

	LoadSprite( &Menu1a, "Resources\\Menu1\\a.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu1b, "Resources\\Menu1\\b.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu1c, "Resources\\Menu1\\c.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu1d, "Resources\\Menu1\\d.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu1e, "Resources\\Menu1\\e.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));

	LoadSprite( &Menu2a, "Resources\\Menu2\\a.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu2b, "Resources\\Menu2\\b.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu2c, "Resources\\Menu2\\c.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));

	LoadSprite( &Menu3a, "Resources\\Menu3\\a.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu3b, "Resources\\Menu3\\b.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &Menu3c, "Resources\\Menu3\\c.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));

	LoadSprite( &RedNormal, "Resources\\Red\\Normal.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &RedUp, "Resources\\Red\\Up.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &RedLeft, "Resources\\Red\\Left.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &RedRight, "Resources\\Red\\Right.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));

	LoadSprite( &BlueNormal, "Resources\\Blue\\Normal.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &BlueUp, "Resources\\Blue\\Up.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &BlueLeft, "Resources\\Blue\\Left.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &BlueRight, "Resources\\Blue\\Right.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));

	LoadSprite( &Trainer1Normal, "Resources\\Trainer1\\Normal.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer1Up, "Resources\\Trainer1\\Up.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));
	LoadSprite( &Trainer1Left, "Resources\\Trainer1\\Left.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer1Right, "Resources\\Trainer1\\Right.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 

	LoadSprite( &Trainer2Normal, "Resources\\Trainer2\\Normal.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer2Up, "Resources\\Trainer2\\Up.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));
	LoadSprite( &Trainer2Left, "Resources\\Trainer2\\Left.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer2Right, "Resources\\Trainer2\\Right.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 

	LoadSprite( &Trainer3Normal, "Resources\\Trainer3\\Normal.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer3Up, "Resources\\Trainer3\\Up.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));
	LoadSprite( &Trainer3Left, "Resources\\Trainer3\\Left.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer3Right, "Resources\\Trainer3\\Right.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 

	LoadSprite( &Trainer4Normal, "Resources\\Trainer4\\Normal.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer4Up, "Resources\\Trainer4\\Up.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));
	LoadSprite( &Trainer4Left, "Resources\\Trainer4\\Left.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255)); 
	LoadSprite( &Trainer4Right, "Resources\\Trainer4\\Right.bmp", 32, 32, D3DCOLOR_XRGB(255, 255, 255));

	LoadSprite( &Battle, "Resources\\Battle\\1.bmp", 800, 600, D3DCOLOR_XRGB(0, 0, 0));
	LoadSprite( &Moves, "Resources\\Battle\\Moves.bmp", 800, 160, D3DCOLOR_XRGB(0, 0, 0));
	LoadSprite( &Selector, "Resources\\Battle\\Selector.bmp", 245, 63, D3DCOLOR_XRGB(255, 255, 255));
	LoadSprite( &Text, "Resources\\Battle\\Text.bmp", 800, 160, D3DCOLOR_XRGB(0, 0, 0));

	LoadSprite( &End1, "Resources\\End\\1.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &End2a, "Resources\\End\\2a.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));
	LoadSprite( &End2b, "Resources\\End\\2b.bmp", 800, 600, D3DCOLOR_XRGB(1,1,1));
	LoadSprite( &End2c, "Resources\\End\\2c.bmp", 800, 600, D3DCOLOR_XRGB(1,1,1));
	LoadSprite( &End3, "Resources\\End\\3.bmp", 800, 600, D3DCOLOR_XRGB(0,0,0));

	initMoveSet();
	initPokemon();
}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::DrawEntity(int X, int Y, int Character, int Type)
{
	if(Character == 0) //Blue
	{
		if(Type == 0)
			gfx.DrawSprite(X, Y, &BlueNormal);
		if(Type == 1)
			gfx.DrawSprite(X, Y, &BlueUp);
		if(Type == 2)
			gfx.DrawSprite(X, Y, &BlueLeft);
		if(Type == 3)
			gfx.DrawSprite(X, Y, &BlueRight);
	}
	if(Character == 1) //Red
	{
		if(Type == 0)
			gfx.DrawSprite(X, Y, &RedNormal);
		if(Type == 1)
			gfx.DrawSprite(X, Y, &RedUp);
		if(Type == 2)
			gfx.DrawSprite(X, Y, &RedLeft);
		if(Type == 3)
			gfx.DrawSprite(X, Y, &RedRight);
	}
	if(Character == 2)
	{
		if(Type == 0)
			gfx.DrawSprite(X, Y, &Trainer1Normal);
		if(Type == 1)
			gfx.DrawSprite(X, Y, &Trainer1Up);
		if(Type == 2)
			gfx.DrawSprite(X, Y, &Trainer1Left);
		if(Type == 3)
			gfx.DrawSprite(X, Y, &Trainer1Right);
	}
	if(Character == 3)
	{
		if(Type == 0)
			gfx.DrawSprite(X, Y, &Trainer2Normal);
		if(Type == 1)
			gfx.DrawSprite(X, Y, &Trainer2Up);
		if(Type == 2)
			gfx.DrawSprite(X, Y, &Trainer2Left);
		if(Type == 3)
			gfx.DrawSprite(X, Y, &Trainer2Right);
	}
	if(Character == 4)
	{
		if(Type == 0)
			gfx.DrawSprite(X, Y, &Trainer3Normal);
		if(Type == 1)
			gfx.DrawSprite(X, Y, &Trainer3Up);
		if(Type == 2)
			gfx.DrawSprite(X, Y, &Trainer3Left);
		if(Type == 3)
			gfx.DrawSprite(X, Y, &Trainer3Right);
	}
	if(Character == 5)
	{
		if(Type == 0)
			gfx.DrawSprite(X, Y, &Trainer4Normal);
		if(Type == 1)
			gfx.DrawSprite(X, Y, &Trainer4Up);
		if(Type == 2)
			gfx.DrawSprite(X, Y, &Trainer4Left);
		if(Type == 3)
			gfx.DrawSprite(X, Y, &Trainer4Right);
	}
}

void Game::DrawMenu(int X, int Y, int Menu, int Type)
{
	if(Menu == 1)
	{
		if(Type == 1)
			gfx.DrawSprite(0, 0, &Menu1a);
		if(Type == 2)
			gfx.DrawSprite(0, 0, &Menu1b);
		if(Type == 3)
			gfx.DrawSprite(0, 0, &Menu1c);
		if(Type == 4)
			gfx.DrawSprite(0, 0, &Menu1d);
		if(Type == 5)
			gfx.DrawSprite(0, 0, &Menu1e);
	}
	if(Menu == 2)
	{
		if(Type == 1)
			gfx.DrawSprite(0, 0, &Menu2a);
		if(Type == 2)
			gfx.DrawSprite(0, 0, &Menu2b);
		if(Type == 3)
			gfx.DrawSprite(0, 0, &Menu2c);

	}
	if(Menu == 3)
	{
		if(Type == 1)
			gfx.DrawSprite(0, 0, &Menu3a);
		if(Type == 2)
			gfx.DrawSprite(0, 0, &Menu3b);
		if(Type == 3)
			gfx.DrawSprite(0, 0, &Menu3c);

	}
}

void Game::DrawNext(int X, int Y)
{
	if((time(NULL)%2 == 0))
		gfx.DrawSprite(X, Y, &Next);
}

void Game::DrawNextRed(int X, int Y)
{
	if((time(NULL)%2 == 0))
		gfx.DrawSprite(X, Y, &NextRed);
}

void Game::LoadSaveFile()
{
	ifstream SaveFile ("Resources\\SaveFile.dat");
	SaveFile >> Trainer1PosX;
	SaveFile >> Trainer1PosY;
	SaveFile >> Trainer2PosX;
	SaveFile >> Trainer2PosY;
	SaveFile >> Trainer3PosX;
	SaveFile >> Trainer3PosY;
	SaveFile >> Trainer4PosX;
	SaveFile >> Trainer4PosY;
	SaveFile >> PlayerPosX;
	SaveFile >> PlayerPosY;
	SaveFile >> Trainer1Status;
	SaveFile >> Trainer2Status;
	SaveFile >> Trainer3Status;
	SaveFile >> Trainer4Status;
}

void Game::SaveToSaveFile()
{
	ofstream SaveFile ("Resources\\SaveFile.dat");
	SaveFile << Trainer1PosX << "\n" << Trainer1PosY << "\n";
	SaveFile << Trainer2PosX << "\n" << Trainer2PosY << "\n";
	SaveFile << Trainer3PosX << "\n" << Trainer3PosY << "\n";
	SaveFile << Trainer4PosX << "\n" << Trainer4PosY << "\n";
	SaveFile << PlayerPosX << "\n" << PlayerPosY << "\n";
	SaveFile << Trainer1Status << "\n" << Trainer2Status << "\n" << Trainer3Status << "\n" << Trainer4Status << "\n";
}

void Game::DelSaveFile()
{
	remove("Resources\\SaveFile.dat");
}

void Game::Initialize(int &X, int &Y)
{
	srand (time(NULL));
	if(Checker2 == 0) {
		Checker3 = rand() % 10000;
		srand (Checker3);
		Checker2++;
	}
	else if(Checker2 == 1) {
		Checker3 = rand() % 1000;
		srand (Checker3);
		Checker2++;
	}
	else if(Checker2 == 2) {
		Checker3 = rand() % 100;
		srand (Checker3);
		Checker2++;
	}
	else if(Checker2 == 3) {
		Checker3 = rand() % 10;
		srand (Checker3);
		Checker2++;
	}
	int j, ExitC = 0;
	do {
		j = rand() % 8;
		if((j == 0)&&(C0 == 0))
		{
			X = rand() % 197 + 93;
			Y = rand() % 52 + 160;
			C0++;
			ExitC = 1;
		}
		/*if((j == 1)&&(C1 == 0))
		{
			X = rand() % 131 + 318;
			Y = rand() % 52 + 160;
			C1++;
			ExitC = 1;
		}*/
		if((j == 2)&&(C2 == 0))
		{
			X = rand() % 198 + 478;
			Y = rand() % 52 + 160;
			C2++;
			ExitC = 1;
		}
		if((j == 3)&&(C3 == 0))
		{
			X = rand() % 197 + 93;
			Y = rand() % 80 + 404;
			C3++;
			ExitC = 1;
		}
		/*if((j == 4)&&(C4 == 0))
		{
			X = rand() % 131 + 318;
			Y = rand() % 80 + 404;
			C4++;
			ExitC = 1;
		}*/
		if((j == 5)&&(C5 == 0))
		{
			X = rand() % 198 + 478;
			Y = rand() % 80 + 404;
			C5++;
			ExitC = 1;
		}
		/*if((j == 6)&&(C6 == 0))
		{
			X = rand() % 197 + 93;
			Y = rand() % 127 + 244;
			C6++;
			ExitC = 1;
		}
		if((j == 7)&&(C7 == 0))
		{
			X = rand() % 198 + 478;
			Y = rand() % 127 + 244;
			C7++;
			ExitC = 1;
		}*/
	}while(ExitC!=1);
}

void Game::SelectPokemon(int no, int type)
{
	if(type == 1)
	{
		if(no == 1)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\1F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 2)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\2F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 3)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\3F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 4)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\4F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 5)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\5F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 6)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\6F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 7)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\7F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 8)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\8F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 9)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\9F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 10)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\10F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 11)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\11F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 12)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\12F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 13)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\13F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 14)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\14F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 15)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\15F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 16)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\16F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 17)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\17F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 18)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\18F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 19)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\19F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 20)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\20F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 21)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\21F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 22)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\22F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 23)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\23F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 24)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\24F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 25)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\25F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 26)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\26F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 27)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\27F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 28)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\28F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 29)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\29F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 30)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\30F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 31)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\31F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 32)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\32F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 33)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\33F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 34)
			LoadSprite( &Pokemon1, "Resources\\Pokemon\\34F.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
	}
	if(type == 2)
	{
		if(no == 1)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\1B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 2)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\2B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 3)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\3B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 4)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\4B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 5)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\5B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 6)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\6B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 7)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\7B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 8)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\8B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 9)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\9B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 10)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\10B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 11)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\11B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 12)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\12B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 13)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\13B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 14)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\14B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 15)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\15B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 16)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\16B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 17)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\17B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 18)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\18B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 19)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\19B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 20)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\20B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 21)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\21B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 22)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\22B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 23)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\23B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 24)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\24B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 25)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\25B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 26)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\26B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 27)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\27B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 28)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\28B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 29)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\29B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 30)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\30B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 31)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\31B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 32)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\32B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 33)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\33B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
		if(no == 34)
			LoadSprite( &Pokemon2, "Resources\\Pokemon\\34B.bmp", 426, 216, D3DCOLOR_XRGB(255,0,255));
	}
}

void Game::Fight()
{
	if(BattleState == 0)
	{
		gfx.DrawSprite( 0, 406, &Moves);
		gfx.DrawString( x.moves[0].name, 27, 446, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
		gfx.DrawString( x.moves[1].name, 27, 504, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
		gfx.DrawString( x.moves[2].name, 277, 446, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
		gfx.DrawString( x.moves[3].name, 277, 504, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));

		if(((MousePosX > 20)&&(MousePosX < 271))&&((MousePosY > 428)&&(MousePosY < 492))&&(BattleIndex4 == 0))
		{
			gfx.DrawSprite(22, 430, &Selector);
			if(mouse.LeftIsPressed())
			{
				xMove = 0;
				BattleIndex4 = 1;
			}
		}
		if(((MousePosX > 272)&&(MousePosX < 516))&&((MousePosY > 428)&&(MousePosY < 490))&&(BattleIndex4 == 0))
		{
			gfx.DrawSprite(268, 430, &Selector);
			if(mouse.LeftIsPressed())
			{
				xMove = 2;
				BattleIndex4 = 1;
			}
		}
		if(((MousePosX > 20)&&(MousePosX < 271))&&((MousePosY > 491)&&(MousePosY < 547))&&(BattleIndex4 == 0))
		{
			gfx.DrawSprite(20, 486, &Selector);
			if(mouse.LeftIsPressed())
			{
				xMove = 1;
				BattleIndex4 = 1;
			}
		}
		if(((MousePosX > 272)&&(MousePosX < 516))&&((MousePosY > 491)&&(MousePosY < 547))&&(BattleIndex4 == 0))
		{
			gfx.DrawSprite(268, 486, &Selector);
			if(mouse.LeftIsPressed())
			{
				xMove = 3;
				BattleIndex4 = 1;
			}
		}
	}

	if(BattleIndex4 == 1)
	{
		xAttackd(xMove);
	}

	if(BattleIndex4 == 2)
	{
		yAttackd();
	}

	if(((MousePosX > 617)&&(MousePosX < 712))&&((MousePosY > 463)&&(MousePosY < 508))&&(BattleIndex4 == 0))
	{
		gfx.DrawSprite(597, 468, &Select);
		if(mouse.LeftIsPressed())
		{
			BattleIndex3 = 0;
		}
	}
}

void Game::xAttackd(int xMove)
{
	if(BattleIndex5 == 0)
	{
		tHPcal = battle.damagecalc(x, y, x.moves[xMove]);
		y.curhp-=tHPcal;
		xMoveNameLen = strlen(x.moves[xMove].name);
		BattleIndex5 = 1;
	}

	gfx.DrawSprite(0, 406, &Text);
	gfx.DrawString( x.name, 39, 441, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "used", 39 + (xNameLen*16) + 18, 441, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( x.moves[xMove].name, 39, 477, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	DrawNext(39 + (xMoveNameLen*16) + 18 , 485);
	if(kbd.KeyIsReleased(VK_RETURN))
	{
		kbd.ClearState();
		BattleIndex4 = 2;
	}
}

void Game::yAttackd()
{
	if(BattleIndex6 == 0)
	{
		do
		{
			yAttack=rand()%4;
		}while(y.moves[yAttack].category!=Regular);
		tHPcal2 = battle.damagecalc(y, x, y.moves[yAttack]);
		x.curhp-=tHPcal2;
		yMoveNameLen = strlen(y.moves[yAttack].name);
		BattleIndex6 = 1;
	}

	gfx.DrawSprite(0, 406, &Text);
	gfx.DrawString( "Foe", 39, 441, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( y.name, 105, 441, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "used", 105 + (yNameLen*16) + 18, 441, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( y.moves[yAttack].name, 39, 477, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	DrawNext(39 + (yMoveNameLen*16) + 18 , 485);
	if(kbd.KeyIsReleased(VK_RETURN))
	{
		kbd.ClearState();
		BattleIndex6 = 0;
		BattleIndex5 = 0;
		BattleIndex4 = 0;
	}
}

void Game::resetBattleInits()
{
	BattleIndex = 0;
	BattleIndex2 = 0;
	BattleIndex3 = 0;
	BattleIndex4 = 0;
	BattleIndex5 = 0;
	BattleIndex6 = 0;
	BattleIndex7w = 0;
	BattleIndex8w = 0;
	BattleIndex7l = 0;
	BattleIndex8l = 0;
	BattleState = 0;
}

void Game::Win()
{
	static int i = 0;
	if(i == 0)
	{
		kbd.ClearState();
		i = 1;
	}
	gfx.DrawSprite(0, 220, &Text);
	gfx.DrawString( x.name, 39, 255, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "has defeated", 39 + (xNameLen*16) + 18, 255, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "foe", 39, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( y.name, 105, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	DrawNext(105 + (yNameLen*16) + 18 , 299);
	if(kbd.KeyIsReleased(VK_RETURN))
	{
		kbd.ClearState();
		BattleIndex7w = 1;
	}
}

void Game::Lose()
{
	static int i = 0;
	if(i == 0)
	{
		kbd.ClearState();
		i = 1;
	}
	gfx.DrawSprite(0, 220, &Text);
	gfx.DrawString( "Foe", 39, 255, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( y.name, 105, 255, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "has defeated", 39, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( x.name, 249, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	DrawNext(249 + (xNameLen*16) + 18 , 299);
	if(kbd.KeyIsReleased(VK_RETURN))
	{
		kbd.ClearState();
		BattleIndex7l = 1;
	}
}

void Game::TrainerWin()
{
	static int i = 0;
	if(i == 0)
	{
		kbd.ClearState();
		i = 1;
	}
	gfx.DrawSprite(0, 220, &Text);
	gfx.DrawString( "You have defeated the Trainer!", 39, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	/*gfx.DrawString( "Wins:", 39, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( tWins, 137, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "Losses:", 39, 327, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( tWins, 171, 327, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));*/
	DrawNext(540 , 291);
	if(kbd.KeyIsReleased(VK_RETURN))
	{
		kbd.ClearState();
		BattleIndex8w = 1;
	}
}

void Game::TrainerLose()
{
	static int i = 0;
	if(i == 0)
	{
		kbd.ClearState();
		i = 1;
	}
	gfx.DrawSprite(0, 220, &Text);
	gfx.DrawString( "The Trainer has defeated you!", 39, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	/*gfx.DrawString( "Losses:", 39, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( tWins, 171, 291, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( "Wins:", 39, 327, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
	gfx.DrawString( tWins, 137, 327, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));*/
	DrawNext(508 , 291);
	if(kbd.KeyIsReleased(VK_RETURN))
	{
		kbd.ClearState();
		BattleIndex8l = 1;
	}
}

void Game::End()
{
        startIndex = 0;
        startIndex2 = 0;
        endIndex = 0;
}

void Game::State0()
{
	if(startIndex == 0)
	{
		if(startIndex2 == 0)
		{
			gfx.DrawSprite(0, 0, &Start1);
			S1++;
			if(S1 >= 210)
				startIndex2 = 1;
		}
		else if(startIndex2 == 1)
		{
			gfx.DrawSprite(0, 0, &Start2);
			S2++;
			if(S2 >= 210)
				startIndex2 = 2;
		}
		else if(startIndex2 == 2)
		{
			gfx.DrawSprite(0, 0, &Start3);
			S3++;
			if(S3 >= 210)
				startIndex = 1;
		}
	}
	else if(startIndex == 1)
	{
		ofstream SaveFile ("Resources\\SaveFile.dat", ios::_Nocreate);
		if(!SaveFile) //Checks if SaveFile already exits or not.
		{
			if(((MousePosX > 58)&&(MousePosX < 742))&&((MousePosY > 259)&&(MousePosY < 342)))
			{
				DrawMenu(0, 0, 2, 2);
				if(mouse.LeftIsPressed())
				{
					if(SaveFile.is_open())
						SaveFile.close();
					Checker = 0;
					GameState = 3;
				}
			}
			else if(((MousePosX > 58)&&(MousePosX < 742))&&((MousePosY > 459)&&(MousePosY < 543)))
			{
				DrawMenu(0, 0, 2, 3);
				if(mouse.LeftIsPressed())
				{
					if(SaveFile.is_open())
						SaveFile.close();
					exit(0);
				}
			}
			else
				DrawMenu(0, 0, 2, 1);
		}
		else
		{
			if(((MousePosX > 58)&&(MousePosX < 742))&&((MousePosY > 259)&&(MousePosY < 342)))
			{
				DrawMenu(0, 0, 1, 2);
				if(mouse.LeftIsPressed())
				{
					if(SaveFile.is_open())
						SaveFile.close();
					Checker = 0;
					GameState = 3;
				}
			}
			else if(((MousePosX > 591)&&(MousePosX < 732))&&((MousePosY > 376)&&(MousePosY < 426)))
			{
				DrawMenu(0, 0, 1, 5);
				if(mouse.LeftIsPressed())
				{
					if(SaveFile.is_open())
						SaveFile.close();
					DelSaveFile();
					Checker = 0;
				}
			}
			else if(((MousePosX > 58)&&(MousePosX < 742))&&((MousePosY > 358)&&(MousePosY < 445)))
			{
				DrawMenu(0, 0, 1, 3);
				if(mouse.LeftIsPressed())
				{
					if(SaveFile.is_open())
						SaveFile.close();
					LoadSaveFile();
					Checker = 1;
					GameState = 1;
				}
			}
			else if(((MousePosX > 58)&&(MousePosX < 742))&&((MousePosY > 459)&&(MousePosY < 543)))
			{
				DrawMenu(0, 0, 1, 4);
				if(mouse.LeftIsPressed())
				{
					if(SaveFile.is_open())
						SaveFile.close();
					exit(0);
				}
			}
			else
				DrawMenu(0, 0, 1, 1);
		}
		gfx.DrawString("Release Candidate v1.3", 8, 570, &fixedSys, D3DCOLOR_XRGB(48, 48, 48));
	}
}

void Game::State1()
{
	if(MapChecker == 0)
			gfx.DrawSprite(0, 0, &Map); //Outputs Map
	else if(MapChecker == 1)
		gfx.DrawSprite(0, 0, &Map2); 

	if(Checker == 0)
	{
		Checker2 = 0;
		Initialize(Trainer1PosX, Trainer1PosY);
		Initialize(Trainer2PosX, Trainer2PosY);
		Initialize(Trainer3PosX, Trainer3PosY);
		Initialize(Trainer4PosX, Trainer4PosY);
		Checker = 1;
	}

	srand (time(NULL));
	Checker4 = rand() % 119 + 1;
	Checker5 = rand() % 119 + 1;
	Checker6 = rand() % 119 + 1;
	Checker7 = rand() % 119 + 1;
	if(Checker4%4 == 0)
	{
		Trainer1Type = rand() % 4;
		Checker4 = 0;
	}
	if(Checker5%4 == 0)
	{
		Trainer2Type = rand() % 4;
		Checker4 = 0;
	}
	if(Checker6%4 == 0)
	{
		Trainer3Type = rand() % 4;
		Checker4 = 0;
	}
	if(Checker7%4 == 0)
	{
		Trainer4Type = rand() % 4;
		Checker4 = 0;
	}

	DrawEntity(Trainer1PosX, Trainer1PosY, Trainer1, Trainer1Type); //
	DrawEntity(Trainer2PosX, Trainer2PosY, Trainer2, Trainer2Type); // 
	DrawEntity(Trainer3PosX, Trainer3PosY, Trainer3, Trainer3Type); // Outputs Player and 4 Trainers
	DrawEntity(Trainer4PosX, Trainer4PosY, Trainer4, Trainer4Type); // 
	DrawEntity(PlayerPosX, PlayerPosY, Red, RedType);               //

	if((Trainer1Status==1)&&(Trainer2Status==1)&&(Trainer3Status==1)&&(Trainer4Status==1)) {
		MapChecker = 1;
		DrawEntity(BluePosX, BluePosY, Blue, BlueType); 
	}

	if(!((Trainer1Status==1)&&(Trainer2Status==1)&&(Trainer3Status==1)&&(Trainer4Status==1))) {
		if(PlayerPosY < 92) {    
			PlayerPosY = 92;     
		}
		if(PlayerPosY > 492) {
			PlayerPosY = 492;
		}
		if(PlayerPosX < 26) {
			PlayerPosX = 26;
		}
		if(PlayerPosX > 742) {
			PlayerPosX = 742;
		}
	}
	else if((Trainer1Status==1)&&(Trainer2Status==1)&&(Trainer3Status==1)&&(Trainer4Status==1)) {
		if(AreaID == 0) {
			if(PlayerPosY < 92) {    
				PlayerPosY = 92;     
			}
			if(PlayerPosY > 492) {
				AreaID = 1;
			}
			if(PlayerPosX < 26) {
				PlayerPosX = 26;
			}
			if(PlayerPosX > 742) {
				PlayerPosX = 742;
			}
		}
		if(AreaID == 1) {
			if(PlayerPosY < 492) {    
				AreaID = 0;     
			}
			if(PlayerPosY > 542) {
				PlayerPosY = 542;
			}
			if(PlayerPosX < 326) {
				PlayerPosX = 326;
			}
			if(PlayerPosX > 442) {
				PlayerPosX = 442;
			}
		}
	}
		
	
	if(kbd.KeyIsPressed(VK_UP)) {
			PlayerPosY -= 2;
			RedType = 1;
	}
	if(kbd.KeyIsPressed(VK_DOWN)) {
			PlayerPosY += 2;
			RedType = 0;
	}
	if(kbd.KeyIsPressed(VK_LEFT)) {
			PlayerPosX -= 2;
			RedType = 2;
	}
	if(kbd.KeyIsPressed(VK_RIGHT)) {
			PlayerPosX += 2;
			RedType = 3;
	}
	if(kbd.KeyIsPressed(VK_ESCAPE)) {
		SaveToSaveFile();
		GameState = 2;
	}

	if((PlayerPosX >= Trainer1PosX - 36)&&(PlayerPosX <= Trainer1PosX + 36))
		if((PlayerPosY >= Trainer1PosY - 36)&&(PlayerPosY <= Trainer1PosY + 36))
			if(Trainer1Status == 0)
			{
				Wins = 0;
				Losses = 0;
				TrainerID = 1;
				GameState = 4;
			}
			else
				gfx.DrawString("You have already defeated me!", 8, 570, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));

	if((PlayerPosX >= Trainer2PosX - 36)&&(PlayerPosX <= Trainer2PosX + 36))
		if((PlayerPosY >= Trainer2PosY - 36)&&(PlayerPosY <= Trainer2PosY + 36))
			if(Trainer2Status == 0)
			{
				Wins = 0;
				Losses = 0;
				TrainerID = 2;
				GameState = 4;
			}
			else
				gfx.DrawString("You have already defeated me!", 8, 570, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));

	if((PlayerPosX >= Trainer3PosX - 36)&&(PlayerPosX <= Trainer3PosX + 36))
		if((PlayerPosY >= Trainer3PosY - 36)&&(PlayerPosY <= Trainer3PosY + 36))
			if(Trainer3Status == 0)
			{
				Wins = 0;
				Losses = 0;
				TrainerID = 3;
				GameState = 4;
			}
			else
				gfx.DrawString("You have already defeated me!", 8, 570, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));

	if((PlayerPosX >= Trainer4PosX - 36)&&(PlayerPosX <= Trainer4PosX + 36))
		if((PlayerPosY >= Trainer4PosY - 36)&&(PlayerPosY <= Trainer4PosY + 36))
			if(Trainer4Status == 0)
			{
				Wins = 0;
				Losses = 0;
				TrainerID = 4;
				GameState = 4;
			}
			else
				gfx.DrawString("You have already defeated me!", 8, 570, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));

	if((Trainer1Status==1)&&(Trainer2Status==1)&&(Trainer3Status==1)&&(Trainer4Status==1)&&(BlueStatus==1))
		GameState = 5;
}

void Game::State2()
{
	if(((MousePosX > 56)&&(MousePosX < 369))&&((MousePosY > 356)&&(MousePosY < 443)))
	{
		DrawMenu(0, 0, 3, 2);
		if(mouse.LeftIsPressed())
		{
			exit(0);
		}
	}
	else if(((MousePosX > 431)&&(MousePosX < 743))&&((MousePosY > 356)&&(MousePosY < 443)))
	{
		DrawMenu(0, 0, 3, 3);
		if(mouse.LeftIsPressed())
		{
			GameState = 1;
		}
	}
	else
		DrawMenu(0, 0, 3, 1);
}

void Game::State3()
{
	if(introIndex == 0)
	{
		gfx.DrawSprite(0, 0, &Intro1);
		DrawNext(657, 485);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 1;
		}
	}
	else if(introIndex == 1)
	{
		gfx.DrawSprite(0, 0, &Intro2);
		DrawNext(717, 484);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 2;
		}
	}
	else if(introIndex == 2)
	{
		gfx.DrawSprite(0, 0, &Intro3);
		DrawNext(114, 540);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 3;
		}
	}
	else if(introIndex == 3)
	{
		gfx.DrawSprite(0, 0, &Intro4);
		//DrawNext(, );
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 4;
		}
	}
	else if(introIndex == 4)
	{
		gfx.DrawSprite(0, 0, &Intro5);
		DrawNext(177, 539);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 5;
		}
	}
	else if(introIndex == 5)
	{
		gfx.DrawSprite(0, 0, &Intro6);
		//DrawNext(, );
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 6;
		}
	}
	else if(introIndex == 6)
	{
		gfx.DrawSprite(0, 0, &Intro7);
		//DrawNext(, );
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 7;
		}
	}
	else if(introIndex == 7)
	{
		gfx.DrawSprite(0, 0, &Intro8);
		//DrawNext(, );
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 8;
		}
	}
	else if(introIndex == 8)
	{
		gfx.DrawSprite(0, 0, &Intro9);
		//DrawNext(, );
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 9;
		}
	}
	else if(introIndex == 9)
	{
		gfx.DrawSprite(0, 0, &Intro10);
		//DrawNext(, );
		Sleep(41);
		introIndex = 10;
	}
	else if(introIndex == 10)
	{
		gfx.DrawSprite(0, 0, &Intro11);
		DrawNext(360, 484);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 11;
		}
	}
	else if(introIndex == 11)
	{
		gfx.DrawSprite(0, 0, &Intro12);
		DrawNext(734, 539);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			introIndex = 12;
		}
	}
	else if(introIndex == 12)
	{
		gfx.DrawSprite(0, 0, &Intro13);
		DrawNext(240, 539);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			Checker = 0;
			GameState = 1;
		}
	}
}

void Game::State4()
{
	if(BattleIndex == 0)
	{
		srand(time(NULL));
		level = 50;
		species=rand()%34+1;
		x.setup(species);
		species=rand()%34+1;
		y.setup(species);

		itoa(x.level, Olevel1, 10);
		itoa(y.level, Olevel2, 10);

		inx = x.curhp;
		iny = y.curhp;

		itoa(inx, ixhp, 10);
		itoa(iny, iyhp, 10);

		SelectPokemon(x.no, 2);
		SelectPokemon(y.no, 1);

		xNameLen = strlen(x.name);
		yNameLen = strlen(y.name);

		BattleIndex = 1;

	}
	if((Wins < 2) && (Losses < 2) && (BattleIndex9 == 0))
	{
		if(((x.curhp > 0))&&((y.curhp > 0)))
		{
			if(BattleIndex == 1)
			{
				gfx.DrawSprite(0, 0, &Battle);

				gfx.DrawString( "Lv:", 660, 295, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				gfx.DrawString( Olevel1, 708, 295, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));

				gfx.DrawString( "Lv:", 253, 102, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				gfx.DrawString( Olevel2, 303, 102, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));

				nx = x.curhp;
				if(nx >= (inx/2))
				{
					xhpct[0] = 88;
					xhpct[1] = 208;
					xhpct[2] = 128;
					xhpcb[0] = 112;
					xhpcb[1] = 248;
					xhpcb[2] = 168;
				}
				else if((nx < (inx/2))&&(nx >= (inx/5)))
				{
					xhpct[0] = 200;
					xhpct[1] = 168;
					xhpct[2] = 8;
					xhpcb[0] = 248;
					xhpcb[1] = 224;
					xhpcb[2] = 56;
				}
				else
				{
					xhpct[0] = 168;
					xhpct[1] = 64;
					xhpct[2] = 73;
					xhpcb[0] = 248;
					xhpcb[1] = 88;
					xhpcb[2] = 56;
				}
				nx/=inx;
				nx*=160;
				for(int y = 0; y < 3; y++)
					gfx.DrawLine(580, 336 + y, 580 + nx, 336 + y, xhpct[0], xhpct[1], xhpct[2]);
				for(int y = 0; y < 7; y++)
					gfx.DrawLine(580, 339 + y, 580 + nx, 339 + y, xhpcb[0], xhpcb[1], xhpcb[2]);

				ny = y.curhp;
				if(ny >= (iny/2))
				{
					yhpct[0] = 88;
					yhpct[1] = 208;
					yhpct[2] = 128;
					yhpcb[0] = 112;
					yhpcb[1] = 248;
					yhpcb[2] = 168;
				}
				else if((ny < (iny/2))&&(ny >= (iny/5)))
				{
					yhpct[0] = 200;
					yhpct[1] = 168;
					yhpct[2] = 8;
					yhpcb[0] = 248;
					yhpcb[1] = 224;
					yhpcb[2] = 56;
				}
				else
				{
					yhpct[0] = 168;
					yhpct[1] = 64;
					yhpct[2] = 73;
					yhpcb[0] = 248;
					yhpcb[1] = 88;
					yhpcb[2] = 56;
				}
				ny/=iny;
				ny*=160;
				for(int y = 0; y < 3; y++)
					gfx.DrawLine(173, 143 + y, 173 + ny, 143 + y, yhpct[0], yhpct[1], yhpct[2]);
				for(int y = 0; y < 7; y++)
					gfx.DrawLine(173, 146 + y, 173 + ny, 146 + y, yhpcb[0], yhpcb[1], yhpcb[2]);
			
				if((x.curhp >= 100)&&(inx >=100))
				{
					itoa(x.curhp, xhp, 10);
					gfx.DrawString( xhp, 627, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( "/", 675, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( ixhp, 691, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				}
				else if((x.curhp < 100)&&(inx >=100))
				{
					itoa(x.curhp, xhp, 10);
					gfx.DrawString( xhp, 643, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( "/", 675, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( ixhp, 691, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				}
				else if((x.curhp < 100)&&(inx < 100))
				{
					itoa(x.curhp, xhp, 10);
					gfx.DrawString( xhp, 659, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( "/", 691, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( ixhp, 707, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				}
				else if((x.curhp < 10)&&(inx >=100))
				{
					itoa(x.curhp, xhp, 10);
					gfx.DrawString( xhp, 659, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( "/", 675, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( ixhp, 691, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				}
				else if((x.curhp < 10)&&(inx < 100))
				{
					itoa(x.curhp, xhp, 10);
					gfx.DrawString( xhp, 675, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( "/", 675, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
					gfx.DrawString( ixhp, 691, 354, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				}
				/*///
				if((y.curhp >= 100)&&(iny >=100))
				{
					itoa(y.curhp, yhp, 10);
					gfx.DrawString( yhp, 627, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( "/", 675, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( iyhp, 691, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
				}
				else if((y.curhp < 100)&&(iny >=100))
				{
					itoa(y.curhp, yhp, 10);
					gfx.DrawString( yhp, 723, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( "/", 675, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( iyhp, 691, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
				}
				else if((y.curhp < 100)&&(iny < 100))
				{
					itoa(y.curhp, yhp, 10);
					gfx.DrawString( yhp, 659, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( "/", 691, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( iyhp, 707, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
				}
				else if((y.curhp < 10)&&(iny >=100))
				{
					itoa(y.curhp, yhp, 10);
					gfx.DrawString( yhp, 659, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( "/", 675, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( iyhp, 691, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
				}
				else if((y.curhp < 10)&&(iny < 100))
				{
					itoa(y.curhp, yhp, 10);
					gfx.DrawString( yhp, 675, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( "/", 675, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
					gfx.DrawString( iyhp, 691, 254, &fixedSys, D3DCOLOR_XRGB(72, 72, 72));
				}
				///*/
				gfx.DrawString( x.name, 466, 295, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));
				gfx.DrawString( y.name, 59, 102, &fixedSys, D3DCOLOR_XRGB(64, 64, 64));

				gfx.DrawString( "What will", 39, 441, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
				gfx.DrawString( x.name, 39, 477, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));
				gfx.DrawString( "do next?", 39 + (xNameLen*16) + 18, 477, &fixedSys, D3DCOLOR_XRGB(248, 248, 248));

				gfx.DrawSprite(374, 33, &Pokemon1);
				gfx.DrawSprite(0, 190, &Pokemon2);

				if(((MousePosX > 443)&&(MousePosX < 562))&&((MousePosY > 439)&&(MousePosY < 488))&&(BattleIndex2==0))
				{
					gfx.DrawSprite(427, 447, &Select);
					if(mouse.LeftIsPressed())
					{
						mouse.ClearState();
						BattleIndex3 = 1;
					}
				}

				if(BattleIndex3 == 1)
				{
					Fight();
				}
			}
		}
		else
		{
			if((y.curhp <= 0)/*&&(x.curhp > 0)*/)
			{
				Win();
				if(BattleIndex7w == 1)
				{
					resetBattleInits();
					Wins++;
					GameState = 4;
				}
				if((Wins > 2) || (Losses > 2))
					BattleIndex = 1;
			}
			if((x.curhp <= 0)/*&&(y.curhp > 0)*/)
			{
				Lose();
				if(BattleIndex7l == 1)
				{
					resetBattleInits();
					Losses++;
					GameState = 4;
				}
				if((Wins > 2) || (Losses > 2))
					BattleIndex9 = 1;
			}
		}
	}
	else
	{
		if(Wins > Losses)
		{
			TrainerWin();
			if(BattleIndex8w == 1)
			{
				TrainerWin();
				if(TrainerID == 1)
					Trainer1Status = 1;
				if(TrainerID == 2)
					Trainer2Status = 1;
				if(TrainerID == 3)
					Trainer3Status = 1;
				if(TrainerID == 4)
					Trainer4Status = 1;
				PlayerPosX = 384;
				PlayerPosY = 309;
				BattleIndex9 = 0;
				GameState = 1;
			}
		}
		else
		{
			TrainerLose();
			if(BattleIndex8l == 1)
			{
				if(TrainerID == 1)
					Trainer1Status = 0;
				if(TrainerID == 2)
					Trainer2Status = 0;
				if(TrainerID == 3)
					Trainer3Status = 0;
				if(TrainerID == 4)
					Trainer4Status = 0;
				PlayerPosX = 384;
				PlayerPosY = 309;
				BattleIndex9 = 0;
				GameState = 1;
			}
		}
	}
}

void Game::State5()
{
	if(endIndex == 0)
	{
		gfx.DrawSprite(0, 0, &End1);
		DrawNextRed(776 , 562);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			endIndex = 1;
		}
	}
	else if(endIndex == 1)
	{
		gfx.DrawSprite(0, 0, &End2a);
		DrawNextRed(776 , 562);
		if((MousePosX > 262)&&(MousePosX < 543)&&(MousePosY > 268)&&(MousePosY < 285))
			gfx.DrawSprite(0, 0, &End2b);
		if((MousePosX > 226)&&(MousePosX < 579)&&(MousePosY > 297)&&(MousePosY < 314))
			gfx.DrawSprite(0, 0, &End2c);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			endIndex = 2;
		}
	}
	else if(endIndex == 2)
	{
		gfx.DrawSprite(0, 0, &End3);
		DrawNextRed(776 , 562);
		if(kbd.KeyIsReleased(VK_RETURN))
		{
			kbd.ClearState();
			End();
			GameState = 0;
		}
	}
}

void Game::ComposeFrame()
{
	MousePosX = mouse.GetMouseX();
	MousePosY = mouse.GetMouseY();

	if(GameState == 0) //Main Menu
		State0();

	if(GameState == 1) //Game
		State1();

	if(GameState == 2) //Exit Menu
		State2();

	if(GameState == 3) //Intro
		State3();

	if(GameState == 4) //Battle
		State4();

	if(GameState == 5) //End
		State5();
}