#include "utils/Keyboard.h"

namespace gltoys::utils
{
	Keyboard Keyboard::s_Keyboard;

	Keyboard::Keyboard()
		:m_Keys(nullptr)
	{
		int32_t keyNums = Keys::KEY_LAST;
		m_Keys = new std::vector<bool>(keyNums);
	}

	Keyboard::~Keyboard()
	{
		delete m_Keys;
	}

	Keyboard& Keyboard::Get()
	{
		return s_Keyboard;
	}

	void Keyboard::OnEvent(events::KeyPressedEvent& event)
	{
		(*m_Keys)[event.GetKeyCode()] = true;
	}

	void Keyboard::OnEvent(events::KeyReleasedEvent& event)
	{
		(*m_Keys)[event.GetKeyCode()] = false;
	}
}