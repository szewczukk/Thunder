#version 330 core

#define MAX_LIGHTS_COUNT 10

out vec4 color;

in vec3 normal;
in vec3 fragmentPosition;
in vec2 uv;

uniform vec3 uModelColor;
uniform vec3 uViewPosition;
uniform sampler2D uTexture;


struct Light
{	
	vec3 position;
	vec3 color;
	float strength;
};

uniform Light uLight[MAX_LIGHTS_COUNT];

vec3 calculateLight(Light light)
{
	//ambient
	float ambientStrength = light.strength;
	vec3 ambient = ambientStrength * light.color;
	
	//diffuse
	vec3 norm = normalize(normal);
	vec3 lightDirection = normalize(light.position - fragmentPosition);
	
	float diff = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = diff * light.color;
	
	//specular
	float specularStrength = light.strength;
	vec3 viewDir = normalize(uViewPosition - fragmentPosition);
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
	//color = vec4(result * uModelColor, 1);
	color = vec4(result, 1) * texture(uTexture, uv);
}