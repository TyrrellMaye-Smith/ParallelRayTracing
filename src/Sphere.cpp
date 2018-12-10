#include "Sphere.h"

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, glm::vec3 _intersect)
{
		//glm::vec3 pi = _ray->m_origin + _ray->m_direction * t;
		glm::vec3 color = glm::vec3(0, 0, 0);
		glm::vec3 lightDirection = { 0, 0, 1 };
		glm::vec3 surfaceNormal;
		glm::vec3 lightColor = { 1, 1, 1 };

		lightDirection = glm::normalize(lightDirection);
		surfaceNormal = glm::normalize(_intersect - m_pos);
		float dot = glm::dot(lightDirection, surfaceNormal);
		glm::vec3 diffuseColor { 0 };

		if (dot > 0)
		{
				diffuseColor = dot * (lightColor * color);
		}

		return diffuseColor;
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

glm::vec3 Sphere::GetNormal(glm::vec3 _pi)
{
		return (_pi - m_pos) / m_radius;
}

//glm::vec3 Geometry::GetNormal(glm::vec3 _centre, glm::vec3 _point)
//{
//		std::shared_ptr<Sphere> sphere;
//		glm::vec3 normal = (_point - _centre) / sphere->GetRadius();
//		return _point - _centre;
//}