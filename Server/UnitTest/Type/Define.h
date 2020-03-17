#ifndef Define_h__
#define Define_h__

#ifdef WIN32
typedef char I8;
typedef unsigned char U8;
typedef short I16;
typedef unsigned short U16;
typedef long I32;
typedef unsigned long U32;
typedef __int64 I64;
typedef unsigned __int64 U64;

typedef float             F32;
typedef double            F64;
typedef long double      F128;
#elif __linux
#include <bits/types.h>

typedef __int8_t        I8;
typedef __int16_t       I16;
typedef __int32_t       I32;
typedef __int64_t       I64;

typedef __uint8_t       U8;
typedef __uint16_t      U16;
typedef __uint32_t      U32;
typedef __uint64_t      U64;

typedef float             F32;
typedef double            F64;
typedef long double      F128;
#endif

const F32 Gravity = -9.81f;

const F32 floatEps = 1E-6f;
#endif // Define_h__
