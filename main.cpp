#include<iostream>
#include"graphics/windows.h"
#include "Maths/vec2.h"
#include "Maths/vec3.h"
#include"Maths/vec4.h"
#include "Maths/mat4.h"
#include "Utils/utils.h"
#include"graphics/sahders.h"
#include"graphics/buffer/buffer.h"
#include"graphics/buffer/vertexarray.h"
#include"graphics/buffer/buffer.h"
#include"graphics/buffer/indexBuffer.h"
#include"graphics/rander2d.h"
#include"graphics/render_2d.h"
#include"graphics/simple2drender.h"
using namespace std;
int main() {
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	Windows window("sparky", 960, 540);
#if 0

#else
	/*VertexArray vao;
	
	vec2 size(4, 4);
	vec4 color(0.0f, 0.0f, 0.0f, 0.0f);
	GLfloat vertices[] = {
				0,0,0,
				0,-size.y,0,
				(size.x),-size.y,0,
				(size.x),0,0
	};
	GLfloat colors[] = {
				   color.x,color.y,color.z,color.w,
				   color.x,color.y,color.z,color.w,
				   color.x,color.y,color.z,color.w,
				   color.x,color.y,color.z,color.w
	};
	GLushort Indices[] =
	{
		0,1,2,
		2,3,0
	};
	IndexBuffer ibo(Indices,6);
	vao.addBuffer(new Buffer(vertices, 12, 3), 0);
	vao.addBuffer(new Buffer(colors, 16, 4), 1);
	*/
#endif
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	//GLuint vao;


	//glGenBuffers(1, &vao);
	//glBindBuffer(GL_ARRAY_BUFFER, vao);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 3,GL_FLOAT,GL_FALSE,0,0);
	//glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f,15.0f,0.0f,15.0f,-2.0f,1.0f);

	

	shaders shader("basic.vert", "basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniform4f("colour", vec4(1.0f, 1.0f, 1.0f, 1.0f));
	//shader.setUniform2f("light_pos", vec2(10-15, ));
	render2d sprite(vec3(0, 0, 0), vec2(4, 4), vec4(1.0f, 0, 0, 0), shader);
	render2d sprite1(vec3(4, -4, 0),vec2(4, 4), vec4(0, 1, 0, 0),shader);
	simple2drender render;

	
	//shader.setUniformMat4("m1_matrix", (mat4::translation(vec3(1,-2,0)))*(mat4::translation(vec3(-15, 0, 0))));
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getcord(x, y);
		//shader.setUniform4f("colour", vec4(0.0f, 0.0f, 1.0f, 0.0f));
		//std::cout << "x>>" << x << "x//" << ((x * 15) / 960) << "y>>" << y << "y//" << ((y * 15) / 540) << endl;
		//ortho = mat4::orthographic(0.0f, (float)((x * 15) / 960), 0.0f, float(-((y * 15) / 540)), -2.0f, 1.0f);
		//shader.setUniformMat4("pr_matrix", ortho);
		//render2d sprite(vec3(10, -10, 0), vec2(4, -4), vec4(0, 0, 0, 0), shader);
		//a = sprite.getPosition();
		//std::cout << "x cord>>"<<a.x << "y cord>>" << a.y << "z cord>>" << a.z << endl;
		shader.setUniform4f("light_pos", vec4((float)(((x * 15) / 960) - 4), float(4 - ((y * 15) / 540)),0,0));
		//shader.setUniform2f("light_pos", vec2(-10, -5));
		render.submit(&sprite);
		render.submit(&sprite1);
		render.flush();
		
		window.update();
	}
	return 0;
}
