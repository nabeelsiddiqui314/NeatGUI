#pragma once
#include "Widget.h"

namespace nt {
	enum class Layout {
		VERTICAL,
		HORIZONTAL
	};

	class Box
	{
	public:
		Box(const Layout& layout, int spacing, int border);
		~Box();
	public:
		void setPosition(int x, int y);
		void setSize(int x, int y);
		const sf::Vector2f& getPosition() const;
		const sf::Vector2f& getSize() const;
		void add(Widget* child, bool autoPosition);
		void update();
		void render();
	private:
		sf::RectangleShape m_box;
		std::vector<Widget*> m_children;
		Layout m_layout;
		int m_spacing;
		int m_border;
		sf::Vector2i m_nextPos;
	};
}