#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <memory>

#include "Sphere.h"
#include "Camera.h"
#include "Ray.h"
#include "RayTracer.h"


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

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);	//creates the renderer

		std::shared_ptr<Camera> camera;
		camera = std::make_shared<Camera>();

		std::shared_ptr<RayTracer> rayTracer;
		rayTracer = std::make_shared<RayTracer>();

		//Red Sphere
		std::shared_ptr<Sphere> redSphere;
		redSphere = std::make_shared<Sphere>();
		redSphere->SetPos(glm::vec3(m_winWidth / 2, m_winHeight / 4, -1.0f));
		redSphere->SetColor(glm::vec3(1, 0, 0));
		redSphere->SetRadius(50.0f);
		
		//Green Sphere
		std::shared_ptr<Sphere> greenSphere;
		greenSphere = std::make_shared<Sphere>();
		greenSphere->SetPos(glm::vec3(m_winWidth / 4, m_winHeight / 1.5f, -1.0f));
		greenSphere->SetColor(glm::vec3(0, 1, 0));
		greenSphere->SetRadius(50.0f);

		//Blue Sphere
		std::shared_ptr<Sphere> blueSphere;
		blueSphere = std::make_shared<Sphere>();
		blueSphere->SetPos(glm::vec3(m_winWidth / 1.35f, m_winHeight / 1.5f, -1.0f));
		blueSphere->SetColor(glm::vec3(0, 0, 1));
		blueSphere->SetRadius(50.0f);

		rayTracer->AddObject(redSphere);
		//rayTracer->AddObject(greenSphere);
		//rayTracer->AddObject(blueSphere);

		for (int i = 0; i < m_winWidth; i++)
		{
				for (int j = 0; j < m_winHeight; j++)
				{
						std::shared_ptr<Ray> ray = camera->RayCreation(glm::ivec2 (i,j));
						glm::vec3 color = (rayTracer->Raytracer(ray)* 255.0f);
						SDL_SetRenderDrawColor(m_renderer, color.x, color.y, color.z, 255);
						SDL_RenderDrawPoint(m_renderer, i, j);
				}
		}

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
			//SDL_RenderClear(m_renderer);
			SDL_RenderPresent(m_renderer);
		}


		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		return 0;
}