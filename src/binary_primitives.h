#pragma once
#include <cstdint>
#include "cs_types.h"

class BinaryPrimitives
{
public:
	// Little Endian Read
	static uint16_t ReadUInt16LittleEndian(const byte* source);
	static uint32_t ReadUInt32LittleEndian(const byte* source);
	static uint64_t ReadUInt64LittleEndian(const byte* source);
	static int16_t ReadInt16LittleEndian(const byte* source);
	static int32_t ReadInt32LittleEndian(const byte* source);
	static int64_t ReadInt64LittleEndian(const byte* source);
	static float ReadSingleLittleEndian(const byte* source);
	static double ReadDoubleLittleEndian(const byte* source);

	// Big Endian Read
	static uint16_t ReadUInt16BigEndian(const byte* source);
	static uint32_t ReadUInt32BigEndian(const byte* source);
	static uint64_t ReadUInt64BigEndian(const byte* source);
	static int16_t ReadInt16BigEndian(const byte* source);
	static int32_t ReadInt32BigEndian(const byte* source);
	static int64_t ReadInt64BigEndian(const byte* source);
	static float ReadSingleBigEndian(const byte* source);
	static double ReadDoubleBigEndian(const byte* source);

	// Little Endian Write
	static void WriteUInt16LittleEndian(byte* destination, uint16_t value);
	static void WriteUInt32LittleEndian(byte* destination, uint32_t value);
	static void WriteUInt64LittleEndian(byte* destination, uint64_t value);
	static void WriteInt16LittleEndian(byte* destination, int16_t value);
	static void WriteInt32LittleEndian(byte* destination, int32_t value);
	static void WriteInt64LittleEndian(byte* destination, int64_t value);
	static void WriteSingleLittleEndian(byte* destination, float value);
	static void WriteDoubleLittleEndian(byte* destination, double value);

	// Big Endian Write
	static void WriteUInt16BigEndian(byte* destination, uint16_t value);
	static void WriteUInt32BigEndian(byte* destination, uint32_t value);
	static void WriteUInt64BigEndian(byte* destination, uint64_t value);
	static void WriteInt16BigEndian(byte* destination, int16_t value);
	static void WriteInt32BigEndian(byte* destination, int32_t value);
	static void WriteInt64BigEndian(byte* destination, int64_t value);
	static void WriteSingleBigEndian(byte* destination, float value);
	static void WriteDoubleBigEndian(byte* destination, double value);

	// Reverse Endianness
	static uint16_t ReverseEndianness(uint16_t value);
	static uint32_t ReverseEndianness(uint32_t value);
	static uint64_t ReverseEndianness(uint64_t value);
	static int16_t ReverseEndianness(int16_t value);
	static int32_t ReverseEndianness(int32_t value);
	static int64_t ReverseEndianness(int64_t value);

private:
	BinaryPrimitives();
};

