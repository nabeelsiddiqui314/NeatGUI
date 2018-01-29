#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

namespace nt {
	class ResourceLoader
	{
	public:
		ResourceLoader();
		~ResourceLoader();
	public:
		void addTexture(const std::string& filepath, const std::string& name);
		void addFont(const std::string& filepath, const std::string& name);
		void addSoundBuffer(const std::string& filepath, const std::string& name);

		const sf::Texture& getTexture(const std::string& name) const;
		const sf::Font&    getFont(const std::string& name) const;
		const sf::SoundBuffer&   getSoundBuffer(const std::string& name) const;
	private:
		std::map<std::string, sf::Texture> m_textures;
		std::map<std::string, sf::Font>    m_fonts;
		std::map<std::string, sf::SoundBuffer>   m_soundBuffers;
	};
}