#pragma once
#include "..//Common.h"

namespace gltoys::ui
{
	class ImGuiWin
	{
	public:
		~ImGuiWin() {}

		ImGuiWin& operator=(const ImGuiWin&) = delete;
		ImGuiWin(const ImGuiWin&) = delete;

		void DockSpace();
		void Begin();
		void End();
		void Setup();


		static ImGuiWin& Get();
		static bool my_tool_active;
	private:
		static ImGuiWin s_Instance;
		ImGuiWin();
	private:
		bool m_DockOpen = false;
	};
}