#pragma once
#include "ImguiWin.h"
#include "renderers/Rectangle.h"
#include "renderers/Cube.h"
#include "renderers/Sphere.h"
#include "renderers/Triangle.h"

namespace gltoys::ui
{
	class ImGuiSetWin
	{
	public:

		static bool open;
		static bool isCube;
		static bool isTri;
		static bool isRect;
		static bool isSphere;
		static void SetWin(std::function<void()> func);

		void GuiContent();

		void GetRenderers(std::shared_ptr<renderer::Renderer> renderer);

	private:
		std::unordered_map<std::string, std::shared_ptr<renderer::Renderer>> m_RendererMap;

	};

	



}