#include "Al_app.hpp"

void Algernon::ALapp::run()
{
	while (!alWindow.shouldClose()) {
		alWindow.pollEvents();
	}
}