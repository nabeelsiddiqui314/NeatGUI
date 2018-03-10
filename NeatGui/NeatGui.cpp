#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "Widget.h"
#include "PushButton.h"
#include "Slider.h"

void sliderSlot();

void buttonSlot();

nt::Slider s(150, sliderSlot);
nt::PushButton p("random slider", buttonSlot);


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
		p.update();
		p.render();
		s.update();
		s.render();
		window->display();
	}
    return 0;
}

