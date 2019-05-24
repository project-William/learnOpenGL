#pragma once
#include <string>	
#include <iostream>	
#include <fstream>
#include <sstream>

//read files
namespace flappy {
	namespace utils {
		class FileUtils {
		public:
			static std::string readFile(const std::string& filepath) {
				std::ifstream infile(filepath);
				if (!infile.is_open())
					throw std::runtime_error("Unable to open the file:" + filepath + "!");
				std::stringstream stream;
				stream << infile.rdbuf();
				return stream.str();
			}
		};
	}
}
