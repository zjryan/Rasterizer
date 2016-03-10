#include "Canvas.h"
#include "Mesh.h"
#include "Interpolation.h"
#include "Utilities.h"
#include "../GraphicLib/inc/Maths.h"

using namespace Math;
using namespace Interpolation;

Canvas::Canvas(int w, int h, const Color& c /*= Colors::Black*/)
	:	backBuffer(new BackBuffer(w, h, c)),
		depthBuffer(new float[w * h]),
		canvasWidth(w),
		canvasHeight(h)
{
	std::fill(depthBuffer, depthBuffer + w * h, INFINITY);
}

Canvas::~Canvas()
{
	Memory::safeDelete(backBuffer);
	Memory::safeDeleteArray(depthBuffer);
}

void Canvas::putPixel(int x, int y, float z, const Color& c)
{
	int index = (canvasHeight - y) * canvasHeight + x;
	// z-test
	if(z > depthBuffer[index])
	{
		return;
	}

	depthBuffer[index] = z;
	backBuffer->drawPixel(x, y, c);
}

void Canvas::clear()
{
	backBuffer->resetBuffer();
}

void Canvas::swapBuffer()
{
	backBuffer->swapBuffer();
}

void Canvas::drawMesh(Mesh* mesh, const Matrix4x4& worldViewProj)
{
	int indexNum = mesh->indicesNum;
	Matrix4x4 worldViewProjInv = worldViewProj.inverse();
	for (int i = 0; i < indexNum; i += 3)
	{
		auto va = mesh->vertices[mesh->indices[i + 0]];
		auto vb = mesh->vertices[mesh->indices[i + 1]];
		auto vc = mesh->vertices[mesh->indices[i + 2]];

		va.position = va.position * worldViewProj;
		vb.position = vb.position * worldViewProj;
		vc.position = vc.position * worldViewProj;
		va.normal = va.normal * worldViewProjInv;
		vb.normal = vb.normal * worldViewProjInv;
		vc.normal = vc.normal * worldViewProjInv;

		va.position = project(va.position);
		vb.position = project(vb.position);
		vc.position = project(vc.position);

		drawTriangle(va, vb, vc, mesh);
	}
}

void Canvas::drawWireFrame(Mesh* mesh, const Matrix4x4& worldViewProj)
{
	int indexNum = mesh->indicesNum;
	for (int i = 0; i < indexNum; i += 3)
	{
		auto va = mesh->vertices[mesh->indices[i + 0]];
		auto vb = mesh->vertices[mesh->indices[i + 1]];
		auto vc = mesh->vertices[mesh->indices[i + 2]];

		va.position = va.position * worldViewProj;
		vb.position = vb.position * worldViewProj;
		vc.position = vc.position * worldViewProj;

		va.position = project(va.position);
		vb.position = project(vb.position);
		vc.position = project(vc.position);

		drawLine(va, vb);
		drawLine(va, vc);
		drawLine(vb, vc);
	}
}

Point Canvas::project(const Point& p)
{
	float x =  p.x * canvasWidth + canvasWidth / 2;
	float y = -p.y * canvasHeight + canvasHeight / 2;
	return Point(x, y, p.z);
}

void Canvas::drawPoint(const Point& p, const Color& c /*= Colors::Black*/)
{
	if (p.x > 0 && p.y > 0 && p.x <= canvasWidth && p.y <= canvasHeight)
	{
		putPixel(p.x, p.y, p.z, c);
	}
}

void Canvas::drawScanline(const Vertex& v1, const Vertex& v2, Mesh* mesh)
{
	int x1 = static_cast<int>(v1.position.x);
	int x2 = static_cast<int>(v2.position.x);
	int sign = x1 > x2 ? -1 : 1;
	float factor = 0.0f;

	for (int x = x1, i = 0; i < (x2 - x1) * sign + 1; i++, x += sign)
	{
		if(x1 != x2)
		{
			factor = static_cast<float>(x - x1) / (x2 - x1);
		}
		auto v = interpolate(v1, v2, factor);
		Color color;

		auto material = mesh->material;
		if(material == nullptr)
		{
			color = v.color;
		}
		else
		{
			color = material->color(v);
		}

		drawPoint(v.position, color);
	}
}

void Canvas::drawLine(const Vertex& v1, const Vertex& v2, const Color& c /*= Colors::Black*/)
{
	int x1 = static_cast<int>(v1.position.x);
	int x2 = static_cast<int>(v2.position.x);
	int y1 = static_cast<int>(v1.position.y);
	int y2 = static_cast<int>(v2.position.y);

	int dx = x1 - x2;
	int dy = y1 - y2;

	if(abs(dx) - abs(dy) > 0)
	{
		int sign = x2 - x1 > 0 ? 1 : -1;
		float ratio = 0.0f;
		if(dx != 0)
		{
			ratio = static_cast<float>(dy) / dx;
		}

		for (int x = x1; x != x2; x+= sign)
		{
			int y = y1 + (x - x1) * ratio;
			Color color = v1.color + (v2.color - v1.color) * static_cast<float>(x - x1) / (x2 - x1);
			drawPoint(Point(x, y, 0.0f), Colors::Black);
		}
	}
	else
	{
		int sign = y2 - y1 > 0 ? 1 : -1;
		float ratio = 0.0f;
		if(dy != 0)
		{
			ratio = static_cast<float>(dx) / dy;
		}

		for (int y = y1; y != y2; y += sign)
		{
			int x = x1 + (y - y1) * ratio;
			Color color = v1.color + (v2.color - v1.color) * static_cast<float>(y - y1) / (y2 - y1);
			drawPoint(Point(x, y, 0.0f), Colors::Black);
		}
	}
}

void Canvas::drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3, Mesh* mesh)
{
	const Vertex* a = &v1;
	const Vertex* b = &v2;
	const Vertex* c = &v3;

	if (a->position.y > b->position.y) 
	{
		std::swap(a, b);
	}
	if (b->position.y > c->position.y) 
	{
		std::swap(b, c);
	}
	if (a->position.y > b->position.y) 
	{
		std::swap(a, b);
	}

	float midFactor = (b->position.y - a->position.y) / (c->position.y - a->position.y);
	Vertex mid = interpolate(*a, *c, midFactor);

	int start = a->position.y;
	int finish = b->position.y;
	for (int y = start; y <= finish; ++y) 
	{
		float factor = 0.0f;
		if (finish != start) 
		{
			factor = static_cast<float>(y - start) / (finish - start);
		}
		Vertex va = interpolate(*a, *b, factor);
		Vertex vb = interpolate(*a, mid, factor);
		drawScanline(va, vb, mesh);
	}

	start = b->position.y;
	finish = c->position.y;
	for (int y = start; y <= finish; ++y) {
		float factor = 0;
		if (start != finish) {
			factor = static_cast<float>(y - start) / (finish - start);
		}
		Vertex va = interpolate(*b, *c, factor);
		Vertex vb = interpolate(mid, *c, factor);
		drawScanline(va, vb, mesh);
	}
}
