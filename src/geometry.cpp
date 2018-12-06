#include "Geometry.h"

glm::vec3 Geomerty::NearestPoint(std::shared_ptr<Ray> _ray, glm::vec3 _query)
{
		return _query;
}

bool Geomerty::Intersect(std::shared_ptr<Ray> _ray, glm::vec3 _centre, float _radius)
{
		float rayProjection = glm::dot((_centre - _ray->m_origin), _ray->m_direction);

		float distance = glm::length(_centre - _ray->m_origin - (rayProjection)* _ray->m_direction);

		if (distance > _radius)
		{
				return false;
		}

		return true;
}