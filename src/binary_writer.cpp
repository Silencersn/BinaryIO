#include "binary_writer.h"

BinaryWriter::BinaryWriter(std::ostream* output)
{
    _outStream = output;
}

BinaryWriter::~BinaryWriter()
{
    _outStream->flush();
}

void BinaryWriter::Flush()
{
    _outStream->flush();
}

void BinaryWriter::Seek(std::streamoff offset, std::ios_base::seekdir origin)
{
    _outStream->seekp(offset, origin);
}

void BinaryWriter::Write(byte value)
{
    _outStream->put(value);
}

void BinaryWriter::Write(bool value)
{
    Write((byte)(value ? 1 : 0));
}

void BinaryWriter::Write(sbyte value)
{
    Write((byte)value);
}

void BinaryWriter::Write(const byte* buffer, std::streamsize index, std::streamsize count)
{
    Write((const char*)buffer, index, count);
}

void BinaryWriter::Write(const char* buffer, std::streamsize index, std::streamsize count)
{
    _outStream->write(buffer + index, count);
}

void BinaryWriter::Write(const byte* buffer, std::streamsize count)
{
    Write(buffer, 0, count);
}

void BinaryWriter::Write(const char* buffer, std::streamsize count)
{
    Write(buffer, 0, count);
}

void BinaryWriter::Write(int16_t value)
{
    byte buffer[sizeof(int16_t)];
    BinaryPrimitives::WriteInt16LittleEndian(buffer, value);
    Write(buffer, sizeof(int16_t));
}

void BinaryWriter::Write(uint16_t value)
{
    byte buffer[sizeof(uint16_t)];
    BinaryPrimitives::WriteUInt16LittleEndian(buffer, value);
    Write(buffer, sizeof(uint16_t));
}

void BinaryWriter::Write(int32_t value)
{
    byte buffer[sizeof(int32_t)];
    BinaryPrimitives::WriteInt32LittleEndian(buffer, value);
    Write(buffer, sizeof(int32_t));

}

void BinaryWriter::Write(uint32_t value)
{
    byte buffer[sizeof(uint32_t)];
    BinaryPrimitives::WriteUInt32LittleEndian(buffer, value);
    Write(buffer, sizeof(uint32_t));
}

void BinaryWriter::Write(int64_t value)
{
    byte buffer[sizeof(int64_t)];
    BinaryPrimitives::WriteInt64LittleEndian(buffer, value);
    Write(buffer, sizeof(int64_t));
}

void BinaryWriter::Write(uint64_t value)
{
    byte buffer[sizeof(uint64_t)];
    BinaryPrimitives::WriteUInt64LittleEndian(buffer, value);
    Write(buffer, sizeof(uint64_t));
}

void BinaryWriter::Write(float value)
{
    byte buffer[sizeof(float)];
    BinaryPrimitives::WriteSingleLittleEndian(buffer, value);
    Write(buffer, sizeof(float));
}

void BinaryWriter::Write(double value)
{
    byte buffer[sizeof(double)];
    BinaryPrimitives::WriteDoubleLittleEndian(buffer, value);
    Write(buffer, sizeof(double));
}

void BinaryWriter::Write(std::string value)
{
    size_t byteCount = value.length();
    Write7BitEncodedInt((int32_t)byteCount);
    Write((byte*)value.c_str(), byteCount);
}

void BinaryWriter::Write(const char* value)
{
    Write((std::string)value);
}

void BinaryWriter::Write7BitEncodedInt(int32_t value)
{
    uint32_t uValue = (uint32_t)value;

    while (uValue > 0x7Fu)
    {
        Write((byte)(uValue | ~0x7Fu));
        uValue >>= 7;
    }

    Write((byte)uValue);
}

void BinaryWriter::Write7BitEncodedInt64(int64_t value)
{
    uint64_t uValue = (uint64_t)value;

    while (uValue > 0x7Fu)
    {
        Write((byte)(uValue | ~0x7Fu));
        uValue >>= 7;
    }

    Write((byte)uValue);
}


void BinaryWriter::Write(half value)
{
    Write(value._value);
}

void BinaryWriter::Write(decimal value)
{
    Write(value._flags);
    Write(value._hi32);
    Write(value._lo64);
}


