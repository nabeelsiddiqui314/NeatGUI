#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget("Push_Button")
	{
		setPosition(500, 500);
		setSize(200, 150);

	}


	PushButton::~PushButton()
	{
	}
}