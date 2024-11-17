#include "binary_reader.h"
#include <iostream>

BinaryReader::BinaryReader(std::istream* input)
{
	_stream = input;
	_buffer = new byte[32];
}

BinaryReader::~BinaryReader()
{
	delete[] _buffer;
}

bool BinaryReader::ReadBoolean()
{
	return ReadByte() != 0;
}

byte BinaryReader::ReadByte()
{
	int value = _stream->get();
	if (_stream->gcount() == 0)
	{
		throw std::runtime_error("Unable to read beyond the end of the stream.");
	}
	return value;
}

sbyte BinaryReader::ReadSByte()
{
	return ReadByte();
}

std::streamsize BinaryReader::Read(byte* buffer, std::streamsize index, std::streamsize count)
{
	return Read((char*)buffer, index, count);
}

std::streamsize BinaryReader::Read(char* buffer, std::streamsize index, std::streamsize count)
{
	_stream->read(buffer + index, count);
	return _stream->gcount();
}

std::streamsize BinaryReader::Read(byte* buffer, std::streamsize count)
{
	return Read(buffer, 0, count);
}

std::streamsize BinaryReader::Read(char* buffer, std::streamsize count)
{
	return Read(buffer, 0, count);
}

byte* BinaryReader::ReadBytes(std::streamsize count)
{
	byte* buffer = new byte[count];
	Read(buffer, count);
	return buffer;
}

int16_t BinaryReader::ReadInt16()
{
	byte buffer[sizeof(int16_t)];
	Read(buffer, sizeof(int16_t));
	return BinaryPrimitives::ReadInt16LittleEndian(buffer);
}

uint16_t BinaryReader::ReadUInt16()
{
	byte buffer[sizeof(uint16_t)];
	Read(buffer, sizeof(uint16_t));
	return BinaryPrimitives::ReadUInt16LittleEndian(buffer);
}

int32_t BinaryReader::ReadInt32()
{
	byte buffer[sizeof(int32_t)];
	Read(buffer, sizeof(int32_t));
	return BinaryPrimitives::ReadInt32LittleEndian(buffer);
}

uint32_t BinaryReader::ReadUInt32()
{
	byte buffer[sizeof(int32_t)];
	Read(buffer, sizeof(int32_t));
	return BinaryPrimitives::ReadUInt32LittleEndian(buffer);
}

int64_t BinaryReader::ReadInt64()
{
	byte buffer[sizeof(int64_t)];
	Read(buffer, sizeof(int64_t));
	return BinaryPrimitives::ReadInt64LittleEndian(buffer);
}

uint64_t BinaryReader::ReadUInt64()
{
	byte buffer[sizeof(int64_t)];
	Read(buffer, sizeof(int64_t));
	return BinaryPrimitives::ReadUInt64LittleEndian(buffer);
}

float BinaryReader::ReadSingle()
{
	byte buffer[sizeof(float)];
	Read(buffer, sizeof(float));
	return BinaryPrimitives::ReadSingleLittleEndian(buffer);
}

double BinaryReader::ReadDouble()
{
	byte buffer[sizeof(double)];
	Read(buffer, sizeof(double));
	return BinaryPrimitives::ReadDoubleLittleEndian(buffer);
}

std::string BinaryReader::ReadString()
{
	int32_t stringLength = Read7BitEncodedInt();
	char* buffer = new char[stringLength + 1] {};
	Read(buffer, stringLength);
	std::string value(buffer);
	delete[] buffer;
	return value;
}

int32_t BinaryReader::Read7BitEncodedInt()
{
	uint32_t result = 0;
	byte byteReadJustNow;

	const int MaxBytesWithoutOverflow = 4;
	for (int shift = 0; shift < MaxBytesWithoutOverflow * 7; shift += 7)
	{
		byteReadJustNow = ReadByte();
		result |= (byteReadJustNow & 0x7Fu) << shift;

		if (byteReadJustNow <= 0x7Fu)
		{
			return (int32_t)result;
		}
	}

	byteReadJustNow = ReadByte();
	if (byteReadJustNow > 0b1111u)
	{
		throw std::runtime_error("Too many bytes in what should have been a 7-bit encoded integer.");
	}

	result |= (uint32_t)byteReadJustNow << (MaxBytesWithoutOverflow * 7);
	return (int32_t)result;
}

int64_t BinaryReader::Read7BitEncodedInt64()
{
	uint64_t result = 0;
	byte byteReadJustNow;

	const int MaxBytesWithoutOverflow = 9;
	for (int shift = 0; shift < MaxBytesWithoutOverflow * 7; shift += 7)
	{
		byteReadJustNow = ReadByte();
		result |= (static_cast<uint64_t>(byteReadJustNow & 0x7Ful)) << shift;

		if (byteReadJustNow <= 0x7Fu)
		{
			return (uint64_t)result;
		}
	}

	byteReadJustNow = ReadByte();
	if (byteReadJustNow > 0b1u)
	{
		throw std::runtime_error("Too many bytes in what should have been a 7-bit encoded integer.");
	}

	result |= (uint64_t)byteReadJustNow << (MaxBytesWithoutOverflow * 7);
	return (long)result;
}


half BinaryReader::ReadHalf()
{
	return half{ ReadUInt16() };
}

decimal BinaryReader::ReadDecimal()
{
	return decimal{ ReadInt32(), ReadUInt32(), ReadUInt64() };
}


byte BinaryReader::PeekByte()
{
	return _stream->peek();
}


