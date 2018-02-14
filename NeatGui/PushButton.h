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
			Widget::update();
			if (isJustClicked(IN));
		}
	private:
	};
}