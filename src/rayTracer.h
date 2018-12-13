#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "Ray.h"
#include "Sphere.h"
#include "Geometry.h"

class Sphere;
class Geometry;

class RayTracer
{
public:
		glm::vec3 Raytracer(std::shared_ptr<Ray> _ray, int a);

		void AddObject(std::shared_ptr<Sphere> _object);

private:
		std::vector<std::shared_ptr<Sphere>> m_objects;
		std::shared_ptr<Geometry> m_geomerty;
};

#endif // !RAYTRACER_H

