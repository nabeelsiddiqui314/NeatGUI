#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "window.h"
#include "Resources.h"
#include "ThemeParser.h"
#include "ThemeContainer.h"

namespace nt {
	class Widget
	{
	private:
		enum State {
			INACTIVE,
			HOVERED,
			PRESSED,
			DISABLED
		};
	protected:
		enum Bounds {
			IN,
			OUT,
			ANYWHERE
		};
	public:
		Widget(const std::string& themeFilePath);
		virtual ~Widget();
	public:
		virtual void update();
		virtual void render();
		
		virtual void setSize(int x, int y);
		virtual void setPosition(int x, int y);
		virtual const sf::Vector2f& getSize() const;
		virtual const sf::Vector2f& getPosition() const;

		void setEnabled(bool shdEnable);
		bool isEnabled() const;
	protected:
		bool isHovered(const Bounds& bounds = Bounds::IN);
		bool isPressed(const Bounds &bounds = Bounds::IN);
		bool isJustClicked(const Bounds& bounds = Bounds::IN);
		bool isReleaseClicked(const Bounds& bounds = Bounds::IN);
		void enableDragX(bool shdEnable = true, bool callOverride = true);
		void enableDragY(bool shdEnable = true, bool callOverride = true);
		void enableDrag(bool shdEnable = true, bool callOverride = true);
	private:
		sf::RectangleShape         m_body;
		State                      m_state = INACTIVE;
		Type                       m_type;
		std::array<sf::IntRect, 4> m_texCoords;
		std::array<Colors, 4>      m_colors;

		bool m_clickedLastFrame = false,
			m_isClickedNow = false,
			m_isDragEnabledX = false,
			m_isDragEnabledY = false,
			m_callOverrideForDrag = true,
			m_enabled = true;

		sf::Vector2f m_dragMouseOffset;
	};
}