#include "RayTracer.h"

glm::vec3 RayTracer::Raytracer(std::shared_ptr<Ray> _ray)
{
		glm::vec3 color = glm::vec3(0, 0, 0);

		//#pragma omp parallel for
		for (size_t i = 0; i < m_objects.size(); i++)
		{
				Intersection result = m_geomerty->Intersect(_ray, m_objects.at(i)->GetPos(), m_objects.at(i)->GetRadius());
				if( result.hit )
				{
						m_objects.at(i)->Shade(_ray, result.intersectionPoint);
						color = m_objects.at(i)->GetColor();
						break;
				}
				else
				{
						color = glm::vec3(0, 0, 0);
				}
		}

		return color;
}

void RayTracer::AddObject(std::shared_ptr<Sphere> _object)
{
		m_objects.push_back(_object);
}