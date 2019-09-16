#include "Shader.h"	
#include <iostream>


Shader::Shader(const std::string& vfile, const std::string& file)
{
	GetShaderSource(vfile, file);
	CreateProgram(m_Source);
}

Shader::~Shader()
{

}

void Shader::UseProgram()
{
	glUseProgram(m_Program);
}

void Shader::GetShaderSource(const std::string& vfile, const std::string& ffile)
{
	m_Source.vertexSource = readFile(vfile);
	m_Source.fragmentSource = readFile(ffile);
	std::cout << m_Source.vertexSource << std::endl;
	std::cout << m_Source.fragmentSource<< std::endl;
}


void Shader::CreateProgram(const ParseShaderSource& source)
{
	GLuint vs = CreateShader(source.vertexSource, GL_VERTEX_SHADER);
	GLuint fs = CreateShader(source.fragmentSource, GL_FRAGMENT_SHADER);
	m_Program = glCreateProgram();
	glAttachShader(m_Program,vs);
	glAttachShader(m_Program,fs);
	glLinkProgram(m_Program);
	glDeleteShader(vs);
	glDeleteShader(fs);
}

GLuint Shader::CreateShader(const std::string& shadersource, GLuint type)
{
	GLuint shader = glCreateShader(type);
	const char* src = shadersource.c_str();
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);
	return shader;
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_Program, name.c_str()), (GLint)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_Program, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_Program, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, const glm::vec2& value) const
{
	glUniform2fv(glGetUniformLocation(m_Program, name.c_str()), 1, &value[0]);
}

void Shader::SetVec2(const std::string& name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(m_Program, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(m_Program, name.c_str()), 1, &value[0]);
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(m_Program, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string& name, const glm::vec4& value) const
{
	glUniform4fv(glGetUniformLocation(m_Program, name.c_str()), 1, &value[0]);
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(m_Program, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string& name, const glm::mat2& mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(m_Program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat3(const std::string& name, const glm::mat3& mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_Program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_Program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}