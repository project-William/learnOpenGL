#shader vertex
#version 330 core
layout(location = 0) in vec3 Pos;

uniform mat4 MVP;

void main()
{
	gl_Position = MVP* vec4(Pos, 1.0f);
}

#shader fragment
#version 330 core
out vec4 color;

void main()
{
	color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}




