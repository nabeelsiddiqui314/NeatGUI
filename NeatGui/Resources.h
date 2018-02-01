#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceLoader.h"

namespace nt {
	class Resources
	{
		Resources();
	public:
		~Resources() {}
	public:
		static Resources& get();

		ResourceLoader<sf::Texture>     textures;
		ResourceLoader<sf::Font>        fonts;
		ResourceLoader<sf::SoundBuffer> soundBuffers;
	};

}