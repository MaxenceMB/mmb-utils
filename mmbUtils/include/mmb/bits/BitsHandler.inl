#ifndef MMB_UTILS_BITS_BITS_HANDLER_INL
#define MMB_UTILS_BITS_BITS_HANDLER_INL

#include <iostream>
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
} // namespace mmb
#endif // Include guard MMB_UTILS_BITS_BITS_HANDLER_INL