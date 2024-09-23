//
// Created on 2024/9/22.
//

#ifndef RAY_TRACING_HITTABLE_H
#define RAY_TRACING_HITTABLE_H

#include "Vector.h"
#include "Ray.h"
#include "Util.h"
#include <memory>

class Material;

class HitContext {
public:
    Point3 pos;
    Vector3 normal;
    double t = 0.0;
    bool front_face = true;

    std::shared_ptr<Material> material;

    void set_front(const Ray& ray, const Vector3& normal_out);
};

class Hittable {
public:
    virtual bool hit(const Ray& ray, const Range& range, HitContext& result) const = 0;
};


#endif //RAY_TRACING_HITTABLE_H
