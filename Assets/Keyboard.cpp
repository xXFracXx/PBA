/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.10.21											  *	
 *	Keyboard.cpp																		  *
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
#include "Keyboard.h"

KeyboardClient::KeyboardClient( KeyboardServer& kServer )
	: server( kServer )
{}

bool KeyboardClient::KeyIsPressed( unsigned char keycode ) const
{
	return server.keystates[ keycode ];
}

bool KeyboardClient::KeyIsReleased( unsigned char keycode ) const
{
	if(server.rKeystates[ keycode ])
	{
		server.rKeystates[ keycode ] = false;
		return true;
	}
	else
		return false;
}

unsigned char KeyboardClient::ReadKey()
{
	if( server.keybuffer.size() > 0 )
	{
		unsigned char keycode = server.keybuffer.front();
		server.keybuffer.pop();
		return keycode;
	}
	else
	{
		return 0;
	}
}

unsigned char KeyboardClient::PeekKey() const
{	
	if( server.keybuffer.size() > 0 )
	{
		return server.keybuffer.front();
	}
	else
	{
		return 0;
	}
}

unsigned char KeyboardClient::ReadChar()
{
	if( server.charbuffer.size() > 0 )
	{
		unsigned char charcode = server.charbuffer.front();
		server.charbuffer.pop();
		return charcode;
	}
	else
	{
		return 0;
	}
}

unsigned char KeyboardClient::PeekChar() const
{
	if( server.charbuffer.size() > 0 )
	{
		return server.charbuffer.front();
	}
	else
	{
		return 0;
	}
}

void KeyboardClient::FlushKeyBuffer()
{
	while( !server.keybuffer.empty() )
	{
		server.keybuffer.pop();
	}
}

void KeyboardClient::FlushCharBuffer()
{
	while( !server.charbuffer.empty() )
	{
		server.charbuffer.pop();
	}
}

void KeyboardClient::FlushBuffers()
{
	FlushKeyBuffer();
	FlushCharBuffer();
}

KeyboardServer::KeyboardServer()
{
	for( int x = 0; x < nKeys; x++ )
	{
		keystates[ x ] = false;
	}
}

void KeyboardServer::OnKeyPressed( unsigned char keycode )
{
	keystates[ keycode ] = true;
	
	keybuffer.push( keycode );
	if( keybuffer.size() > bufferSize )
	{
		keybuffer.pop();
	}
}

void KeyboardServer::OnKeyReleased( unsigned char keycode )
{
	keystates[ keycode ] = false;
	rKeystates[ keycode ] = true;
}

void KeyboardServer::OnChar( unsigned char character )
{
	charbuffer.push( character );
	if( charbuffer.size() > bufferSize )
	{
		charbuffer.pop();
	}
}

void KeyboardServer::ClearState()
{
	for( int i = 0; i < nKeys; i++ )
	{
		keystates[ i ] = false;
	}
}

void KeyboardClient::ClearState()
{
	server.ClearState();
}