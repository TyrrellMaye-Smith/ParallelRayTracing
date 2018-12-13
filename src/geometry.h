#ifndef GOEMETRY_H
#define GEOMETRY_H
#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "Ray.h"

struct Intersection
{
		glm::vec3 intersectionPoint;
		float distanceToHit;
		bool hit = false;
};

class Geometry
{
public:
		glm::vec3 NearestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query);

		Intersection Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius);
};
#endif // !GEOMETRY_H