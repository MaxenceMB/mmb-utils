#ifndef MMB_UTILS_LOGS_PRINTER_H
#define MMB_UTILS_LOGS_PRINTER_H

#include <string>
#include <vector>

namespace mmb
{
	/// <summary>
	/// Prints a formatted log into the console.
	/// </summary>
	/// <param name="_tag">The log's tag.</param>
	/// <param name="_log">The actual text to log.</param>
	void print(const std::string& _tag, const std::string& _log);

	/// <summary>
	/// Prints a formatted log into the console.
	/// <para>Styles it as a Success, all green.</para>
	/// </summary>
	/// <param name="_tag">The log's tag.</param>
	/// <param name="_log">The actual text to log.</param>
	void printSuccess(const std::string& _tag, const std::string& _log);

	/// <summary>
	/// Prints a formatted log into the console.
	/// <para>Styles it as a Warning, all yellow.</para>
	/// </summary>
	/// <param name="_tag">The log's tag.</param>
	/// <param name="_log">The actual text to log.</param>
	void printWarning(const std::string& _tag, const std::string& _log);

	/// <summary>
	/// Prints a formatted log into the console.
	/// <para>Styles it as an Error, all red.</para>
	/// </summary>
	/// <param name="_tag">The log's tag.</param>
	/// <param name="_log">The actual text to log.</param>
	void printError(const std::string& _tag, const std::string& _log);

	/// <summary>
	/// Displays anytype as their individual bits.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_value">The value displayed in binary.</param>
	/// <param name="_newLine">True if there should be a new line after the print, False if not.</param>
	template<typename T>
	void printBits(T _value, bool _newLine = true);

	/// <summary>
	/// Prints a vector into the console.
	/// </summary>
	/// <typeparam name="T">Any type stored inside the vector.</typeparam>
	/// <param name="_v">The vector we want to print.</param>
	/// <param name="_endNewLine">True to print a new line after the vector.</param>
	/// <param name="_newLine">True to print a new line after each element.</param>
	template<typename T>
	void printVector(const std::vector<T>& _v, bool _endNewLine = false, bool _newLine = false);

	/// <summary>
	/// Prints elements inside a vector as their binary values into the console.
	/// </summary>
	/// <typeparam name="T">Any type stored inside the vector.</typeparam>
	/// <param name="_v">The vector we want to print.</param>
	/// <param name="_endNewLine">True to print a new line after the vector.</param>
	/// <param name="_newLine">True to print a new line after each element.</param>
	template<typename T>
	void printVectorAsBits(const std::vector<T>& _v, bool _endNewLine = false, bool _newLine = false);

} // namespace mmb

#include <mmb/logs/Printer.inl>

#endif // Include guard MMB_UTILS_LOGS_PRINTER_H