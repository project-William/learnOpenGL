#shader vertex
#version 330 core

layout(location=0) in vec3 aPos;

void main()
{
	gl_Position=vec4(aPos,1.0f);
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 FragColor;

void main()
{
	FragColor=vec4(1.0f,0.0f,0.0f,0.0f);
}