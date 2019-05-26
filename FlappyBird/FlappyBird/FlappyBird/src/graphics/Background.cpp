#include "Background.h"

namespace flappy {
	namespace graphics {

		Background::Background() {
			bg_shader = new Shader("src/shader/backgroundVert.vert", "src/shader/backgroundFrag.frag");
			bg_mesh = new Mesh(bg_shader, "res/bg.jpeg", 0);

			bg_mesh->setup(m_background, m_TexCoord);
			bg_mesh->setvaovbo(bg_shader);

		}

		Background::~Background() {
			delete bg_mesh;
			delete bg_shader;
		}

		void Background::use() {
			for (int i = map; i < map + 4; i++) {
				trans_background = math::Matrix4f::translate(math::Vec3(i * 1.0f + xscroll * 0.0005f, 0.0f, 0.0f));
				bg_shader->setMat4("translate", trans_background);
				bg_mesh->bind();
			}
			
			
			xscroll--;
			if (-xscroll % 2000 == 0) map++;
		}
	}
}