#include "Source.h"

void Source::Init()
{
		
		tracer = std::make_shared<RayTracer>();

		whiteSphere = std::make_shared<Sphere>();
		whiteSphere->SetPos(glm::vec3(0.0f, 0.0f, 10.0f));
		whiteSphere->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
		whiteSphere->SetRadius(1.0f);

		redSphere = std::make_shared<Sphere>();
		redSphere->SetPos(glm::vec3(0.0f, -4.0f, 15.0f));
		redSphere->SetColor(glm::vec3(1, 0, 0));
		redSphere->SetRadius(1.0f);

		greenSphere = std::make_shared<Sphere>();
		greenSphere->SetPos(glm::vec3(4.0f, 2.0f, 15.0f));
		greenSphere->SetColor(glm::vec3(0, 1, 0));
		greenSphere->SetRadius(1.0f);

		blueSphere = std::make_shared<Sphere>();
		blueSphere->SetPos(glm::vec3(-4.0f, 2.0f, 15.0f));
		blueSphere->SetColor(glm::vec3(0, 0, 1));
		blueSphere->SetRadius(1.0f);

		yellowSphere = std::make_shared<Sphere>();
		yellowSphere->SetPos(glm::vec3(4.0f, -2.0f, 20.0f));
		yellowSphere->SetColor(glm::vec3(1, 1, 0));
		yellowSphere->SetRadius(1.0f);

		cyanSphere = std::make_shared<Sphere>();
		cyanSphere->SetPos(glm::vec3(-4.0f, -2.0f, 20.0f));
		cyanSphere->SetColor(glm::vec3(0, 1, 1));
		cyanSphere->SetRadius(1.0f);

		magentaSphere = std::make_shared<Sphere>();
		magentaSphere->SetPos(glm::vec3(0.0, 4.5f, 20.0f));
		magentaSphere->SetColor(glm::vec3(1, 0, 1));
		magentaSphere->SetRadius(1.0f);

		tracer->AddObject(whiteSphere);
		tracer->AddObject(redSphere);
		tracer->AddObject(greenSphere);
		tracer->AddObject(blueSphere);
		tracer->AddObject(yellowSphere);
		tracer->AddObject(cyanSphere);
		tracer->AddObject(magentaSphere);

		SDL_Init(SDL_INIT_EVERYTHING);	//Initialises SDL

		m_window = SDL_CreateWindow("Parallel Ray Tracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_winWidth, m_winHeight, SDL_WINDOW_SHOWN);	//Uses SDL to create a window

		renderer = SDL_CreateRenderer(m_window, -1, 0);	//creates the renderer
		
}

void Source::MultiThread(int _beginX, int _beginY, int _endX, int _endY)
{
		camera = std::make_shared<Camera>(renderer, 500.0f, 500.0f);

		for (int i = _beginX; i < _endX; i++)
		{
				for (int j = _beginY; j < _endY; j++)
				{
						std::shared_ptr<Ray> _ray = camera->RayCreation(glm::ivec2(i, j));
						color = (tracer->Raytracer(_ray, 2)* 255.0f);

						mutex.lock();
						SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, 255);
						SDL_RenderDrawPoint(renderer, i, j);
						mutex.unlock();
				}
		}
}

void Source::Update()
{
		for (size_t x = 0; x < m_winWidth; x += 500)
		{
				for (size_t y = 0; y < m_winHeight; y += 500)
				{
						t.push_back(std::thread(&Source::MultiThread, this, x, y, x + 500, y + 500));
				}
		}

		std::cout << t.size() << std::endl;

		for (size_t i = 0; i < t.size(); i++)
		{
				t.at(i).join();
		}
		t.clear();

		while (m_start)
		{
				while (SDL_PollEvent(&e))
				{
						if (e.type == SDL_QUIT)
						{
								m_start = false;
						}
				}
				SDL_RenderPresent(renderer);
		}
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(renderer);
}