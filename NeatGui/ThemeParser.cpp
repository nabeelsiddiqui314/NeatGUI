#include "stdafx.h"
#include "ThemeParser.h"

namespace nt {
	ThemeParser::ThemeParser(const std::string& filepath) 
	{
		m_file.open("./Theme/" + filepath + ".txt");

		std::string temp;
		m_file >> temp;
		if (temp == "COLORED") {
			m_type = COLORED;
			while (std::getline(m_file, temp)) {
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

				m_colors.emplace_back(sf::Color(bodyR, bodyG, bodyB), sf::Color(borderR, borderG, borderB));
			}
		}
		else if (temp == "TEXTURED") {
			m_type = TEXTURED;
			while (std::getline(m_file, temp)) {
				m_file >> temp;
				int startX = std::stoi(temp);
				m_file >> temp;
				int startY = std::stoi(temp);
				m_file >> temp;
				int width = std::stoi(temp);
				m_file >> temp;
				int height = std::stoi(temp);
				m_texCoords.emplace_back(startX, startY, width, height);
			}
		}
	}

	const Type& ThemeParser::getType() const {
		return m_type;
	}

	const std::string& ThemeParser::getFilepath() const {
		return m_filepath;
	}

	const std::vector<Colors>&  ThemeParser::getColors() const {
		return m_colors;
	}

	const std::vector<sf::IntRect>& ThemeParser::getTexCoords() const {
		return m_texCoords;
	}

	ThemeParser::~ThemeParser()
	{
		m_file.close();
	}
}