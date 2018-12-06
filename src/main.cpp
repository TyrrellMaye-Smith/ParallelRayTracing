#include <iostream>

#include "Screen.h"

int main()
{
		int m_winWidth = 500;
		int m_winHeight = 500;
		bool m_start = true;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Event e;

		SDL_Init(SDL_INIT_EVERYTHING);	//Initialises SDL

		m_window = SDL_CreateWindow("Parallel Ray Tracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_winWidth, m_winHeight, SDL_WINDOW_SHOWN);	//Uses SDL to create a window

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);	//creates the renderer

		while (m_start)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					m_start = false;
				}
			}
			SDL_PumpEvents();
			SDL_RenderClear(m_renderer);
		}

		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		return 0;
}