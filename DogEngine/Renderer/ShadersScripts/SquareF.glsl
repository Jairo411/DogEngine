#version 460 core 
layout (location =0) in vec2 TexCoords;
out vec4 colour;

uniform sampler2D image;
uniform vec3 spriteColour;

void main()
{
	//colour = vec4(1.0f,0.5f,1.0f,0.0f);
	colour = texture(image,TexCoords);
}