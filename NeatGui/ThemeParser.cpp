#include "stdafx.h"
#include "ThemeParser.h"

namespace hiddenNT {
	ThemeParser::ThemeParser(const std::string& filepath) {
		m_file.open("./Theme/" + filepath + ".txt");

		std::string temp;
		while (std::getline(m_file, temp)) {
			if (temp == "COLORED") {
				m_type = COLORED;
				for (unsigned short int i = 0; i < 3; i++) {
					m_file >> temp;
					int bodyR = std::stoi(temp);
					m_file >> temp;
					int bodyG = std::stoi(temp);
					m_file >> temp;
					int bodyB = std::stoi(temp);

					m_file >> temp;
					int borderR = std::stoi(temp);
					m_file >> temp;
					int borderG = std::stoi(temp);
					m_file >> temp;
					int borderB = std::stoi(temp);

					m_colors[i].body   = sf::Color(bodyR, bodyG, bodyB);
					m_colors[i].border = sf::Color(borderR, borderG, borderB);
				}
			}
			else if (temp == "TEXTURED") {
				m_type = TEXTURED;
				m_file >> temp;
				m_filepath = temp;
				for (unsigned short int i = 0; i < 3; i++) {
					m_file >> temp;
					int startX = std::stoi(temp);
					m_file >> temp;
					int startY = std::stoi(temp);
					m_file >> temp;
					int width = std::stoi(temp);
					m_file >> temp;
					int height = std::stoi(temp);
					m_texCoords[i] = sf::IntRect(startX, startY, width, height);
				}
			}
		}
	}

	const Type& ThemeParser::getType() const {
		return m_type;
	}

	const std::string& ThemeParser::getFilepath() const {
		return m_filepath;
	}

	const std::array<Colors, 3>& ThemeParser::getColors() const {
		return m_colors;
	}

	const std::array<sf::IntRect, 3>& ThemeParser::getTexCoords() const {
		return m_texCoords;
	}

	ThemeParser::~ThemeParser()
	{
		m_file.clear();
	}
}