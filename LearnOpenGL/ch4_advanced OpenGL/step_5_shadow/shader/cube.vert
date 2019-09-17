#version 330 core

layout (location=0) in vec3 apos;

out vec3 vpos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;




void main()
{
	vpos=apos;
	gl_Position=projection*view* model*vec4(apos,1.0f);
}