#include "RayTracer.h"

glm::vec3 RayTracer::Raytracer(std::shared_ptr<Ray> _ray)
{
		glm::vec3 colour = glm::vec3(0, 0, 0);

		for (size_t i = 0; i < m_objects.size(); i++)
		{
				if (m_geomerty->Intersect(_ray, m_objects.at(i)->GetPos(), m_objects.at(i)->GetRadius()))
				{
						colour = m_objects.at(i)->GetColor();
						break;
				}
				else
				{
						colour = glm::vec3(0, 0, 0);
				}
		}

		return colour;
}

void RayTracer::AddObject(std::shared_ptr<Sphere> _object)
{
		m_objects.push_back(_object);
}