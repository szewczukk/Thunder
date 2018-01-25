#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;

out vec3 oNormal;
out vec3 oFragmentPosition;

uniform mat4 mTransform;
uniform mat4 mPerspective;

void main()
{
	oNormal = mat3(transpose(inverse(mTransform))) * inNormal;
	oFragmentPosition = vec3(mTransform * vec4(inPosition, 1));
	gl_Position = mPerspective * mTransform * vec4(inPosition, 1);
}