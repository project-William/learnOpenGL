#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>	
#include <fstream>
#include <sstream>
#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>

#define MAX_VAOS 64
#define MAX_VBOS 64

class Shader {

public:
	Shader(const char*vertex_path, const char*fragment_path);
	void Use();
	void Draw(GLuint ordinal_num);
	void VaosAndVbos(GLint num);
	void TriangleSetup(GLuint ordinal_num, GLsizeiptr size, const void* data);
	~Shader();
private:
	void CheckError(GLint shader, const std::string& type);

private:
	const char*vertex_code, *fragment_code;
	GLuint VAOs[MAX_VAOS];
	GLuint VBOs[MAX_VBOS];
	GLint ID;

};