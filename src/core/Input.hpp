#pragma once

# include "types.hpp"

# include "GLFW/glfw3.h"

enum	Keys
{
	Escape,
	W,
	A,
	S,
	D,
	Space,
	Ctrl,
	Shift,
	Up,
	Left,
	Down,
	Right,
	KeyAmount,
};

class	Input
{
	public:
		static void	Init(GLFWwindow *window);

		// Keyboard state
		static bool	keyboard[KeyAmount];

		// Mouse state
		static f64	cursorX;
		static f64	cursorY;

	private:
		static void	setKeyCallback(GLFWwindow *window, i32 key, i32 scancode, i32 action, i32 mods);
		static void	setCursorPosCallback(GLFWwindow *window, f64 xpos, f64 ypos);
};
