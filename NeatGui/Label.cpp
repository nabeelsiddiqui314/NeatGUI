#include "stdafx.h"
#include "Label.h"

namespace nt {
	Label::Label()
	{
		StaticElement::setColor(sf::Color::Transparent);
	}

	void Label::render() {
		StaticElement::render();
		window::get()->draw(m_label);
	}

	void Label::setPosition(int x, int y) {
		StaticElement::setPosition(x, y);
		repositionText();
	}

	void Label::setSize(int x, int y) {
		StaticElement::setSize(x, y);
		repositionText();
	}

	void Label::setText(const std::string& text) {
		m_label.setString(text);
		repositionText();
	}

	void Label::setCharacterSize(unsigned int size) {
		m_label.setCharacterSize(size);
		repositionText();
	}

	void Label::repositionText() {
		m_label.setPosition(getPosition().x + (getSize().x / 2) - (m_label.getGlobalBounds().width / 2),
			getPosition().y + (getSize().y / 2) - (m_label.getGlobalBounds().height / 2) - 2);
	}

	void Label::setFont(const sf::Font& font) {
		m_label.setFont(font);
	}

	void Label::setColor(const sf::Color& color) {
		m_label.setFillColor(color);
	}

	const std::string& Label::getText() const {
		return m_label.getString();
	}
 
	Label::~Label()
	{
	}
}