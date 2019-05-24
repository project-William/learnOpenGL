#pragma once
#include "EntryPoint.h"
using namespace flappy;


class Application {
private:
	graphics::Window* myWindow;
	utils::Input* input;
	graphics::Shader* shader;
public:
	Application();
	~Application();

	Application(const Application& other) = delete;
	Application& operator=(const Application& other) = delete;

	void run();

};

