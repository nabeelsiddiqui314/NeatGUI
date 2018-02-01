#pragma once
#include <SFML/Graphics.hpp>
#include <array>

namespace nt {
	class Widget
	{
	protected:
		enum class State {
			INACTIVE,
			HOVERED,
			PRESSED
		};
	public:
		Widget(const std::string& texture, std::array<sf::IntRect, 3> texCoords);
		~Widget();
	public:
		bool isClicked();
		void update();
		void render();
	protected:
		sf::RectangleShape m_body;
		std::string m_texture;
		std::array<sf::IntRect, 3> m_texCoords;
	};
}