#version 330 core

layout(location=0) in vec3 vertexPos;
layout(location=0) in vec2 texCoord;

out vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	texCoords=texCoord;
	gl_Position= projection*view*model*vec4(vertexPos,1.0f);
}