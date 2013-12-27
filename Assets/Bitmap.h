#pragma once
#include <d3d9.h>

struct BitmapFileHeader
{              
   unsigned int fileSize;             
   unsigned short reserved1, reserved2;
   unsigned int offsetToPixelData;                  
};

struct BitmapInfoHeader
{
   unsigned int size;               
   long int width,height;                
   unsigned short int planes;         
   unsigned short int bits;                
   unsigned int compression;               
   unsigned int imagesize;    
   int xresolution,yresolution;     
   unsigned int ncolours;           
   unsigned int importantcolours;   
};

struct Pixel24
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

void LoadBmp( const char* filename, D3DCOLOR* surface );