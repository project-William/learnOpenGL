#include "Shader.h"
#include "Renderer.h"

Shader::Shader(const std::string& filepath)
	:m_RendererID(0), m_filepath(filepath)
{
	ShaderProgramSource source = ParseShader(filepath);
	std::cout << "vertex" << std::endl;
	std::cout << source.vertex_source << std::endl;
	std::cout << "fragment" << std::endl;
	std::cout << source.fragment_source << std::endl;

	m_RendererID = CreateProgram(source.vertex_source, source.fragment_source);
}

void Shader::bind() const{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::unbind() const{
	GLCall(GLCall(glUseProgram(0)));
}

void Shader::SetBool(const std::string& name, bool value) const {
	GLCall(glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), (GLint)value));
}

void Shader::SetInt(const std::string& name, int value) const {
	GLCall(glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value));
}

void Shader::SetFloat(const std::string& name, float value) const {
	GLCall(glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value));
}

void Shader::SetVec2(const std::string& name, glm::vec2& value) const {
	GLCall(glUniform2fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]));
}

void Shader::SetVec2(const std::string& name, float x, float y) const {
	GLCall(glUniform2f(glGetUniformLocation(m_RendererID, name.c_str()), x, y));
}

void Shader::SetVec3(const std::string& name, glm::vec3& value) const {
	GLCall(glUniform3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]));
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const {
	GLCall(glUniform3f(glGetUniformLocation(m_RendererID, name.c_str()), x, y, z));
}

void Shader::SetVec4(const std::string& name, glm::vec4& value) const {
	GLCall(glUniform4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, &value[0]));
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w) const {
	GLCall(glUniform4f(glGetUniformLocation(m_RendererID, name.c_str()), x, y, z, w));
}

void Shader::SetMat2(const std::string& name, glm::mat2& mat) const {
	GLCall(glUniformMatrix2fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::SetMat3(const std::string& name, glm::mat3& mat) const {
	GLCall(glUniformMatrix3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}

void Shader::SetMat4(const std::string& name, glm::mat4& mat) const {
	GLCall(glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, &mat[0][0]));
}


Shader::~Shader(){
	GLCall(glDeleteProgram(m_RendererID));
}

ShaderProgramSource Shader::ParseShader(const std::string& filepath){

	std::ifstream stream(filepath);

	std::string line;
	std::stringstream ss[2];

	enum class ShaderType {
		NONE = -1,
		VERT =  0,
		FRAG =  1
	};

	ShaderType type = ShaderType::NONE;

	while (std::getline(stream, line)){
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERT;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAG;
		}
		else ss[(int)type] << line << '\n';
	}
	return ShaderProgramSource({ ss[0].str(), ss[1].str() });
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source){
	GLCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));
	checkError("shader", id);
	return id;
}

unsigned int Shader::CreateProgram(const std::string& vertex_shader, const std::string& fragment_shader){
	GLCall(unsigned int program = glCreateProgram());
		  
	GLCall(unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex_shader));
	GLCall(unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment_shader));

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	checkError("program", program);
	GLCall(glValidateProgram(program));
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));


	return program;
}

void Shader::checkError(const std::string & type, unsigned int shader){
	int success;
	char* infoLog;
	int length;
	if (type != "program") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			infoLog = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(shader, length, NULL, infoLog);
			std::cout << "shader error:" << "(" << infoLog << ")" << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			infoLog = (char*)alloca(length * sizeof(char));
			glGetProgramInfoLog(shader, length, NULL, infoLog);
			std::cout << "program error:" << "(" << infoLog << ")" << std::endl;
		}

	}

}
