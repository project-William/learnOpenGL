#version 330 core

layout(location=0) in vec3 vertexPos;

uniform vec2 triangle_pos;

void main()	
{
	gl_Position=vec4(vertexPos.x+triangle_pos.x,vertexPos.y+triangle_pos.y,vertexPos.z,1.0f);
}