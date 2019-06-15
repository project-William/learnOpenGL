#version 330 core

layout(location=0) in vec3 vertexPos;

uniform vec2 rectangle_pos;

void main()	
{
	gl_Position=vec4(vertexPos.x+rectangle_pos.x,vertexPos.y+rectangle_pos.y,vertexPos.z,1.0f);
}