#include "Mesh.h"
#include "Utilities.h"
#include "../GraphicLib/inc/Maths.h"

Mesh::Mesh()
	:	Geometry()
{
}

Mesh::Mesh(Material* m)
	:	Geometry(),
		material(m)
{
}

Mesh::~Mesh()
{
	Memory::safeDelete(material);
}

void Mesh::createTriangle(Mesh* mesh)
{
	mesh->vertices.clear();
	mesh->indices.clear();
		
	mesh->vertices.resize(3);
	mesh->indices.resize(3);
	mesh->verticesNum = 3;
	mesh->indicesNum = 3;
		
	mesh->vertices[0] = Vertex(-1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, Colors::Red);
	mesh->vertices[1] = Vertex( 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, Colors::Green);
	mesh->vertices[2] = Vertex( 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, Colors::Blue);
		
	mesh->indices[0] = 0;
	mesh->indices[1] = 1;
	mesh->indices[2] = 2;
}

void Mesh::createCube(Mesh* mesh, float width, float height, float depth)
{
	mesh->vertices.clear();
	mesh->indices.clear();

	mesh->vertices.resize(24);
	mesh->indices.resize(36);
	mesh->verticesNum = 24;
	mesh->indicesNum = 36;

	float w = 0.5f * width;
	float h = 0.5f * height;
	float d = 0.5f * depth;

	// Fill in the front face vertex data.
	mesh->vertices[0] = Vertex(-w, -h, -d, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, Colors::Red);
	mesh->vertices[1] = Vertex(-w, +h, -d, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, Colors::Green);
	mesh->vertices[2] = Vertex(+w, +h, -d, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, Colors::Blue);
	mesh->vertices[3] = Vertex(+w, -h, -d, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, Colors::Black);

	// Fill in the back face vertex data.
	mesh->vertices[4] = Vertex(-w, -h, +d, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, Colors::Yellow);
	mesh->vertices[5] = Vertex(+w, -h, +d, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, Colors::Cyan);
	mesh->vertices[6] = Vertex(+w, +h, +d, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, Colors::Coral);
	mesh->vertices[7] = Vertex(-w, +h, +d, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, Colors::White);

	// Fill in the top face vertex data.
	mesh->vertices[8] = Vertex(-w, +h, -d, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, Colors::Green);
	mesh->vertices[9] = Vertex(-w, +h, +d, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, Colors::White);
	mesh->vertices[10] = Vertex(+w, +h, +d, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, Colors::Coral);
	mesh->vertices[11] = Vertex(+w, +h, -d, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, Colors::Blue);

	// Fill in the bottom face vertex data.
	mesh->vertices[12] = Vertex(-w, -h, -d, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, Colors::Red);
	mesh->vertices[13] = Vertex(+w, -h, -d, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, Colors::Black);
	mesh->vertices[14] = Vertex(+w, -h, +d, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, Colors::Cyan);
	mesh->vertices[15] = Vertex(-w, -h, +d, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, Colors::Yellow);

	// Fill in the left face vertex data.
	mesh->vertices[16] = Vertex(-w, -h, +d, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, Colors::Yellow);
	mesh->vertices[17] = Vertex(-w, +h, +d, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, Colors::White);
	mesh->vertices[18] = Vertex(-w, +h, -d, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, Colors::Green);
	mesh->vertices[19] = Vertex(-w, -h, -d, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, Colors::Red);

	// Fill in the right face vertex data.
	mesh->vertices[20] = Vertex(+w, -h, -d, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, Colors::Black);
	mesh->vertices[21] = Vertex(+w, +h, -d, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, Colors::Blue);
	mesh->vertices[22] = Vertex(+w, +h, +d, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, Colors::Coral);
	mesh->vertices[23] = Vertex(+w, -h, +d, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, Colors::Cyan);

	mesh->indices = {  0,  1,  2,
					   0,  2,  3,
					   4,  5,  6,
					   4,  6,  7,
					   8,  9, 10,
					   8, 10, 11,
					  12, 13, 14,
					  12, 14, 15,
					  16, 17, 18,
					  16, 18, 19,
					  20, 21, 22,
					  20, 22, 23 };
}

void Mesh::createSphere(Mesh* mesh, float radius, unsigned sliceCount, unsigned stackCount)
{
	mesh->vertices.clear();
	mesh->indices.clear();

	Vertex top(0.0f, +radius, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, Colors::Black);
	Vertex bottom(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, Colors::Black);

	mesh->vertices.push_back(top);

	float phiStep = PI / stackCount;
	float thetaStep = TWO_PI / sliceCount;

	for (int i = 1; i <= stackCount - 1; ++i)
	{
		float phi = i * phiStep;
		for (int j = 0; j <= sliceCount; ++j)
		{
			float theta = j * thetaStep;

			Vertex v;

			v.position.x = radius * sinf(phi) * cosf(theta);
			v.position.y = radius * cosf(phi);
			v.position.z = radius * sinf(phi) * sinf(theta);

			Vector3 normal = v.position;
			normal.normalize();
			v.normal = normal;

			v.texCoord.x = theta * INV_TWO_PI;
			v.texCoord.y = phi * INV_PI;

			v.color = Colors::Black;

			mesh->vertices.push_back(v);
		}
	}

	mesh->vertices.push_back(bottom);
	mesh->verticesNum = mesh->vertices.size();

	for (unsigned i = 1; i <= sliceCount; ++i)
	{
		mesh->indices.push_back(0);
		mesh->indices.push_back(i + 1);
		mesh->indices.push_back(i);
	}

	unsigned baseIndex = 1;
	unsigned ringVertexCount = sliceCount + 1;

	for (unsigned i = 0; i < stackCount - 2; ++i)
	{
		for (unsigned j = 0; j < sliceCount; ++j)
		{
			mesh->indices.push_back(baseIndex + i * ringVertexCount + j);
			mesh->indices.push_back(baseIndex + i * ringVertexCount + j + 1);
			mesh->indices.push_back(baseIndex + (i + 1) * ringVertexCount + j);

			mesh->indices.push_back(baseIndex + (i + 1) * ringVertexCount + j);
			mesh->indices.push_back(baseIndex + i * ringVertexCount + j + 1);
			mesh->indices.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
		}
	}

	unsigned southPoleIndex = mesh->vertices.size() - 1;
	baseIndex = southPoleIndex - ringVertexCount;

	for (unsigned i = 0; i < sliceCount; ++i)
	{
		mesh->indices.push_back(southPoleIndex);
		mesh->indices.push_back(baseIndex + i);
		mesh->indices.push_back(baseIndex + i + 1);
	}

	mesh->indicesNum = mesh->indices.size();
}

Color Mesh::color(const Vertex& v) const
{
	return material->color(v);
}
