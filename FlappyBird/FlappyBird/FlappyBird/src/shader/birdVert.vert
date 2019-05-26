#version 330 core

layout (location=0) in vec3 birdPos;
layout (location=1) in vec2 texcoord;

out vec2 tex;

uniform mat4 birdview;
void main()
{
    tex=texcoord;
	gl_Position= birdview * vec4(birdPos,1.0f);
}