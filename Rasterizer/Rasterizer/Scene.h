#ifndef ZJR_SCENE_
#define ZJR_SCENE_

#include "../GraphicLib/inc/Matrix4x4.h"
#include "Mesh.h"
#include <vector>

class Canvas;
using std::vector;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void				createScene() = 0;
	Matrix4x4					viewProjectionMatrix() const;
	void						setViewProjectionMatrix(const Matrix4x4& m);
	void						add(Mesh* m);

	static void					drawScene(Canvas* canvas, Scene* scene);

protected:
	void						destroyMeshes();
	virtual void				draw(Canvas* canvas, Mesh* mesh, const Matrix4x4& wvp) = 0;

protected:
	Matrix4x4					viewProjection;
	vector<Mesh*>				meshes;
};

inline Matrix4x4 Scene::viewProjectionMatrix() const
{
	return viewProjection;
}

inline void Scene::setViewProjectionMatrix(const Matrix4x4& m)
{
	viewProjection = m;
}

class WireFrameScene : public Scene
{
public:
	WireFrameScene();
	~WireFrameScene();

	virtual void				createScene() override;
	virtual void				draw(Canvas* canvas, Mesh* mesh, const Matrix4x4& wvp) override;
};

class TextureScene : public Scene
{
public:
	TextureScene();
	~TextureScene();

	virtual void				createScene() override;
	virtual void				draw(Canvas* canvas, Mesh* mesh, const Matrix4x4& wvp) override;
};

#endif
