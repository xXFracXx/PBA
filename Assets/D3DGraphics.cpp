/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	D3DGraphics.cpp																		  *
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
#include "D3DGraphics.h"
#include "Bitmap.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>

D3DGraphics::D3DGraphics( HWND hWnd )
{
	HRESULT result;

	backRect.pBits = NULL;
	
	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );
	assert( pDirect3D != NULL );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    result = pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );
	assert( !FAILED( result ) );

	result = pDevice->GetBackBuffer( 0,0,D3DBACKBUFFER_TYPE_MONO,&pBackBuffer );
	assert( !FAILED( result ) );
}

D3DGraphics::~D3DGraphics()
{
	if( pDevice )
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if( pDirect3D )
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
	if( pBackBuffer )
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
	}
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{	
	assert( x >= 0 );
	assert( y >= 0 );
	assert( x < 800 );
	assert( y < 600 );
	((D3DCOLOR*)backRect.pBits)[ x + (backRect.Pitch >> 2) * y ] = D3DCOLOR_XRGB( r,g,b );
}

void D3DGraphics::PutPixel( int x,int y, D3DCOLOR c )
{	
	assert( x >= 0 );
	assert( y >= 0 );
	assert( x < 800 );
	assert( y < 600 );
	((D3DCOLOR*)backRect.pBits)[ x + (backRect.Pitch >> 2) * y ] = c;
}

void D3DGraphics::BeginFrame()
{
	HRESULT result;

	result = pDevice->Clear( 0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),0.0f,0 ); //Bacground Color Change
	assert( !FAILED( result ) );

	result = pBackBuffer->LockRect( &backRect,NULL,NULL );
	assert( !FAILED( result ) );
}

void D3DGraphics::EndFrame()
{
	HRESULT result;

	result = pBackBuffer->UnlockRect();
	assert( !FAILED( result ) );

	result = pDevice->Present( NULL,NULL,NULL,NULL );
	assert( !FAILED( result ) );
}

void D3DGraphics::DrawDisc( int cx,int cy,int r,int rd,int g,int b )
{
	for( int x = cx - r; x < cx + r; x++ )
	{
		for( int y = cy - r; y < cy + r; y++ )
		{
			if( sqrt( (float)( (x - cx)*(x - cx) + (y - cy)*(y - cy) ) ) < r )
			{
				PutPixel( x,y,rd,g,b );
			}
		}
	}
}

void D3DGraphics::DrawLine( int x1,int y1,int x2,int y2,int r,int g,int blu )
{
	 int dx = x2 - x1;
	int dy = y2 - y1;

	if( dy == 0 && dx == 0 )
	{
		PutPixel( x1,y1,r,g,blu );
	}
	else if( abs( dy ) > abs( dx ) )
	{
		if( dy < 0 )
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		float m = (float)dx / (float)dy;
		float b = x1 - m*y1;
		for( int y = y1; y <= y2; y = y + 1 )
		{
			int x = (int)(m*y + b + 0.5f);
			PutPixel( x,y,r,g,blu );
		}
	}
	else
	{
		if( dx < 0 )
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		float m = (float)dy / (float)dx;
		float b = y1 - m*x1;
		for( int x = x1; x <= x2; x = x + 1 )
		{
			int y = (int)(m*x + b + 0.5f);
			PutPixel( x,y,r,g,blu );
		}
	}
}

void D3DGraphics::DrawCircle( int centerX,int centerY,int radius,int r,int g,int b )
{
	int rSquared = radius*radius;
	int xPivot = (int)(radius * 0.707107f + 0.5f);
	for( int x = 0; x <= xPivot; x++ )
	{
		int y = (int)(sqrt( (float)( rSquared - x*x ) ) + 0.5f);
		PutPixel( centerX + x,centerY + y,r,g,b );
		PutPixel( centerX - x,centerY + y,r,g,b );
		PutPixel( centerX + x,centerY - y,r,g,b );
		PutPixel( centerX - x,centerY - y,r,g,b );
		PutPixel( centerX + y,centerY + x,r,g,b );
		PutPixel( centerX - y,centerY + x,r,g,b );
		PutPixel( centerX + y,centerY - x,r,g,b );
		PutPixel( centerX - y,centerY - x,r,g,b );
	}
}

/*void D3DGraphics::DrawSurface( int xoff, int yoff, int width, int height, const D3DCOLOR* surf )
{
	for(int y = 0; y < height; y++)
		for(int x = 0; x < width; x++)
			PutPixel(x + xoff, y + yoff, surf[x + y*width]);
}*/

void D3DGraphics::DrawSprite(int xoff, int yoff, Sprite* sprite)
{
	for(int y = 0; y < sprite->heigth; y++)
		for(int x = 0; x < sprite->width; x++)
		{
			D3DCOLOR c = sprite->surface[x + y * sprite->width];
			if(c != sprite->key)
				PutPixel(x + xoff, y + yoff, c);
		}
}

void LoadSprite( Sprite* sprite, const char* fileName, unsigned int width, unsigned int height, D3DCOLOR key)
{
	sprite->surface = (D3DCOLOR*)malloc( sizeof(D3DCOLOR) * width * height);
	LoadBmp(fileName, sprite->surface);
	sprite->heigth = height;
	sprite->width = width;
	sprite->key = key;
}

void LoadFont( Font* font, const char* filename, int charWidth, int charHeight, int nCharsPerRow )
{
	font->surface = (D3DCOLOR*)malloc( sizeof(D3DCOLOR) * (charWidth * nCharsPerRow) * (charHeight * 3) );
	LoadBmp( filename,font->surface );
	font->charHeight = charHeight;
	font->charWidth = charWidth;
	font->nCharsPerRow = nCharsPerRow;
}

void D3DGraphics::DrawChar( char c,int xoff,int yoff,Font* font,D3DCOLOR color )
{
	if( c < ' ' || c > '~' )
		return;
	const int sheetIndex = c - ' ';
	const int sheetCol = sheetIndex % font->nCharsPerRow;
	const int sheetRow = sheetIndex / font->nCharsPerRow;
	const int xStart = sheetCol * font->charWidth;
	const int yStart = sheetRow * font->charHeight;
	const int xEnd = xStart + font->charWidth;
	const int yEnd = yStart + font->charHeight;
	const int surfWidth = font->charWidth * font->nCharsPerRow;
	for( int y = yStart; y < yEnd; y++ )
	{
		for( int x = xStart; x < xEnd; x++ )
		{
			if( font->surface[ x + y * surfWidth ] == D3DCOLOR_XRGB( 0,0,0 ) )
				PutPixel( x + xoff - xStart,y + yoff - yStart,color );
		}	
	}
 }
void D3DGraphics::DrawString( const char* string,int xoff,int yoff,Font* font,D3DCOLOR color )
{
	for( int index = 0; string[ index ] != '\0'; index++ )
	{
		DrawChar(string[index], xoff + index * font->charWidth, yoff, font, color);
	}
}

void FreeSprite( Sprite* sprite)
{
	free(sprite->surface);
}