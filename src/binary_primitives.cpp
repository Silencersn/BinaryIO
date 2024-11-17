#include "binary_primitives.h"

// Little Endian Read
uint16_t BinaryPrimitives::ReadUInt16LittleEndian(const byte* source)
{
	return source[0] | source[1] << 8;
}
uint32_t BinaryPrimitives::ReadUInt32LittleEndian(const byte* source)
{
	return source[0] | source[1] << 8 | source[2] << 16 | source[3] << 24;
}
uint64_t BinaryPrimitives::ReadUInt64LittleEndian(const byte* source)
{
	return ReadUInt32LittleEndian(source) | static_cast<uint64_t>(ReadUInt32LittleEndian(source + 4)) << 32;
}
int16_t BinaryPrimitives::ReadInt16LittleEndian(const byte* source)
{
	return ReadUInt16LittleEndian(source);
}
int32_t BinaryPrimitives::ReadInt32LittleEndian(const byte* source)
{
	return ReadUInt32LittleEndian(source);
}
int64_t BinaryPrimitives::ReadInt64LittleEndian(const byte* source)
{
	return ReadUInt64LittleEndian(source);
}
float BinaryPrimitives::ReadSingleLittleEndian(const byte* source)
{
	uint32_t bits = ReadUInt32LittleEndian(source);
	return *reinterpret_cast<float*>(&bits);
}
double BinaryPrimitives::ReadDoubleLittleEndian(const byte* source)
{
	uint64_t bits = ReadUInt64LittleEndian(source);
	return *reinterpret_cast<double*>(&bits);
}

// Big Endian Read
uint16_t BinaryPrimitives::ReadUInt16BigEndian(const byte* source)
{
	return source[0] << 8 | source[1];
}
uint32_t BinaryPrimitives::ReadUInt32BigEndian(const byte* source)
{
	return source[0] << 24 | source[1] << 16 | source[2] << 8 | source[3];
}
uint64_t BinaryPrimitives::ReadUInt64BigEndian(const byte* source)
{
	return static_cast<uint64_t>(ReadUInt32BigEndian(source)) << 32 | ReadUInt32BigEndian(source + 4);
}
int16_t BinaryPrimitives::ReadInt16BigEndian(const byte* source)
{
	return ReadUInt16BigEndian(source);
}
int32_t BinaryPrimitives::ReadInt32BigEndian(const byte* source)
{
	return ReadUInt32BigEndian(source);
}
int64_t BinaryPrimitives::ReadInt64BigEndian(const byte* source)
{
	return ReadUInt64BigEndian(source);
}
float BinaryPrimitives::ReadSingleBigEndian(const byte* source)
{
	uint32_t bits = ReadUInt32BigEndian(source);
	return *reinterpret_cast<float*>(&bits);
}
double BinaryPrimitives::ReadDoubleBigEndian(const byte* source)
{
	uint64_t bits = ReadUInt64BigEndian(source);
	return *reinterpret_cast<double*>(&bits);
}

// Little Endian Write
void BinaryPrimitives::WriteUInt16LittleEndian(byte* destination, uint16_t value)
{
	destination[0] = (byte)value;
	destination[1] = (byte)(value >> 8);
}
void BinaryPrimitives::WriteUInt32LittleEndian(byte* destination, uint32_t value)
{
	destination[0] = (byte)value;
	destination[1] = (byte)(value >> 8);
	destination[2] = (byte)(value >> 16);
	destination[3] = (byte)(value >> 24);
}
void BinaryPrimitives::WriteUInt64LittleEndian(byte* destination, uint64_t value)
{
	WriteUInt32LittleEndian(destination, (uint32_t)value);
	WriteUInt32LittleEndian(destination + 4, (uint32_t)(value >> 32));
}
void BinaryPrimitives::WriteInt16LittleEndian(byte* destination, int16_t value)
{
	WriteUInt16LittleEndian(destination, value);
}
void BinaryPrimitives::WriteInt32LittleEndian(byte* destination, int32_t value)
{
	WriteUInt32LittleEndian(destination, value);
}
void BinaryPrimitives::WriteInt64LittleEndian(byte* destination, int64_t value)
{
	WriteUInt64LittleEndian(destination, value);
}
void BinaryPrimitives::WriteSingleLittleEndian(byte* destination, float value)
{
	WriteUInt32LittleEndian(destination, *reinterpret_cast<uint32_t*>(&value));
}
void BinaryPrimitives::WriteDoubleLittleEndian(byte* destination, double value)
{
	WriteUInt64LittleEndian(destination, *reinterpret_cast<uint64_t*>(&value));
}

// Big Endian Write
void BinaryPrimitives::WriteUInt16BigEndian(byte* destination, uint16_t value)
{
	destination[0] = (byte)(value >> 8);
	destination[1] = (byte)value;
}
void BinaryPrimitives::WriteUInt32BigEndian(byte* destination, uint32_t value)
{
	destination[0] = (byte)(value >> 24);
	destination[1] = (byte)(value >> 16);
	destination[2] = (byte)(value >> 8);
	destination[3] = (byte)value;
}
void BinaryPrimitives::WriteUInt64BigEndian(byte* destination, uint64_t value)
{
	WriteUInt32BigEndian(destination + 4, (uint32_t)value);
	WriteUInt32BigEndian(destination, (uint32_t)(value >> 32));
}
void BinaryPrimitives::WriteInt16BigEndian(byte* destination, int16_t value)
{
	WriteUInt16BigEndian(destination, value);
}
void BinaryPrimitives::WriteInt32BigEndian(byte* destination, int32_t value)
{
	WriteUInt32BigEndian(destination, value);
}
void BinaryPrimitives::WriteInt64BigEndian(byte* destination, int64_t value)
{
	WriteUInt64BigEndian(destination, value);
}
void BinaryPrimitives::WriteSingleBigEndian(byte* destination, float value)
{
	WriteUInt32BigEndian(destination, *reinterpret_cast<uint32_t*>(&value));
}
void BinaryPrimitives::WriteDoubleBigEndian(byte* destination, double value)
{
	WriteUInt64BigEndian(destination, *reinterpret_cast<uint64_t*>(&value));
}

// Reverse Endianness
uint16_t BinaryPrimitives::ReverseEndianness(uint16_t value)
{
	return (value >> 8) | (value << 8);
}
uint32_t BinaryPrimitives::ReverseEndianness(uint32_t value)
{
	value = (value >> 16) | (value << 16);
	return ((value & 0xFF00FF00) >> 8) | ((value & 0x00FF00FF) << 8);
}
uint64_t BinaryPrimitives::ReverseEndianness(uint64_t value)
{
	value = (value >> 32) | (value << 32);
	value = ((value & 0xFFFF0000FFFF0000) >> 16) | ((value & 0x0000FFFF0000FFFF) << 16);
	return ((value & 0xFF00FF00FF00FF00) >> 8) | ((value & 0x00FF00FF00FF00FF) << 8);
}
int16_t BinaryPrimitives::ReverseEndianness(int16_t value)
{
	return ReverseEndianness(static_cast<uint16_t>(value));
}
int32_t BinaryPrimitives::ReverseEndianness(int32_t value)
{
	return ReverseEndianness(static_cast<uint32_t>(value));
}
int64_t BinaryPrimitives::ReverseEndianness(int64_t value)
{
	return ReverseEndianness(static_cast<uint64_t>(value));
}