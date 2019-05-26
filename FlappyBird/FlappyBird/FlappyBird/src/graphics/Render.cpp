#include "Render.h"

namespace flappy {
	namespace graphics {
		Render::Render() {
			//background setting
			bg_shader = new Shader("src/shader/backgroundVert.vert", "src/shader/backgroundFrag.frag");
			bg_mesh = new Mesh(bg_shader,"res/bg.jpeg", 0);

			bg_mesh->setup(m_background, m_TexCoord);
			bg_mesh->setvaovbo(bg_shader);
			//pipe setting
			pipe_shader = new Shader("src/shader/pipeVert.vert", "src/shader/pipeFrag.frag");
			pipe_mesh = new Mesh(pipe_shader, "res/pipe.jpg", 1);

			pipe_mesh->setup(m_Pipes, m_TexCoord);
			pipe_mesh->setvaovbo(pipe_shader);
			
		}

		Render::~Render() {
			delete bg_mesh;
			delete bg_shader;

			delete pipe_mesh;
			delete pipe_shader;
		}

	
		void Render::update() {
			xscroll--;
			if (-xscroll % 2000 == 0) map++;
			pipescroll--;
			if (-pipescroll % 2000 == 0) pipem++;
		}

		void Render::render() {
			for (int i = map; i < map+4; i++) {
				tran = math::Matrix4f::translate(math::Vec3(i * 1.0f + xscroll*0.0005f , 0.0f, 0.0f));
				bg_shader->setMat4("translate", tran);
				bg_mesh->bind();
			}


			for (int i = pipem; i < pipem + 4; i++) {
				trans = math::Matrix4f::translate(math::Vec3(i * 0.5f + pipescroll * 0.0005f, 0.0f, 0.0f));
				pipe_shader->setMat4("translate", trans);
				pipe_mesh->bind();
			}

		}
	}
}