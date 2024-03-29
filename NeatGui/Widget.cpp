#include "stdafx.h"
#include "Widget.h"

namespace nt {
	Widget::Widget(const std::string& themeFilePath)
	{
		auto& themeFile = ThemeContainer::get(themeFilePath);
		switch (themeFile.getType()) {
		case COLORED:
			m_type = COLORED;
			for (std::size_t i = 0; i < 4; i++)
				m_colors[i] = themeFile.getColors()[i];
			m_body.setFillColor(m_colors[0].body);
			m_body.setOutlineThickness(1);
			m_body.setOutlineColor(m_colors[0].border);
			break;
		case TEXTURED:
			m_type = TEXTURED;
			for (std::size_t i = 0; i < 4; i++)
				m_texCoords[i] = themeFile.getTexCoords()[i];
			m_body.setTexture(&Resources::get().textures.get(themeFile.getFilepath()));
			m_body.setTextureRect(m_texCoords[0]);
			break;
		}
	}

	void Widget::addBody(sf::RectangleShape& rect) {
		m_body2rect = &rect;
		m_body2text = nullptr;
	}

	void Widget::addBody(sf::Text& text) {
		m_body2text = &text;
		m_body2rect = nullptr;
	}

	bool Widget::isHovered(const Bounds& bounds) {
		if (!m_enabled)
			return false;
		auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*window::get());
		bool isSecondHovered = false;

		if (m_body2rect == nullptr && m_body2text == nullptr) {
			isSecondHovered = false;
		}
		else if (m_body2rect != nullptr && m_body2rect->getGlobalBounds().contains(mousePos)) {
			isSecondHovered = true;
		}
		else if (m_body2text != nullptr && m_body2text->getGlobalBounds().contains(mousePos)) {
			isSecondHovered = true;
		}
		else {
			isSecondHovered = false;
		}

		bool Val = m_body.getGlobalBounds().contains(mousePos) || isSecondHovered;
		switch (bounds) {
		case ANYWHERE:
			return true;
			break;
		case IN:
			return Val;
			break;
		case OUT:
			return !Val;
			break;
		}
	}

	bool Widget::isPressed(const Bounds& bounds) {
		return isHovered(bounds) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	bool Widget::isJustClicked(const Bounds& bounds) {
		m_isClickedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool Val;
		Val = !m_clickedLastFrame && m_isClickedNow;
		return isHovered(bounds) && Val;
	}

	bool Widget::isReleaseClicked(const Bounds& bounds) {
		m_isClickedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool Val;
		Val = m_clickedLastFrame && !m_isClickedNow;
		return isHovered(bounds) && Val;
	}

	void Widget::enableDragX(bool shdEnable, bool callOverride) {
		m_isDragEnabledX = shdEnable;
		m_callOverrideForDrag = callOverride;
	}

	void Widget::enableDragY(bool shdEnable, bool callOverride) {
		m_isDragEnabledY = shdEnable;
		m_callOverrideForDrag = callOverride;
	}

	void Widget::enableDrag(bool shdEnable, bool callOverride) {
		enableDragX(shdEnable);
		enableDragY(shdEnable);
	}

	void Widget::update() {
		if (!m_enabled) {
			m_state = State::DISABLED;
		}
		else if (!isHovered() && !isPressed()) {
			m_state = State::INACTIVE;
		}
		else if (isHovered() && !isPressed()) {
			m_state = State::HOVERED;
		}
		else if (isPressed()) {
			m_state = State::PRESSED;
		}

		switch (m_type)
		{
		case COLORED:
			m_body.setFillColor(m_colors[(int)m_state].body);
			m_body.setOutlineColor(m_colors[(int)m_state].border);
			break;
		case TEXTURED:
			m_body.setTextureRect(m_texCoords[(int)m_state]);
			break;
		}

		if (m_isDragEnabledX || m_isDragEnabledY) {
			auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*nt::window::get());
			auto bodyPos = m_body.getPosition();

			if (isJustClicked()) {
				m_dragMouseOffset = { mousePos.x - bodyPos.x,
							 mousePos.y - bodyPos.y };
				m_isDragging = true;
			}

			if (isReleaseClicked(ANYWHERE)) {
				m_isDragging = false;
			}

			if (m_isDragging) {
				if (m_isDragEnabledX) {
					if (m_callOverrideForDrag) 
						setPosition(mousePos.x - m_dragMouseOffset.x, m_body.getPosition().y);
					else 
						m_body.setPosition(mousePos.x - m_dragMouseOffset.x, m_body.getPosition().y);
				}
				if (m_isDragEnabledY) {
					if (m_callOverrideForDrag) 
						setPosition(m_body.getPosition().x, mousePos.y - m_dragMouseOffset.y);
					else
						m_body.setPosition(m_body.getPosition().x, mousePos.y - m_dragMouseOffset.y);
				}
			}
		}
		m_clickedLastFrame = m_isClickedNow;
	}

	void Widget::render() {
		window::get()->draw(m_body);
	}

	void Widget::setSize(int x, int y) {
		float xSize = std::max(10, x);
		float ySize = std::max(10, y);
		m_body.setSize({xSize, ySize});
	}

	void Widget::setPosition(int x, int y) {
		m_body.setPosition(x, y);
	}

	const sf::Vector2f& Widget::getSize() const {
		return m_body.getSize();
	}

	const sf::Vector2f& Widget::getPosition() const {
		return m_body.getPosition();
	}

	void Widget::setEnabled(bool shdEnable) {
		m_enabled = shdEnable;
	}

	bool Widget::isEnabled() const {
		return m_enabled;
	}

	void Widget::setInactive() {
		m_state = INACTIVE;
		switch (m_type)
		{
		case COLORED:
			m_body.setFillColor(m_colors[0].body);
			m_body.setOutlineColor(m_colors[0].border);
			break;
		case TEXTURED:
			m_body.setTextureRect(m_texCoords[0]);
			break;
		}
	}

	Widget::~Widget()
	{
	}
}