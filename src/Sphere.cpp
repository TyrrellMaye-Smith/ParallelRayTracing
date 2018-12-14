#include "Sphere.h"

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, RayTracer& _tracer, glm::vec3 _intersect, int a)
{
		glm::vec3 color = GetColor();
		glm::vec3 lightDirection = { -1.0f, -1.0f, -1.0f };
		glm::vec3 lightColor = { 1.0f, 1.0f, 1.0f };
		glm::vec3 pointLight = glm::vec3(100, 100, 100) - _intersect;

		float specularInt = 1.0f;

		//Ambient
		glm::vec3 ambientCol = glm::vec3(1.0f, 0.0f, 0.0f);
		float ambientstrength = 0.1f;
		glm::vec3 ambient = ambientstrength * color;

		//Diffuse
		lightDirection = glm::normalize(lightDirection);
		glm::vec3 surfaceNormal = glm::normalize(_intersect - m_pos);
		float diffuseColor = glm::max(glm::dot(lightDirection, surfaceNormal), 0.0f);

		//Point light diffuse
		pointLight = glm::normalize(pointLight);
		float pointLightDiffuseColor = glm::max(glm::dot(pointLight, surfaceNormal), 0.0f);

		//Specular
		glm::vec3 reflect = glm::reflect(-lightDirection, surfaceNormal);
		glm::vec3 view = glm::normalize(-_ray->m_direction);
		float specularColour = glm::pow(glm::max(glm::dot(view, glm::normalize(reflect)), 0.0f), 50);
		specularColour *= specularInt;

		//Point light specular
		glm::vec3 pointLightReflect = glm::reflect(-pointLight, surfaceNormal);
		float pointLightSpecularColour = glm::pow(glm::max(glm::dot(view, glm::normalize(pointLightReflect)), 0.0f), 30);
		pointLightSpecularColour *= specularInt;

		float dot = glm::dot(lightDirection, surfaceNormal);

		glm::vec3 reflectionColor;

		if (a > 0)
		{
				//Reflection
				std::shared_ptr<Ray> rayReflection = std::make_shared<Ray>();
				rayReflection->m_direction = glm::reflect(-_ray->m_direction, surfaceNormal);
				rayReflection->m_origin = _intersect + rayReflection->m_direction * 0.001f;
				reflectionColor = 0.5f * _tracer.Raytracer(rayReflection, a - 1);
		}

		glm::vec3 touchColor = (diffuseColor + pointLightDiffuseColor + specularColour + pointLightSpecularColour + ambient) * lightColor * color + reflectionColor;

		return glm::clamp(touchColor, glm::vec3(0), glm::vec3(1));
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