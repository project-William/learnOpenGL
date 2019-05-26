#version 330 core

layout (location=0) in vec3 pipePos;
layout (location=1) in vec2 texcoord;

uniform mat4 pipeview;

out vec2 texc;
void main()
{
    texc=texcoord;
	gl_Position=pipeview * vec4(pipePos,1.0f);
}