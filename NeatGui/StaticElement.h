#pragma once
#include <SFML/Graphics.hpp>
#include "window.h"

namespace nt {
	class StaticElement
	{
	public:
		StaticElement();
		virtual ~StaticElement();
	public:
		virtual void render();
		virtual void setPosition(int x, int y);
		virtual void setSize(int x, int y);
		virtual const sf::Vector2f& getPosition() const;
		virtual const sf::Vector2f& getSize() const;
	protected:
		void setTexture(const sf::Texture& texture);
		void setColor(const sf::Color& color);
	private:
		sf::RectangleShape m_body;
	};
}