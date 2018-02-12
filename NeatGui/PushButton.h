#pragma once
#include <SFML/Graphics.hpp>
#include "Widget.h"

namespace nt {
	class PushButton : public Widget
	{
	public:
		PushButton();
		~PushButton();
	public:
		void update() {
			if (isClicked()) {
				std::cout << "click1 ";
			}
			if (isClicked()) {
				std::cout << "click2 ";
			}
			Widget::update();
		}
	private:
	};
}