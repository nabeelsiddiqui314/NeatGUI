#include "stdafx.h"
#include "StaticElement.h"

namespace nt {
	StaticElement::StaticElement()
	{
	}

	void StaticElement::render() {
		window::get()->draw(m_body);
	}

	void StaticElement::setPosition(int x, int y) {
		m_body.setPosition(x, y);
	}

	void StaticElement::setSize(int x, int y) {
		m_body.setSize({ (float)x, (float)y });
	}

	const sf::Vector2f& StaticElement::getPosition() const {
		return m_body.getPosition();
	}

	const sf::Vector2f& StaticElement::getSize() const {
		return m_body.getSize();
	}

	void StaticElement::setTexture(const sf::Texture& texture) {
		m_body.setTexture(&texture);
	}

	void StaticElement::setColor(const sf::Color& color) {
		m_body.setFillColor(color);
	}

	StaticElement::~StaticElement()
	{
	}
}