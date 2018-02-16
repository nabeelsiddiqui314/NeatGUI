#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget("button", {sf::IntRect(0, 0, 200, 150), sf::IntRect(50, 50, 200, 150), sf::IntRect(100, 100, 200, 150)})
	{
		setPosition(500, 500);
		setSize(200, 150);

	}


	PushButton::~PushButton()
	{
	}
}