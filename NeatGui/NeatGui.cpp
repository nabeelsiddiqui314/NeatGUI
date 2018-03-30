#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "PushButton.h"
#include "Slider.h"
#include "CheckBox.h"
#include "Box.h"


int main()
{
	nt::window::create(1000, 630, "Neat Gui Tests");

	auto window = nt::window::get();

	nt::Box box(nt::Layout::HORIZONTAL, 10, 5);
	nt::PushButton p1("p1");
	nt::PushButton p2("p2");
	nt::PushButton p3("p3");
	nt::PushButton p4("p4");
	nt::PushButton p5("p5");

	p2.setSize(80, 80);
	p3.setSize(80, 80);
	p1.setSize(80, 80);
	p4.setSize(80, 80);
	p5.setSize(80, 80);

	box.setPosition(400, 200);
	box.setSize(300, 60);

	box.add(&p1, true);
	box.add(&p2, true);
	box.add(&p3, true);
	box.add(&p4, true);
	box.add(&p5, true);
	

	while (window->isOpen()) {
		sf::Event evnt;
		while (window->pollEvent(evnt)) {
			if (evnt.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, evnt.size.width, evnt.size.height);
				window->setView(sf::View(visibleArea));
			}
			if (evnt.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->clear(sf::Color(255, 255, 255));

		box.update();
		box.render();
		
		window->display();
	}
    return 0;
}

