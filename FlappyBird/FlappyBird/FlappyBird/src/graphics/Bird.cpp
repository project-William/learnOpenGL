#include "Bird.h"

namespace flappy {
	namespace graphics {


		Bird::Bird()
			:bird_shader(nullptr),bird_mesh(nullptr)
		{

			bird_shader = new Shader("src/shader/birdVert.vert", "src/shader/birdFrag.frag");
			bird_mesh = new Mesh(bird_shader, "res/bird.png", 1);

			bird_mesh->setup(m_bird, m_TexCoord);
			bird_mesh->setvaovbo(bird_shader);
		}

		void Bird::use(Window& window) {
			if (glfwGetKey(window.getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
				bd_pos.y += 0.002f;
				count = 0;
				rot_bird = math::Matrix4f::rotate(-5.0f);
			}
			else {
				rot_bird = math::Matrix4f::rotate(count * 0.04f);
			}
			count++;
			bd_pos.y -= (float)0.05f * powf(sqrt(count) * 0.006f, 2.1f);
			trans_bird = math::Matrix4f::translate(math::Vec3(0, bd_pos.y, 0.0f));
			view_bird = math::multiply(trans_bird, rot_bird);
			bird_shader->setMat4("birdview", view_bird);
			bird_mesh->bind();
		}

		Bird::~Bird() {
			delete bird_mesh;
			delete bird_shader;
		}
	}
}