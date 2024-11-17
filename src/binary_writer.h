#pragma once

#include "binary_primitives.h"
#include <ostream>

class BinaryWriter
{
public:
	BinaryWriter(std::ostream* output);
	~BinaryWriter();

	void Flush();
	void Seek(std::streamoff offset, std::ios_base::seekdir origin);

	void Write(byte value);
	void Write(bool value);
	void Write(sbyte value);
	void Write(const byte* buffer, std::streamsize index, std::streamsize count);
	void Write(const char* buffer, std::streamsize index, std::streamsize count);
	void Write(const byte* buffer, std::streamsize count);
	void Write(const char* buffer, std::streamsize count);
	void Write(int16_t value);
	void Write(uint16_t value);
	void Write(int32_t value);
	void Write(uint32_t value);
	void Write(int64_t value);
	void Write(uint64_t value);
	void Write(float value);
	void Write(double value);
	void Write(std::string value);
	void Write(const char* value);
	void Write7BitEncodedInt(int32_t value);
	void Write7BitEncodedInt64(int64_t value);

	void Write(half value);
	void Write(decimal value);

	template <typename T>
	void WriteUnaligned(T value);

private:	
	BinaryWriter();

	std::ostream* _outStream;
};


template<typename T>
inline void BinaryWriter::WriteUnaligned(T value)
{
	Write(reinterpret_cast<const char*>(&value), sizeof(T));
}
