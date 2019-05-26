#include "Pipes.h"


namespace flappy {
	namespace graphics {
		
		
		Pipes::Pipes() {
			pipe_shader = new Shader("src/shader/pipeVert.vert", "src/shader/pipeFrag.frag");
			pipe_mesh = new Mesh(pipe_shader, "res/pipe.jpg", 1);

			pipe_mesh->setup(m_Pipes, m_TexCoord);
			pipe_mesh->setvaovbo(pipe_shader);

		}

		Pipes::~Pipes() {
			delete pipe_mesh;
			delete pipe_shader;
		}

		void Pipes::setup(math::Matrix4f& mat4) {
			pipe_shader->setMat4("pipeview", mat4);
		}
	
		void Pipes::use() {
			
			pipe_mesh->bind();
		}
	}
}