#pragma once
#include "StaticElement.h"

namespace nt {
	class Label : public StaticElement
	{
	public:
		Label();
		~Label();
	public:
		void render() override;
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;

		void setText(const std::string& text);
		void setCharacterSize(unsigned int size);
		void setFont(const sf::Font& font);
		void setColor(const sf::Color& color);

		const std::string& getText() const;
	private:
		void repositionText();
	private:
		sf::Text m_label;
	};
}