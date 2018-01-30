#include "stdafx.h"
#include "Resources.h"

namespace nt {
	Resources::Resources() 
	: textures("textures", "png")
	, fonts("fonts", "ttf")
	, soundBuffers("sounds", "ogg") {

	}

	Resources& Resources::get() {
		static Resources container;
		return container;
	}
}