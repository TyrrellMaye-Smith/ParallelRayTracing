#include "Geometry.h"
#include "Sphere.h"

glm::vec3 Geometry::NearestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query)
{
		glm::vec3 origin = _ray->m_origin;
		glm::vec3 direction = _ray->m_direction;

		float rayProjection = glm::dot(_query - origin, direction);
		glm::vec3 X = origin + (rayProjection * direction);
		return X;
}

bool Geometry::Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius)
{

		//x = sqrt(squr(distance) - squr(_radius))

		//b
		//c
		glm::vec3 X = NearestPoint(_ray, _centre);

		if (glm::length(_centre - X) <= _radius)
		{
				return true;
		}
		else
		{
				return false;
		}

		//float distance = glm::length(originToCentre - (rayProjection)* direction);

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
//		return _point - _centre;
//}