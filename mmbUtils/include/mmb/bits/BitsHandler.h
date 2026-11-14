#ifndef MMB_UTILS_BITS_BITS_HANDLER_H
#define MMB_UTILS_BITS_BITS_HANDLER_H

#include <cstdint>

namespace mmb
{
	/// <summary>
	/// Returns a 64bit mask covering the first N bits.
	/// </summary>
	/// <param name="_nbBits">The number of bits to cover.</param>
	/// <returns>The 64bit mask.</returns>
	uint64_t bitMask(size_t _nbBits);

	/// <summary>
	/// Returns the minimum number of bits required to write a given value.
	/// </summary>
	/// <param name="_value">The value.</param>
	/// <returns>The number of bits required.</returns>
	size_t bitWidth(uint64_t _value);

	/// <summary>
	/// Returns the minimum number of bits required to write every number
	/// inside a specified range.
	/// </summary>
	/// <param name="_min">The lowest value of the range. (Inclusive)</param>
	/// <param name="_max">The largest value of the range. (Exclusive)</param>
	/// <returns>The number of bits required.</returns>
	size_t bitRange(uint64_t _min, uint64_t _max);

	/// <summary>
	/// Displays anytype as their individual bits.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value displayed in binary.</param>
	/// <param name="_newLine">True if there should be a new line after the print, False if not.</param>
	/// <param name="_blockSize">The number of bits to show side by side before spacing.</param>
	template<typename T>
	void printBits(T _value, bool _newLine = true, size_t _blockSize = 8);
} // namespace mmb

#endif // Include guard MMB_UTILS_BITS_BITS_HANDLER_H