#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton(const std::string& label, const std::function<void()>& slot)
		: Widget("Push_Button")
	{
		setPosition(0, 0);
		setSize(100, 100);
		m_label.setCharacterSize(14u);
		m_label.setText("Push_Button");
		m_label.setColor(sf::Color::Black);
		m_label.setFont(Resources::get().fonts.get("setME"));
		setLabel(label);
		setSlot(slot);
	}

	void PushButton::setLabel(const std::string& label) {
		m_label.setText(label);
	}

	const std::string& PushButton::getLabel() const {
		return m_label.getText();
	}

	void PushButton::update() {
		Widget::update();
		if (isReleaseClicked()) {
			callSlot();
		}
	}

	void PushButton::render() {
		Widget::render();
		m_label.render();
	}

	void PushButton::setPosition(int x, int y) {
		Widget::setPosition(x, y);
		m_label.setPosition(x, y);
	}

	void PushButton::setSize(int x, int y) {
		Widget::setSize(x, y);
		m_label.setSize(x, y);
	}

	PushButton::~PushButton()
	{
	}
}