#include "Shader.h"
#include "Renderer.h"


Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath)
{
	ShaderProgramSource source = ParseShader(filepath);
	std::cout << "VERTEX" << std::endl;
	std::cout << source.vertexSource << std::endl;
	std::cout << "FARAGMENT" << std::endl;
	std::cout << source.fragmentSource << std::endl;
	program = CreateProgram(source.vertexSource, source.fragmentSource);
}

Shader::~Shader(){
	GLCall(glDeleteProgram(program));
}

void Shader::bind() const{
	GLCall(glUseProgram(program));
}

void Shader::unbind() const{
	GLCall(glUseProgram(0));
}

void Shader::SetBool(const std::string& name, bool value) const {
	GLCall(glUniform1i(glGetUniformLocation(program, name.c_str()), (GLint)value));
}

void Shader::SetInt(const std::string& name, int value) const {
	GLCall(glUniform1i(glGetUniformLocation(program, name.c_str()), value));
}

void Shader::SetFloat(const std::string& name, float value) const {
	GLCall(glUniform1f(glGetUniformLocation(program, name.c_str()), value));
}

void Shader::SetVec2(const std::string& name, glm::vec2& value) const {
	GLCall(glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]));
}

void Shader::SetVec2(const std::string& name, float x, float y) const {
	GLCall(glUniform2f(glGetUniformLocation(program, name.c_str()), x, y));
}

void Shader::SetVec3(const std::string& name, glm::vec3& value) const {
	GLCall(glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]));
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const {
	GLCall(glUniform3f(glGetUniformLocation(program, name.c_str()), x, y, z));
}

void Shader::SetVec4(const std::string& name, glm::vec4& value) const {
	GLCall(glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]));
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w) const {
	GLCall(glUniform4f(glGetUniformLocation(program, name.c_str()), x, y, z, w));
}

void Shader::SetMat2(const std::string& name, glm::mat2& mat) const {
	GLCall(glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::SetMat3(const std::string& name, glm::mat3& mat) const {
	GLCall(glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::SetMat4(const std::string& name, glm::mat4& mat) const {
	GLCall(glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}



ShaderProgramSource Shader::ParseShader(const std::string & filepath){
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];
	enum class ShaderType {
		NONE = -1, VERT = 0, FRAG = 1
	};

	ShaderType type = ShaderType::NONE;
	while (std::getline(stream,line)){
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				//set vertex shader mode
				type = ShaderType::VERT;
			else if(line.find("fragment")!=std::string::npos)
				//set fragment shader mode
				type = ShaderType::FRAG;
		}
		else ss[(int)type] << line << '\n';
	}
	return ShaderProgramSource({ ss[0].str(), ss[1].str() });
}

unsigned int Shader::CreateProgram(const std::string& vertexsource, const std::string& fragmentsource) {
	GLCall(unsigned int renderer = glCreateProgram());
	GLCall(unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexsource));
	GLCall(unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentsource));
	GLCall(glAttachShader(renderer, vs));
	GLCall(glAttachShader(renderer, fs));
	GLCall(glLinkProgram(renderer));
	GLCall(checkError(renderer, "program"));
	GLCall(glValidateProgram(renderer));
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return renderer;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string & shadersource){
	const char* src = shadersource.c_str();
	GLCall(unsigned int id = glCreateShader(type));
	GLCall(glShaderSource(id, 1, &src, NULL));
	GLCall(glCompileShader(id));
	GLCall(checkError(id, "shader"));
	return id;
}

void Shader::checkError(unsigned int shader, const std::string & shadername) const{
	int success;
	char* infoLog;
	int length;
	if (shadername != "program") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			infoLog = (char*)malloc(length * sizeof(char));
			glGetShaderInfoLog(shader, length, NULL, infoLog);
			std::cout << "shader error:" << "(" << infoLog << ")" << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			infoLog = (char*)malloc(length * sizeof(char));
			glGetProgramInfoLog(shader, length, NULL, infoLog);
			std::cout << "program error:" << "(" << infoLog << ")" << std::endl;
		}
	}

}
