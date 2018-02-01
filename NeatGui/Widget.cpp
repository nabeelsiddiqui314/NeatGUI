#include "stdafx.h"
#include "Widget.h"

namespace nt {
	Widget::Widget(const std::string& texture, std::array<sf::IntRect, 3> texCoords)
		: m_texture(texture)
		, m_texCoords(texCoords) 
	{

	}


	Widget::~Widget()
	{
	}
}