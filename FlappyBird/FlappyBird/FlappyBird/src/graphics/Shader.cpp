#include "Shader.h"


namespace flappy {
	namespace graphics {
		Shader::Shader(const std::string& v_filepath, const std::string& f_filepath)
			:m_f_Filepath(f_filepath), m_v_Filepath(v_filepath), m_Program(0)
		{
			m_ShaderSource = getShaderSource();
			std::cout << m_ShaderSource.vertexShader << std::endl;
			std::cout << m_ShaderSource.fragmentShader << std::endl;
			m_Program = createProgram();
		}

		void Shader::enableProgram()const {
			glUseProgram(m_Program);
		}

		void Shader::disableProgram()const {
			glUseProgram(0);
		}

		void Shader::setInt(const std::string& name, int value) const {
			glUniform1i(getLocation(name), value);
		}

		void Shader::setFloat(const std::string& name, float value) const {
			glUniform1f(getLocation(name), value);
		}

		void Shader::setVec2(const std::string& name, math::Vec2 vec2) const {
			glUniform2f(getLocation(name), vec2.get_x(),vec2.get_y());
		}

		void Shader::setVec3(const std::string& name, math::Vec3 vec3) const {
			glUniform3f(getLocation(name), vec3.get_x(), vec3.get_y(), vec3.get_z());
		}

		void Shader::setMat4(const std::string& name, math::Matrix4f mat4) const {
			glUniformMatrix4fv(getLocation(name), 1, false, &mat4[0]);
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

		int Shader::getLocation(const std::string& name)const {
			return glGetUniformLocation(m_Program, name.c_str());
		}

	}
}


