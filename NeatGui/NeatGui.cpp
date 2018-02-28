#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "Widget.h"
#include "PushButton.h"
#include "Slider.h"

int main()
{
	nt::window::create(1000, 630, "Neat Gui Tests");

	auto window = nt::window::get();
	nt::PushButton p;
	nt::Slider s({ 500, 200 }, { 200, 40 }, 10, 0, 100);
	
	p.setPosition(100, 100);


	while (window->isOpen()) {
		sf::Event evnt;
		while (window->pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->clear(sf::Color(255, 255, 255));
		p.update();
		p.render();
		s.update();
		s.render();
		std::cout << s.getValue() << std::endl;
		window->display();
	}
    return 0;
}

