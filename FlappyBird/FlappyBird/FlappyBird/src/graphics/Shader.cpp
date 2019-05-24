#include "Shader.h"


namespace flappy {
	namespace graphics {
		Shader::Shader(const std::string& v_filepath, const std::string& f_filepath)
			:m_f_Filepath(f_filepath), m_v_Filepath(v_filepath), m_Program(0)
		{
			m_ShaderSource = getShaderSource();
			std::cout << m_ShaderSource.vertexShader << std::endl;
			std::cout << m_ShaderSource.fragmentShader << std::endl;
		}

		void Shader::useProgram()const {
			glUseProgram(m_Program);
		}

		ParseShader Shader::getShaderSource() {
			m_ShaderSource.vertexShader = utils::FileUtils::readFile(m_v_Filepath);
			m_ShaderSource.fragmentShader = utils::FileUtils::readFile(m_f_Filepath);
			return m_ShaderSource;
		}

		unsigned int Shader::compileShader(unsigned int shaderType, const std::string& shadersource) {
			const char* shader_src = shadersource.c_str();
			int shader = glCreateShader(shaderType);
			glShaderSource(shader, 1, &shader_src, NULL);
			glCompileShader(shader);
			return shader;
		}

		unsigned int Shader::createProgram() {
			unsigned int vs = compileShader(GL_VERTEX_SHADER, m_ShaderSource.vertexShader);
			unsigned int fs = compileShader(GL_FRAGMENT_SHADER, m_ShaderSource.fragmentShader);
			m_Program = glCreateProgram();
			glAttachShader(m_Program, vs);
			glAttachShader(m_Program, fs);
			glDeleteShader(vs);
			glDeleteShader(fs);
			glLinkProgram(m_Program);
			return m_Program;
		}

	}
}


