#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		//: Widget("button", { sf::IntRect(0, 0, 100, 100), sf::IntRect(0, 100, 100, 100), sf::IntRect(0, 200, 100, 100) })
		: Widget({ Colors(sf::Color(189, 189, 189), sf::Color(200, 200, 200)), 
			Colors(sf::Color(189, 213, 225), sf::Color(150, 200, 200)), 
			Colors(sf::Color(0, 210, 210), sf::Color(200, 200, 150)) })
	{
		setPosition(0, 0);
		setSize(305, 300);
		m_label.setCharacterSize(15u);
		m_label.setString("Text");
		m_label.setFillColor(sf::Color::Black);
		m_label.setFont(Resources::get().fonts.get("setMe"));
		repositionText();
	}

	bool PushButton::isClicked() {
		return isReleaseClicked(IN);
	}

	void PushButton::setLabel(const std::string& label) {
		m_label.setString(label);
		repositionText();
	}

	void PushButton::render() {
		Widget::render();
		window::get()->draw(m_label);
	}

	void PushButton::repositionText() {
		m_label.setPosition(getPosition().x + (getSize().x / 2) - (m_label.getGlobalBounds().width / 2),
			getPosition().y + (getSize().y / 2) - (m_label.getGlobalBounds().height / 2));
	}

	void PushButton::setPosition(int x, int y) {
		Widget::setPosition(x, y);
		repositionText();
	}

	void PushButton::setSize(int x, int y) {
		Widget::setSize(x, y);
		repositionText();
	}

	PushButton::~PushButton()
	{
	}
}