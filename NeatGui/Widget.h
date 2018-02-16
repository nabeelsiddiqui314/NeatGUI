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
	protected:
		enum Bounds {
			IN,
			OUT,
			ANYWHERE
		};
	public:
		Widget(const std::string& path, std::array<sf::IntRect, 3> texCoords);
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
	protected:
		sf::RectangleShape m_body;
	private:
		State m_state = State::INACTIVE;
		std::array<sf::IntRect, 3> m_texCoords;
		bool m_clickedLastFrame = false,
		     m_isClickedNow = false,
		     m_isDragEnabledX = false,
			 m_isDragEnabledY = false;
		sf::Vector2f m_dragMouseOffset;
	};
}