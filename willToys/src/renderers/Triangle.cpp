#include "renderers/Triangle.h"

namespace gltoys::renderer
{
	Triangle::Triangle()
	{
		m_VertexArray = std::shared_ptr<opengl::VertexArray>
			(new opengl::VertexArray(sizeof(float) * m_TriData.size(), &m_TriData[0]));
		m_Layout =
		{
			{ opengl::ShaderDataType::FLOAT3, "a_VertexPos" },
			{ opengl::ShaderDataType::FLOAT2, "a_TexCoords" },
			{ opengl::ShaderDataType::FLOAT3, "a_Normals" }
		};
		m_VertexArray->AddBufferLayout(m_Layout);
	}

	Triangle::~Triangle()
	{
	}

	std::string Triangle::GetRendererName()const
	{
		return "Triangle";
	}

	void Triangle::BindVAO()const
	{
		m_VertexArray->BindVertexArray();
	}

	void Triangle::Draw()const
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Triangle::SetMVP(std::function<void()> func)
	{
		func();
	}
}