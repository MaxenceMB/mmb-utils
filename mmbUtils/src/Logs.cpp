#include "mmb/Logs.h"

namespace mmb
{
	Modifier::Modifier(Style _style)
	{
		this->m_code = (int)_style;
	}

	Modifier::Modifier(int _code)
	{
		this->m_code = _code;
	}

	Modifier::Modifier(const Modifier& _mod)
	{
		this->m_code = _mod.m_code;
	}

	std::ostream& operator<<(std::ostream& _os, const Modifier& _mod)
	{
		_os << "\033[" << _mod.m_code << "m";
		return _os;
	}

	void print(const std::string& _tag, const std::string& _log)
	{
		std::string formattedTag = "[" + _tag + "]";
		size_t whitespaceLength = getWhitespaceLength(formattedTag);

		std::cout << Modifier(BG_CYAN) << Modifier(FG_BLACK) << formattedTag << Modifier(RESET);	// TAG
		std::cout << std::string(whitespaceLength, ' ');											// Padding
		std::cout << Modifier(FG_CYAN) << " - " << _log << Modifier(RESET) << std::endl;			// Log
	}

	void printWarning(const std::string& _tag, const std::string& _log)
	{
		std::string formattedTag = "[" + _tag + "]";
		size_t whitespaceLength = getWhitespaceLength(formattedTag);

		std::cout << Modifier(BG_YELLOW) << Modifier(FG_BLACK) << formattedTag << Modifier(RESET);	// TAG
		std::cout << std::string(whitespaceLength, ' ');											// Padding
		std::cout << Modifier(FG_YELLOW) << " - " << _log << Modifier(RESET) << std::endl;			// Log
	}

	void printError(const std::string& _tag, const std::string& _log)
	{
		std::string formattedTag = "[" + _tag + "]";
		size_t whitespaceLength = getWhitespaceLength(formattedTag);

		std::cout << Modifier(BG_RED) << Modifier(FG_WHITE) << formattedTag << Modifier(RESET);		// TAG
		std::cout << std::string(whitespaceLength, ' ');											// Padding
		std::cout << Modifier(FG_RED) << " - " << _log << Modifier(RESET) << std::endl;				// Log
	}

	size_t getWhitespaceLength(const std::string& _tag)
	{
		size_t len = _tag.length();
		size_t whitespaceLength = len < MMB_LOGS_TAB_LENGTH ? MMB_LOGS_TAB_LENGTH - len : 0;

		return whitespaceLength;
	}
}