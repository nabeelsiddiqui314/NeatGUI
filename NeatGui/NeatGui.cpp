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

	nt::Box box(nt::Layout::VERTICAL, 5, 5);
	nt::PushButton p1("p1adawdawd");
	nt::PushButton p2("p2");
	nt::PushButton p3("p3");
	nt::PushButton p4("p4");
	nt::PushButton p5("p5");
	nt::Slider s;
	nt::CheckBox c;

	p2.setSize(50, 50);
	p3.setSize(50, 50);
	p1.setSize(50, 50);
	p4.setSize(50, 50);
	p5.setSize(50, 50);
	s.setSize(200, 50);
	c.setSize(70, 30);

	box.setPosition(400, 200);
	box.setSize(400, 400);

	box.add(&p1);
	box.add(&p2);
	box.add(&p4);
	box.add(&c);
	box.add(&s);
	box.add(&p5);
	box.add(&p3);

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
		window->clear(sf::Color(250, 250, 250));

		box.update();
		box.render();
		
		window->display();
	}
    return 0;
}

