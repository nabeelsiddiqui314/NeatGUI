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
			if (isClicked(false)) {
				std::cout << "click ";
			}
		}
	private:
	};
}