#pragma once
#include "Widget.h"
#include "Slot.h"

namespace nt {
	enum class Mode {
		ENABLED,
		DISABLED
	};
	class CheckBox : public Widget, public Slot
	{
	public:
		CheckBox(const Mode& mode = Mode::DISABLED, const std::function<void()>& slot = nullptr);
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