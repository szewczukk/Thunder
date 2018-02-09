#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inUv;

out vec3 normal;
out vec3 fragmentPosition;
out vec2 uv;

uniform mat4 uTransform;
uniform mat4 uPerspective;

void main()
{
	uv = inUv;
	normal = mat3(transpose(inverse(uTransform))) * inNormal;
	fragmentPosition = vec3(uTransform * vec4(inPosition, 1));
	gl_Position = uPerspective * uTransform * vec4(inPosition, 1);
}