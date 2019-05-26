#include "Render.h"
#include <random>

namespace flappy {
	namespace graphics {

		Render::Render() {
	
			//pipes
			for (int i = 0; i < 8; i++) {
				pipes.push_back(new Pipes());
			}
			//random

			for (int i = 0; i < 8; i++) {
				randomup.push_back(rand() / double(RAND_MAX));
			}
			for (int i = 0; i < 8; i++) {
				randombottom.push_back(rand() / double(RAND_MAX));
			}
			

		
			bg = new Background();
			bird = new Bird();

		}

		Render::~Render() {
			
			delete bird;
			delete bg;
		
		}

	

		void Render::renderBackground() {
			bg->use();
		}


		void Render::renderPipes() {

		/*	if (-pipeRef == 8000) {
				pipeRef = 0;
				
			}
			else {
				int a = -50;
				int b = 50;
				z = ((double)rand() / RAND_MAX) * (b - a) + a;
				for (int j = 0; j < pipes_shader.size(); j+=2) {

					trans_pipes = math::Matrix4f::translate(math::Vec3(pipeRef * 0.0005f + (j/2) * 0.5f, -0.9f+z/300, 0.0f));
					pipes_shader[j]->setMat4("pipeview", trans_pipes);
					pipes_mesh[j]->bind();
				}
				
				for (int j = 1; j < pipes_shader.size(); j+=2) {

					z = ((double)rand() / RAND_MAX) * (b - a) + a;
					trans_pipes = math::Matrix4f::translate(math::Vec3( 2.25f + pipeRef * 0.0005f + (j-1)/2 * 0.5f, z/330+1.0f+0.0f, 0.0f));
					rot_pipes = math::Matrix4f::rotate(180.0f);
					pipes_view = math::multiply(trans_pipes, rot_pipes);
					pipes_shader[j]->setMat4("pipeview", pipes_view);
					pipes_mesh[j]->bind();
				}
			}*/
			


			for (int i = 0; i < 8; i+=2) {
				translate = math::Matrix4f::translate(math::Vec3(i / 2 * 0.5f + ref * 0.0005f, -0.9f + randomup[i] / 4, 0.0f));
				pipes[i]->setup(translate);
				pipes[i]->use();
			}

			for (int i = 1; i < 8; i+=2) {
				translate = math::Matrix4f::translate(math::Vec3( -3.9f + (i-1)/2 * 0.5f - ref * 0.0005f, -1.0f+ randombottom[i] / 4, 0.0f));
				rotate = math::Matrix4f::rotate(180.0f);
				view = math::multiply(rotate, translate);
				pipes[i]->setup(view);
				pipes[i]->use();
			}

			ref--;
			if (-ref % 8000 == 0) {

				ref = 0;

				for (int i = 0; i < 8; i++) {
					randomup[i]=(rand() / double(RAND_MAX));
				}
				for (int i = 0; i < 8; i++) {
					randombottom[i]=(rand() / double(RAND_MAX));
				}
			}

		
		}

		void Render::renderBird(Window& window) {

			bird->use(window);
		}

		
	}
}