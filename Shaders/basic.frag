#version 330 core

layout (location = 0) out vec4 color;
uniform vec4 colour;
uniform vec4 light_pos;
in DATA{
	vec4 position;
	vec4 colour;

}fs_in;
void main()
{
	//mat4 a = mat4::translation(vec4(0) - fs_in.position)
	float intensity = 1/length(fs_in.position - light_pos);
	color = (fs_in.colour)*intensity;
	//color = fs_in.colour;

}