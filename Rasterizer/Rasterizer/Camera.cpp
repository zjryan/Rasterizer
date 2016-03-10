#include "Camera.h"
#include "Maths.h"

using namespace Math;

Vector3 Camera::rotate = Vector3(0.0f, 0.0f, 0.0f);

Camera::Camera()
	:	eye(0.0f,0.0f,-20.0f),
		target(0.0f, 0.0f, 0.0f),
		up(0.0f, 1.0f, 0.0f)
{
}

Camera::~Camera()
{
}

Matrix4x4 Camera::lookAtLH(const Point& eye, const Point& target, const Vector3& up)
{
	auto vz = target - eye;
	vz.normalize();
	auto vx = up.cross(vz);
	vx.normalize();
	auto vy = vz.cross(vx);
	vy.normalize();

	float eyex = -vx.dot(eye);
	float eyey = -vy.dot(eye);
	float eyez = -vz.dot(eye);

	return Matrix4x4(vx.x, vy.x, vz.x, 0.0f,
					 vx.y, vy.y, vz.y, 0.0f,
					 vx.z, vy.z, vz.z, 0.0f,
					 eyex, eyey, eyez, 1.0f);
}

Matrix4x4 Camera::perspectiveFovLH(float fieldOfView, float aspect, float znear, float zfar)
{
	float height = 1 / tan(radians(fieldOfView) / 2);
	float width = height / aspect;
	return Matrix4x4(width,	0.0f,   0.0f,							 0.0f,
					  0.0f,	height, 0.0f,							 0.0f,
					  0.0f, 0.0f,	zfar / (zfar - znear),			 1.0f,
					  0.0f, 0.0f,	(znear * zfar) / (znear - zfar), 0.0f);
}

void Camera::rotateCamera(Camera* cam)
{
	auto rotateMatrix = Matrix4x4::rotate(rotate);
	cam->eye = cam->eye * rotateMatrix;
	cam->up = cam->up * rotateMatrix;
}



