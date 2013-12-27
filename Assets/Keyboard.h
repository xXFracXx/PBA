/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.10.21											  *	
 *	Keyboard.h																			  *
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
#include <Windows.h>
#include <queue>

class KeyboardServer;

class KeyboardClient
{
public:
	KeyboardClient( KeyboardServer& kServer );
	bool KeyIsPressed( unsigned char keycode ) const;
	bool KeyIsReleased( unsigned char keycode ) const;
	unsigned char ReadKey();
	unsigned char PeekKey() const;
	unsigned char ReadChar();
	unsigned char PeekChar() const;
	void FlushKeyBuffer();
	void FlushCharBuffer();
	void FlushBuffers();
	void ClearState();
	
private:
	KeyboardServer& server;
};

class KeyboardServer
{
	friend KeyboardClient;
public:
	KeyboardServer();
	void OnKeyPressed( unsigned char keycode );
	void OnKeyReleased( unsigned char keycode );
	void OnChar( unsigned char character );
	void ClearState();
private:
	static const int nKeys = 256;
	static const int bufferSize = 4;
	bool keystates[ nKeys ];
	bool rKeystates[ nKeys ];
	std::queue<unsigned char> keybuffer;
	std::queue<unsigned char> charbuffer;
};