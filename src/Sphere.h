#ifndef SPHERE_H
#define SPHERE_H

#include <glm/glm.hpp>
#include <memory>


#include "Ray.h"
#include "rayTracer.h"

class Sphere
{
public:
		glm::vec3 Shade(std::shared_ptr<Ray> _ray, RayTracer& _tracer, glm::vec3 _intersect, int a);

		void SetPos(glm::vec3 _pos);
		void SetRadius(float _radius);
		void SetColor(glm::vec3 _color);

		glm::vec3 GetPos();
		glm::vec3 GetColor();

		float GetRadius();

		glm::vec3 GetNormal(glm::vec3 _pi);
		//glm::vec3 Reflections(std::shared_ptr<RayTracer> _tracer, glm::vec3 _intersect, int a);
		//glm::vec3 Shadows(std::shared_ptr<Ray> _ray, glm::vec3 _intersect);

private:
		glm::vec3 m_pos;
		glm::vec3 m_color;

		float m_radius;
		
};

#endif // !SPHERE_H

