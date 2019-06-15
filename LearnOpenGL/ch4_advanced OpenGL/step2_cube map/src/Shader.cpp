#include "Shader.h"
#include <iostream>

Shader::Shader(const std::string& filepath)
	:program(0)
{
	ParseShaderSource source = getShaderSource(filepath);
	program = createProgram(source);
	std::cout << source.vertexSource << std::endl;
	std::cout << source.fragmentSource << std::endl;
}


Shader::~Shader()
{
}

void Shader::bind() const
{
	glUseProgram(program);
}

void Shader::unbind() const
{
	glUseProgram(0);
}

ParseShaderSource Shader::getShaderSource(const std::string& filepath) const
{
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];

	enum class ShaderType {
		NONE = -1,
		VERT = 0,
		FRAG = 1,
	};

	ShaderType type = ShaderType::NONE;

	while (std::getline(stream,line))
	{
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERT;
			else if(line.find("fragment")!= std::string::npos)
				type = ShaderType::FRAG;
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	return ParseShaderSource({ ss[0].str(),ss[1].str() });
}


void Shader::SetBool(const std::string& name, bool value) const {
	(glUniform1i(glGetUniformLocation(program, name.c_str()), (GLint)value));
}

void Shader::SetInt(const std::string& name, int value) const {
	(glUniform1i(glGetUniformLocation(program, name.c_str()), value));
}

void Shader::SetFloat(const std::string& name, float value) const {
	(glUniform1f(glGetUniformLocation(program, name.c_str()), value));
}

void Shader::SetVec2(const std::string& name, glm::vec2& value) const {
	(glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]));
}

void Shader::SetVec2(const std::string& name, float x, float y) const {
	(glUniform2f(glGetUniformLocation(program, name.c_str()), x, y));
}

void Shader::SetVec3(const std::string& name, glm::vec3& value) const {
	(glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]));
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const {
	(glUniform3f(glGetUniformLocation(program, name.c_str()), x, y, z));
}

void Shader::SetVec4(const std::string& name, glm::vec4& value) const {
	(glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]));
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w) const {
	(glUniform4f(glGetUniformLocation(program, name.c_str()), x, y, z, w));
}

void Shader::SetMat2(const std::string& name, glm::mat2& mat) const {
	(glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::SetMat3(const std::string& name, glm::mat3& mat) const {
	(glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::SetMat4(const std::string& name, glm::mat4& mat) const {
	(glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}


int Shader::compileShader(GLenum type, const std::string& shaderSource)
{
	const char* src = shaderSource.c_str();
	int id = glCreateShader(type);
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);
	return id;
}


int Shader::createProgram(const ParseShaderSource& source) {
	program = glCreateProgram();
	int vs = compileShader(GL_VERTEX_SHADER, source.vertexSource);
	int fs = compileShader(GL_FRAGMENT_SHADER, source.fragmentSource);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return program;
}