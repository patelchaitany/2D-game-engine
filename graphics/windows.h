#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
namespace sparky {
	namespace graphics {
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
		class Windows {
		private:
			const char* m_name;
			int m_width, m_height;
			GLFWwindow* m_Window;
			bool m_Closed;
			
			static bool m_keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			static double mx;
			static double my ;
		public:
			Windows(const char* name, int width, int height);
			~Windows();
			void clear() const;
			void update() ;
			bool closed() const;
			//inline int getWidth() const { return m_width; }
			//inline int getHeight() const { return m_height; }
			static bool isKeyPressed(unsigned int key_code);
			static bool isButtonPressed(unsigned int button);
			static void getcord(double &x,double &y);
		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void mouse_pos(GLFWwindow* window, double posx, double posy);
		};
		
	}
}