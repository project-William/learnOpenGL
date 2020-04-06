#include "gui/ImguiSetWin.h"


namespace gltoys::ui
{
	bool ImGuiSetWin::open = true;
	bool ImGuiSetWin::isCube = true;
	bool ImGuiSetWin::isRect = true;
	bool ImGuiSetWin::isSphere = true;
	bool ImGuiSetWin::isTri = true;

	void ImGuiSetWin::SetWin(std::function<void()> func)
	{
		ImGui::Begin("Setting",&open);
		func();
		ImGui::End();
	}

	void ImGuiSetWin::GuiContent()
	{
		ImGui::Checkbox("cube",&isCube);
		
	}

	void ImGuiSetWin::GetRenderers(std::shared_ptr<renderer::Renderer> renderer)
	{
		m_RendererMap.insert(std::make_pair(renderer->GetRendererName(), renderer));
	}

	
}