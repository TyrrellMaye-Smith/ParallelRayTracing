#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

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

		//SetBackground(0, 0, 0);

		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		return 0;
}

//void SetBackground(int _red, int _green, int _blue)
//{
//		SDL_SetRenderDrawColor(m_renderer, _red, _green, _blue, 225);		//Set the colour for drawing
//		SDL_RenderClear(m_renderer);		//Clears the screen to the selected colour
//}
//
//void DrawPixel(int _pixelX, int _pixelY, int _red, int _green, int _blue)
//{
//		SDL_SetRenderDrawColor(m_renderer, _red, _green, _blue, 225);
//		SDL_RenderDrawPoint(m_renderer, _pixelX, _pixelY);
//}