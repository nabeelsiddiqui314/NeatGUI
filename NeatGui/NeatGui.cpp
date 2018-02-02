#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"

int main()
{
	nt::window::create(1000, 630, "Neat Gui Tests");

	auto window = nt::window::get();

	while (window->isOpen()) {
		sf::Event evnt;
		while (window->pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->clear();
		window->display();
	}
    return 0;
}

