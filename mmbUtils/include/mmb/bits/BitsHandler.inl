#ifndef MMB_UTILS_BITS_BITS_HANDLER_INL
#define MMB_UTILS_BITS_BITS_HANDLER_INL

#include <iostream>
#include <bit>
#include <bitset>

namespace mmb
{
	template<typename T>
	T byteSwap(const T& _value)
	{
		if (sizeof(T) <= 1) return _value;

		T swapped = _value;
		uint64_t lByteMask, rByteMask, swapMask, lByteValue, rByteValue;
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
	T toLittleEndian(const T& _value)
	{
		if (std::endian::native == std::endian::big)
		{
			return byteSwap<T>(_value);
		}
		return _value;
	}

	template<typename T>
	T toBigEndian(const T& _value)
	{
		if (std::endian::native == std::endian::little)
		{
			return byteSwap<T>(_value);
		}
		return _value;
	}

	template<typename T>
	T hostToNet(const T& _value)
	{
		if (std::endian::native == std::endian::little)
		{
			return byteSwap<T>(_value);
		}
		return _value;
	}

	template<typename T>
	T netToHost(const T& _value)
	{
		if (std::endian::native == std::endian::little)
		{
			return byteSwap<T>(_value);
		}
		return _value;
	}

} // namespace mmb

#endif // Include guard MMB_UTILS_BITS_BITS_HANDLER_INL