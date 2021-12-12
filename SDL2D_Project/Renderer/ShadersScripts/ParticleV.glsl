#version 460 core 

layout(location = 0) in vec4 vertex; // <vec2 position, vec2 TexCoords>

out vec2 TexCoords;
out vec4 ParticleColour;


layout(location = 1) uniform mat4 projection;
layout(location = 2) uniform vec2 offset;
layout(location = 3) uniform vec4 colour;

void main()
{
	TexCoords= vertex.zw;
	ParticleColour = colour;
//	gl_Position = projection * vec4((vertex.xy * scale)+offset, 0.0,1.0);
//	gl_Position = transformIdentity * vec4(vertex.xy,0.0,1.0);

	gl_Position = projection * transform *vec4((vertex.xy),0.0,1.0);
}