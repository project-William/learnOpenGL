#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>	
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

static std::string readFile(const std::string& filepath)
{
	std::ifstream stream(filepath);
	std::stringstream ss;
	if (stream)
	{
		ss << stream.rdbuf();
		return ss.str();
	}

	return "";
}

struct ParseShaderSource
{
	std::string vertexSource;
	std::string fragmentSource;
};


class Shader
{
public:
	Shader(const std::string& vfile, const std::string& ffile);
	~Shader();


private:
	ParseShaderSource m_Source;
	GLuint m_Program;
	void GetShaderSource(const std::string& vfile, const std::string& ffile);
	void CreateProgram(const ParseShaderSource& source);
	GLuint CreateShader(const std::string& shadersource, GLuint type);
public:
	void UseProgram();

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetVec2(const std::string& name, const glm::vec2& value) const;
	void SetVec2(const std::string& name, float x, float y) const;
	void SetVec3(const std::string& name, const glm::vec3& value) const;
	void SetVec3(const std::string& name, float x, float y, float z) const;
	void SetVec4(const std::string& name, const glm::vec4& value) const;
	void SetVec4(const std::string& name, float x, float y, float z, float w) const;
	void SetMat2(const std::string& name, const glm::mat2& mat) const;
	void SetMat3(const std::string& name, const glm::mat3& mat) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;

};

