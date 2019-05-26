#pragma once
#include <glad/glad.h>	
#include <vector>
#include "math/Vec3.h"
#include "math/Vec2.h"
#include "graphics/Shader.h"
#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"
#include "Texture.h"

namespace flappy {
	namespace graphics {
		
		class Mesh {
		private:
			VertexArray* vao;
			VertexBuffer* vbo;
			VertexBuffer* tbo;
			Texture* tex;
			unsigned int texture;
			std::string m_Filepath;

			std::vector<float> m_Position;
			std::vector<float> m_TexCoord;
		
			int m_Index;
		public:
			Mesh(Shader* shader,const std::string& filepath,int index);
			Mesh& operator=(const Mesh& other) = delete;
			Mesh(const Mesh& other) = delete;
			~Mesh();
			
			void setup(std::vector<float>& vertices,std::vector<float>& texcoord);
			void setvaovbo(Shader* shader);
			void bind();

		};

	}
}


