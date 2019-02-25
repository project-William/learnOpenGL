#version 330 core

struct Material{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform Material material;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
	//ambient
	vec3 ambient=material.ambient*lightColor;
	//diffuse
	vec3 nor=normalize(Normal);
	vec3 lightDir=normalize(lightPos-FragPos);
	float diff=max(dot(nor,lightDir),0.0f);
	vec3 diffuse=(diff*material.diffuse)*lightColor;
	//specular
	vec3 viewDir=normalize(viewPos-FragPos);
	vec3 reflectDir=reflect(-lightDir,nor);
	float spec=pow(max(dot(viewDir,reflectDir),0.0f),material.shininess);
	vec3 specular=lightColor*(spec*material.specular);
	
	vec3 result=(ambient+diffuse+specular);

	FragColor=vec4(result,1.0f);
}