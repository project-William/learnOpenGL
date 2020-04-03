#include "renderers/Cube.h"

namespace gltoys::renderer
{
	Cube::Cube()
	{
		m_VertexArray = std::shared_ptr<opengl::VertexArray>
			(new opengl::VertexArray(sizeof(float) * m_CubeData.size(), &m_CubeData[0]));
		m_Layout =
		{
			{ opengl::ShaderDataType::FLOAT3, "a_VertexPos" },
			{ opengl::ShaderDataType::FLOAT2, "a_TexCoords" },
			{ opengl::ShaderDataType::FLOAT3, "a_Normals" }
		};

		m_VertexArray->AddBufferLayout(m_Layout);
	}

	Cube::~Cube()
	{ }

	void Cube::BindVAO() const
	{
		m_VertexArray->BindVertexArray();
	}

	void Cube::Draw() const
	{
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	void Cube::SetMVP(std::function<void()> func)
	{
		func();
	}
}