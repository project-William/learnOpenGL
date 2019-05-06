#include "Shader.h"
#include <iostream>
namespace origin {

	namespace graphics {

		Shader::Shader(const std::string& v_filepath, const std::string& f_filepath)
			:m_program(0), m_Source({ "","" })
		{
			m_Source = getSource(v_filepath,f_filepath);
			std::cout << m_Source.vertexShader << std::endl;
			std::cout << m_Source.fragmentShader << std::endl;
			m_program = createProgram();

			float data[] = {
				-0.5f,-0.5f,0.0f,
				 0.5f,-0.5f,0.0f,
				 0.0f, 0.5f,0.0f,
			};



			unsigned int vao, vbo;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

		}

		void Shader::bind() {
			glUseProgram(m_program);
		}

		void Shader::unbind() {
			glUseProgram(0);
		}

		ParseShaderSource& Shader::getSource(const std::string& v_filepath, const std::string& f_filepath)
		{
			origin::utils::FileUtil readfile;
			m_Source.vertexShader=readfile.read_file(v_filepath);
			m_Source.fragmentShader = readfile.read_file(f_filepath);
			return m_Source;
		}

		unsigned int Shader::compileShader(const std::string& source, unsigned int type) {
			const char* src = source.c_str();
			unsigned int id = glCreateShader(type);
			glShaderSource(id, 1, &src, NULL);
			glCompileShader(id);
			return id;
		}

		unsigned int Shader::createProgram()
		{
			m_program=glCreateProgram();
			unsigned int vs = compileShader(m_Source.vertexShader, GL_VERTEX_SHADER);
			unsigned int fs = compileShader(m_Source.fragmentShader, GL_FRAGMENT_SHADER);
			glAttachShader(m_program, vs);
			glAttachShader(m_program, fs);
			glLinkProgram(m_program);
			glDeleteShader(vs);
			glDeleteShader(fs);
			return m_program;
		}






	}

}