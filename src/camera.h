#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

#include "Ray.h"

class Camera
{
public:
		std::shared_ptr<Ray> RayCreation(glm::ivec2 _pos);
private:
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
};

#endif // !CAMERA_H