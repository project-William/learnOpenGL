#pragma once
#include "ToyHeaders.h"
#include "Window.h"

namespace gltoys
{
	class Application
	{
	public:
		~Application() {}
		void Run();
		static Application& Get();
		void RegisteEvents();
	private:
		static Application s_Instance;
		Application();

		
	private:
		std::shared_ptr<renderer::Rectangle> m_Rect;
		std::shared_ptr<utils::Camera> m_Camera;
		std::shared_ptr<opengl::Shader> m_Shader;
	private:
		Window& m_Window;
		utils::Keyboard& m_Keyboard;
		utils::Mouse& m_Mouse;

		void OnEvent(events::Event& e);

		bool OnWindowResizedEvent(events::WindowResizedEvent& e);
		bool OnWindowClosedEvent(events::WindowClosedEvent& e);
		bool OnWindowMovedEvent(events::WindowMovedEvent& e);

		bool OnMouseButtonPressed(events::MousePressedEvent& e);
		bool OnMouseButtonReleased(events::MouseRelasedEvent& e);
		bool OnMouseMovedEvent(events::MouseMovedEvent& e);
		bool OnMouseScrollEvent(events::MouseScrollEvent& e);

		bool OnKeyPressedEvent(events::KeyPressedEvent& e);
		bool OnKeyReleasedEvent(events::KeyReleasedEvent& e);

		bool m_WindowResized_flag = false;
		bool m_Running = true;
	};
}