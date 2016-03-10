#ifndef ZJR_UTILITIES_
#define ZJR_UTILITIES_

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CANVAS_WIDTH 800
#define CANVAS_HEIGHT 800

#define MSAA_ON true
#if MSAA_ON true
#define CANVAS_WIDTH 1600
#define CANVAS_HEIGHT 1600
#endif

#define MIPLEVEL 0

namespace Memory
{
	template<typename T>
	void safeDelete(T t)
	{
		if (t != nullptr)
		{
			delete t;
		}
		t = nullptr;
	}

	template<typename T>
	void safeDeleteArray(T t)
	{
		if (t != nullptr)
		{
			delete[] t;
		}
		t = nullptr;
	}

	template<typename T>
	void safeRelease(T t)
	{
		if (t != nullptr)
		{
			t->Release();
		}
		t = nullptr;
	}
}

#endif
