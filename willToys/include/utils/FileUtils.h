#pragma once
#include "..//Common.h"


namespace gltoys::utils
{
	class FileUtils
	{
	public:
		static const std::string ReadFile(const std::string& filepath)
		{
			std::ifstream infile(filepath);
			if (infile)
			{
				std::stringstream strstream;
				strstream << infile.rdbuf();
				std::string result = strstream.str();
				return result;
			}
			return "";
		}

	};
}
