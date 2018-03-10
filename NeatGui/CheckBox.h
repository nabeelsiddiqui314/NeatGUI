#pragma once
#include "Widget.h"

namespace nt {
	class CheckBox : public Widget
	{
	public:
		CheckBox();
		~CheckBox();
	public:
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;
		const sf::Vector2f& getPosition() const override;
		const sf::Vector2f& getSize() const override;
		void update() override;
		void render() override;
	private:
		sf::RectangleShape m_checkMark;
		bool               m_isActive;
	};
}