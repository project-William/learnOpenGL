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
			
			//bird setting
			bird_shader = new Shader("src/shader/birdVert.vert", "src/shader/birdFrag.frag");
			bird_mesh = new Mesh(bird_shader, "res/bird.png", 1);

			bird_mesh->setup(m_bird, m_TexCoord);
			bird_mesh->setvaovbo(bird_shader);

		}

		Render::~Render() {
			delete bg_mesh;
			delete bg_shader;
			delete bird_mesh;
			delete bird_shader;

		}

	
		void Render::update() {
			xscroll--;
			if (-xscroll % 2000 == 0) map++;
			
		}

		void Render::render(Window& window) {
			for (int i = map; i < map+4; i++) {
				trans_background = math::Matrix4f::translate(math::Vec3(i * 1.0f + xscroll*0.0005f , 0.0f, 0.0f));
				bg_shader->setMat4("translate", trans_background);
				bg_mesh->bind();
			}
			
			if (glfwGetKey(window.getWindow(), GLFW_KEY_A))
				birdPos.x -= 0.003f;
			if (glfwGetKey(window.getWindow(), GLFW_KEY_W))
				birdPos.y += 0.003f;
			if (glfwGetKey(window.getWindow(), GLFW_KEY_S))
				birdPos.y -= 0.003f;
			if (glfwGetKey(window.getWindow(), GLFW_KEY_D))
				birdPos.x += 0.003f;

			trans_bird = math::Matrix4f::translate(math::Vec3(birdPos.x, birdPos.y , 0.0f));
			bird_shader->setMat4("translate", trans_bird);
			bird_mesh->bind();
			
		}
	}
}