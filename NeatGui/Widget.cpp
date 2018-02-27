#include "stdafx.h"
#include "Widget.h"

namespace nt {
	Widget::Widget(const hiddenNT::InfoFile& infoFile)
	{
		switch (infoFile.getType()) {
		case hiddenNT::COLORED:
			m_type = hiddenNT::COLORED;
			m_colors = infoFile.getColors();
			m_body.setFillColor(m_colors[0].body);
			m_body.setOutlineThickness(1);
			m_body.setOutlineColor(m_colors[0].border);
			break;
		case hiddenNT::TEXTURED:
			m_type = hiddenNT::TEXTURED;
			m_texCoords = infoFile.getTexCoords();
			m_body.setTexture(&Resources::get().textures.get(infoFile.getFilepath()));
			m_body.setTextureRect(m_texCoords[0]);
			break;
		}
	}

	bool Widget::isHovered(const Bounds& bounds) {
		auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*window::get());
		bool Val = m_body.getGlobalBounds().contains(mousePos);
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

	void Widget::enableDragX(bool shdEnable) {
		m_isDragEnabledX = shdEnable;
	}

	void Widget::enableDragY(bool shdEnable) {
		m_isDragEnabledY = shdEnable;
	}

	void Widget::enableDrag(bool shdEnable) {
		enableDragX(shdEnable);
		enableDragY(shdEnable);
	}

	void Widget::update() {
		if (!isHovered() && !isPressed()) {
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
		case hiddenNT::COLORED:
			m_body.setFillColor(m_colors[(int)m_state].body);
			m_body.setOutlineColor(m_colors[(int)m_state].border);
			break;
		case hiddenNT::TEXTURED:
			m_body.setTextureRect(m_texCoords[(int)m_state]);
			break;
		}

		m_clickedLastFrame = m_isClickedNow;
		if (m_isDragEnabledX || m_isDragEnabledY) {
			auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*nt::window::get());
			auto bodyPos = m_body.getPosition();
			if (isJustClicked())
				m_dragMouseOffset = { mousePos.x - bodyPos.x,
						     mousePos.y - bodyPos.y };
			if (m_state == State::PRESSED) {
				if (m_isDragEnabledX)
					setPosition(mousePos.x - m_dragMouseOffset.x, m_body.getPosition().y);
				if (m_isDragEnabledY)
					setPosition(m_body.getPosition().x, mousePos.y - m_dragMouseOffset.y);
			}
		}
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

	Widget::~Widget()
	{
	}
}