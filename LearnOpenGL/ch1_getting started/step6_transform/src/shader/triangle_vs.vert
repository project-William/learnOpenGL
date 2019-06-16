#version 330 core

layout(location=0) in vec3 vertexPos;
uniform mat4 m_MVP;
uniform vec2 rectangle_pos;

void main()	
{
	gl_Position=m_MVP*vec4(vertexPos.x+rectangle_pos.x,vertexPos.y+rectangle_pos.y,vertexPos.z,1.0f);
}