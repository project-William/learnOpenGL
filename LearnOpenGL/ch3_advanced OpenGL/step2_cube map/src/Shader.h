#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ParseShaderSource
{
	std::string vertexSource;
	std::string fragmentSource;
};


class Shader
{
private:
	int program;
public:
	Shader(const std::string& filepath);
	~Shader();

	void bind()const;
	void unbind()const;

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetVec2(const std::string& name, glm::vec2& value) const;
	void SetVec2(const std::string& name, float x, float y) const;
	void SetVec3(const std::string& name, glm::vec3& value) const;
	void SetVec3(const std::string& name, float x, float y, float z) const;
	void SetVec4(const std::string& name, glm::vec4& value) const;
	void SetVec4(const std::string& name, float x, float y, float z, float w) const;
	void SetMat2(const std::string& name, glm::mat2& mat) const;
	void SetMat3(const std::string& name, glm::mat3& mat) const;
	void SetMat4(const std::string& name, glm::mat4& mat) const;

	
private:
	ParseShaderSource getShaderSource(const std::string& filepath)const;
	int compileShader(GLenum type, const std::string& shaderSource);
	int createProgram(const ParseShaderSource& source);
};




