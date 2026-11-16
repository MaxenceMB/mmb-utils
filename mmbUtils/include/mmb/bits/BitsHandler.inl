#ifndef MMB_UTILS_BITS_BITS_HANDLER_INL
#define MMB_UTILS_BITS_BITS_HANDLER_INL

#include <iostream>
#include <bit>
#include <bitset>

namespace mmb
{
	template<typename T>
	void printBits(T _value, bool _newLine)
	{
		unsigned char bytes[sizeof(T)];
		std::memcpy(bytes, &_value, sizeof(T));

		for (int i = sizeof(T) - 1; i >= 0; i--)
		{
			std::cout << std::bitset<8>(bytes[i]) << ' ';
		}
		if (_newLine) std::cout << std::endl;
	}

	template<typename T>
	T byteSwap(T _value)
	{
		T swapped = _value;
		uint64_t lByteMask, rByteMask, swapMask;
		uint8_t lByteValue, rByteValue;

		for (size_t i = 0; i < sizeof(T) / 2; i++)
		{
			lByteMask = bitMask(8) << ((sizeof(T) - 1 - i) * 8);
			rByteMask = bitMask(8) << (i * 8);
			swapMask = bitMask(sizeof(T) * 8) & (lByteMask | rByteMask);

			lByteValue = (_value & lByteMask) >> ((sizeof(T) - 1 - i) * 8);
			rByteValue = (_value & rByteMask) >> (i * 8);

			swapped &= ~swapMask;
			swapped |= ((rByteValue << ((sizeof(T) - 1 - i) * 8)) | (lByteValue << (i * 8)));
		}

		return swapped;
	}

	template<typename T>
	T toLittleEndian(T _value)
	{
		if (std::endian::native == std::endian::big)
		{
			return bitSwap<T>(_value);
		}
		return _value;
	}

	template<typename T>
	T toBigEndian(T _value)
	{
		if (std::endian::native == std::endian::little)
		{
			return bitSwap<T>(_value);
		}
		return _value;
	}

} // namespace mmb
#endif // Include guard MMB_UTILS_BITS_BITS_HANDLER_INL