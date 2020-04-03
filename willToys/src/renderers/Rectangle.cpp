#include "renderers/Rectangle.h"

namespace gltoys::renderer
{
	Rectangle::Rectangle()
	{
		m_VertexArray = std::shared_ptr<opengl::VertexArray>
			(new opengl::VertexArray(sizeof(float) * m_RectData.size(), &m_RectData[0]));
		m_Layout =
		{
			{ opengl::ShaderDataType::FLOAT3, "a_VertexPos" },
			{ opengl::ShaderDataType::FLOAT2, "a_TexCoords" },
			{ opengl::ShaderDataType::FLOAT3, "a_Normals" }
		};
		m_VertexArray->AddBufferLayout(m_Layout);
	}

	Rectangle::~Rectangle()
	{

	}

	std::string Rectangle::GetRendererName()const
	{
		return "Rectangle";
	}

	void Rectangle::BindVAO()const
	{
		m_VertexArray->BindVertexArray();
	}

	void Rectangle::Draw()const
	{
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void Rectangle::SetMVP(std::function<void()> func)
	{
		func();
	}
}


