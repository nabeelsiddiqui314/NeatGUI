#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget("play", {sf::IntRect(1,2,3,4), sf::IntRect(1,2,3,4), sf::IntRect(1,2,3,4)})
	{
	}


	PushButton::~PushButton()
	{
	}
}