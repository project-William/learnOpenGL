#version 330 core
layout (location=0) in vec3 vertexPos;
layout (location=1) in vec3 normal;
layout (location=2) in vec2 texc;

out vec3 norm;
out vec2 texcoord;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()	
{
	norm=normal;
	texcoord=texc;
	fragPos=vec3(model*vec4(vertexPos,1.0f));

	gl_Position=projection*view*model*vec4(vertexPos,1.0f);
}