/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.10.21											  *	
 *	Windows.cpp																			  *
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
#include <Windows.h>
#include <wchar.h>
#include "D3DGraphics.h"
#include "Game.h"
#include "resource.h"
#include "Mouse.h"

static KeyboardServer kServ;
static MouseServer mServ;

LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;
		/*case WM_ACTIVATE:
			if( LOWORD(wParam) == WA_INACTIVE )
				kServ.ClearState();
			break;*/
		// ************ KEYBOARD MESSAGES ************ //
		case WM_KEYDOWN:
			kServ.OnKeyPressed( wParam );
			break;
		case WM_KEYUP:
   			kServ.OnKeyReleased( wParam );
			break;
		case WM_CHAR:
			kServ.OnChar( wParam );
			break;
		// ************ END KEYBOARD MESSAGES ************ //

		// ************ MOUSE MESSAGES ************ //
		case WM_MOUSEMOVE:
			{
				int x = (short)LOWORD( lParam );
				int y = (short)HIWORD( lParam );
				if( x > 0 && x < 800 && y > 0 && y < 600 )
				{
					mServ.OnMouseMove( x,y );
					if( !mServ.IsInWindow() )
					{
						SetCapture( hWnd );
						mServ.OnMouseEnter();
					}
				}
				else
				{
					if( wParam & (MK_LBUTTON | MK_RBUTTON) )
					{
						x = max( 0,x );
						x = min( 800-1,x );
						y = max( 0,y );
						y = min( 600-1,y );
						mServ.OnMouseMove( x,y );
					}
					else
					{
						ReleaseCapture();
						mServ.OnMouseLeave();
						mServ.OnLeftReleased();
						mServ.OnRightReleased();
					}
				}
			}
			break;
		case WM_LBUTTONDOWN:
			mServ.OnLeftPressed();
			break;
		case WM_RBUTTONDOWN:
			mServ.OnRightPressed();
			break;
		case WM_LBUTTONUP:
			mServ.OnLeftReleased();
			break;
		case WM_RBUTTONUP:
			mServ.OnRightReleased();
			break;
		// ************ END MOUSE MESSAGES ************ //
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}


int WINAPI wWinMain( HINSTANCE hInst,HINSTANCE,LPWSTR,INT )
{
	WNDCLASSEX wc = { sizeof( WNDCLASSEX ),CS_CLASSDC,MsgProc,0,0,
                      GetModuleHandle( NULL ),NULL,NULL,NULL,NULL,
                      L"Pok�mon Battle Arena",NULL };
    wc.hIconSm = (HICON)LoadImage( hInst,MAKEINTRESOURCE( IDI_APPICON16 ),IMAGE_ICON,16,16,0 );
	wc.hIcon   = (HICON)LoadImage( hInst,MAKEINTRESOURCE( IDI_APPICON32 ),IMAGE_ICON,32,32,0 );
	wc.hCursor = LoadCursor( NULL,IDC_ARROW );
    RegisterClassEx( &wc );
	
	RECT wr;
	wr.left = 650;
	wr.right = 800 + wr.left;
	wr.top = 150;
	wr.bottom = 600 + wr.top;
	AdjustWindowRect( &wr,WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,FALSE );
    HWND hWnd = CreateWindowW( L"Pok�mon Battle Arena",L"Pok�mon Battle Arena",
                              WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,wr.left,wr.top,wr.right-wr.left,wr.bottom-wr.top,
                              NULL,NULL,wc.hInstance,NULL );

    ShowWindow( hWnd,SW_SHOWDEFAULT );
    UpdateWindow( hWnd );

	Game theGame( hWnd,kServ,mServ );
	
    MSG msg;
    ZeroMemory( &msg,sizeof( msg ) );
    while( msg.message != WM_QUIT )
    {
        if( PeekMessage( &msg,NULL,0,0,PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
		{
			theGame.Go();
		}
    }

    UnregisterClass( L"Pok�mon Battle Arena Window",wc.hInstance );
    return 0;
}