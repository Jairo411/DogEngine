#version 460 core 
layout (location = 0) in vec4 position; 


out vec2 TexCoords;

uniform mat4 projection; 
uniform mat4 transform;

void main()
{
	TexCoords=position.zw;
	gl_Position = projection*transform*vec4(position.xy,0.0,1.0);
}