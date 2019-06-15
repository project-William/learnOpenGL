#version 330 core
uniform vec4 triangle_color;

out vec4 fragColor;

void main()
{
	fragColor=triangle_color;
}