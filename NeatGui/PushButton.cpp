#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget({ "ey" })
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