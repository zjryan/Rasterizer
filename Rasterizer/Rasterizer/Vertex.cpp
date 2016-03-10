#include "Vertex.h"

Vertex::Vertex()
	:	position(),
		normal(),
		texCoord(),
		color()
{
}

Vertex::Vertex(const Point& p, const Normal& n, const Vector2& t, const Color& c)
	:	position(p),
		normal(n),
		texCoord(t),
		color(c)
{
}

Vertex::Vertex(float px, float py, float pz, float nx, float ny, float nz, float u, float v, float r, float g, float b)
	:	position(px, py, pz),
		normal(nx, ny, nz),
		texCoord(u, v),
		color(r, g, b)
{
}

Vertex::Vertex(float px, float py, float pz, float nx, float ny, float nz, float u, float v, const Color& c)
	:	position(px, py, pz),
		normal(nx, ny, nz),
		texCoord(u, v),
		color(c)
{
}

Vertex::~Vertex()
{
}
