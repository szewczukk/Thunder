#version 330 core

out vec3 oColor;

in vec3 oNormal;
in vec3 oFragmentPosition;

uniform vec3 mModelColor;
uniform vec3 mViewPosition;

struct Light
{	
	vec3 position;
	vec3 color;
	float strength;
};

#define MAX_LIGHTS_COUNT 10

uniform Light uLight[MAX_LIGHTS_COUNT];

vec3 calculateLight(Light light)
{
	//ambient
	float ambientStrength = light.strength;
	vec3 ambient = ambientStrength * light.color;
	
	//diffuse
	vec3 norm = normalize(oNormal);
	vec3 lightDirection = normalize(light.position - oFragmentPosition);
	
	float diff = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = diff * light.color;
	
	//specular
	float specularStrength = light.strength;
	vec3 viewDir = normalize(mViewPosition - oFragmentPosition);
	vec3 reflectDir = reflect(-lightDirection, norm);  
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * light.color;  
	
	return vec3(ambient + diffuse + specular);
}


void main()
{
	vec3 result;
	for(int i = 0; i < MAX_LIGHTS_COUNT; i++)
	{
		result += calculateLight(uLight[i]);
	}
	oColor = result * mModelColor;
}