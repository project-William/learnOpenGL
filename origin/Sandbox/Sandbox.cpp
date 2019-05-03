#include <Application.h>


#ifdef OG_PLATFORM_WINDOWS


int main() {

	origin::graphics::Window win(800, 600, "wew");

	while (!win.close())
	{
		win.update();
	}

	return 0;
}

#endif // OG_PLATFORM_WINDOWS





