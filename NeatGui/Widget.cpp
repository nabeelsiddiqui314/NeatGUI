#include "stdafx.h"
#include "Widget.h"

namespace nt {
	Widget::Widget(const std::string& texture, std::array<sf::IntRect, 3> texCoords)
		: m_texCoords(texCoords) 
	{
		m_body.setTexture(&Resources::get().textures.get(texture));
	}

	bool Widget::isClicked() {
		auto mousePos = (sf::Vector2f)sf::Mouse::getPosition(*window::get());
		return m_body.getGlobalBounds().contains(mousePos) &&
			   sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	bool Widget::isReleaseClicked() {
		return false;
	}

	void Widget::updateTextures() {
		m_body.setTextureRect(m_texCoords[(int)m_state]);
	}

	void Widget::render() {
		window::get()->draw(m_body);
	}

	Widget::~Widget()
	{
	}
}