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

		// Methods
		bool	ShouldClose() const;
		void	Clear() const;
		void	SwapBuffers() const;
		void	PollEvents() const;

	private:
		GLFWwindow	*_win;
		i8			*_title;
};
