#pragma once
#include "ThemeParser.h"
#include <unordered_map>
#include "Resources.h"

namespace nt {
	class ThemeContainer
	{
	public:
		ThemeContainer() = delete;
		~ThemeContainer();
	public:
		static const ThemeParser& get(const std::string& name);
		static void applyToOne(const std::string& name, sf::RectangleShape& rect);
	private:
		static std::unordered_map<std::string, ThemeParser> m_themes;
		static ThemeParser m_fail;
	};
}