#pragma once

# include "types.hpp"
# include "GLAD/glad.h"
# include "GLFW/glfw3.h"

class	Window
{
	public:
		// RAII
		void	Init(const i32 width, const i32 height, const i8 *title);
		void	Cleanup();

		// Getters & Setters
		GLFWwindow	*GetWin() const;

		i8			*GetTitle() const;
		void		SetTitle(i8 *title);

		i32			GetWidth() const;
		i32			GetHeight() const;

		// Methods
		bool	ShouldClose() const;
		void	Clear() const;
		void	SwapBuffers() const;
		void	PollEvents() const;

	private:
		GLFWwindow	*_win;
		i8			*_title;

		static void	setFramebufferSizeCallback(GLFWwindow *window, i32 width, i32 height);
		static i32	_width;
		static i32	_height;
};
