#include "Input.hpp"

bool	Input::keyboard[KeyAmount] = { false };
f64		Input::cursorX = 0.0;
f64		Input::cursorY = 0.0;

void	Input::setKeyCallback(GLFWwindow *window, i32 key, i32 scancode, i32 action, i32 mods)
{
	(void)window;
	(void)scancode;
	(void)mods;

	switch (key)
	{
		// Window
		case (GLFW_KEY_ESCAPE): keyboard[Escape] = (action != GLFW_RELEASE); break ;

		// Camera Movements
		case (GLFW_KEY_W): keyboard[W] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_A): keyboard[A] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_S): keyboard[S] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_D): keyboard[D] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_SPACE): keyboard[Space] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_LEFT_CONTROL): keyboard[Ctrl] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_LEFT_SHIFT): keyboard[Shift] = (action != GLFW_RELEASE); break ;

		// Object Movements
		case (GLFW_KEY_UP): keyboard[Up] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_LEFT): keyboard[Left] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_DOWN): keyboard[Down] = (action != GLFW_RELEASE); break ;
		case (GLFW_KEY_RIGHT): keyboard[Right] = (action != GLFW_RELEASE); break ;
		default: break ;
	}
}

void	Input::setCursorPosCallback(GLFWwindow *window, f64 xpos, f64 ypos)
{
	(void)window;

	cursorX = xpos;
	cursorY = ypos;
}

void	Input::Init(GLFWwindow *window)
{
	glfwSetKeyCallback(window, setKeyCallback);
	glfwSetCursorPosCallback(window, setCursorPosCallback);
}
