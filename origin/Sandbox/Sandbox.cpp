#include <Origin.h>
#include <glad/glad.h>
#ifdef OG_PLATFORM_WINDOWS

int main() {

	origin::graphics::Window window(1200, 800, "w");
	origin::graphics::Shader shader("D:\\dev\\Origin\\Origin\\Origin\\res\\shader\\vertexShader.vert",
		"D:\\dev\\Origin\\Origin\\Origin\\res\\shader\\fragmentShader.frag");



	while (!window.close())
	{
		window.clear();

		shader.bind();
		shader.draw();

		window.update();
	}

	return 0;
}

#endif // OG_PLATFORM_WINDOWS





