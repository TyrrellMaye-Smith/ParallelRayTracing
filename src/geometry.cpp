#include "Geometry.h"
#include "Sphere.h"

#include <iostream>

Intersection Geometry::Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius)
{
		//Testing for struct
		Intersection first;

		//_centre is P

		//a
		glm::vec3 origin = _ray->m_origin;

		//n
		glm::vec3 direction = _ray->m_direction;

		//P-a
		glm::vec3 originToCentre = _centre - _ray->m_origin;

		//((P-a).n)
		float rayProjection = glm::dot(originToCentre, direction);
		
		//d
		float distance = glm::length(originToCentre - (rayProjection)* direction);

		if (distance > _radius)
		{
				return first;
		}
		else
		{
				//x
				float x = sqrt(pow(_radius, 2) - pow(distance, 2));

				//a+(((P-a).n)-x)n
				first.distanceToHit = rayProjection - x;
				first.intersectionPoint = origin + first.distanceToHit* direction;
				first.hit = true;

				return first;		//Intersecting
		}
}