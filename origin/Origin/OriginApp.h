#pragma once

#include "src/Origin.h"
#include <memory>
namespace origin {

	class ORIGIN_API OriginApp
	{
	private:
		std::shared_ptr<graphics::Window> window;
	public:
		OriginApp();
		void run();
		~OriginApp();
	};

}


