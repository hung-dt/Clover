#pragma once

#ifdef CLV_PLATFORM_WIN

#ifdef CLV_BUILD_DLL
#define CLV_API _declspec(dllexport)
#else
#define CLV_API _declspec(dllimport)
#endif

#else

#define CLV_API

#endif

#define BIT(x) (1 << x)
