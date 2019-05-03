#pragma once
#include <stdio.h>
#include <string>	

namespace origin {
	namespace utils {
		std::string readFile(const std::string& filepath) {

			FILE* read_file;
			read_file = fopen(filepath.c_str(), "r");


		}

	}
}