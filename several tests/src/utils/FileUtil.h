#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileUtil {
public:

	static std::string read_file(const std::string& filepath) {
		std::ifstream infile(filepath);
		std::stringstream stream;
		if (!infile.is_open())
			throw std::runtime_error("Unable to open the file!" + filepath);
		else {
			stream << infile.rdbuf();
			return stream.str();
		}
	}
};



