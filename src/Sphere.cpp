#include "Sphere.h"

glm::vec3 Sphere::Shade(std::shared_ptr<Ray> _ray, RayTracer& _tracer, glm::vec3 _intersect, int a)
{
		glm::vec3 color = GetColor();
		glm::vec3 lightDirection = { 0.0f, 0.0f, 1.0f };
		glm::vec3 surfaceNormal;
		glm::vec3 lightColor = { 1.0f, 1.0f, 1.0f };
		glm::vec3 diffuseColor { 0.0f };

		lightDirection = glm::normalize(lightDirection);
		surfaceNormal = glm::normalize(_intersect - m_pos);

		float dot = glm::dot(lightDirection, surfaceNormal);
		//float specularInt = 1.0f;	//UNCOMMENT
		//float ambientstrength = 0.1f;	//UNCOMMENT
		//float diffuseColor = glm::max(glm::dot(-lightDirection, surfaceNormal), 0.0f);	//UNCOMMENT

		//glm::vec3 ambient = ambientstrength * color;		//UNCOMMENT

		//glm::vec3 reflect = glm::reflect(-lightDirection, surfaceNormal);		//UNCOMMENT
		//glm::vec3 view = glm::normalize(-_ray->m_direction);		//UNCOMMENT
		//glm::vec3 reflectionColor;	//UNCOMMENT

		//float specularColour = glm::pow(glm::max(glm::dot(view, glm::normalize(reflect)), 0.0f)50);	//UNCOMMENT
		//specularColour *= specularInt;	//UNCOMMENT

		//glm::vec3 touchColor = (diffuseColor + specularColour + ambient) * lightColor * color * reflectionColor * color;		//UNCOMMENT

		//if (a > 0)	//UNCOMMENT
		//{
		//		std::shared_ptr<Ray> rayReflection = std::make_shared<Ray>();
		//		rayReflection->m_direction = glm::reflect(-_ray->m_direction, surfaceNormal);
		//		rayReflection->m_origin = _intersect + rayReflection->m_direction * 0.001f;
		//		reflectionColor = 0.5f * _tracer->Raytracer(rayReflection, a - 1);
		//}

		if (dot > 0)		
		{
				diffuseColor = dot * (lightColor * color);
		}

		return diffuseColor;
		//return glm::clamp(touchColor, glm::vec3(0), glm::vec3(1));	//UNCOMMENT
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