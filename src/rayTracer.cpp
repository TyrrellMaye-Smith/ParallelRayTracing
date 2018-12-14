#include "RayTracer.h"

glm::vec3 RayTracer::Raytracer(std::shared_ptr<Ray> _ray, int a)
{
		glm::vec3 color = glm::vec3(0, 0, 0);
		std::shared_ptr<Sphere> closestObject = nullptr;
		float distanceToPoint = INFINITY;
		glm::vec3 intersectionPoint;

		m_geomerty = std::make_shared<Geometry>();

		//#pragma omp parallel for
		for (size_t i = 0; i < m_objects.size(); i++)
		{
				Intersection result = m_geomerty->Intersect(_ray, m_objects.at(i)->GetPos(), m_objects.at(i)->GetRadius());
				if( result.hit )
				{
						if (result.distanceToHit < distanceToPoint)
						{
								distanceToPoint = result.distanceToHit;
								closestObject = m_objects.at(i);
								intersectionPoint = result.intersectionPoint;
						}
				}
				else
				{
						color = glm::vec3(0, 0, 0);
				}
		}

		if (closestObject != nullptr)
		{
				color = closestObject->Shade(_ray, *this, intersectionPoint, a);
		}

		return color;
}

void RayTracer::AddObject(std::shared_ptr<Sphere> _object)
{
		m_objects.push_back(_object);
}