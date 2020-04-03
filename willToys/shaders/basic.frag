#version 410 core
out vec4 FragColor;

in vec2 tex;

uniform sampler2D texture_diffuse1;

void main()
{    
    FragColor = vec4(1.0f,0.0f,0.0f,1.0f);
}