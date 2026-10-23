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

#ifdef CLV_ENABLE_ASSERTS

#define CLV_ASSERT(x, ...)                                       \
  {                                                              \
    if ( !x ) {                                                  \
      CLV_CLIENT_LOG_ERROR("Assertion failed: {}", __VA_ARGS__); \
      __debugbreak();                                            \
    }                                                            \
  }

#define CLV_CORE_ASSERT(x, ...)                                \
  {                                                            \
    if ( !x ) {                                                \
      CLV_CORE_LOG_ERROR("Assertion failed: {}", __VA_ARGS__); \
      __debugbreak();                                          \
    }                                                          \
  }

#else

#define CLV_ASSERT(x, ...)

#define CLV_CORE_ASSERT(x, ...)

#endif

#define BIT(x) (1 << x)
