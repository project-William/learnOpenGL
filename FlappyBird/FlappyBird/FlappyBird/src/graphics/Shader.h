#pragma once
#include <glad/glad.h>
#include "utils/FileUtils.h"

namespace flappy {
	namespace graphics {
		struct ParseShader {
			std::string vertexShader;
			std::string fragmentShader;
		};

		class Shader {
		private:
			ParseShader m_ShaderSource;
			unsigned int m_Program;
			std::string m_v_Filepath;
			std::string m_f_Filepath;
		public:
			Shader():m_Program(0) {}
			~Shader() {}
			Shader(const std::string& v_filepath, const std::string& f_filepath);
			void useProgram()const;
		private:
			ParseShader getShaderSource();
			unsigned int compileShader(unsigned int shaderType, const std::string& shadersource);
			unsigned int createProgram();

		};
	}
}


