#include "stdafx.h"
#include "CheckBox.h"

namespace nt {
	CheckBox::CheckBox(const Mode& mode, const std::function<void()>& slot)
		: Widget("CheckBox")
	{
		ThemeContainer::applyToOne("CheckMark", m_checkMark);
		m_isActive = mode == Mode::ENABLED ? true : false;
		setSize(10, 10);
		setPosition(600, 400);
		setSlot(slot);
	}

	void CheckBox::setPosition(int x, int y) {
		Widget::setPosition(x, y);
		m_checkMark.setPosition(x, y);
	}

	void CheckBox::setSize(int x, int y) {
		Widget::setSize(x, y);
		m_checkMark.setSize({ (float)x, (float)y });
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
	}

	bool CheckBox::isActive() const {
		return m_isActive;
	}

	CheckBox::~CheckBox() {

	}
}