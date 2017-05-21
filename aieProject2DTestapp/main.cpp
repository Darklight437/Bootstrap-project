#include "aieProject2DTestappApp.h"

int main() {
	
	auto app = new aieProject2DTestappApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}