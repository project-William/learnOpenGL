#pragma once
#include "Origin/Core.h"
#include <string>
#include <glad/glad.h>
#include "Origin/utils/ReadFile.h"

namespace origin {
	namespace graphics {
		struct ParseShaderSource {
			std::string vertexShader;
			std::string fragmentShader;
		};

		class ORIGIN_API Shader {
		private:
			unsigned int m_program;
			ParseShaderSource m_Source;
		public:
			Shader() :m_program(0), m_Source({ "","" }) {}
			Shader(const std::string& v_filepath, const std::string& f_filepath);
			void bind();
			void unbind();
			void draw()const { glDrawArrays(GL_TRIANGLES, 0, 6); }
		private:
			ParseShaderSource& getSource(const std::string& v_filepath, const std::string& f_filepath);
			unsigned int compileShader(const std::string& source, unsigned int type);
			unsigned int createProgram();

		};

	}
}


