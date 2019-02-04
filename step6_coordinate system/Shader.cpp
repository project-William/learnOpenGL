#include "Shader.h"

Shader::Shader(const char* vertex_path, const char* fragment_path) {
	std::fstream vertex_file, fragment_file;
	std::stringstream vertex_stream, fragment_stream;
	std::string vertex_string, fragment_string;

	vertex_file.exceptions(std::fstream::badbit | std::fstream::failbit);
	fragment_file.exceptions(std::fstream::badbit | std::fstream::failbit);

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

	vertex_source = vertex_string.c_str();
	fragment_source = fragment_string.c_str();

	GLint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(vertex_shader);
	CheckError(vertex_shader, "vertex_shader");


	GLint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source, NULL);
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

void Shader::VaosVbos() {
	glGenVertexArrays(1, VAOs);
	glGenBuffers(1, VBOs);
}

void Shader::RectangluarSetup(GLint ordinal_num, GLsizeiptr size, const void* data) {

	glBindVertexArray(VAOs[ordinal_num]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[ordinal_num]);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);


}

void Shader::SetBool(const std::string& name, bool value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, glm::vec2 value) const {
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec2(const std::string& name, float x, float y) const {
	glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string& name, glm::vec3 value) const {
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const {
	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string& name, glm::vec4 value) const {
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w) const {
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string& name, glm::mat2 mat) const {
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat3(const std::string& name, glm::mat3 mat) const {
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat4(const std::string& name, glm::mat4 mat) const {
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


void Shader::UseProgram() {
	glBindVertexArray(VAOs[0]);
	glUseProgram(ID);
}

void Shader::Draw() {
	glDrawArrays(GL_TRIANGLES, 0, 36);
}



void Shader::CheckError(GLint shader, const std::string& name) {
	GLchar infoLog[512];
	int success;
	if (name == "program") {
		glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
			std::cout << "program error:" << infoLog << std::endl;
		}
		else {
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				std::cout << name << " error:" << infoLog << std::endl;
			}
		}
	}
}

Shader::~Shader() {

}


