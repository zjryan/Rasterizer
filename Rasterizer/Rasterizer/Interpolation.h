#ifndef ZJR_INTERPOLATION_
#define ZJR_INTERPOLATION_

#include "Vertex.h"

namespace Interpolation
{
	inline Color interpolate(const Color& c1, const Color& c2, float factor)
	{
		return c1 + (c2 - c1) * factor;
	}

	inline Point interpolate(const Point& p1, const Point& p2, float factor)
	{
		return p1 + (p2 - p1) * factor;
	}

	inline Normal interpolate(const Normal& n1, const Normal& n2, float factor)
	{
		return n1 + (n2 - n1) * factor;
	}

	inline Vector2 interpolate(const Vector2& t1, const Vector2& t2, float factor)
	{
		return t1 + (t2 - t1) * factor;
	}

	inline Vertex interpolate(const Vertex& v1, const Vertex& v2, float factor)
	{
		auto position = interpolate(v1.position, v2.position, factor);
		auto normal = interpolate(v1.normal, v2.normal, factor);
		auto texCoord = interpolate(v1.texCoord, v2.texCoord, factor);
		auto color = interpolate(v1.color, v2.color, factor);
		return Vertex(position, normal, texCoord, color);
	}
}

#endif
