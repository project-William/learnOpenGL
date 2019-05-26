#version 330 core

out vec4 fragcolor;

in vec2 tex;
uniform sampler2D texture1;


void main()
{
	vec4 texColor = texture(texture1, tex);
    if(texColor.a < 0.1)
        discard;
	fragcolor= texColor;
}

