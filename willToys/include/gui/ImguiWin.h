#pragma once
#include "..//Common.h"

namespace gltoys::ui
{
	struct ImGuiWin
	{
		static void Begin();
		static void End();
		static void Setup();

		bool m_DockOpen = false;
	};
}