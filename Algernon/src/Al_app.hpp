#pragma once

#include "Al_window.hpp"
#include "Al_pipeline.hpp"

namespace Algernon {
	class ALapp {
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

	private:
		ALwindow alWindow{ WIDTH, HEIGHT, "Vulkan" };
		ALpipeline alPipeline{ "D:/Engine/Render/Algernon/src/shaders/shader" };

	public:
		void run();
	};
}