#include "include/Application.h"

int main()
{
	auto& app = gltoys::Application::Get();
	app.RegisteEvents();
	app.Run();

	return 0;
}