#pragma once

#include "Al_window.hpp"

namespace Algernon {

	class ALapp {

		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

	private:
		ALwindow alwindow{ WIDTH, HEIGHT, "Vulkan" };

	public:
		void run();
	};
}