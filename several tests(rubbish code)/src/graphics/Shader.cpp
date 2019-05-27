#include "Shader.h"



Shader::Shader(const std::string& vs_filepath, const std::string& fs_filepath)
	:m_VS_FilePath(vs_filepath),m_FS_FilePath(fs_filepath)
{
	ShaderProgramSource source = ParseShader(vs_filepath,fs_filepath);
	std::cout << "VERTEX" << std::endl;
	std::cout << source.vertexSource << std::endl;
	std::cout << "FARAGMENT" << std::endl;
	std::cout << source.fragmentSource << std::endl;
	program = CreateProgram(source.vertexSource, source.fragmentSource);
}

Shader::~Shader() {
	 glDeleteProgram(program);
}	 
	 
void Shader::bind() const {
	 glUseProgram(program);
}	 
	 
void Shader::unbind() const {
	 glUseProgram(0);
}	 
	 
void Shader::setBool(const std::string& name, bool value) const {
	 glUniform1i(glGetUniformLocation(program, name.c_str()), (GLint)value);
}	 
	 
void Shader::setInt(const std::string& name, int value) const {
	 glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}	 
	 
void Shader::setFloat(const std::string& name, float value) const {
	 glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}	 
	 
void Shader::setVec2(const std::string& name, glm::vec2& value) const {
	 glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}	 
	 
void Shader::setVec2(const std::string& name, float x, float y) const {
	 glUniform2f(glGetUniformLocation(program, name.c_str()), x, y);
}	 
	 
void Shader::setVec3(const std::string& name, glm::vec3& value) const {
	 glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}	 
	 
void Shader::setVec3(const std::string& name, float x, float y, float z) const {
	 glUniform3f(glGetUniformLocation(program, name.c_str()), x, y, z);
}	 
	 
void Shader::setVec4(const std::string& name, glm::vec4& value) const {
	 glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}	 
	 
void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const {
	 glUniform4f(glGetUniformLocation(program, name.c_str()), x, y, z, w);
}	 
	 
void Shader::setMat2(const std::string& name, glm::mat2& mat) const {
	 glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}	 
	 
void Shader::setMat3(const std::string& name, glm::mat3& mat) const {
	 glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}	 
	 
void Shader::setMat4(const std::string& name, glm::mat4& mat) const {
	 glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}



ShaderProgramSource Shader::ParseShader(const std::string& vs_filepath, const std::string& fs_filepath) {
	
	std::string vs_string, fs_string;
	vs_string = FileUtil::read_file(vs_filepath);
	fs_string = FileUtil::read_file(fs_filepath);

	return ShaderProgramSource({ vs_string, fs_string });
}

unsigned int Shader::CreateProgram(const std::string & vertexsource, const std::string & fragmentsource) {
	unsigned int renderer = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexsource);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentsource);
	glAttachShader(renderer, vs);
	glAttachShader(renderer, fs);
	glLinkProgram(renderer);
	checkError(renderer, "program");
	glValidateProgram(renderer);
	glDeleteShader(vs);
	glDeleteShader(fs);

	return renderer;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string & shadersource) {
	const char* src = shadersource.c_str();
	unsigned int id = glCreateShader(type);
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);
	checkError(id, "shader");
	return id;
}

void Shader::checkError(unsigned int shader, const std::string & shadername) const {
	int success;
	char* infoLog;
	int length;
	if (shadername != "program") {
		(glGetShaderiv(shader, GL_COMPILE_STATUS, &success));
		if (!success) {
			(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
			infoLog = (char*)malloc(length * sizeof(char));
			(glGetShaderInfoLog(shader, length, NULL, infoLog));
			std::cout << "shader error:" << "(" << infoLog << ")" << std::endl;
			delete[] infoLog;
		}
	}
	else {
		(glGetProgramiv(shader, GL_LINK_STATUS, &success));
		if (!success) {
			(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
			infoLog = (char*)malloc(length * sizeof(char));
			(glGetProgramInfoLog(shader, length, NULL, infoLog));
			std::cout << "program error:" << "(" << infoLog << ")" << std::endl;
			delete[] infoLog;
		}
	}

}