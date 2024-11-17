#pragma once

struct CSharpHalf
{
	uint16_t _value;
};

struct CSharpDecimal
{
	int32_t _flags;
	uint32_t _hi32;
	uint64_t _lo64;
};

struct CSharpChar
{
	uint16_t _value;
};

typedef uint8_t			byte;
typedef int8_t			sbyte;
typedef CSharpHalf		half;
typedef CSharpDecimal	decimal;
typedef CSharpChar		utf16_char;