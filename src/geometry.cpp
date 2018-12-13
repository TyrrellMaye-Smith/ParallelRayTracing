#include "Geometry.h"
#include "Sphere.h"

#include <iostream>

glm::vec3 Geometry::NearestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query)
{
		//a
		glm::vec3 origin = _ray->m_origin;

		//n
		glm::vec3 direction = _ray->m_direction;

		//((P-a).n)
		float rayProjection = glm::dot(_query - origin, direction);
		glm::vec3 X = origin + (rayProjection * direction);
		return X;
}

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
		float rayProjection = glm::dot(_centre - origin, direction);
		
		//d
		float distance = glm::length(originToCentre - (rayProjection)* direction);


		//Checks if origin is inside sphere
		//Add code here

		//Closest point on the ray to the sphere centre
		glm::vec3 X = NearestPoint(_ray, _centre);

		//Check if the closest point is behind the camera.
		//Add code here

		if (distance > _radius)
		{
				return first;		//Not intersecting
		}
		else
		{
				//x
				float x = sqrt(pow(_radius, 2) - pow(distance, 2));

				//a+(((P-a).n)-x)n
				first.distanceToHit = rayProjection - x;
				first.intersectionPoint = origin + first.distanceToHit* direction;
				first.hit = true;
				//std::cout << first.intersectionPoint.x << " " << first.intersectionPoint.y << " " << first.intersectionPoint.z << std::endl;

				return first;		//Intersecting
		}

		//float disc = rayProjection * rayProjection - 4 * distance;

		/*if (disc < 1e-4)
		{
				return first;
		}

		disc = sqrt(disc);

		float firstInt = -rayProjection - disc;
		float secondInt = -rayProjection + disc;*/

		//if (distance > _radius)
		//{
		//		return false;
		//}
		//if (distance = _radius || distance < _radius)
		//{
		//		return true;
		//}

		//return true;
}