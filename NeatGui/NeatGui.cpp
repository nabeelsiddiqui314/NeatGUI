#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "ResourceLoader.h"

nt::ResourceLoader res;

struct rect {
	rect() {
		rct.setTexture(&res.getTexture("play"));
		rct.setPosition(50, 50);
		rct.setSize({50.0f, 50.0f});
	}
	sf::RectangleShape rct;
};

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1000, 630), "Neat Gui Tests", sf::Style::Close);

	res.addTexture("./play.png", "play");
	rect r[100];

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		for (int i = 0; i < 50; i++) {
			window.draw(r[i].rct);
		}
		window.display();
	}
    return 0;
}

