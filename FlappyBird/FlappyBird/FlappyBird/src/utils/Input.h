#pragma once
#include "graphics/Window.h"

namespace flappy {
	namespace utils {

		class Input {
		public:
			Input() {}
			void processInput(graphics::Window& window);
			~Input(){}
		};
	}
}