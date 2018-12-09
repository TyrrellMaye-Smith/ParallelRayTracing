#ifndef GOEMETRY_H
#define GEOMETRY_H

#include <glm/glm.hpp>
#include <memory>

#include "Ray.h"

struct Intersection
{
		glm::vec3 distanceToHit;
		std::shared_ptr<Ray> ray;
		glm::vec3 centre;
		float radius;
};

class Geometry
{
public:
		glm::vec3 NearestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query);

		bool Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius);

		glm::vec3 GetNormal(glm::vec3 _pi);
		//glm::vec3 GetNormal(glm::vec3 _center, glm::vec3 _point);

		glm::vec3 GetIntersect(float a, float b, glm::vec3 c);
};
#endif // !GEOMETRY_H