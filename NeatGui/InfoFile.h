#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>

namespace hiddenNT {
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

	class InfoFile
	{
	public:
		InfoFile(const std::string& filepath);
		~InfoFile();
	public:
		const Type& getType() const;
		const std::string& getFilepath() const;
		const std::array<Colors, 3>& getColors() const;
		const std::array<sf::IntRect, 3>& getTexCoords() const;
	private:
		Type                       m_type;
		std::string                m_filepath;
		std::array<Colors, 3>      m_colors;
		std::array<sf::IntRect, 3> m_texCoords;
		std::ifstream              m_file;
	};
}