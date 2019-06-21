//#version 330 core
//layout (location=0) in vec3 vertexPos;
//layout (location=1) in vec3 normal;
//layout (location=2) in vec2 texc;
//
//out vec3 norm;
//out vec2 texcoord;
//out vec3 fragPos;
//
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
//
//
//void main()	
//{
//	norm=normal;
//	texcoord=texc;
//	fragPos=vec3(model*vec4(vertexPos,1.0f));
//
//	gl_Position=projection*view*model*vec4(vertexPos,1.0f);
//}

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    Normal = mat3(transpose(inverse(model))) * aNormal;
    Position = vec3(model * vec4(aPos, 1.0));
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}