#pragma once
#include <fstream>
#include <sstream>
#include <string>

namespace utils {
	class FileUtils {
	public:
		static std::string read_file(const std::string& filepath) {
			std::ifstream infile(filepath);
			std::stringstream stream;

			if (!infile.is_open())
				throw std::runtime_error("Unable to open file" + filepath);
			stream << infile.rdbuf();
			return stream.str();
		}
	};
}