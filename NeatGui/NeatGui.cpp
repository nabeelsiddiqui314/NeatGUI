#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "PushButton.h"
#include "Slider.h"
#include "CheckBox.h"

void sliderSlot();

void buttonSlot();

nt::Slider s(150, 0, sliderSlot);
nt::PushButton p("random slider", buttonSlot);
nt::CheckBox c;

void sliderSlot() {
	p.setLabel(std::to_string(s.getValue()));
}

void buttonSlot() {
	s.setValue(s.getValue() + (rand() % 20 - 10));
}

int main()
{
	nt::window::create(1000, 630, "Neat Gui Tests");

	auto window = nt::window::get();
	
	p.setPosition(100, 100);
	s.setPosition(200, 200);
	


	while (window->isOpen()) {
		sf::Event evnt;
		while (window->pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->clear(sf::Color(255, 255, 255));
		if (c.isActive())
			p.setEnabled(true);
		else
			p.setEnabled(false);
		p.update();
		p.render();
		s.update();
		s.render();
		c.update();
		c.render();
		window->display();
	}
    return 0;
}

