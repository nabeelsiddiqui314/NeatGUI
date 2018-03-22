#pragma once
#include "Widget.h"

namespace nt {
	enum class Mode {
		ENABLED,
		DISABLED
	};
	class CheckBox : public Widget
	{
	public:
		CheckBox(const Mode& mode = Mode::DISABLED);
		~CheckBox();
	public:
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;
		void update() override;
		void render() override;
		bool isActive() const;
	private:
		sf::RectangleShape m_checkMark;
		bool               m_isActive;
	};
}