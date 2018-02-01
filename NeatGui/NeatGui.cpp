#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1000, 630), "Neat Gui Tests", sf::Style::Close);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.display();
	}
    return 0;
}

