#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "Ray.h"
#include "Sphere.h"
#include "Geometry.h"

class RayTracer
{
public:
		glm::vec3 rayTracer(std::shared_ptr<Ray> _ray);

		void AddObject(std::shared_ptr<Sphere> _object);

private:
		std::vector<std::shared_ptr<Sphere>> m_objects;
		std::shared_ptr<Geomerty> m_geomerty;
};

#endif // !RAYTRACER_H

