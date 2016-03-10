#ifndef ZJR_WINGDI_
#define ZJR_WINGDI_

#include <Windows.h>
#include <string>

namespace WinGDI
{
	class WinBitmap
	{
	public:
		enum BmBits
		{
			bm24Bits,
			bm32Bits
		};

		WinBitmap(std::wstring filename);
		WinBitmap(UINT w, UINT h, BmBits bits = bm24Bits);
		~WinBitmap();

		UINT					width() const;
		UINT					height() const;
		INT						bitmapBits(BmBits bits) const;
		INT						bitmapBits() const;
		HBITMAP					hBitmap() const;
		BYTE*					pixelBits() const;

	protected:
		UINT					bmbits;
		UINT					bmwidth;
		UINT					bmheight;
		HBITMAP					bmHandle;
		BYTE*					bmPixelBits;

		void					constructBitmap(std::wstring filename);
		void					constructBitmap(UINT w, UINT h, BmBits bits);
	};

	inline UINT WinBitmap::width() const
	{
		return bmwidth;
	}

	inline UINT WinBitmap::height() const
	{
		return bmheight;
	}

	inline INT WinBitmap::bitmapBits(BmBits bits) const
	{
		switch (bits)
		{
		case bm24Bits:
			return 24;

		case bm32Bits:
			return 32;

		default:
			return 1;
		}
	}

	inline INT WinBitmap::bitmapBits() const
	{
		return bmbits;
	}

	inline HBITMAP WinBitmap::hBitmap() const
	{
		return bmHandle;
	}

	inline BYTE* WinBitmap::pixelBits() const
	{
		return bmPixelBits;
	}

}

#endif
