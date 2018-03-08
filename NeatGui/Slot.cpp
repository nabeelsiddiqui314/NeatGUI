#include "stdafx.h"
#include "Slot.h"

namespace nt {
	void Slot::setSlot(const std::function<void()>& slot) {
		m_slot = slot;
	}

	void Slot::callSlot() {
		m_slot();
	}

	bool Slot::isSlotSet() {
		return m_slot != nullptr;
	}
}
