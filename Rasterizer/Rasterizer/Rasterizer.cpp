#include "Rasterizer.h"
#include "BackBuffer.h"
#include "Scene.h"
#include "Texture.h"
#include "Utilities.h"

namespace
{
	Simulator* pRasterizer = nullptr;
}

LRESULT CALLBACK MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (pRasterizer == nullptr)
	{
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return pRasterizer->wndProc(hwnd, msg, wParam, lParam);
}


Rasterizer::Rasterizer(HINSTANCE hinstance, std::wstring title)
	:	Simulator(hinstance, WINDOW_WIDTH, WINDOW_HEIGHT, title),
		canvas(nullptr),
		scene(nullptr),
		camera(nullptr)
{
	pRasterizer = this;
	buildCanvas(Colors::LightSkyBlue);
	buildCamera();
	buildScene();
}

Rasterizer::~Rasterizer()
{
	Memory::safeDelete(canvas);
	Memory::safeDelete(scene);
	Memory::safeDelete(camera);
}

bool Rasterizer::initialized()
{
	if (!Simulator::initialized())
	{
		return false;
	}

	return true;
}

int Rasterizer::run()
{
	MSG msg = {};

	timer.reset();

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//calculate FPS and present
			timer.tick();
			calculateFPS();

			//rendering loop

			//update Camera
			updateCamera();

			//clear back buffer to background color
			clear();

			//update every element in the scene
			updateSceneElement();

			//render scene
			renderScene();

			//present the scene on the window
			//and switch buffer as well
			present();
		}
	}

	return msg.wParam;
}

void Rasterizer::buildCanvas(const Color& backgroundColor)
{
	canvas = new Canvas(CANVAS_WIDTH, CANVAS_HEIGHT, backgroundColor);
}

void Rasterizer::buildCamera()
{
	camera = new Camera();
}

void Rasterizer::buildScene()
{
	scene = new TextureScene();
	scene->createScene();
}

void Rasterizer::updateCamera()
{
	auto eye = camera->eyePos();
	auto target = camera->targetPos();
	auto up = camera->upVector();
	Camera::rotateCamera(camera);

	Matrix4x4 view = Camera::lookAtLH(eye, target, up);
	Matrix4x4 project = Camera::perspectiveFovLH(45, width / height, 0.1f, 100.0f);
	scene->setViewProjectionMatrix(view * project);
} 

void Rasterizer::updateSceneElement()
{

}

void Rasterizer::clear()
{
	canvas->clear();
}

void Rasterizer::renderScene()
{
	Scene::drawScene(canvas, scene);
}

void Rasterizer::present()
{
	canvas->swapBuffer();
	RECT updateRegion = { 0, 0, CANVAS_WIDTH, CANVAS_HEIGHT };
	RedrawWindow(hWnd, &updateRegion, NULL, RDW_INVALIDATE);
}

LRESULT Rasterizer::wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WinGDI::WinBitmap*		presentImage;
	int						imageWidth, imageHeight;
	HBITMAP					hbitmap;
	HDC						hdc, hdcMem;
	PAINTSTRUCT				ps;

	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (canvas)
		{
			auto backBuffer = canvas->frameBuffer();
			presentImage = backBuffer->presentImage();
			imageWidth	 = canvas->width();
			imageHeight  = canvas->height();
			hbitmap = presentImage->hBitmap();

			if (hbitmap)
			{
				hdcMem = CreateCompatibleDC(hdc);
				SelectObject(hdcMem, hbitmap);
				BitBlt(hdc, 0, 0, 800, 600, hdcMem, 0, 100, SRCCOPY);
				DeleteDC(hdcMem);
			}
		}

		EndPaint(hwnd, &ps);
		return 0;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

