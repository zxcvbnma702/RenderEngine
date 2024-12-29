#include "Al_app.hpp"

namespace Algernon {

	void Algernon::ALapp::run()
	{
		while (!alwindow.shouldClose()) {
			alwindow.pollEvents();
		}
	}

}
