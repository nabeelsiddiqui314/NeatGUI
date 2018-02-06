#include "stdafx.h"
#include "Widget.h"

namespace nt {
	Widget::Widget(const std::string& texture, std::array<sf::IntRect, 3> texCoords)
		: m_texCoords(texCoords) 
	{
		m_body.setTexture(&Resources::get().textures.get(texture));
	}

	bool Widget::isHovered() {
		auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*window::get());
		return m_body.getGlobalBounds().contains(mousePos);
	}

	bool Widget::isClicked() {
		return isHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	bool Widget::isPressed() {
		bool isClkedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool Val;
		Val = m_clickedLastFrame && !isClkedNow;
		m_clickedLastFrame = isClkedNow;
		return isHovered() && Val;
	}

	void Widget::update() {
		if (!isHovered() && !isClicked()) {
			m_state = State::INACTIVE;
		}
		else if (isHovered() && !isClicked()) {
			m_state = State::HOVERED;
		}
		else if (isClicked()) {
			m_state = State::PRESSED;
		}
		m_body.setTextureRect(m_texCoords[(int)m_state]);
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