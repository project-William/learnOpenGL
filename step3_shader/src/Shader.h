#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	~Shader();
private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateProgram(const std::string& vertex_shader, const std::string& fragment_shader);
	void checkError(const std::string& type,unsigned int shader);
};

