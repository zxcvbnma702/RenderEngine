#include "Al_window.hpp"

void Algernon::ALwindow::initWindow()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		mWindowsName.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		mWidth,
		mHeight,
		SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE
	);

	SDL_SetWindowData(window, "UserData", this);
}

void Algernon::ALwindow::pollEvents()
{
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit = true;
		}
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			framebufferResized = true;
		}
	}
}

void Algernon::ALwindow::framebufferResizeCallback(SDL_Window* window, int width, int height)
{
	auto app = reinterpret_cast<ALwindow*>(SDL_GetWindowData(window, "UserData"));
	app->framebufferResized = true;
}