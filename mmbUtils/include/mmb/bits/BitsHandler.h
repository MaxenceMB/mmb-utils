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
	size_t bitRange(uint64_t _minInclusive, uint64_t _maxExclusive);

	/// <summary>
	/// Returns the minimum number of bits required to write every number
	/// inside a specified range.
	/// <para>This version allows negative bounds.</para>
	/// </summary>
	/// <param name="_min">The lowest value of the range. (Inclusive)</param>
	/// <param name="_max">The largest value of the range. (Exclusive)</param>
	/// <returns>The number of bits required.</returns>
	size_t bitRange(int64_t _minInclusive, int64_t _maxExclusive);

	/// <summary>
	/// Displays anytype as their individual bits.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value displayed in binary.</param>
	/// <param name="_newLine">True if there should be a new line after the print, False if not.</param>
	template<typename T>
	void printBits(T _value, bool _newLine = true);

	/// <summary>
	/// Swaps individual bytes from first to last.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value to swap.</param>
	/// <returns>The same value, but in a swapped byte order.</returns>
	template<typename T>
	T byteSwap(const T& _value);

	/// <summary>
	/// Swaps individual bytes to have the least significant byte at the lowest memory address.
	/// <para>Note that if your architecture is already in LSB this won't do anything.</para>
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value to swap.</param>
	/// <returns>The same value, but with the LSB first.</returns>
	template<typename T>
	T toLittleEndian(const T& _value);

	/// <summary>
	/// Swaps individual bytes to have the most significant byte at the lowest memory address.
	/// <para>Note that if your architecture is already in MSB this won't do anything.</para>
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value to swap.</param>
	/// <returns>The same value, but with the MSB first.</returns>
	template<typename T>
	T toBigEndian(const T& _value);

	/// <summary>
	/// Swaps individual bytes to match the Network byte order (MSB).
	/// <para>Note that if your architecture is already in MSB this won't do anything.</para>
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value to swap.</param>
	/// <returns>The same value, but with the MSB first.</returns>
	template<typename T>
	T hostToNet(const T& _value);

	/// <summary>
	/// Swaps individual bytes to match your machine's internal byte order.
	/// <para>Note that if your architecture is already in MSB first this won't do anything as
	/// the Network byte order is also MSB first.</para>
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value to swap.</param>
	/// <returns>The same value, but with the MSB first.</returns>
	template<typename T>
	T netToHost(const T& _value);

} // namespace mmb

#include "mmb/bits/BitsHandler.inl"
#endif // Include guard MMB_UTILS_BITS_BITS_HANDLER_H