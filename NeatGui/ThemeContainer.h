#pragma once
#include "ThemeParser.h"
#include <unordered_map>

namespace nt {
	class ThemeContainer
	{
	public:
		ThemeContainer() = delete;
		~ThemeContainer();
	public:
		static const ThemeParser& get(const std::string& name);
	private:
		static std::unordered_map<std::string, ThemeParser> m_themes;
		static ThemeParser m_fail;
	};
}