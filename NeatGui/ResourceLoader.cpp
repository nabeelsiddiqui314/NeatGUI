#include "stdafx.h"
#include "ResourceLoader.h"

namespace nt {
	ResourceLoader::ResourceLoader() {

	}

	void ResourceLoader::addTexture(const std::string& filepath, const std::string& name) {
		sf::Texture tex;
		tex.loadFromFile(filepath);
		m_textures[name] = tex;
	}

	void ResourceLoader::addFont(const std::string& filepath, const std::string& name) {
		sf::Font font;
		font.loadFromFile(filepath);
		m_fonts[name] = font;
	}

	void ResourceLoader::addSoundBuffer(const std::string& filepath, const std::string& name) {
		sf::SoundBuffer sound;
		sound.loadFromFile(filepath);
		m_soundBuffers[name] = sound;
	}

	const sf::Texture& ResourceLoader::getTexture(const std::string& name) const {
		return m_textures.at(name);
	}

	const sf::Font& ResourceLoader::getFont(const std::string& name) const {
		return m_fonts.at(name);
	}

	const sf::SoundBuffer& ResourceLoader::getSoundBuffer(const std::string& name) const {
		return m_soundBuffers.at(name);
	}

	ResourceLoader::~ResourceLoader() {
		m_textures.clear();
		m_fonts.clear();
		m_soundBuffers.clear();
	}
}