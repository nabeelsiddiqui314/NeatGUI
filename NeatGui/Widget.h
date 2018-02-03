#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "window.h"
#include "Resources.h"

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
	protected:
		bool isClicked();
		bool isReleaseClicked();
		void updateTextures();
		void render();
	protected:
		State m_state = State::INACTIVE;
	private:
		sf::RectangleShape m_body;
		std::array<sf::IntRect, 3> m_texCoords;
		bool m_clickedLastFrame = false;
	};
}