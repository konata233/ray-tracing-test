//
// Created on 2024/9/22.
//

#ifndef RAY_TRACING_SPHERE_H
#define RAY_TRACING_SPHERE_H

#include "Vector.h"
#include "Ray.h"
#include "Material.h"
#include "Hittable.h"
#include "Util.h"
#include <memory>

#define range_close(_var, _a, _b) (_var > _a && _var < _b)

class Sphere : public Hittable {
public:
    bool hit(const Ray& ray, const Range& range, HitContext& result) const override;

    Sphere() = default;

    Sphere(const Point3& c, double rad, std::shared_ptr<Material> mat);
protected:
    Point3 center;
    double radius = 0.0;
    std::shared_ptr<Material> material;
};


#endif //RAY_TRACING_SPHERE_H
