#pragma once
#include <SFML/Graphics.hpp>
#include "Widget.h"
#include "Slot.h"
#include "Label.h"

namespace nt {
	class PushButton : public Widget, public Slot
	{
	public:
		PushButton(const std::string& label = "", const std::function<void()>& slot = nullptr);
		~PushButton();
	public:
		void setLabel(const std::string& label);
		const std::string& getLabel() const;
		void update() override;
		void render() override;
		void setPosition(int x, int y) override;
		void setSize(int x, int y) override;
	private:
		Label m_label;
	};
}