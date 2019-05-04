#pragma once
#include <string>	
#include <fstream>
#include <sstream>
#include "Origin/Core.h"
namespace origin {
	namespace utils {
		class ORIGIN_API FileUtil {
		public:
			static std::string read_file(const std::string& filepath) {
				std::ifstream stream(filepath);
				std::string line;
				std::stringstream sstream;
				while (std::getline(stream,line))
				{
					sstream << line <<'\n';
				}
		
				return sstream.str();
			}
		};
	}
}