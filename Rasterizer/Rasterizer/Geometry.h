#ifndef ZJR_GEOMETRY_
#define ZJR_GEOMETRY_

#include "../GraphicLib/inc/Vector3.h"

class Geometry
{
public:
	Geometry();
	virtual ~Geometry() = 0;

	Vector3					rotate;
	Vector3					translate;
	Vector3					scale;
};

#endif
