#include "stdafx.h"
#include "PushButton.h"

namespace nt {
	PushButton::PushButton()
		: Widget("test")
	{
		setPosition(500, 500);
		setSize(200, 150);
		//enableDrag();
	}


	PushButton::~PushButton()
	{
	}
}