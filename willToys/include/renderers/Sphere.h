#pragma once
#include "Renderer.h"

namespace gltoys::renderer
{
	class Sphere :public Renderer
	{
	public:
		Sphere();
		~Sphere();

		void BindVAO()const override;
		void Draw() const override;
		std::string GetRendererName()const override { return "Sphere"; }

		void SetMVP(std::function<void()> func);
	private:
		std::shared_ptr<opengl::VertexArray> m_VertexArray;
		opengl::BufferLayout m_Layout;

		size_t m_IndexCount;
		const int32_t X_SEGMENTS;
		const int32_t Y_SEGMENTS;
		const float m_PI;
		std::vector<float> m_SphereData;
		void CreateSphere();

		std::vector<glm::vec3> m_Positions;
		std::vector<glm::vec2> m_UV;
		std::vector<glm::vec3> m_Normals;
		std::vector<uint32_t> m_Indices;
	};
}