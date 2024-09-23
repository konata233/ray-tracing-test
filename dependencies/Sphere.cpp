//
// Created on 2024/9/22.
//
#include <cmath>

#include "Sphere.h"

Sphere::Sphere(const Point3& c, double rad, std::shared_ptr<Material> mat) {
    this->center = c;
    this->radius = rad;
    this->material = mat;
}

bool Sphere::hit(const Ray& ray, const Range& range, HitContext& result) const {
    auto oc = center - ray.orig();
    double a = ray.dir().mod_squared();
    double b = ray.dir().dot_product(oc);
    double c = oc.mod_squared() - this->radius * this->radius;
    double delta = b * b - a * c;

    if (delta < 0) {
        return false;
    } else {
        double sqrt_delta = std::sqrt(delta);
        double root = (b - sqrt_delta) / a;
        if (!range.contains_closed(root)) {
            root = (b + sqrt_delta) / a;
            if (!range.contains_closed(root)) {
                return false;
            }
        }
        result.pos = ray.at(root);
        result.t = root;
        auto normal = (result.pos - center) / radius;
        result.set_front(ray, normal);
        result.material = material;
        return true;
    }
}
