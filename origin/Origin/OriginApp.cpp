#include "OriginApp.h"

namespace origin {

	OriginApp::OriginApp() {
		window = std::make_shared<graphics::Window>(800, 600, "w");
	}


	OriginApp::~OriginApp() {
	}

	void OriginApp::run() {
		while (!window->close())
		{
			window->update();
		}
	}

}

