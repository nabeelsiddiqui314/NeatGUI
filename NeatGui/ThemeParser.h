#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>

namespace nt {
	enum Type {
		COLORED,
		TEXTURED
	};

	struct Colors {
		Colors() = default;
		Colors(const sf::Color& body, const sf::Color& border)
			: body(body)
			, border(border)
		{}
		sf::Color body;
		sf::Color border;
	};

	class ThemeParser
	{
	public:
		ThemeParser(const std::string& filepath, const int entries);
		~ThemeParser();
	public:
		const Type& getType() const;
		const std::string& getFilepath() const;
		const std::vector<Colors>& getColors() const;
		const std::vector<sf::IntRect>& getTexCoords() const;
	private:
		Type                       m_type;
		std::string                m_filepath;
		std::vector<Colors>        m_colors;
		std::vector<sf::IntRect>   m_texCoords;
		std::ifstream              m_file;
		const int                  m_entries;
	};
}