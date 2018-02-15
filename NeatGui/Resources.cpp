#include "stdafx.h"
#include "Resources.h"

namespace nt {
	Resources::Resources() 
	: textures("textures", "png")
	, fonts("fonts", "ttf")
	, soundBuffers("sounds", "wav") 
	{
		textures.add("Push_Button/inactive", "Push_Button/inactive");
		textures.add("Push_Button/hovered", "Push_Button/hovered");
		textures.add("Push_Button/pressed", "Push_Button/pressed");
	}

	Resources& Resources::get() {
		static Resources container;
		return container;
	}
}