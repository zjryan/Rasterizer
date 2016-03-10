#include <assert.h>
#include "Texture.h"
#include "Utilities.h"
#include "../GraphicLib/inc/Color.h"

Texture::Texture(std::wstring texturePath)
{
	Bitmap* tex = new Bitmap(texturePath);
	int tw = tex->width();
	int th = tex->height();
	pixelBits = tex->bitmapBits();
	mipmap.push_back(tex);
	
	//initialize mipchain
	for (int i = 1; i < 4; ++i)
	{
		downSampleTexture(i);
	}
}

Texture::~Texture()
{
	destoryMipChain();
}

Color Texture::sample(float u, float v, int level)
{
	assert(level >= 0 && level < 4);
	auto tex = mipmap[level];
	int w = tex->width();
	int h = tex->height();

	int utex = static_cast<int>(u * (w - 1));
	int vtex = static_cast<int>(v * (h - 1));

	int index = utex + vtex * w;
	auto imageBuffer = tex->pixelBits();
	
	auto pixelBytes = pixelBits / 8;
	auto R = static_cast<float>(imageBuffer[index * pixelBytes + 2]) / 256.0f;
	auto G = static_cast<float>(imageBuffer[index * pixelBytes + 1]) / 256.0f;
	auto B = static_cast<float>(imageBuffer[index * pixelBytes + 0]) / 256.0f;

	return Color(R, G, B);
}

void Texture::downSampleTexture(int level)
{
	assert(level < 4 && level > 0);
	auto lastTex = mipmap[level - 1];
	int w = lastTex->width();
	int h = lastTex->height();

	Bitmap::BmBits bits = pixelBits == 24 ? Bitmap::BmBits::bm24Bits : Bitmap::BmBits::bm32Bits;
	int pixelBytes = pixelBits / 8;
	w /= 2;
	h /= 2;
	Bitmap* tex = new Bitmap(w, h, bits);
	auto curImage = tex->pixelBits();
	auto lastImage = mipmap[level - 1]->pixelBits();

	for (int i = 0, n = 0; i < h; ++i, n += 2)
	{
		for (int j = 0, m = 0; j < w; ++j, m += 2)
		{
			auto curIndex = j + i * w;
			auto lastIndex = m + n * w * 2;

			curImage[curIndex * pixelBytes + 2] = lastImage[lastIndex * pixelBytes + 2];
			curImage[curIndex * pixelBytes + 1] = lastImage[lastIndex * pixelBytes + 1];
			curImage[curIndex * pixelBytes + 0] = lastImage[lastIndex * pixelBytes + 0];
		}
	}
	mipmap.push_back(tex);
}

void Texture::destoryMipChain()
{
	for(auto elem : mipmap)
	{
		Memory::safeDelete(elem);
	}
}
