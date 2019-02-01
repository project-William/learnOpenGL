#include "Shader.h"

Shader::Shader(const char*vertex_path, const char*fragment_path) {

	std::fstream vertex_file, fragment_file;
	std::stringstream vertex_stream, fragment_stream;
	std::string vertex_string, fragment_string;

	vertex_file.exceptions(std::fstream::failbit | std::fstream::badbit);
	fragment_file.exceptions(std::fstream::failbit | std::fstream::badbit);

	try
	{
		vertex_file.open(vertex_path);
		fragment_file.open(fragment_path);

		vertex_stream << vertex_file.rdbuf();
		fragment_stream << fragment_file.rdbuf();


		vertex_string = vertex_stream.str();
		fragment_string = fragment_stream.str();

		vertex_file.close();
		fragment_file.close();

	}
	catch (const std::exception&e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << vertex_string << std::endl;
	std::cout << fragment_string << std::endl;

	vertex_code = vertex_string.c_str();
	fragment_code = fragment_string.c_str();

	GLint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_code, NULL);
	glCompileShader(vertex_shader);
	CheckError(vertex_shader, "vertex_shader");

	GLint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_code, NULL);
	glCompileShader(fragment_shader);
	CheckError(fragment_shader, "fragment_shader");

	ID = glCreateProgram();
	glAttachShader(ID, vertex_shader);
	glAttachShader(ID, fragment_shader);
	glLinkProgram(ID);
	CheckError(ID, "program");

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	
}

void Shader::VaosAndVbos(GLint num) {
	glGenVertexArrays(num, VAOs);
	glGenBuffers(num, VBOs);
	
}

void Shader::TriangleSetup(GLuint ordinal_num, GLsizeiptr size, const void* data) {
	glBindVertexArray(VAOs[ordinal_num]);
	glBindBuffer(GL_ARRAY_BUFFER, VAOs[ordinal_num]);

	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);

}

void Shader::CheckError(GLint shader, const std::string& type) {
	GLchar infoLog[512];
	int success;
	if (type == "program") {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
			std::cout << "program error:" << infoLog << std::endl;
		}
	}
	else {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "shader error:" << infoLog << std::endl;
		}
	}

}

void Shader::Use() {
	glUseProgram(ID);
}

void Shader::Draw(GLuint ordinal_num) {
	glBindVertexArray(VAOs[ordinal_num]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}



Shader::~Shader() {
		
}



