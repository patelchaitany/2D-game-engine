#pragma once
#include "GL/glew.h"
#include"graphics/buffer/buffer.h"
#include"graphics/buffer/indexBuffer.h"
#include"graphics/buffer/vertexarray.h"
#include"Maths/vec2.h"
#include"Maths/vec3.h"
#include"Maths/vec4.h"
#include"sahders.h"
namespace sparky {
	namespace graphics {
	
		class render2d {
		protected:
			maths::vec3 m_Position;
			maths::vec2 m_size;
			maths::vec4 m_Color;
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
			shaders& m_shader;
		public:
			render2d(maths::vec3 position, maths::vec2 size, maths::vec4 color,shaders& shader):m_Position(position),m_size(size),m_Color(color),m_shader(shader) {

				m_VertexArray = new VertexArray();

				GLfloat vertices[] = {
				0,0,0,
				0,-size.y,0,
				size.x,-size.y,0,
				size.x,0,0
				};

				GLfloat colors[] = {
				   color.x,color.y,color.z,color.w,
				   color.x,color.y,color.z,color.w,
				   color.x,color.y,color.z,color.w,
				   color.x,color.y,color.z,color.w
				};

				m_VertexArray->addBuffer(new Buffer(vertices, 3 * 4, 3),0);
				m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 3), 1);//here you can change component count to 3 and see som magic

				GLushort Indices[] = 
			    {
					0,1,2,
					2,3,0
				};
				m_IndexBuffer = new IndexBuffer(Indices, 6);

			}

			~render2d(){
				delete m_VertexArray;
				delete m_IndexBuffer;
			}
			inline shaders& getshader() const { return m_shader; }
			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const  IndexBuffer* getIBO() const { return m_IndexBuffer; }
			const maths::vec3& getPosition() const {
				return m_Position;
			}
			const maths::vec2& getSize() const {
				return m_size;
			}
			const maths::vec4& getColor() const {
				return m_Color;;
			}
	};

	}
}