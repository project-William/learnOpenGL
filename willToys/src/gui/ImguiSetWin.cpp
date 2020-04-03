#include "gui/ImguiSetWin.h"


namespace gltoys::ui
{
	void ImGuiSetWin::SetWin(std::function<void()> func)
	{
		ImGui::Begin("Setting",&open);
		func();
		ImGui::End();
	}

	void ImGuiSetWin::GuiContent()
	{

	}

	
}