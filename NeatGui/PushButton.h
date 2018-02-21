#pragma once
#include <SFML/Graphics.hpp>
#include "Widget.h"

namespace nt {
	class PushButton : public Widget
	{
	public:
		PushButton();
		~PushButton();
	public:
		bool isClicked();
		void setLabel(const std::string& label);
		void render() override;
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;
	private:
		void repositionText();
	private:
		sf::Text m_label;
	};
}