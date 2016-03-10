#ifndef ZJR_VERTEX_
#define ZJR_VERTEX_

#include "../GraphicLib/inc/Point.h"
#include "../GraphicLib/inc/Vector2.h"
#include "../GraphicLib/inc/Normal.h"
#include "../GraphicLib/inc/Color.h"

class Vertex
{
public:
	Point					position;
	Normal					normal; 
	Vector2					texCoord;
	Color					color;

	Vertex();
	Vertex(const Point& p, const Normal& n = Normal(), const Vector2& t = Vector2(), const Color& c = Colors::Black);
	Vertex(float px, float py, float pz,
		   float nx, float ny, float nz,
		   float u, float v,
		   float r, float g, float b);
	Vertex(float px, float py, float pz,
		   float nx, float ny, float nz,
		   float u, float v,
		   const Color& c);
	~Vertex();
};

#endif
