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
	GLCall(glUseProgram(0));
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
