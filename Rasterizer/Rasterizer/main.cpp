#include "stdafx.h"

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
{
#if defined(DEBUG) || defined(_DEBUG)
	FILE *f(nullptr);
	if (AllocConsole())
	{
		freopen_s(&f, "CONOUT$", "w", stdout);
	}
#endif	

	Rasterizer r(hInstance);

	if(!r.initialized())
	{
		return 1;
	}

	return r.run();
}