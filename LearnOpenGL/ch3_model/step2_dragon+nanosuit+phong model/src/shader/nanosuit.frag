#version 330 core

out vec4 frag;


uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

uniform vec3 viewPos;
uniform vec3 lightPos;
in vec3 norm;
in vec2 texcoord;
in vec3 fragPos;

void main()	
{
	float ambient_s=0.3f;
	vec3 ambient=ambient_s*vec3(texture(texture_diffuse1,texcoord));


	vec3 nor=normalize(norm);
	vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(nor, lightDir), 0.0);
    vec3 diffuse = diff * vec3(texture(texture_diffuse1,texcoord));

	float spec_s=0.8f;
	vec3 viewDir=normalize(viewPos-fragPos);
	vec3 reflectDir=reflect(-lightDir,nor);
	float spec=pow(max(dot(viewDir,reflectDir),0.0f),64);
	vec3 specular=spec*spec_s*vec3(texture(texture_diffuse1,texcoord));

	frag=vec4(ambient+diffuse+specular,1.0f);
}