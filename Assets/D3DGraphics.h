/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	D3DGraphics.h																		  *
 *	Copyright 2012 PlanetChili <http://www.planetchili.net>								  *
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

#include <d3d9.h>

struct Sprite
{
	unsigned int width;
	unsigned int heigth;
	D3DCOLOR key;
	D3DCOLOR* surface;
};

struct Font
{
	int charWidth;
	int charHeight;
	int nCharsPerRow;
	D3DCOLOR* surface;
};

void LoadSprite( Sprite* sprite, const char* fileName, unsigned int width, unsigned int height, D3DCOLOR key);
void LoadFont( Font* font, const char* filename, int charWidth, int charHeight, int nCharsPerRow );

void FreeSprite( Sprite* sprite);

class D3DGraphics
{
public:
	D3DGraphics( HWND hWnd );
	~D3DGraphics();
	void PutPixel( int x,int y,int r,int g,int b );
	void PutPixel( int x,int y, D3DCOLOR c );
	void DrawLine( int x1,int y1,int x2,int y2,int r,int g,int b );
	void DrawCircle( int cx,int cy,int radius,int r,int g,int b );
	void DrawDisc( int cx,int cy,int r,int rd,int g,int b );
	void DrawChar( char c,int xoff,int yoff,Font* font,D3DCOLOR color );
	void DrawString( const char* string,int xoff,int yoff,Font* font,D3DCOLOR color );
	//void D3DGraphics::DrawSurface( int xoff, int yoff, int width, int height, const D3DCOLOR* surf );
	void DrawSprite( int xoff, int yoff, Sprite* sprite);
	void BeginFrame();
	void EndFrame();
private:
	IDirect3D9*			pDirect3D;
	IDirect3DDevice9*	pDevice;
	IDirect3DSurface9*	pBackBuffer;
	D3DLOCKED_RECT		backRect;
};

