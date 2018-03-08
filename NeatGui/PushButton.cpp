#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget({ "Push_Button" })
	{
		setPosition(0, 0);
		setSize(100, 100);
		m_label.setCharacterSize(14u);
		m_label.setString("Text");
		m_label.setFillColor(sf::Color::Black);
		m_label.setFont(Resources::get().fonts.get("setME"));
		repositionText();
	}

	PushButton::PushButton(const std::string& label)
		: Widget({ "Push_Button" })
	{
		setPosition(0, 0);
		setSize(100, 100);
		m_label.setCharacterSize(14u);
		m_label.setString("Text");
		m_label.setFillColor(sf::Color::Black);
		m_label.setFont(Resources::get().fonts.get("setME"));
		repositionText();
		setLabel(label);
	}

	PushButton::PushButton(const std::string& label, const std::function<void()>& slot)
		: Widget({ "Push_Button" })
	{
		setPosition(0, 0);
		setSize(100, 100);
		m_label.setCharacterSize(14u);
		m_label.setString("Text");
		m_label.setFillColor(sf::Color::Black);
		m_label.setFont(Resources::get().fonts.get("setME"));
		repositionText();
		setLabel(label);
		setSlot(slot);
	}

	void PushButton::setLabel(const std::string& label) {
		m_label.setString(label);
		repositionText();
	}

	const std::string& PushButton::getLabel() const {
		return m_label.getString();
	}

	void PushButton::update() {
		Widget::update();
		if (isReleaseClicked()) {
			callSlot();
		}
	}

	void PushButton::render() {
		Widget::render();
		window::get()->draw(m_label);
	}

	void PushButton::repositionText() {
		m_label.setPosition(getPosition().x + (getSize().x / 2) - (m_label.getGlobalBounds().width / 2),
			getPosition().y + (getSize().y / 2) - (m_label.getGlobalBounds().height / 2) - 2);
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