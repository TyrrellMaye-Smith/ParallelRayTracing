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

bool Geometry::Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius)
{
		//Testing for struct
		Intersection first;
		Intersection second;

		first.centre = _centre;
		first.radius = _radius;
		first.ray = _ray;

		second.centre = _centre;
		second.radius = _radius;
		second.ray = _ray;

		//_centre is P
		
		glm::vec3 X = NearestPoint(_ray, _centre);

		//a
		glm::vec3 origin = _ray->m_origin;

		//n
		glm::vec3 direction = _ray->m_direction;

		//P-a
		glm::vec3 originToCentre = _ray->m_origin - _centre;

		//((P-a).n)
		float rayProjection = glm::dot(_centre - origin, direction);
		
		//d
		float distance = glm::length(originToCentre - (rayProjection)* direction);

		if (distance > _radius)
		{
				return false;		//Not intersecting
		}
		else
		{
				if (glm::length(_centre - X) <= _radius)
				{
						//x
						float x = sqrt(pow(_radius, 2) - pow(distance, 2));

						//a+(((P-a).n)-x)n
						glm::vec3 firstIntersect = origin + (rayProjection - x)* direction;
						glm::vec3 secondIntersect = origin + (rayProjection + x)* direction;
						//std::cout << firstIntersect.x << " " << firstIntersect.y << " " << firstIntersect.z << std::endl;
						//std::cout << secondIntersect.x << " " << secondIntersect.y << " " << secondIntersect.z << std::endl;

						glm::vec3 Intersection = GetIntersect(_centre.z, _centre.z - _radius, firstIntersect);

						return true;		//Intersecting
				}
				else
				{
						return false;		//Not intersecting
				}

		}


		//float disc = rayProjection * rayProjection - 4 * distance;

		//if (disc < 1e-4)
		//{
		//		return false;
		//}

		//disc = sqrt(disc);

		//float firstInt = -rayProjection - disc;
		//float secondInt = -rayProjection + disc;

		////_radius = (firstInt < secondInt) ? firstInt : secondInt;

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

glm::vec3 Geometry::GetNormal(glm::vec3 _pi)
{
		std::shared_ptr<Sphere> sphere;
		return (_pi - sphere->GetPos()) / sphere->GetRadius();
}

//glm::vec3 Geometry::GetNormal(glm::vec3 _centre, glm::vec3 _point)
//{
//		std::shared_ptr<Sphere> sphere;
//		glm::vec3 normal = (_point - _centre) / sphere->GetRadius();
//		return _point - _centre;
//}

glm::vec3 Geometry::GetIntersect(float a, float b, glm::vec3 c)
{
		return (c - a) / (b - a);
}