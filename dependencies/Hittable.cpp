//
// Created on 2024/9/22.
//

#include "Hittable.h"

void HitContext::set_front(const Ray& ray, const Vector3& normal_out) {
    front_face = ray.dir().dot_product(normal_out) < 0;
    normal = front_face ? normal_out : -normal_out;
}
