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

	namespace 
	{
		size_t s_tagWidth = 0;

		void printStyled(const std::string& _tag, const std::string& _log,
						 Style _tagBg, Style _tagFg, Style _logBg, Style _logFg)
		{
			std::string formattedTag = "[" + _tag + "]";
			size_t whitespaceLength = formattedTag.length();

			if (whitespaceLength > s_tagWidth) s_tagWidth = whitespaceLength;
			whitespaceLength = std::max(whitespaceLength, s_tagWidth);

			std::cout << Modifier(_tagBg) << Modifier(_tagFg) << formattedTag << Modifier(RESET);				// TAG
			std::cout << std::string(whitespaceLength, ' ');													// Padding
			std::cout << Modifier(_logBg) << Modifier(_logFg) << " - " << _log << Modifier(RESET) << std::endl;	// Log
		}
	}

	void print(const std::string& _tag, const std::string& _log)
	{
		printStyled(_tag, _log, BG_CYAN, FG_BLACK, BG_BLACK, FG_CYAN);
	}

	void printSuccess(const std::string& _tag, const std::string& _log)
	{
		printStyled(_tag, _log, BG_GREEN, FG_BLACK, BG_BLACK, FG_GREEN);
	}

	void printWarning(const std::string& _tag, const std::string& _log)
	{
		printStyled(_tag, _log, BG_YELLOW, FG_BLACK, BG_BLACK, FG_YELLOW);
	}

	void printError(const std::string& _tag, const std::string& _log)
	{
		printStyled(_tag, _log, BG_RED, FG_WHITE, BG_BLACK, FG_RED);
	}
}