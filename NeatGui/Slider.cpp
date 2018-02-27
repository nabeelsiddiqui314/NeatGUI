#include "stdafx.h"
#include "Slider.h"

namespace nt {
	Slider::Slider()
		: Widget({ "Slider" }) 
	{
		enableDragX(true, false);
		m_bar.setSize({400.0f, 20.0f});
		setSize(400, 40);
		setPosition(50, 50);
		m_bar.setFillColor(sf::Color(189, 189, 189));
		m_bar.setOutlineThickness(1);
		m_bar.setOutlineColor(sf::Color::Black);
	}

	void Slider::setPosition(int x, int y) {
		Widget::setPosition(x, y);
		m_bar.setPosition(x, y + Widget::getSize().y / 2 - m_bar.getSize().y / 2);
	}

	void Slider::setSize(int x, int y) {
		m_bar.setSize({(float)x, m_bar.getSize().y});
		Widget::setSize(Widget::getSize().x, y);
	}

	const sf::Vector2f& Slider::getPosition() const {
		return { m_bar.getPosition().x, Widget::getPosition().y };
	}

	const sf::Vector2f& Slider::getSize() const {
		return { m_bar.getSize().x, Widget::getSize().y };
	}

	void Slider::update() {
		Widget::update();

		if (Widget::getPosition().x + Widget::getSize().x / 2 > m_bar.getPosition().x + m_bar.getSize().x)
			Widget::setPosition(m_bar.getPosition().x + m_bar.getSize().x - Widget::getSize().x / 2, Widget::getPosition().y);

		if (Widget::getPosition().x + Widget::getSize().x / 2 < m_bar.getPosition().x)
			Widget::setPosition(m_bar.getPosition().x - Widget::getSize().x / 2, Widget::getPosition().y);
	}

	void Slider::render() {
		window::get()->draw(m_bar);
		Widget::render();
	}

	Slider::~Slider()
	{
	}
}