#version 330 core

layout (location=0) in vec3 vertexPos;

uniform mat4 projection;
uniform mat4 view;

out vec3 texcoord;

void main()
{
	texcoord=vertexPos;
	vec4 pos=projection*view*vec4(vertexPos,1.0f);
	gl_Position=pos.xyzw;
}