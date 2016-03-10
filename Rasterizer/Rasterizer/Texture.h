#ifndef ZJR_TEXTURE_
#define ZJR_TEXTURE_

#include "../Win32Lib/WinGDI.h"
#include <vector>

class Color;

class Texture
{
public:
	typedef WinGDI::WinBitmap Bitmap;

	Texture(std::wstring texturePath);
	~Texture();

	Color						sample(float u, float v, int level = 0);
	int							mipLevel(float z);

private:
	void						downSampleTexture(int level);
	void						destoryMipChain();

	std::vector<Bitmap*>		mipmap;
	int							pixelBits;
};

inline int Texture::mipLevel(float z)
{
	if (z > 0.0f && z < 0.5f)
	{
		return 0;
	}
	else if (z >= 0.5f && z < 0.75f)
	{
		return 1;
	}
	else if (z >= 0.75f && z < 0.875f)
	{
		return 2;
	}
	return 3;
}

#endif
