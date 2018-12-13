#include "Camera.h"

std::shared_ptr<Ray> Camera::RayCreation(glm::ivec2 _pos)
{
		std::shared_ptr<Ray> rtn = std::make_shared<Ray>();
		rtn->m_origin.x = _pos.x;
		rtn->m_origin.y = _pos.y;
		rtn->m_origin.z = 0;
		//glm::ivec2(_pos.x, _pos.y);		//Sets the origin of the ray
		rtn->m_direction = glm::vec3(0, 0, -1);	//Sets the direction of the ray

		//rtn.direction = glm::vec3(glm::perspective(45.0f, 1.0f, -1.0f, 1.0f) * glm::vec4(rtn.direction, 1));		//Alines with the camera
		//rtn.origin = glm::vec3(glm::perspective(45.0f, 1.0f, -1.0f, 1.0f) * glm::vec4(rtn.origin, 1));	//Alines the origin for the camera
		return rtn;
}