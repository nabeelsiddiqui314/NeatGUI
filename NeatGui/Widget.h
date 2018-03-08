#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "window.h"
#include "Resources.h"
#include "ThemeParser.h"

namespace nt {
	class Widget
	{
	private:
		enum State {
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
		Widget(const hiddenNT::ThemeParser& infoFile);
		virtual ~Widget();
	public:
		virtual void update();
		virtual void render();
		
		virtual void setSize(int x, int y);
		virtual void setPosition(int x, int y);
		virtual const sf::Vector2f& getSize() const;
		virtual const sf::Vector2f& getPosition() const;
	protected:
		bool isHovered(const Bounds& bounds = Bounds::IN);
		bool isPressed(const Bounds &bounds = Bounds::IN);
		bool isJustClicked(const Bounds& bounds = Bounds::IN);
		bool isReleaseClicked(const Bounds& bounds = Bounds::IN);
		void enableDragX(bool shdEnable = true, bool callOverride = true);
		void enableDragY(bool shdEnable = true, bool callOverride = true);
		void enableDrag(bool shdEnable = true, bool callOverride = true);
	private:
		sf::RectangleShape                   m_body;
		State                                m_state = INACTIVE;
		hiddenNT::Type                       m_type;
		std::array<sf::IntRect, 3>           m_texCoords;
		std::array<hiddenNT::Colors, 3>      m_colors;

		bool m_clickedLastFrame = false,
		     m_isClickedNow = false,
		     m_isDragEnabledX = false,
			 m_isDragEnabledY = false,
		     m_callOverrideForDrag = true;

		sf::Vector2f m_dragMouseOffset;
	};
}