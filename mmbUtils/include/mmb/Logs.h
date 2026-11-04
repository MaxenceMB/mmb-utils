#ifndef MMB_UTILS_LOGS__H
#define MMB_UTILS_LOGS__H

#include <iostream>
#include <string>
#include <algorithm>

#define MMB_LOGS_TAB_LENGTH 15

/// <summary>
/// A whole helper to write logs easier and make everything look cleaner
/// </summary>
namespace mmb
{
	/// <summary>
	/// Style ANSI code for console logs.
	/// </summary>
	enum Style
	{
		// Main
		RESET = 0,
		BOLD = 1,
		FAINT = 2,
		ITALIC = 3,
		UNDERLINE = 4,
		INVERT = 7,
		STRIKE = 9,

		// Colours
		FG_BLACK = 30,
		FG_RED = 31,
		FG_GREEN = 32,
		FG_YELLOW = 33,
		FG_BLUE = 34,
		FG_MAGENTA = 35,
		FG_CYAN = 36,
		FG_WHITE = 37,
		FG_DEFAULT = 39,

		BG_BLACK = 40,
		BG_RED = 41,
		BG_GREEN = 42,
		BG_YELLOW = 43,
		BG_BLUE = 44,
		BG_MAGENTA = 45,
		BG_CYAN = 46,
		BG_WHITE = 47,
		BG_DEFAULT = 49,
	};

	/// <summary>
	/// Modifier are here to change how the logs look in the console.
	/// <para>A Modifier has to be inserted before the text in a std::cout line.</para>
	/// </summary>
	class Modifier
	{
	public:
		/// <summary>
		/// Default Constructor deleted. A Modifier without any style code is nonsense. 
		/// </summary>
		Modifier() = delete;

		/// <summary>
		/// Main Modifier Constructor.
		/// </summary>
		/// <param name="_style">The ANSI style code.</param>
		Modifier(Style _style);

		/// <summary>
		/// Main Modifier Constructor.
		/// </summary>
		/// <param name="_code">The ANSI style code.</param>
		Modifier(int _code);

		/// <summary>
		/// Modifier Copy Constructor.
		/// </summary>
		/// <param name="_mod">The other Modifier</param>
		Modifier(const Modifier& _mod);

		friend std::ostream& operator<<(std::ostream& _os, const Modifier& _mod);

	private:
		int m_code;
	};

	/// <summary>
	/// Prints a formatted log into the console.
	/// </summary>
	/// <param name="_tag">The log's tag.</param>
	/// <param name="_log">The actual text to log.</param>
	void print(const std::string& _tag, const std::string& _log);

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
	/// Computes the required whitespace length to align all the tags properly.
	/// <para>This is used by the print() functions.</para>
	/// </summary>
	/// <param name="_tag">The log's tag.</param>
	/// <returns>The whitespace length (in characters).</returns>
	size_t getWhitespaceLength(const std::string& _tag);
}

#endif