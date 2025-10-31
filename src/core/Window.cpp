#include "Window.hpp"

#include "debug.hpp"

#include <stdexcept>

// ========================================================================== //
//                                    RAII                                    //
// ========================================================================== //

void	Window::Init(const i32 width, const i32 height, const i8 *title)
{
	// GLFW: Initialization and configuration
	if (!glfwInit())
		throw std::runtime_error("Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	printLog(LogType::Success, "GLFW initialized successfully");

	// GLFW: Window Creation
	_win = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!_win)
		throw std::runtime_error("Failed to create the window");
	glfwMakeContextCurrent(_win);
	printLog(LogType::Success, "Window created successfully");

	// GLAD: Initialization
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize GLAD");
	printLog(LogType::Success, "GLAD initialized successfully");
}

void	Window::Cleanup()
{
	printLog(LogType::Warning, "Cleaning Window object...");
	if (_win)
		glfwDestroyWindow(_win);
	glfwTerminate();
}

// ========================================================================== //
//                              Getters & Setters                             //
// ========================================================================== //

GLFWwindow	*Window::GetWin() const { return (_win); }

i8			*Window::GetTitle() const { return (_title); }
void		Window::SetTitle(i8 *title) { _title = title; }

// ========================================================================== //
//                                   Methods                                  //
// ========================================================================== //

bool	Window::ShouldClose() const
{
	return (glfwWindowShouldClose(_win));
}

void	Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void	Window::SwapBuffers() const
{
	glfwSwapBuffers(_win);
}

void	Window::PollEvents() const
{
	glfwPollEvents();
}
