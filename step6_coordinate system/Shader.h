#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>

#include <glm/glm.hpp>

#define MAX_VAOS 64
#define MAX_VBOS 64

class Shader {
public:
	Shader(const char* vertex_path, const char* fragment_path);

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetVec2(const std::string& name, glm::vec2 value) const;
	void SetVec2(const std::string& name, float x, float y) const;
	void SetVec3(const std::string& name, glm::vec3 value) const;
	void SetVec3(const std::string& name, float x, float y, float z) const;
	void SetVec4(const std::string& name, glm::vec4 value) const;
	void SetVec4(const std::string& name, float x, float y, float z, float w) const;
	void SetMat2(const std::string& name, glm::mat2 mat) const;
	void SetMat3(const std::string& name, glm::mat3 mat) const;
	void SetMat4(const std::string& name, glm::mat4 mat) const;


	void UseProgram();
	void Draw();
	void VaosVbos();
	void RectangluarSetup(GLint ordinal_num, GLsizeiptr size, const void* data);
	~Shader();
	
private:
	void CheckError(GLint shader, const std::string& name);
private:
	const char*vertex_source, *fragment_source;
	GLint ID;
	GLuint VAOs[MAX_VAOS], VBOs[MAX_VBOS];
};
