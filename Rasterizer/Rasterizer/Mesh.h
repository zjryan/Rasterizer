#ifndef ZJR_MESH_
#define ZJR_MESH_

#include "Geometry.h"
#include "Vertex.h"
#include "Material.h"
#include <vector>

using std::vector;

class Mesh : public Geometry
{
public:
	vector<Vertex>				vertices;
	vector<unsigned>			indices;
	int							verticesNum;
	int							indicesNum;
	Material*					material;

	Mesh();
	Mesh(Material* m);
	~Mesh();

	Color					color(const Vertex& v) const;

	static void				createTriangle(Mesh* mesh);
	static void				createCube(Mesh* mesh, float width, float height, float depth);
	static void				createSphere(Mesh* mesh, float radius, unsigned sliceCount, unsigned stackCount);
};

#endif
