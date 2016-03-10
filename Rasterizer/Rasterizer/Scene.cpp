#include "Scene.h"
#include "Canvas.h"
#include "Utilities.h"
#include "Texture.h"

Scene::Scene()
	:	viewProjection(),
		meshes()
{
}

Scene::~Scene()
{
	destroyMeshes();
}

void Scene::add(Mesh* mesh)
{
	meshes.push_back(mesh);
}

void Scene::drawScene(Canvas* canvas, Scene* scene)
{
	Matrix4x4 scale;
	Matrix4x4 rotate;
	Matrix4x4 translate;
	Matrix4x4 world;
	Matrix4x4 worldViewProj;
	for (auto mesh : scene->meshes)
	{
		scale = Matrix4x4::scale(mesh->scale);
		rotate = Matrix4x4::rotate(mesh->rotate);
		translate = Matrix4x4::translate(mesh->translate);
		world = scale * rotate * translate;
		worldViewProj = world * scene->viewProjectionMatrix();
		scene->draw(canvas, mesh, worldViewProj);
	}
}

void Scene::destroyMeshes()
{
	for(auto m : meshes)
	{
		Memory::safeDelete(m);
	}
	meshes.clear();
}

WireFrameScene::WireFrameScene()
{
}

WireFrameScene::~WireFrameScene()
{
}

void WireFrameScene::createScene()
{
	Mesh* cube = new Mesh();
	Mesh::createCube(cube, 1.0f, 1.0f, 1.0f);
	cube->scale = Vector3(1.0f, 1.0f, 1.0f);
	cube->rotate = Vector3(45.0f, 45.0f, 0.0f);
	cube->translate = Vector3(0.0f, 0.0f, 0.0f);
	add(cube);

	Mesh* sphere = new Mesh();
	Mesh::createSphere(sphere, 1.0f, 40, 40);
	sphere->scale = Vector3(1.0f, 1.0f, 1.0f);
	sphere->rotate = Vector3(60.0f, 0.0f, 0.0f);
	sphere->translate = Vector3(2.0f, 2.0f, 0.0f);
	add(sphere);
}

void WireFrameScene::draw(Canvas* canvas, Mesh* mesh, const Matrix4x4& wvp)
{
	canvas->drawWireFrame(mesh, wvp);
}

TextureScene::TextureScene()
{
}

TextureScene::~TextureScene()
{
}

void TextureScene::createScene()
{
	Texture* t1 = new Texture(L"./Textures/darkbrick.bmp");
	Material* m1 = new Material(t1);
	Mesh* cube = new Mesh(m1);
	Mesh::createCube(cube, 1.0f, 1.0f, 1.0f);
	cube->scale = Vector3(1.0f, 1.0f, 1.0f);
	cube->rotate = Vector3(45.0f, 45.0f, 0.0f);
	cube->translate = Vector3(0.0f, 0.0f, 0.0f);
	add(cube);

	Texture* t2 = new Texture(L"./Textures/Earth.bmp");
	Material* m2 = new Material(t2);
	Mesh* sphere = new Mesh(m2);
	Mesh::createSphere(sphere, 1.0f, 40, 40);
	sphere->scale = Vector3(1.0f, 1.0f, 1.0f);
	sphere->rotate = Vector3(60.0f, 0.0f, 0.0f);
	sphere->translate = Vector3(2.0f, 2.0f, 0.0f);
	add(sphere);
}

void TextureScene::draw(Canvas* canvas, Mesh* mesh, const Matrix4x4& wvp)
{
	canvas->drawMesh(mesh, wvp);
}
