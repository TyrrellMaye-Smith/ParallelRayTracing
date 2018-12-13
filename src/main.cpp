#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <memory>
#include <thread>
#include <mutex>
#include <fstream>

#include "Sphere.h"
#include "Camera.h"
#include "Ray.h"
#include "RayTracer.h"

//static const int numberOfThreads = 4;
std::vector<std::thread> numberOfThreads;
std::mutex multi;		//Protects any shared data from being used by other threads

void MultiThread(int _thread, std::shared_ptr<RayTracer> _tracer, std::shared_ptr<Camera> _camera, std::shared_ptr<Ray> _ray, glm::vec3 _color,
		SDL_Renderer* _renderer, int _beginX, int _beginY, int _endX, int _endY)
{
		time_t start, finish;

		time(&start);
		for (int x = _beginX; x < _endX; x++)
		{
				for (int y = _beginY; y < _endY; y++)
				{
						std::shared_ptr<Ray> _ray = _camera->RayCreation(glm::ivec2(x, y));
						_color = (_tracer->Raytracer(_ray, 2)* 255.0f);
						SDL_SetRenderDrawColor(_renderer, _color.x, _color.y, _color.z, 255);
						SDL_RenderDrawPoint(_renderer, x, y);
				}
		}

		time(&finish);
		std::cout << difftime(finish, start) << "seconds" << std::endl;
}

//void MultiThread()		Continue...

int main()
{
		int m_winWidth = 500;
		int m_winHeight = 500;
		int beginX = 0;
		int beginY = 0;
		int endX = 0;
		int endY = 0;

		bool m_start = true;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Event e = { 0 };

		SDL_Init(SDL_INIT_EVERYTHING);	//Initialises SDL

		m_window = SDL_CreateWindow("Parallel Ray Tracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_winWidth, m_winHeight, SDL_WINDOW_SHOWN);	//Uses SDL to create a window

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);	//creates the renderer

		std::shared_ptr<Camera> camera; 
		camera = std::make_shared<Camera>();

		std::shared_ptr<RayTracer> rayTracer;
		rayTracer = std::make_shared<RayTracer>();

		std::shared_ptr<Ray> ray;

		glm::vec3 color = glm::vec3(0, 0, 0);

		//std::thread t[numberOfThreads];

		//White Sphere
		std::shared_ptr<Sphere> whiteSphere;
		whiteSphere = std::make_shared<Sphere>();
		whiteSphere->SetPos(glm::vec3(250, 250, -1.0f));
		whiteSphere->SetColor(glm::vec3(1, 1, 1));
		whiteSphere->SetRadius(75.0f);

		//Red Sphere
		std::shared_ptr<Sphere> redSphere;
		redSphere = std::make_shared<Sphere>();
		redSphere->SetPos(glm::vec3(250, 100, -1.0f));
		redSphere->SetColor(glm::vec3(1, 0, 0));
		redSphere->SetRadius(50.0f);
		
		//Green Sphere
		std::shared_ptr<Sphere> greenSphere;
		greenSphere = std::make_shared<Sphere>();
		greenSphere->SetPos(glm::vec3(150, 350, -1.0f));
		greenSphere->SetColor(glm::vec3(0, 1, 0));
		greenSphere->SetRadius(50.0f);

		//Blue Sphere
		std::shared_ptr<Sphere> blueSphere;
		blueSphere = std::make_shared<Sphere>();
		blueSphere->SetPos(glm::vec3(350, 350, -1.0f));
		blueSphere->SetColor(glm::vec3(0, 0, 1));
		blueSphere->SetRadius(50.0f);

		//Yellow Sphere
		std::shared_ptr<Sphere> yellowSphere;
		yellowSphere = std::make_shared<Sphere>();
		yellowSphere->SetPos(glm::vec3(75 , 150, -1.0f));
		yellowSphere->SetColor(glm::vec3(1, 1, 0));
		yellowSphere->SetRadius(25.0f);

		//Cyan Sphere
		std::shared_ptr<Sphere> cyanSphere;
		cyanSphere = std::make_shared<Sphere>();
		cyanSphere->SetPos(glm::vec3(250, 425, -1.0f));
		cyanSphere->SetColor(glm::vec3(0, 1, 1));
		cyanSphere->SetRadius(25.0f);

		//Magenta Sphere
		std::shared_ptr<Sphere> magentaSphere;
		magentaSphere = std::make_shared<Sphere>();
		magentaSphere->SetPos(glm::vec3(425, 150, -1.0f));
		magentaSphere->SetColor(glm::vec3(1, 0, 1));
		magentaSphere->SetRadius(25.0f);

		rayTracer->AddObject(whiteSphere);
		rayTracer->AddObject(redSphere);
		rayTracer->AddObject(greenSphere);
		rayTracer->AddObject(blueSphere);
		rayTracer->AddObject(yellowSphere);
		rayTracer->AddObject(cyanSphere);
		rayTracer->AddObject(magentaSphere);

		////Multi-Threading
		//MultiThread(1, rayTracer, camera, ray, color, m_renderer, 0, 0, m_winWidth / 2, m_winHeight / 2);		//Top left
		//MultiThread(1, rayTracer, camera, ray, color, m_renderer, m_winWidth / 2, 0, m_winWidth, m_winHeight / 2);		//Top right
		//MultiThread(1, rayTracer, camera, ray, color, m_renderer, 0, m_winHeight / 2, m_winWidth / 2, m_winHeight);		//Bottom left
		//MultiThread(1, rayTracer, camera, ray, color, m_renderer, m_winWidth / 2, m_winHeight / 2, m_winWidth, m_winHeight);		//Bottom right
		MultiThread(1, rayTracer, camera, ray, color, m_renderer, 0, 0, 500, 500);		//Full screen

	/*	for (int i = 0; i < m_winWidth; i += 125)
		{
				for (int j = 0; j < m_winHeight; j += 125)
				{
						numberOfThreads.push_back(std::thread(MultiThread));
				}
		}*/

		/*for (int i = 0; i < numberOfThreads; i++)
		{
				t[i] = std::thread(MultiThread, i, rayTracer, camera, ray, color, m_renderer, beginX, beginY, endX + 125, endY + 125);
				t[i].join();
		}*/

		/*for (int i = 0; i < numberOfThreads; i++)
		{
				t[i].join();
		}*/

		while (m_start)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					m_start = false;
				}
			}
			//SDL_PumpEvents();
			//SDL_RenderClear(m_renderer);
			SDL_RenderPresent(m_renderer);
		}

		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		return 0;
}