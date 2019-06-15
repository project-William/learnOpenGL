#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
	TexCoords = aPos;
	vec4 pos = projection * view * vec4(aPos.x, -aPos.y, aPos.z, 1.0);
	gl_Position = pos.xyww;
}

#shader fragment
#version 330 core
out vec4 fragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{
	fragColor = texture(skybox, TexCoords);
}