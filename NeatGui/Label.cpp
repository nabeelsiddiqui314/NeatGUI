#include "stdafx.h"
#include "Label.h"

namespace nt {
	Label::Label()
	{
	}

	void Label::render() {
		window::get()->setView(m_textArea);
		window::get()->draw(m_label);
		window::get()->setView(window::get()->getDefaultView());
	}

	void Label::setPosition(int x, int y) {
		StaticElement::setPosition(x, y);
		resetPosition();
	}

	void Label::setSize(int x, int y) {
		StaticElement::setSize(x, y);
		resetPosition();
	}

	void Label::setText(const std::string& text) {
		m_label.setString(text);
		resetPosition();
	}

	void Label::setCharacterSize(unsigned int size) {
		m_label.setCharacterSize(size);
		resetPosition();
	}

	void Label::resetPosition() {
		m_label.setPosition(getPosition().x + (getSize().x / 2) - (m_label.getGlobalBounds().width / 2),
			getPosition().y + (getSize().y / 2) - (m_label.getGlobalBounds().height / 2) - 2);

		float screenWidth = window::get()->getSize().x;
		float screenHeight = window::get()->getSize().y;
		auto rectPos = sf::Vector2f(StaticElement::getPosition().x, StaticElement::getPosition().y);
		auto rectSize = sf::Vector2f(StaticElement::getSize().x, StaticElement::getSize().y);

		m_textArea.reset(sf::FloatRect(rectPos, rectSize));
		m_textArea.setViewport(sf::FloatRect(rectPos.x / screenWidth, rectPos.y / screenHeight,
			rectSize.x / screenWidth, rectSize.y / screenHeight));
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