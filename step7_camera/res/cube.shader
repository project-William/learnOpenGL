#shader vertex
#version 330 core

layout(location = 0) in vec3 vertexPos;
layout(location = 1) in vec2 texturePos;

uniform mat4 MVP;

out vec2 texCoord;
void main()
{
	texCoord = texturePos;
	gl_Position = MVP*vec4(vertexPos, 1.0f);
}

#shader fragment
#version 330 core

out vec4 FragColor;
in vec2 texCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main()
{
	FragColor = texture(texture0, texCoord);
}
