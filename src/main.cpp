#include "types.hpp"
#include "debug.hpp"

#include "Window.hpp"
#include "Input.hpp"
#include "ObjectManager.hpp"

i32	main()
{
	bool			ret = 0;
	Window			window;
	ObjectManager	objectManager;

	try
	{
		window.Init(1280, 720, "scop by flmarsou");

		objectManager.Load("assets/test.obj");
	}
	catch(const std::exception &error)
	{
		printLog(LogType::Error, error.what());
		ret = 1;
		goto terminate_scop;
	}

	Input::Init(window.GetWin());

	while (!window.ShouldClose())
	{
		window.Clear();
		window.SwapBuffers();
		window.PollEvents();
	}

	terminate_scop:
		window.Cleanup();

	return (ret);
}
