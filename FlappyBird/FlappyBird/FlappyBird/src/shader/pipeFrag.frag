#version 330 core

out vec4 color;
in vec2 texc;

uniform sampler2D texture1;


void main()
{
	vec4 texColor = texture(texture1, texc);
    if(texColor.a < 0.1)
        discard;
	color= texColor;
}