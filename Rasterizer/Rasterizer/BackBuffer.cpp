#include "BackBuffer.h"
#include <iostream>

using namespace WinGDI;

BackBuffer::BackBuffer(INT w, INT h, const Color& bgColor, bool msaa)
	:	MSAA(msaa),
		bufferWidth(w),
		bufferHeight(h),
		backgroundColor(bgColor),
		presentBuffer(nullptr),
		inputBuffer(nullptr)
{
	inputBuffer = new WinBitmap(w, h);
	if(MSAA)
	{
		w /= 2;
		h /= 2;
	}
	presentBuffer = new WinBitmap(w, h);
}

BackBuffer::~BackBuffer()
{
	Memory::safeDelete(inputBuffer);
	Memory::safeDelete(presentBuffer);
}

void BackBuffer::swapBuffer()
{
	if(MSAA)
	{
		writeToPresentBuffer();
	}
	else
	{
		std::swap(inputBuffer, presentBuffer);
	}
}

void BackBuffer::resetBuffer()
{
	auto bgc = backgroundColor.format();
	unsigned char R = bgc.R;
	unsigned char G = bgc.G;
	unsigned char B = bgc.B;

	auto drawArea = inputBuffer->pixelBits();
	for (int i = 0; i < bufferHeight; ++i)
	{
		for (int j = 0; j < bufferWidth; ++j)
		{
			auto index = j + i * bufferWidth;
			drawArea[index * 3 + 2] = R;
			drawArea[index * 3 + 1] = G;
			drawArea[index * 3 + 0] = B;
		}
	}
}

void BackBuffer::writeToPresentBuffer()
{
	int w = bufferWidth / 2;
	int h = bufferHeight / 2;

	auto presentArea = presentBuffer->pixelBits();
	
	for (int i = 0, n = 0; i < h; ++i, n+=2)
	{
		for (int j = 0, m = 0; j < w; ++j, m+=2)
		{
			auto pindex = j + i * w;
			BYTE R, G, B;
			averageColor(m, n, R, G, B);
			/*std::cout << m << n << std::endl;*/

			//std::cout << (int)R  <<" "<< (int)G <<" "<< (int)B<<" "<< std::endl;
			presentArea[pindex * 3 + 2] = R;
			presentArea[pindex * 3 + 1] = G;
			presentArea[pindex * 3 + 0] = B;
		}
	}
}

void BackBuffer::averageColor(int x, int y, BYTE& R, BYTE& G, BYTE& B)
{
	auto inputArea = inputBuffer->pixelBits();
	short r, g, b;
	auto index = x + y * bufferWidth;
	r = inputArea[index * 3 + 2];
	g = inputArea[index * 3 + 1];
	b = inputArea[index * 3 + 0];
	index = (x + 1) + y * bufferWidth;
	r += inputArea[index * 3 + 2];
	g += inputArea[index * 3 + 1];
	b += inputArea[index * 3 + 0];
	index = x + (y + 1) * bufferWidth;
	r += inputArea[index * 3 + 2];
	g += inputArea[index * 3 + 1];
	b += inputArea[index * 3 + 0];
	index = (x + 1) + (y + 1) * bufferWidth;
	r += inputArea[index * 3 + 2];
	g += inputArea[index * 3 + 1];
	b += inputArea[index * 3 + 0];

	R = static_cast<BYTE>(r / 4);
	G = static_cast<BYTE>(g / 4);
	B = static_cast<BYTE>(b / 4);
}
