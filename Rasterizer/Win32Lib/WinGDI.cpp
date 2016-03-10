#include "WinGDI.h"
#include <iostream>
using namespace std;

namespace WinGDI
{
	WinBitmap::WinBitmap(std::wstring filename)
	{
		constructBitmap(filename);
	}

	WinBitmap::WinBitmap(UINT w, UINT h, BmBits bits)
		:	bmwidth(w),
			bmheight(h)
	{
		constructBitmap(w, h, bits);
	}

	WinBitmap::~WinBitmap()
	{
		if (bmHandle)
		{
			DeleteObject(bmHandle);
		}
	}

	void WinBitmap::constructBitmap(std::wstring filename)
	{
		BITMAPFILEHEADER	bmHeader;
		BITMAPINFO*			bmInfo;
		HANDLE				filehandle;

		filehandle = CreateFile(filename.c_str(), GENERIC_READ, FILE_SHARE_READ,
			NULL, OPEN_EXISTING, 0, NULL);
		//读文件失败，BmHandle设置为NULL
		if (filehandle == INVALID_HANDLE_VALUE)
		{
			bmHandle = NULL;
			return;
		}

		//读文件头
		DWORD bytesRead;
		bool succeed = ReadFile(filehandle, &bmHeader, sizeof(BITMAPFILEHEADER),
			&bytesRead, NULL);

		if (!succeed || bytesRead != sizeof(BITMAPFILEHEADER)
			|| bmHeader.bfType != 0x4d42)
		{
			CloseHandle(filehandle);
			bmHandle = NULL;
			return;
		}

		//读信息头
		DWORD bmInfoSize = bmHeader.bfOffBits - sizeof(BITMAPFILEHEADER);
		bmInfo = new BITMAPINFO[bmInfoSize];

		succeed = ReadFile(filehandle, bmInfo, bmInfoSize, &bytesRead, NULL);
		if (!succeed || bytesRead != bmInfoSize)
		{
			delete[] bmInfo;
			CloseHandle(filehandle);
			bmHandle = NULL;
			return;
		}
		bmHandle = CreateDIBSection(NULL, bmInfo, DIB_RGB_COLORS, (void**)&bmPixelBits, NULL, 0);
		if (bmHandle == NULL)
		{
			delete[] bmInfo;
			CloseHandle(filehandle);
			return;
		}

		BITMAP tempBitmap;
		GetObject(bmHandle, sizeof(BITMAP), &tempBitmap);
		bmwidth = tempBitmap.bmWidth;
		bmheight = tempBitmap.bmHeight;
		bmbits = tempBitmap.bmBitsPixel;
		ReadFile(filehandle, bmPixelBits, bmHeader.bfSize - bmHeader.bfOffBits,
			&bytesRead, NULL);

		delete[] bmInfo;
		CloseHandle(filehandle);
	}

	void WinBitmap::constructBitmap(UINT w, UINT h, BmBits bits)
	{
		int bitCount = bitmapBits(bits);
		BITMAPINFO bmpInfo;
		bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmpInfo.bmiHeader.biWidth = w;
		bmpInfo.bmiHeader.biHeight = h;
		bmpInfo.bmiHeader.biPlanes = 1;
		bmpInfo.bmiHeader.biBitCount = bitCount;
		bmpInfo.bmiHeader.biCompression = BI_RGB;

		bmHandle = CreateDIBSection(NULL, &bmpInfo, DIB_RGB_COLORS, (void**)&bmPixelBits, NULL, 0);
	}

}
