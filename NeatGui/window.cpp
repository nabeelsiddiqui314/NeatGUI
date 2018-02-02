#include "stdafx.h"
#include "window.h"

namespace nt {
	std::shared_ptr<sf::RenderWindow> window::m_window = std::make_shared<sf::RenderWindow>();

	void window::create(const unsigned int width, const unsigned int height, const std::string& title) {
		m_window->create(sf::VideoMode(width, height), title, sf::Style::Close);
	}

	std::shared_ptr<sf::RenderWindow> window::get() {
		return m_window;
	}
}