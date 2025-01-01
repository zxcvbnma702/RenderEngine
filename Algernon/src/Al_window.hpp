#pragma once

#include <SDL.h>
#include <string>
#include <vector>

namespace Algernon {
	class ALwindow {
	public:
		SDL_Window* window;
		SDL_Event event;

		ALwindow(int width, int height) : ALwindow(width, height, "VulkanApplication") {}

		ALwindow(int width, int height, std::string windowName) :
			mWidth(static_cast<uint32_t>(width)),
			mHeight(static_cast<uint32_t>(height)),
			mWindowsName(windowName) {
			initWindow();
		}

		~ALwindow() {
			SDL_DestroyWindow(window);
			SDL_Quit();
		}

		void pollEvents();

		bool shouldClose() {
			return quit;
		}

		bool wasWindowResized() { return framebufferResized; }

		void resetWindowResized() { framebufferResized = false; }

	private:

		void initWindow();

		static void framebufferResizeCallback(SDL_Window* window, int width, int height);

	private:

		const uint32_t mWidth;
		const uint32_t mHeight;

		std::string mWindowsName;

		bool framebufferResized = false;

		bool quit = false;
	};
}