#ifndef MMB_UTILS_LOGS_PRINTER_H
#define MMB_UTILS_LOGS_PRINTER_H

#include <string>

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
}

#endif