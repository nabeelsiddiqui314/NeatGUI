#include "stdafx.h"
#include "Widget.h"

namespace nt {
	Widget::Widget(const std::string& folder)
		: m_paths({
				folder + "/inactive",
				folder + "/hovered",
				folder + "/pressed"
			})
	{
		m_body.setTexture(&Resources::get().textures.get(m_paths[0]));
	}

	bool Widget::isHovered(bool inside) {
		auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*window::get());
		bool Val = m_body.getGlobalBounds().contains(mousePos);
		 if(inside) 
			 return Val;
		 else 
			 return !Val;
	}

	bool Widget::isPressed(bool inside) {
		return isHovered(inside) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	bool Widget::isClicked(bool inside) {
		m_isClickedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool Val;
		Val = m_clickedLastFrame && !m_isClickedNow;
		return isHovered(inside) && Val;
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
		m_body.setTexture(&Resources::get().textures.get(m_paths[(int)m_state]));
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

	Widget::~Widget()
	{
	}
}