#pragma once
#include "Widget.h"
#include "Slot.h"
#include "Label.h"

namespace nt {
	enum class Mode {
		ENABLED,
		DISABLED
	};
	class CheckBox : public Widget, public Slot
	{
	public:
		CheckBox(const Mode& mode = Mode::DISABLED, const std::string& label = "CheckBox", const std::function<void()>& slot = nullptr);
		~CheckBox();
	public:
		void setLabel(const std::string& label);
		void setCharacterSize(unsigned int size);
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;
		const sf::Vector2f& getSize() const override;
		void update() override;
		void render() override;
		bool isActive() const;
	private:
		sf::RectangleShape m_checkMark;
		Label              m_label;
		bool               m_isActive;
	};
}