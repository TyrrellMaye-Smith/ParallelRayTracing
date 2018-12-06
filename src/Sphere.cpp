#include "Sphere.h"

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, glm::vec3(_intersect))
{
		glm::vec3 color = glm::vec3(0, 0, 0);

		return color;
}

void Sphere::SetPos(glm::vec3 _pos)
{
		m_pos = _pos;
}

void Sphere::SetRadius(float _radius)
{
		m_radius = _radius;
}

void Sphere::SetColor(glm::vec3 _color)
{
		m_color = _color;
}

glm::vec3 Sphere::GetPos()
{
		return m_pos;
}

float Sphere::GetRadius()
{
		return m_radius;
}

glm::vec3 Sphere::GetColor()
{
		return m_color;
}