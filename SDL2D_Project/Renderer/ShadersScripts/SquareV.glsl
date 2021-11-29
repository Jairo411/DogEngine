#version 460 core 
layout (location = 0) in vec2 position; // which position to vec4 
layout (location = 1) in vec2 texcoords;

out vec2 TexCoords;

uniform mat4 projection; 
uniform mat4 transform;

void main()
{
	gl_Position = projection*transform*vec4(position.xy,0.0,1.0);
}