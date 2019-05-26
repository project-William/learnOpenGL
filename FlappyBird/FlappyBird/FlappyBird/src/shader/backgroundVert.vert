#version 330 core
layout(location=0) in vec3 vertexPos;
layout(location=1) in vec2 texcoord;

uniform mat4 translate;
out vec2 tex;

void main()
{
    tex=texcoord;
	gl_Position= translate * vec4(vertexPos,1.0f);
}