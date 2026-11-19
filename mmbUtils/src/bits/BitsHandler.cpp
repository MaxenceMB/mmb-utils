#include <mmb/bits/BitsHandler.h>

namespace mmb
{
	uint64_t bitMask(size_t _nbBits)
	{
		if (_nbBits >= sizeof(uint64_t) * 8) return UINT64_MAX;
		if (_nbBits <= 0) return static_cast<uint64_t>(0);

		return (static_cast<uint64_t>(1) << _nbBits) - 1;
	}

	size_t bitWidth(uint64_t _value)
	{
		size_t width = 0;
		while (_value > 0)
		{
			width++;
			_value >>= 1;
		}
		return width;
	}

	size_t bitRange(uint64_t _min, uint64_t _max)
	{
		if (_min > _max) return static_cast<size_t>(0);

		return bitWidth(_max - _min);
	}

	size_t bitRange(int64_t _min, int64_t _max)
	{
		if (_min > _max) return static_cast<size_t>(0);
		if (_max + std::abs(_min) < _min) return static_cast<size_t>(0);

		return bitWidth(static_cast<uint64_t>(std::abs(_max - _min) + 1));
	}
}