#pragma once
#include <SFML/Graphics.hpp>
#include "Widget.h"

namespace nt {
	class Slider : public Widget
	{
	public:
		Slider();
		Slider(const sf::Vector2i& pos, const sf::Vector2i& size, const int sliderWidth, const int startVal, const int max);
		~Slider();
	public:
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;
		const sf::Vector2f& getPosition() const override;
		const sf::Vector2f& getSize() const override;
		void update() override;
		void render() override;
		const int getValue() const;
		void setValue(const int value);
	private:
		sf::RectangleShape m_bar;
		int m_max;
	};
}