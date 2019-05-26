#pragma once
#include "EntryPoint.h"
using namespace flappy;


class Application {
private:
	graphics::Window* myWindow;
	utils::Input* input;
	graphics::Render* render;

	float currentTime = 0.0f;
	float lastTime = 0.0f;
	float deltaTime = 0.0f;

public:
	Application();
	~Application();

	Application(const Application& other) = delete;
	Application& operator=(const Application& other) = delete;

	void run();

};

