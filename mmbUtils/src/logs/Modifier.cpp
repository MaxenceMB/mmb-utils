#include "mmb/logs/Modifier.h"

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
}