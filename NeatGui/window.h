#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

namespace nt {
	class window
	{
	public:
		window() = delete;
		~window() {}
	public:
		static void create(const unsigned int width, const unsigned int height, const std::string& title);
		static const std::shared_ptr<sf::RenderWindow> get();
	private:
		static std::shared_ptr<sf::RenderWindow> m_window;
	};
}