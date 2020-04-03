#pragma once
#include "..//Common.h"

namespace gltoys::events
{
	enum class EventType
	{
		NONE_EVENT = 0,
		WINDOW_RESIZE,
		WINDOW_CLOSE,
		WINDOW_MOVE,
		MOUSE_MOVE,
		MOUSE_BUTTON,
		MOUSE_PRESS,
		MOUSE_RELEASE,
		MOUSE_SCROLL,
		KEYBOARD,
		KEY_PRESS,
		KEY_RELEASE,
		KEY_TYPE
	};


	enum EventCategory
	{
		NONE_CG = 0,
		EVENT_CATEGORY_INPUT = TWO_SQUARE(0),
		EVENT_CATEGORY_MOUSE = TWO_SQUARE(1),
		EVENT_CATEGORY_MOUSE_BUTTON = TWO_SQUARE(2),
		EVENT_CATEGORY_KEYBOARD = TWO_SQUARE(3),
		EVENT_CATEGORY_WINDOW = TWO_SQUARE(4),
		EVENT_CATEGORY_GUI = TWO_SQUARE(5)
	};


	class Event
	{
	public:
		friend class EventDispatcher;
		Event() {}
		virtual ~Event() {}
		static EventType GetStaticEventType() { return EventType::NONE_EVENT; }
		virtual EventType GetEventType()const = 0;
		virtual const char* GetEventName()const = 0;
		virtual int GetCategoryFlags()const = 0;

		virtual const std::string To_String()const { return GetEventName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:

		bool m_Handled = false;

	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEventType() {return EventType::##type;}\
		virtual EventType GetEventType() const override { return GetStaticEventType(); }

#define EVENT_NAME_TYPE(type) virtual const char* GetEventName() const override { return #type; }

#define EVENT_CATEGORY_TYPE(category) virtual int GetCategoryFlags()const override { return category; }

	class EventDispatcher
	{
	private:
		Event& m_Event;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{

		}


		//dispatcher the event to the appropriate listener
		template<typename T>
		bool Dispatch(std::function<bool(T&)> efunc)
		{
			if (!m_Event.m_Handled && m_Event.GetEventType() == T::GetStaticEventType())
			{

				m_Event.m_Handled = efunc(*(T*)&m_Event);
				return true;
			}

			return false;
		}

	};
}