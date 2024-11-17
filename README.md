# BinaryIO
Provides streaming operations similar and interoperate to C# in binary.

Including classes: `BinaryWriter`, `BinaryReader` and `BinaryPrimitives`.

## Types
### byte
```c++
typedef uint8_t byte;
```

### sbyte
```c++
typedef int8_t sbyte;
```

### half
```c++
struct CSharpHalf
{
	uint16_t _value;
};
typedef CSharpHalf half;
```

### decimal
```c++
struct CSharpDecimal
{
	int32_t _flags;
	uint32_t _hi32;
	uint64_t _lo64;
};
typedef CSharpDecimal decimal;
```

## BinaryWriter
|BinaryIO|C#|Notes|
|-|-|-|
|Wirte(sbyte)|Wirte(sbyte)||
|Wirte(byte)|Wirte(byte)||
|Wirte(int16_t)|Wirte(short)||
|Wirte(uint16_t)|Wirte(ushort)||
|Wirte(int32_t)|Wirte(int)||
|Wirte(uint32_t)|Wirte(uint)||
|Wirte(int64_t)|Wirte(long)||
|Wirte(uint64_t)|Wirte(ulong)||
|Wirte(bool)|Wirte(bool)||
|Write(const byte*, std::streamsize, std::streamsize)|Write(byte[], int, int)||
|Write(const char*, std::streamsize, std::streamsize)|Write(byte[], int, int)||
|Write(const byte*, std::streamsize)|Write(byte[], int, int)|index is 0|
|Write(const char*, std::streamsize)|Write(byte[], int, int)|index is 0|
|Write(const char*)|Write(string)|ignores encoding|
|Write(std::string)|Write(string)|ignores encoding|
|Write7BitEncodedInt(int32_t)|Write7BitEncodedInt(int)||
|Write7BitEncodedInt64(int64_t)|Write7BitEncodedInt64(long)||
|Wirte(half)|Wirte(Half)|marshaled as Half in C#|
|Wirte(decimal)|Wirte(decimal)|marshaled as decimal in C#|
|WriteUnaligned<T>(T)||same as Unsafe.WriteUnaligned<T>(T)|
|Flush()|Flush()||
|Seek(std::streamoff, std::ios_base::seekdir)|Seek(int, SeekOrigin)||

## BinaryPrimitives
|BinaryIO|C#|Notes|
|-|-|-|
|ReadSByte()|ReadSByte()||
|ReadByte()|ReadByte()||
|ReadInt16()|ReadInt16()||
|ReadUInt16()|ReadUInt16()||
|ReadInt32()|ReadInt32()||
|ReadUInt32()|ReadUInt32()||
|ReadInt64()|ReadInt64()||
|ReadUInt64()|ReadUInt64()||
|ReadBoolean()|ReadBoolean()||
|Read(byte*, std::streamsize, std::streamsize)|Read(byte[], int, int)||
|Read(char*, std::streamsize, std::streamsize)|Read(byte[], int, int)||
|Read(byte*, std::streamsize)|Read(byte[], int, int)|index is 0|
|Read(char*, std::streamsize)|Read(byte[], int, int)|index is 0|
|ReadString()|ReadString()|ignore encoding|
|Read7BitEncodedInt()|Read7BitEncodedInt()||
|Read7BitEncodedInt64()|Read7BitEncodedInt64()||
|ReadHalf()|ReadHalf()|marshaled as Half in C#|
|ReadDecimal()|ReadDecimal()|marshaled as decimal in C#|
|ReadUnaligned<T>()||same as Unsafe.ReadUnaligned<T>()|

# BinaryPrimitives
|BinaryIO|C#|Notes|
|-|-|-|
|ReadUInt16LittleEndian(const byte*)|ReadUInt16LittleEndian(ReadOnlySpan<byte>)||
|ReadUInt32LittleEndian(const byte*)|ReadUInt32LittleEndian(ReadOnlySpan<byte>)||
|ReadUInt64LittleEndian(const byte*)|ReadUInt64LittleEndian(ReadOnlySpan<byte>)||
|ReadInt16LittleEndian(const byte*)|ReadInt16LittleEndian(ReadOnlySpan<byte>)||
|ReadInt32LittleEndian(const byte*)|ReadInt32LittleEndian(ReadOnlySpan<byte>)||
|ReadInt64LittleEndian(const byte*)|ReadInt64LittleEndian(ReadOnlySpan<byte>)||
|ReadSingleLittleEndian(const byte*)|ReadSingleLittleEndian(ReadOnlySpan<byte>)||
|ReadDoubleLittleEndian(const byte*)|ReadDoubleLittleEndian(ReadOnlySpan<byte>)||
|ReadUInt16BigEndian(const byte*)|ReadUInt16BigEndian(ReadOnlySpan<byte>)||
|ReadUInt32BigEndian(const byte*)|ReadUInt32BigEndian(ReadOnlySpan<byte>)||
|ReadUInt64BigEndian(const byte*)|ReadUInt64BigEndian(ReadOnlySpan<byte>)||
|ReadInt16BigEndian(const byte*)|ReadInt16BigEndian(ReadOnlySpan<byte>)||
|ReadInt32BigEndian(const byte*)|ReadInt32BigEndian(ReadOnlySpan<byte>)||
|ReadInt64BigEndian(const byte*)|ReadInt64BigEndian(ReadOnlySpan<byte>)||
|ReadSingleBigEndian(const byte*)|ReadSingleBigEndian(ReadOnlySpan<byte>)|
|ReadDoubleBigEndian(const byte*)|ReadDoubleBigEndian(ReadOnlySpan<byte>)||
|WriteUInt16LittleEndian(byte*, uint16_t)|WriteUInt16LittleEndian(Span<byte>, ushort)||
|WriteUInt32LittleEndian(byte*, uint32_t)|WriteUInt32LittleEndian(Span<byte>, uint)||
|WriteUInt64LittleEndian(byte*, uint64_t)|WriteUInt64LittleEndian(Span<byte>, ulong)||
|WriteInt16LittleEndian(byte*, int16_t)|WriteInt16LittleEndian(Span<byte>, short)||
|WriteInt32LittleEndian(byte*, int32_t)|WriteInt32LittleEndian(Span<byte>, int)||
|WriteInt64LittleEndian(byte*, int64_t)|WriteInt64LittleEndian(Span<byte>, long)||
|WriteSingleLittleEndian(byte*, float)|WriteSingleLittleEndian(Span<byte>, float)||
|WriteDoubleLittleEndian(byte*, double)|WriteDoubleLittleEndian(Span<byte>, double)||
|WriteUInt16BigEndian(byte*, uint16_t)|WriteUInt16BigEndian(Span<byte>, ushort)||
|WriteUInt32BigEndian(byte*, uint32_t)|WriteUInt32BigEndian(Span<byte>, uint)||
|WriteUInt64BigEndian(byte*, uint64_t)|WriteUInt64BigEndian(Span<byte>, ulong)||
|WriteInt16BigEndian(byte*, int16_t)|WriteInt16BigEndian(Span<byte>, short)||
|WriteInt32BigEndian(byte*, int32_t)|WriteInt32BigEndian(Span<byte>, int)||
|WriteInt64BigEndian(byte*, int64_t)|WriteInt64BigEndian(Span<byte>, long)||
|WriteSingleBigEndian(byte*, float)|WriteSingleBigEndian(Span<byte>, float)||
|WriteDoubleBigEndian(byte*, double)|WriteDoubleBigEndian(Span<byte>, double)||
|ReverseEndianness(uint16_t)|ReverseEndianness(ushort)||
|ReverseEndianness(uint32_t)|ReverseEndianness(uint)||
|ReverseEndianness(uint64_t)|ReverseEndianness(ulong)||
|ReverseEndianness(int16_t)|ReverseEndianness(short)||
|ReverseEndianness(int32_t)|ReverseEndianness(int)||
|ReverseEndianness(int64_t)|ReverseEndianness(long)||
