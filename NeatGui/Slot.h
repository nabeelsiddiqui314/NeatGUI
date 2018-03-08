#pragma once
#include <functional>

namespace nt {
	class Slot {
	private:
		std::function<void()> m_slot = nullptr;
	public:
		void setSlot(const std::function<void()>& slot);
		void callSlot();
		bool isSlotSet();
	};
}