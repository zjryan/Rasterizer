#ifndef ZJR_CAMERA_
#define ZJR_CAMERA_

#include "../GraphicLib/inc/Point.h"
#include "../GraphicLib/inc/Matrix4x4.h"

class Camera
{
public:
	Camera();
	~Camera();

	Point					eyePos() const;
	Point					targetPos() const;
	Vector3					upVector() const;
	
	static Vector3			rotation();
	static void				setRotate(const Vector3& r);
	static Matrix4x4		lookAtLH(const Point& eye, const Point& target, const Vector3& up);	
	static Matrix4x4		perspectiveFovLH(float fieldOfView, float aspect, float znear, float zfar);
	static void				rotateCamera(Camera* cam);

private:
	Point					eye;
	Point					target;
	Vector3					up;
	static Vector3			rotate;
};

inline Point Camera::eyePos() const
{
	return eye;
}

inline Point Camera::targetPos() const
{
	return target;
}

inline Vector3 Camera::upVector() const
{
	return up;
}

inline Vector3 Camera::rotation()
{
	return rotate;
}

inline void Camera::setRotate(const Vector3& r)
{
	rotate = r;
}

#endif
