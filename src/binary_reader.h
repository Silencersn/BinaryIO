#pragma once

#include "binary_primitives.h"
#include <istream>

class BinaryReader
{
public:
	BinaryReader(std::istream* input);
	~BinaryReader();

	bool ReadBoolean();
	byte ReadByte();
	sbyte ReadSByte();
	std::streamsize Read(byte* buffer, std::streamsize index, std::streamsize count);
	std::streamsize Read(char* buffer, std::streamsize index, std::streamsize count);
	std::streamsize Read(byte* buffer, std::streamsize count);
	std::streamsize Read(char* buffer, std::streamsize count);
	byte* ReadBytes(std::streamsize count);
	int16_t ReadInt16();
	uint16_t ReadUInt16();
	int32_t ReadInt32();
	uint32_t ReadUInt32();
	int64_t ReadInt64();
	uint64_t ReadUInt64();
	float ReadSingle();
	double ReadDouble();
	std::string ReadString();
	int32_t Read7BitEncodedInt();
	int64_t Read7BitEncodedInt64();

	half ReadHalf();
	decimal ReadDecimal();

	template <typename T>
	T ReadUnaligned();

	byte PeekByte();

private:
	BinaryReader();

	std::istream* _stream;
	byte* _buffer;
};


template<typename T>
T BinaryReader::ReadUnaligned()
{
	byte buffer[sizeof(T)]{};
	Read(buffer, sizeof(T));
	return *reinterpret_cast<T*>(buffer);
}