#include "stdafx.h"
#include "Slot.h"

namespace nt {
	void Slot::setSlot(const std::function<void()>& slot) {
		m_slot = slot;
	}

	void Slot::callSlot() {
		if(m_slot != nullptr)
			m_slot();
	}
}
