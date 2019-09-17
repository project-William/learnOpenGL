#version 330 core
layout(location=0) out vec4 FragColor;

in vec3 vpos;

void main()
{
	FragColor=vec4(vpos+0.5f,1.0f);
}