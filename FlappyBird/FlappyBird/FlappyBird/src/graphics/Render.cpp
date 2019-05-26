#include "Render.h"
namespace flappy {
	namespace graphics {
		Render::Render() {
			//background setting
			bg_shader = new Shader("src/shader/backgroundVert.vert", "src/shader/backgroundFrag.frag");
			bg_mesh = new Mesh(bg_shader,"res/bg.jpeg", 0);

			bg_mesh->setup(m_background, m_TexCoord);
			bg_mesh->setvaovbo(bg_shader);
			
			//bird setting
			bird_shader = new Shader("src/shader/birdVert.vert", "src/shader/birdFrag.frag");
			bird_mesh = new Mesh(bird_shader, "res/bird.png", 1);

			bird_mesh->setup(m_bird, m_TexCoord);
			bird_mesh->setvaovbo(bird_shader);


			

			//pipes settings
			for (int i = 0; i < 8; i+=2) {
				pipes_shader.push_back(new Shader("src/shader/pipeVert.vert", "src/shader/pipeFrag.frag"));
			}
			
			for (int i = 1; i < 8; i+=2) {
				pipes_shader.push_back(new Shader("src/shader/pipeVert.vert", "src/shader/pipeFrag.frag"));
			}

			for (int i = 0; i < 8; i+=2) {
				pipes_mesh.push_back(new Mesh(pipes_shader[i], "res/pipe.jpg", 1));
			}

			for (int i = 1; i < 8; i+=2) {
				pipes_mesh.push_back(new Mesh(pipes_shader[i], "res/pipe.jpg", 1));
			}

			for (int i = 0; i < 8; i+=2) {
				pipes_mesh[i]->setup(m_Pipes, m_TexCoord);
				pipes_mesh[i]->setvaovbo(pipes_shader[i]);
			}

			for (int i = 1; i < 8; i+=2) {
				pipes_mesh[i]->setup(m_Pipes, m_TexCoord);
				pipes_mesh[i]->setvaovbo(pipes_shader[i]);
			}
			


		}

		Render::~Render() {
			delete bg_mesh;
			delete bg_shader;
			delete bird_mesh;
			delete bird_shader;
		


		 	for (int i = 0; i < pipes_mesh.size(); i++)
				delete pipes_mesh[i];

			for (int i = 0; i < pipes_shader.size(); i++)
				delete pipes_shader[i];
			
			for (int i = 0; i < pipes_mesh1.size(); i++)
				delete pipes_mesh1[i];

			for (int i = 0; i < pipes_shader1.size(); i++)
				delete pipes_shader1[i];
			
		
		}

	
		void Render::update() {
			xscroll--;
			pipeRef--;
			if (-xscroll % 2000 == 0) map++;
			//std::cout << -xscroll << std::endl
		}

		void Render::renderBackground() {
			//background

			for (int i = map; i < map + 4; i++) {
				trans_background = math::Matrix4f::translate(math::Vec3(i * 1.0f + xscroll * 0.0005f, 0.0f, 0.0f));
				bg_shader->setMat4("translate", trans_background);
				bg_mesh->bind();
			}
		}


		void Render::renderPipes() {

			if (-pipeRef == 8000) {
				pipeRef = 0;
			}
			else {
				for (int j = 0; j < pipes_shader.size(); j+=2) {

					trans_pipes = math::Matrix4f::translate(math::Vec3(pipeRef * 0.0005f + (j/2) * 0.5f, -0.3f+0.0f, 0.0f));
					pipes_shader[j]->setMat4("pipeview", trans_pipes);
					pipes_mesh[j]->bind();
				}
				
				for (int j = 1; j < pipes_shader.size(); j+=2) {

					trans_pipes = math::Matrix4f::translate(math::Vec3( 2.25f + pipeRef * 0.0005f + (j-1)/2 * 0.5f, 1.0f+0.0f, 0.0f));
					rot_pipes = math::Matrix4f::rotate(180.0f);
					pipes_view = math::multiply(trans_pipes, rot_pipes);
					pipes_shader[j]->setMat4("pipeview", pipes_view);
					pipes_mesh[j]->bind();
				}
			}
		}

		void Render::renderBird(Window& window) {

			if (glfwGetKey(window.getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
				bd_pos.y += 0.004f;
				count = 0;
				rot_bird = math::Matrix4f::rotate(-35.0f);
			}
			else {
				rot_bird = math::Matrix4f::rotate(count*0.13f);
			}
			count++;
			bd_pos.y -= (float)0.5f * powf(sqrt(count) * 0.006f, 2.1f);
			trans_bird = math::Matrix4f::translate(math::Vec3(0, bd_pos.y, 0.0f));
			bird_view = math::multiply(trans_bird, rot_bird);
			bird_shader->setMat4("birdview", bird_view);
			bird_mesh->bind();
		}

		
	}
}