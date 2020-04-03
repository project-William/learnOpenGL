#pragma once

#include <iostream>
#include <utility>
#include <algorithm>
#include <memory>
#include <future>
#include <functional>
#include <sstream>
#include <fstream>
#include <thread>
#include <chrono>


//data structure
#include <string>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <forward_list>

//windows API
#include <Windows.h>

//glad glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//openGL 3D math lib
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//imgui
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#define TWO_SQUARE(x) (1<<x)

#define BIND_EVENT(x) std::bind(&x, this, std::placeholders::_1)

#define ASPECT_IN_RANGE(x) isnan(x) == true ? 1.0f : x






