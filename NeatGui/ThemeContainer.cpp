#include "stdafx.h"
#include "ThemeContainer.h"

namespace nt {
	std::unordered_map<std::string, ThemeParser> ThemeContainer::m_themes;
	ThemeParser ThemeContainer::m_fail = { "FAIL" };

	const ThemeParser& ThemeContainer::get(const std::string& name) {
		if (m_themes.find(name) != m_themes.end())
			return m_themes.at(name);
		else {
			m_themes.emplace(std::make_pair(name, name));
			return m_themes.at(name);
		}
	}

	ThemeContainer::~ThemeContainer()
	{
	}
}