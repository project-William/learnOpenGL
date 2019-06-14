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

			for (int i = 0; i < 8; i++) {
				randomup1.push_back(rand() / double(RAND_MAX));
			}

			for (int i = 0; i < 8; i++) {
				randombottom1.push_back(rand() / double(RAND_MAX));
			}
	
			bg = new Background();
			bird = new Bird();

		}

		Render::~Render() {
			
			delete bird;
			delete bg;

			for (int i = 0; i < pipes.size(); i++) {
				delete pipes[i];
			}
			
		}

	

		void Render::renderBackground() {
			bg->use();
		}


		void Render::renderPipes() {

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

			delay--;
			if (-delay <= 4000) {

			}
 			else {
				delay = -4001;
				for (int i = 0; i < 8; i += 2) {
					translate = math::Matrix4f::translate(math::Vec3(i / 2 * 0.5f + ref1 * 0.0005f, -0.9f + randomup1[i] / 4, 0.0f));
					pipes[i]->setup(translate);
					pipes[i]->use();
				}

				for (int i = 1; i < 8; i += 2) {
					translate = math::Matrix4f::translate(math::Vec3(-3.9f + (i - 1) / 2 * 0.5f - ref1 * 0.0005f, -1.0f + randombottom1[i] / 4, 0.0f));
					rotate = math::Matrix4f::rotate(180.0f);
					view = math::multiply(rotate, translate);
					pipes[i]->setup(view);
					pipes[i]->use();
				}

				if (-ref1 % 8000 == 0) {
					ref1 = 0;
					for (int i = 0; i < 8; i++) {
						randomup1[i] = (rand() / double(RAND_MAX));
					}
					for (int i = 0; i < 8; i++) {
						randombottom1[i] = (rand() / double(RAND_MAX));
					}
				}
				ref1--;
			}
		}

		void Render::renderBird(Window& window) {
			bird->use(window);
		}

	}
}