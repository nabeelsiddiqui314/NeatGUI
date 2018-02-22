#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "Widget.h"
#include "PushButton.h"

int main()
{
	nt::window::create(1000, 630, "Neat Gui Tests");

	auto window = nt::window::get();
	std::unique_ptr<nt::PushButton> p = std::make_unique<nt::PushButton>();
	
	p->setPosition(100, 100);
	p->setSize(200, 275);


	while (window->isOpen()) {
		sf::Event evnt;
		while (window->pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->clear(sf::Color(200, 200, 200));
		p->update();
		p->render();
		window->display();
	}
    return 0;
}

