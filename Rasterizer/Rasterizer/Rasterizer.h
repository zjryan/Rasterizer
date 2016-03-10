#ifndef ZJR_RASTERIZER_
#define ZJR_RASTERIZER_

#include "../Win32Lib/Simulator.h"
#include "Canvas.h"
#include "Camera.h"

class Scene;

class Rasterizer : public Simulator
{
public:
	Rasterizer(HINSTANCE hinstance, std::wstring = L"Rasterizer");
	~Rasterizer();

	bool					initialized() override;
	int						run() override;
	LRESULT					wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

private:
	void					buildCanvas(const Color& backgroundColor);
	void					buildScene();
	void					buildCamera();

	void					updateCamera();
	void					updateSceneElement();
	void					clear();
	void					renderScene();
	void					present();

private:
	Canvas*					canvas;
	Scene*					scene;
	Camera*					camera;
};

#endif

