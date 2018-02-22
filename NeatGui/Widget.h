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
		enum State {
			INACTIVE,
			HOVERED,
			PRESSED
		};
		enum Type {
			COLORED,
			TEXTURED
		};
	protected:
		enum Bounds {
			IN,
			OUT,
			ANYWHERE
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
	public:
		Widget(const std::string& path, const std::array<sf::IntRect, 3>& texCoords);
		Widget(const std::array<Colors, 3>& colors, int borderThickness = 1);
		virtual ~Widget();
	public:
		virtual void update();
		virtual void render();
		
		virtual void setSize(int x, int y);
		virtual void setPosition(int x, int y);
		virtual const sf::Vector2f& getSize() const;
		virtual const sf::Vector2f& getPosition() const;
	protected:
		bool isHovered(const Bounds bounds = Bounds::IN);
		bool isPressed(const Bounds bounds = Bounds::IN);
		bool isJustClicked(const Bounds bounds = Bounds::IN);
		bool isReleaseClicked(const Bounds bounds = Bounds::IN);
		void enableDragX(bool shdEnable = true);
		void enableDragY(bool shdEnable = true);
		void enableDrag(bool shdEnable = true);
	private:
		sf::RectangleShape         m_body;
		State                      m_state = INACTIVE;
		Type                       m_type;
		std::array<sf::IntRect, 3> m_texCoords;
		std::array<Colors, 3>      m_colors;

		bool m_clickedLastFrame = false,
		     m_isClickedNow = false,
		     m_isDragEnabledX = false,
			 m_isDragEnabledY = false;
		sf::Vector2f m_dragMouseOffset;
	};
}