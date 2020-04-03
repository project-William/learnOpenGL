#pragma once
#include "Event.h"

namespace gltoys::events
{

	class WindowResizedEvent :public Event
	{
	private:
		size_t m_Width, m_Height;

	public:

		WindowResizedEvent() :m_Width(0), m_Height(0) {}
		WindowResizedEvent(size_t width, size_t height)
			:m_Width(width), m_Height(height)
		{
			glViewport(0, 0, width, height);
		}
		~WindowResizedEvent() {}

		const size_t GetWidth()const { return m_Width; }
		const size_t GetHeight()const { return m_Height; }

		EVENT_CLASS_TYPE(WINDOW_RESIZE)
		EVENT_NAME_TYPE(WINDOW_RESIZE)

		EVENT_CATEGORY_TYPE(EVENT_CATEGORY_WINDOW)
	};


	class WindowClosedEvent :public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WINDOW_CLOSE)
		EVENT_NAME_TYPE(WINDOW_CLOSE)

		EVENT_CATEGORY_TYPE(EVENT_CATEGORY_WINDOW)
	};


	class WindowMovedEvent :public Event
	{
	private:
		int32_t m_Xpos, m_Ypos;
	public:
		WindowMovedEvent(int xpos, int ypos)
			:m_Xpos(xpos), m_Ypos(ypos)
		{

		}

		int32_t GetWindowXpos()const { return m_Xpos; }
		int32_t GetWindowYpos()const { return m_Ypos; }


		EVENT_CLASS_TYPE(WINDOW_MOVE)
		EVENT_NAME_TYPE(WINDOW_MOVE)
		EVENT_CATEGORY_TYPE(EVENT_CATEGORY_WINDOW)
	};
}
