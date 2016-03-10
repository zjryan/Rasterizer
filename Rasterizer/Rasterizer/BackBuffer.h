#ifndef ZJR_BACKBUFFER_
#define ZJR_BACKBUFFER_

#include "../Win32Lib/WinGDI.h"
#include "../GraphicLib/inc/Color.h"
#include "Utilities.h"

class BackBuffer
{
public:
	using Bitmap = WinGDI::WinBitmap;

	BackBuffer(INT w, INT h, const Color& bgColor, bool msaa = MSAA_ON);
	~BackBuffer();

	INT							width() const;
	INT							height() const;
	Bitmap*						presentImage() const;
	void						drawPixel(int x, int y, const Color& c);

	void						swapBuffer();
	void						resetBuffer();
	void						writeToPresentBuffer();
	void						averageColor(int x, int y, BYTE& R, BYTE& G, BYTE& B);

public:
	bool						MSAA;
	INT							bufferWidth;
	INT							bufferHeight;
	Color						backgroundColor;
	Bitmap						*presentBuffer;
	Bitmap						*inputBuffer;
};

inline INT BackBuffer::width() const
{
	return bufferWidth;
}

inline INT BackBuffer::height() const
{
	return bufferHeight;
}

inline WinGDI::WinBitmap* BackBuffer::presentImage() const
{
	return presentBuffer;
}

__forceinline void BackBuffer::drawPixel(int x, int y, const Color& c)
{
	auto bgc = c.format();
	unsigned char R = bgc.R;
	unsigned char G = bgc.G;
	unsigned char B = bgc.B;
	auto drawArea = inputBuffer->pixelBits();
	auto index = (bufferHeight - y) * bufferWidth + x;
	drawArea[index * 3 + 2] = R;
	drawArea[index * 3 + 1] = G;
	drawArea[index * 3 + 0] = B;
}

#endif
