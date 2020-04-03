#pragma once
#include "Renderer.h"

namespace gltoys::renderer
{
	class Triangle :public Renderer
	{
	public:
		Triangle();
		~Triangle();

		std::shared_ptr<opengl::VertexArray> m_VertexArray;
		opengl::BufferLayout m_Layout;

		void BindVAO()const override;
		void Draw()const override;
		std::string GetRendererName()const override;
		void SetMVP(std::function<void()> func);

	private:
		std::vector<float> m_TriData = {
			// positions        // texture Coords
			0.0f,1.0f,0.0f, 0.5f,1.0f,0.0f,0.0f,1.0f,
			-1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,
			1.0f,-1.0f,0.0f,1.0f,0.0f,0.0f,0.0f,1.0f
		};
	};
}