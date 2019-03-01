#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
struct ShaderProgramSource{
	std::string vertex_source;
	std::string fragment_source;
};

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_filepath;
public:
	Shader(const std::string& filepath);
	void bind()const;
	void unbind()const;

	~Shader();
private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateProgram(const std::string& vertex_shader, const std::string& fragment_shader);
	void checkError(const std::string& type,unsigned int shader);
};

