#include <iostream>
#include "src/Window.h"

int main()
{
	
	GLfw::Window::GetInstance()->Init(1200,800,"william");
	GLfw::Window::GetInstance()->Run();
	GLfw::Window::GetInstance()->Terminate();
	return 0;
}