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

	void ThemeContainer::applyToOne(const std::string& name, sf::RectangleShape& rect) {
		auto& theme = get(name);
		switch (theme.getType()) {
		case COLORED:
			rect.setFillColor(theme.getColors()[0].body);
			rect.setOutlineThickness(1);
			rect.setOutlineColor(theme.getColors()[0].border);
			break;
		case TEXTURED:
			rect.setTexture(&Resources::get().textures.get(theme.getFilepath()));
			rect.setTextureRect(theme.getTexCoords()[0]);
			break;
		}
	}

	ThemeContainer::~ThemeContainer()
	{
	}
}