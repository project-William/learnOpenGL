#pragma once
#include "..//OpenGL/VertexArray.h"

namespace gltoys::renderer
{

	enum class RendererType
	{
		TRIANGLE,RECTANGLE,CUBE,SPHERE
	};

	struct Renderer
	{
		Renderer() = default;
		virtual ~Renderer() {}
		virtual std::string GetRendererName()const = 0;
		virtual void Draw()const = 0;
		virtual void BindVAO()const = 0;
	};
}