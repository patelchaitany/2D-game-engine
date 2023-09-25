#include "windows.h"


namespace sparky {
	namespace graphics {
		bool Windows::m_keys[MAX_KEYS];
		bool Windows::m_MouseButtons[MAX_BUTTONS];
		double Windows::mx;
		double Windows::my;
		void window_Resize(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
		static void mouse_pos(GLFWwindow* window, double posx, double posy);
		Windows::Windows(const char* name, int width, int height) {
			m_name = name;
			m_width = width;
			m_height = height;
			if (!init()) {
				glfwTerminate();
			}
			glfwSetWindowUserPointer(m_Window, this);
			for (int i = 0; i < MAX_KEYS; i++) {
				m_keys[i] = false;
			}
			for (int i = 0; i <MAX_BUTTONS;i++){
				m_MouseButtons[i] = false;
			}
		}
		Windows::~Windows() {
			glfwTerminate();
		}
		void Windows::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Windows::update()  {
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_width, &m_height);
			//glViewport(0, 0, m_width, m_height);
			glfwSwapBuffers(m_Window);
		}
		void Windows::getcord(double& x, double& y) {
			x = mx;
			y = my;
		}
		bool Windows::isKeyPressed(unsigned int key_code) {
			if (key_code >= MAX_KEYS) {
				return false;
			}
			return m_keys[key_code]; 
		}
		bool Windows::isButtonPressed(unsigned int button) {
			if (button >= MAX_BUTTONS) {
				return false;
			}
			return m_MouseButtons[button];
		}

		bool Windows::init()
		{
			if (!glfwInit()) {
				cout << "error" << endl;
				return false;
			}
			m_Window = glfwCreateWindow(m_width, m_height,m_name,NULL,NULL);
			if (!m_Window) {
				glfwTerminate();
				cout << "fail" << endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window,window_Resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_callback);
			glfwSetCursorPosCallback(m_Window, mouse_pos);
			if (glewInit() != GLEW_OK) {
				cout << "Not ok" << endl;
				return false;
			}
			return true;

		}
		bool Windows::closed() const {
			return glfwWindowShouldClose(m_Window);
		}
		void window_Resize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0,width, height);
		}
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Windows* win = (Windows*)glfwGetWindowUserPointer(window);
			win->m_keys[key] = action != GLFW_RELEASE;
		}
		static void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
			Windows* win = (Windows*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		static void mouse_pos(GLFWwindow* window, double posx, double posy) {
			Windows* win = (Windows*)glfwGetWindowUserPointer(window);
			win->mx = posx;
			win->my = posy;
		}


	}
}