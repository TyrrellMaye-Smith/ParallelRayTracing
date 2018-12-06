#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL2/SDL.h>
#include <exception>

class Screen
{
public:
	Screen();
	~Screen();

	void Renderer();

	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();

	//static int getWidth(), getHeight();

private:

	//static int m_winWidth, m_winHeight;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
#endif