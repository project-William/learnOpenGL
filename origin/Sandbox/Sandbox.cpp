#include <OriginApp.h>

#ifdef OG_PLATFORM_WINDOWS

int main() {

	std::unique_ptr<origin::OriginApp> app(new origin::OriginApp());

	app->run();

	return 0;
}

#endif // OG_PLATFORM_WINDOWS





