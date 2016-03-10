#ifndef ZJR_SIMULATOR_
#define ZJR_SIMULATOR_

#include <windows.h>
#include <string>
#include "Timer.h"

class Simulator
{
public:
	Simulator(HINSTANCE hinstance, std::wstring title = L"Simulator");
	Simulator(HINSTANCE hinstance, int width, int height, std::wstring title = L"Simulator");
	Simulator(const Simulator &wv) = delete;
	virtual ~Simulator();

	virtual bool			initialized();
	virtual int				run();
	virtual LRESULT			wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	HINSTANCE				instance() const;
	HWND					windowHandle() const;
	void					calculateRenderingTime();
	void					calculateFPS();

protected:
	bool					windowInitialized();

protected:

	HINSTANCE				hInstance;
	HWND					hWnd;
	std::wstring			title;
	UINT					width;
	UINT					height;
	Timer					timer;
};

inline HINSTANCE Simulator::instance() const
{
	return hInstance;
}

inline HWND Simulator::windowHandle() const
{
	return hWnd;
}

extern LRESULT CALLBACK MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif
