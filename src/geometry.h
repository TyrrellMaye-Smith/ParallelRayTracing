#ifndef GOEMETRY_H
#define GEOMETRY_H

#include <glm/glm.hpp>
#include <memory>

#include "Ray.h"


class Geomerty
{
public:
		glm::vec3 NearestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _find);

		bool Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius);
};
#endif // !GEOMETRY_H