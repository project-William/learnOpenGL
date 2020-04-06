#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gltoys
{
	Application Application::s_Instance;

	Application& Application::Get()
	{
		return s_Instance;
	}

	void Application::RegisteEvents()
	{
		m_Window.SetEventCallback(BIND_EVENT(Application::OnEvent));
	}

	void Application::setUpObjects()
	{
		m_Camera = std::shared_ptr<utils::Camera>(new utils::Camera(glm::vec3(0.0f, 0.0f, 10.0f)));

		m_Rect = std::shared_ptr<renderer::Rectangle>(new renderer::Rectangle());
		m_Tri = std::shared_ptr<renderer::Triangle>(new renderer::Triangle());
		m_Cube = std::shared_ptr<renderer::Cube>(new renderer::Cube());
		m_Sphere = std::shared_ptr<renderer::Sphere>(new renderer::Sphere());
		m_Shader = std::shared_ptr<opengl::Shader>
			(new opengl::Shader("shaders/basic.vert", "shaders/basic.frag", opengl::ShaderType::BASIC));

		m_SetWin = std::shared_ptr<ui::ImGuiSetWin>(new ui::ImGuiSetWin());

		//set up imgui
		ui::ImGuiWin::Setup();
	}

	void Application::Run()
	{
		setUpObjects();

		glm::mat4 projection;
		glm::mat4 view;
		glm::mat4 model;
		

		while (!m_Window.Closed())
		{
			m_Window.Clear();
			m_Window.ClearColor();
		
			m_Camera->EnableInputEvent();
		
			m_Cube->BindVAO();
			m_Shader->BindShaderProgram();


			projection = m_Camera->GetProjectionMatrix(45.0f);
			view = m_Camera->GetViewMatrix();
			model = glm::mat4(1.0f);
		
			m_Shader->SetMat4("projection", projection);
			m_Shader->SetMat4("view", view);
			m_Shader->SetMat4("model", model);
		
			m_Cube->Draw();

			ui::ImGuiWin::Begin();
			m_SetWin->GuiContent();
			ui::ImGuiWin::End();
		
		
			m_Window.OnUpdate();
		}
	}

	Application::Application()
		:m_Window(Window::Get()),
		m_Keyboard(utils::Keyboard::Get()),
		m_Mouse(utils::Mouse::Get())
	{
		
	}



	void Application::OnEvent(events::Event& e)
	{
		bool handled = false;
		events::EventDispatcher dispatcher(e);

		if (e.IsInCategory(events::EVENT_CATEGORY_WINDOW))
		{
			if (!handled)
			{
				handled = dispatcher.Dispatch<events::WindowResizedEvent>(BIND_EVENT(Application::OnWindowResizedEvent));
			}

			if (!handled)
			{
				handled = dispatcher.Dispatch<events::WindowClosedEvent>(BIND_EVENT(Application::OnWindowClosedEvent));
			}

			if (!handled)
			{
				handled = dispatcher.Dispatch<events::WindowMovedEvent>(BIND_EVENT(Application::OnWindowMovedEvent));
			}
		}

		else if (e.IsInCategory(events::EVENT_CATEGORY_KEYBOARD))
		{
			if (!handled)
			{
				handled = dispatcher.Dispatch<events::KeyPressedEvent>(BIND_EVENT(Application::OnKeyPressedEvent));
			}

			if (!handled)
			{
				handled = dispatcher.Dispatch<events::KeyReleasedEvent>(BIND_EVENT(Application::OnKeyReleasedEvent));
			}

		}

		else if (e.IsInCategory(events::EVENT_CATEGORY_MOUSE))
		{
			if (!handled)
			{
				handled = dispatcher.Dispatch<events::MouseMovedEvent>(BIND_EVENT(Application::OnMouseMovedEvent));
			}

			if (!handled)
			{
				handled = dispatcher.Dispatch<events::MousePressedEvent>(BIND_EVENT(Application::OnMouseButtonPressed));
			}

			if (!handled)
			{
				handled = dispatcher.Dispatch<events::MouseRelasedEvent>(BIND_EVENT(Application::OnMouseButtonReleased));
			}

			if (!handled)
			{
				handled = dispatcher.Dispatch<events::MouseScrollEvent>(BIND_EVENT(Application::OnMouseScrollEvent));
			}
		}
	}

	bool Application::OnWindowResizedEvent(events::WindowResizedEvent& e)
	{
		m_Window.OnWindowResized();
		m_WindowResized_flag = true;
		return true;
	}

	bool Application::OnWindowClosedEvent(events::WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowMovedEvent(events::WindowMovedEvent& e)
	{
		return true;
	}

	bool Application::OnMouseButtonPressed(events::MousePressedEvent& e)
	{
		utils::Mouse::GetMouseInstance().OnEvent(e);
		return true;
	}

	bool Application::OnMouseButtonReleased(events::MouseRelasedEvent& e)
	{
		utils::Mouse::GetMouseInstance().OnEvent(e);
		return true;
	}

	bool Application::OnMouseMovedEvent(events::MouseMovedEvent& e)
	{
		utils::Mouse::GetMouseInstance().OnEvent(e);
		return true;
	}

	bool Application::OnMouseScrollEvent(events::MouseScrollEvent& e)
	{
		utils::Mouse::GetMouseInstance().OnEvent(e);
		return true;
	}

	bool Application::OnKeyPressedEvent(events::KeyPressedEvent& e)
	{
		utils::Keyboard::GetKeyboardInstance().OnEvent(e);
		return true;
	}

	bool Application::OnKeyReleasedEvent(events::KeyReleasedEvent& e)
	{
		utils::Keyboard::GetKeyboardInstance().OnEvent(e);
		return true;
	}
}