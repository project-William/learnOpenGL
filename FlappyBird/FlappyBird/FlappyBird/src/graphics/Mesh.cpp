#include "Mesh.h"

namespace flappy {
	namespace graphics {
		Mesh::Mesh(Shader* shader,const std::string& filepath, int index) 
			:m_Filepath(filepath),m_Index(index),
			vao(nullptr), vbo(nullptr), tbo(nullptr), tex(nullptr)
		{
		}

		Mesh::~Mesh() {
			delete vao;
			delete vbo;
			delete tex;
			delete tbo;
		}


		void Mesh::setup(std::vector<float>& vertices, std::vector<float>& texcoord) {
			m_Position = vertices;
			m_TexCoord = texcoord;
		}

		void Mesh::setvaovbo(Shader* shader) {
			//vao
			vao = new VertexArray();
			vao->bind();
			//vbo
			vbo = new VertexBuffer(m_Position.size(), &m_Position[0]);
			vbo->bind();

			tex = new Texture(m_Filepath,m_Index);
			texture = tex->getTexture();

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(math::Vec3), 0);
			glEnableVertexAttribArray(0);

			tbo = new VertexBuffer(m_TexCoord.size(), &m_TexCoord[0]);
			tbo->bind();

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(math::Vec2), 0);
			glEnableVertexAttribArray(1);

			shader->setInt("texture1", texture);
			shader->enableProgram();
		}

		void Mesh::bind() {
			vao->bind();
			tbo->bind();
			glBindTexture(GL_TEXTURE_2D, texture);
			glActiveTexture(GL_TEXTURE0);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			vao->unbind();
			tbo->unbind();
		}
	}
}
