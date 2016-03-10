#ifndef ZJR_MATERIAL_
#define ZJR_MATERIAL_

#include "../GraphicLib/inc/Color.h"
#include "Vertex.h"

class Texture;

class Material
{
public:
	Material(Texture* texture);
	~Material();

	Color			color(const Vertex& v);

private:
	Texture*		texture;
};

#endif
