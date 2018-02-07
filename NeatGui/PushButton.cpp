#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget("test")
	{
		setPosition(5, 5);
		setSize(200, 150);
	}


	PushButton::~PushButton()
	{
	}
}