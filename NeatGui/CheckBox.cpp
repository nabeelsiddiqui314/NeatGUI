#include "stdafx.h"
#include "CheckBox.h"

namespace nt {

	static int boxSize = 15;

	CheckBox::CheckBox(const Mode& mode, const std::string& label, const std::function<void()>& slot)
		: Widget("CheckBox")
	{
		ThemeContainer::applyToOne("CheckMark", m_checkMark);
		m_checkMark.setSize({ (float)boxSize, (float)boxSize });
		m_isActive = mode == Mode::ENABLED ? true : false;
		Widget::setSize(boxSize, boxSize);
		setSlot(slot);
		m_label.setFont(Resources::get().fonts.get("setME"));
		m_label.setCharacterSize(10u);
		m_label.setText(label);
		m_label.setColor(sf::Color::Black);
	}

	void CheckBox::setLabel(const std::string& label) {
		m_label.setText(label);
	}

	void CheckBox::setCharacterSize(unsigned int size) {
		m_label.setCharacterSize(size);
	}

	void CheckBox::setPosition(int x, int y) {
		Widget::setPosition(x, y);
		m_checkMark.setPosition(x, y);
		m_label.setPosition(Widget::getPosition().x + Widget::getSize().x, Widget::getPosition().y);
	}

	void CheckBox::setSize(int x, int y) {
		m_label.setSize(x - boxSize, boxSize);
	}

	const sf::Vector2f& CheckBox::getSize() const {
		return { Widget::getSize().x + m_label.getSize().x, m_label.getSize().y};
	}

	void CheckBox::update() {
		Widget::update();
		if (isReleaseClicked(IN)) {
			m_isActive = !m_isActive;
			callSlot();
		}
	}

	void CheckBox::render() {
		Widget::render();
		if(m_isActive)
			window::get()->draw(m_checkMark);
		m_label.render();
	}

	bool CheckBox::isActive() const {
		return m_isActive;
	}

	CheckBox::~CheckBox() {

	}
}