#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

#include "Ray.h"
#include "SDL2\SDL.h"

class Ray;

class Camera
{
public:
		Camera(SDL_Renderer* _renderer, float _screenW, float _screenH);
		std::shared_ptr<Ray> RayCreation(glm::ivec2 _pos);

		int m_winWidth = 500.0f;
		int m_winHeight = 500.0f;

		SDL_Renderer* m_renderer;
private:
};

#endif // !CAMERA_H