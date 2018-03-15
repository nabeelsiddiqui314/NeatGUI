#pragma once
#include <SFML/Graphics.hpp>
#include "Widget.h"
#include "Slot.h"

namespace nt {
	class Slider : public Widget, public Slot
	{
	public:
		Slider(const int max = 100, const int startVal = 0, const std::function<void()>& slot = nullptr);
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
		void setMax(const int max);
	private:
		sf::RectangleShape m_bar;
		int m_prevPos;
		int m_max;
	};
}