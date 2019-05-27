#include "Window.h"
#include "Renderer.h"

const char* vertexSource = "#version 330 core\n"
	"layout(location=0) in vec3 pos;\n"
	"void main()\n"
	"{\n"
		"gl_Position=vec4(pos,1.0f);"
	"}\n";
const char* fragmentSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
		"FragColor=vec4(1.0f,0.0f,0.0f,1.0f);"
	"}\n";

unsigned int CompileShader(unsigned int type, const char* source) {
	GLCall(unsigned int shader = glCreateShader(type));
	GLCall(glShaderSource(shader, 1, &source, NULL));
	GLCall(glCompileShader(shader));

	int success, length;
	char* infoLog;
	GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &success));
	if (!success) {
		GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
		infoLog = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(shader, length, NULL, infoLog));
		std::cout << "shader compile error:" << "(" << infoLog << ")" << std::endl;
	}
	else return shader;
}
unsigned int CreateProgram(const char* vertexSource, const char* fragmentSource) {
	GLCall(unsigned int renderer = glCreateProgram());
	GLCall(unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexSource));
	GLCall(unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource));
	GLCall(glAttachShader(renderer, vs));
	GLCall(glAttachShader(renderer, fs));
	GLCall(glLinkProgram(renderer));
	GLCall(glValidateProgram(renderer));
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));
	
	int success, length;
	char* infoLog;
	GLCall(glGetProgramiv(renderer, GL_LINK_STATUS, &success));
	if (!success) {
		GLCall(glGetProgramiv(renderer, GL_INFO_LOG_LENGTH, &length));
		infoLog = (char*)alloca(length * sizeof(char));
		GLCall(glGetProgramInfoLog(renderer, length, NULL, infoLog));
		std::cout << "program error:" << "(" << infoLog << ")" << std::endl;
	}
	else return renderer;
}

int main() {
	{
		Window window("william", 1200, 800);
		Renderer render;

		float vertices[] = {
			-0.5f,-0.5f,0.0f,
			 0.5f,-0.5f,0.0f,
			 0.0f, 0.5f,0.0f
		};

		unsigned int program = CreateProgram(vertexSource, fragmentSource);
		
	
		unsigned int vao, vbo;
		GLCall(glGenBuffers(1, &vbo));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

		GLCall(glGenVertexArrays(1, &vao));
		GLCall(glBindVertexArray(vao));
		GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
		GLCall(glEnableVertexAttribArray(0));


		while (!window.closed()) {

			render.clear(0.2f, 0.4f, 1.0f, 1.0f);

			GLCall(glUseProgram(program));
			GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));

			window.update();
		}
		GLCall(glDeleteProgram(program));
	}
	glfwTerminate();

	return 0;
}
