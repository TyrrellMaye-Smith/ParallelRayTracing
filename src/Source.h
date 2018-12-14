#ifndef SOURCE_H
#define SOURCE_H

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

class Source
{
public:
		void Init();
		void Update();
private:
		void MultiThread(int _beginX, int _beginY, int _endX, int _endY);

		std::shared_ptr<Camera> camera;
		std::shared_ptr<RayTracer> tracer;
		std::shared_ptr<Ray> ray;
		std::shared_ptr<Sphere> whiteSphere;
		std::shared_ptr<Sphere> redSphere;
		std::shared_ptr<Sphere> greenSphere;
		std::shared_ptr<Sphere> blueSphere;
		std::shared_ptr<Sphere> yellowSphere;
		std::shared_ptr<Sphere> cyanSphere;
		std::shared_ptr<Sphere> magentaSphere;
		
		glm::vec3 color;

		SDL_Renderer* renderer;

		std::mutex mutex;

		std::vector<std::thread> t;

		int m_winWidth = 500;
		int m_winHeight = 500;
		int beginX = 0;
		int beginY = 0;
		int endX = 0;
		int endY = 0;

		bool m_start = true;

		SDL_Window* m_window;
		SDL_Event e = { 0 };
};
#endif // !SOURCE_H
