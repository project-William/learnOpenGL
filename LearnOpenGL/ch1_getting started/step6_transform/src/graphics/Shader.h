#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "..//utils/ReadFile.h"

struct ShaderProgramSource {
	std::string vertexSource;
	std::string fragmentSource;
};

class Shader
{
private:
	std::string m_VS_FilePath;
	std::string m_FS_FilePath;
	unsigned int program;
public:
	Shader(const std::string& vs_filepath, const std::string& fs_filepath);
	~Shader();
	void bind()const;
	void unbind()const;

	inline unsigned int getProgram()const { return program; }


	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec2(const std::string& name, glm::vec2& value) const;
	void setVec2(const std::string& name, float x, float y) const;
	void setVec3(const std::string& name, glm::vec3& value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec4(const std::string& name, glm::vec4& value) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;
	void setMat2(const std::string& name, glm::mat2& mat) const;
	void setMat3(const std::string& name, glm::mat3& mat) const;
	void setMat4(const std::string& name, glm::mat4& mat) const;
private:
	ShaderProgramSource ParseShader(const std::string& vs_filepath, const std::string& fs_filepath);
	unsigned int CreateProgram(const std::string& vertexsource, const std::string& fragmentsource);
	unsigned int CompileShader(unsigned int type, const std::string& shadersource);
	void checkError(unsigned int shader, const std::string& shadername)const;

};