#pragma once
#include "ImguiWin.h"

namespace gltoys::ui
{
	struct ImGuiSetWin
	{
		static bool open;
		static void SetWin(std::function<void()> func);

		void GuiContent();
	};

	bool ImGuiSetWin::open = true;


}