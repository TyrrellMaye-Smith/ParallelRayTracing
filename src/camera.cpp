#include "Camera.h"

Camera::Camera(SDL_Renderer* _renderer, float _screenW, float _screenH)
{
		m_renderer = _renderer;
		m_winWidth = _screenW;
		m_winHeight = _screenH;
}

std::shared_ptr<Ray> Camera::RayCreation(glm::ivec2 _pos)
{
		std::shared_ptr<Ray> rtn = std::make_shared<Ray>();
		rtn->m_origin.x = _pos.x;
		rtn->m_origin.y = _pos.y;
		rtn->m_origin.z = 0;
		rtn->m_direction = glm::vec3(0, 0, -1);	//Sets the direction of the ray

		glm::vec4 nearPlane;
		glm::vec4 farPlane;

		nearPlane.x = (_pos.x / (500.0f / 2.0f)) - 1;
		nearPlane.y = -((_pos.y / (500.0f / 2.0f)) - 1);
		nearPlane.z = -1.0f;
		nearPlane.w = 1.0f;

		farPlane.x = (_pos.x / (500.0f / 2.0f)) - 1;
		farPlane.y = -((_pos.y / (500.0f / 2.0f)) - 1);
		farPlane.z = 1.0f;
		farPlane.w = 1.0f;

		glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), (float)m_winWidth / (float)m_winHeight, nearPlane.z, farPlane.z);

		nearPlane = glm::inverse(projectionMatrix) * nearPlane;
		nearPlane /= nearPlane.w;

		farPlane = glm::inverse(projectionMatrix) * farPlane;
		farPlane /= farPlane.w;

		rtn->m_origin = nearPlane;
		rtn->m_direction = glm::normalize(-nearPlane + farPlane);

		return rtn;
}