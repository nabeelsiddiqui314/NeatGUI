#include "stdafx.h"
#include "Slider.h"

namespace nt {
	Slider::Slider()
		: Widget({ "Slider" }) 
	{
		enableDragX(true, false);
		m_bar.setSize({ 400.0f, 5.0f });
		setSize(400, 40);
		setPosition(50, 50);
		m_bar.setFillColor(sf::Color(189, 189, 189));
		m_bar.setOutlineThickness(1);
		m_bar.setOutlineColor(sf::Color::Black);
	}

	Slider::Slider(const sf::Vector2i& pos, const sf::Vector2i& size, const int sliderWidth, const int startVal, const int max)
		: Widget({ "Slider" })
		, m_max(max)
	{
		enableDragX(true, false);
		m_bar.setSize({ (float)size.x, 5.0f });
		setSize(size.x, std::max(size.y, 5));
		setPosition(pos.x, pos.y);
		m_bar.setFillColor(sf::Color(189, 189, 189));
		m_bar.setOutlineThickness(1);
		m_bar.setOutlineColor(sf::Color::Black);
		Widget::setSize(sliderWidth, Widget::getSize().y);
		setValue(startVal);
	}

	void Slider::setPosition(int x, int y) {
		Widget::setPosition(x + Widget::getPosition().x  - m_bar.getPosition().x , y);
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

		const float sliderPosX = Widget::getPosition().x + Widget::getSize().x / 2;
		const float sliderPosY = Widget::getPosition().y;
		const float sliderCenter = Widget::getSize().x / 2;
		const float barPos = m_bar.getPosition().x;
		const float barWidth = m_bar.getSize().x;

		if (sliderPosX > barPos + barWidth)
			Widget::setPosition(barPos + barWidth - sliderCenter, sliderPosY);

		if (sliderPosX < barPos)
			Widget::setPosition(barPos - sliderCenter, sliderPosY);
	}

	void Slider::render() {
		window::get()->draw(m_bar);
		Widget::render();
	}

	const int Slider::getValue() const {
		float pos = Widget::getSize().x / 2 + Widget::getPosition().x - m_bar.getPosition().x;
		float maxLength = m_bar.getSize().x;
		float Val = (pos / maxLength) * m_max;
		return Val;
	}

	void Slider::setValue(const int value) {
		float offset = m_bar.getPosition().x - Widget::getSize().x / 2;
		float pos = (value * m_bar.getSize().x) / m_max;
		Widget::setPosition(offset + pos, Widget::getPosition().y);
	}

	Slider::~Slider()
	{
	}
}