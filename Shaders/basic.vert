#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 colour;
uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 m1_matrix = mat4(1.0);

out DATA{

	vec4 position;
	vec4 colour;

}vs_out;

void main()
{
	gl_Position = pr_matrix*vw_matrix*m1_matrix*position;
	vs_out.position = position;
	vs_out.colour = colour;
	
}