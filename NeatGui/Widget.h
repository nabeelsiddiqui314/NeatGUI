#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include "window.h"
#include "Resources.h"

namespace nt {
	class Widget
	{
	private:
		enum class State {
			INACTIVE,
			HOVERED,
			PRESSED
		};
	public:
		Widget(const std::string& folder);
		virtual ~Widget();
	public:
		virtual void update();
		virtual void render();
		bool isHovered();
		bool isPressed();
		bool isClicked();
		
		void setSize(int x, int y);
		void setPosition(int x, int y);
		const sf::Vector2f& getSize() const;
		const sf::Vector2f& getPosition() const;
	protected:
		sf::RectangleShape m_body;
	private:
		State m_state = State::INACTIVE;
		std::array<std::string, 3> m_paths;
		bool m_clickedLastFrame = false;
	};
}