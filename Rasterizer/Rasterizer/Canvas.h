#ifndef ZJR_CANVAS_
#define ZJR_CANVAS_

#include "Vertex.h"
#include "BackBuffer.h"
#include "../GraphicLib/inc/Matrix4x4.h"

class Mesh;
class Texture;

class Canvas
{
public:
	typedef float* DepthBuffer;

	Canvas(int w, int h, const Color& c = Colors::Black);
	~Canvas();

	const BackBuffer*		frameBuffer() const;
	int						width() const;
	int						height() const;

	void					clear();
	void					swapBuffer();

	void					drawMesh(Mesh* mesh, const Matrix4x4& worldViewProj);
	void					drawWireFrame(Mesh* mesh, const Matrix4x4& worldViewProj);

private:
	Point					project(const Point& p);
	void					putPixel(int x, int y, float z, const Color& c);
	void					drawPoint(const Point& p, const Color& c = Colors::Black);
	void					drawLine(const Vertex& v1, const Vertex& v2, const Color& c = Colors::Black);
	void					drawScanline(const Vertex& v1, const Vertex& v2, Mesh* mesh = nullptr);
	void					drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3, Mesh* mesh = nullptr);

private:
	BackBuffer*				backBuffer;
	DepthBuffer				depthBuffer;
	int						canvasWidth;
	int						canvasHeight;
};


inline const BackBuffer* Canvas::frameBuffer() const
{
	return backBuffer;
}

inline int Canvas::width() const
{
	return canvasWidth;
}

inline int Canvas::height() const
{
	return canvasHeight;
}

#endif
