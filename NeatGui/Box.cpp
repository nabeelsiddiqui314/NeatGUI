#include "stdafx.h"
#include "Box.h"

namespace nt {
	Box::Box(const Layout& layout, int spacing, int border)
	: m_layout(layout)
	, m_spacing(spacing)
	, m_border(border)
	{
		m_box.setSize({ 50.0f, 50.0f});
		m_box.setPosition(0, 0);
		ThemeContainer::applyToOne("Box", m_box);
		m_nextPos.x = m_box.getPosition().x + m_border;
		m_nextPos.y = m_box.getPosition().y + m_border;
	}

	void Box::setPosition(int x, int y) {
		m_nextPos.x += x;
		m_nextPos.y += y;

		if (m_children.size() > 0) {
			int xDiff = x - m_box.getPosition().x;
			int yDiff = y - m_box.getPosition().y;

			for (auto& child : m_children) {
				child->setPosition(child->getPosition().x + xDiff, child->getPosition().y + yDiff);
			}
		}
		m_box.setPosition(x, y);
	}

	void Box::setSize(int x, int y) {
		m_box.setSize({(float)x, (float)y});
	}

	const sf::Vector2f& Box::getPosition() const {
		return m_box.getPosition();
	}

	const sf::Vector2f& Box::getSize() const {
		return m_box.getSize();
	}

	void Box::add(Widget* child, bool autoPosition) {
		m_children.emplace_back(child);
		child->setPosition(m_nextPos.x, m_nextPos.y);

		auto& boxPos = m_box.getPosition();
		auto& boxSize = m_box.getSize();
		auto& childPos = child->getPosition();
		auto& childSize = child->getSize();

		if (autoPosition) {
			switch (m_layout) {
			case Layout::VERTICAL:
				m_nextPos.x = boxPos.x + m_border;
				m_nextPos.y = childPos.y + childSize.y + m_spacing;
				break;
			case Layout::HORIZONTAL:
				m_nextPos.x = childPos.x + childSize.x + m_spacing;
				m_nextPos.y = boxPos.y + m_border;
			}
		}
		else {
			child->setPosition(child->getPosition().x + m_box.getPosition().x, child->getPosition().y + m_box.getPosition().y);
		}
	}

	void Box::update() {
		for (auto& child : m_children)
			child->update();
	}

	void Box::render() {
		window::get()->draw(m_box);
		for (auto& child : m_children)
			child->render();
	}

	Box::~Box()
	{
	}
}