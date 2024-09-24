//
// Created on 2024/9/24.
//

#include "Camera.h"

Camera::Camera(Point3 look_at, Point3 look_from, Point3 up) {
    this->look_at = look_at;
    this->look_from = look_from;
    this->up = up;
}

auto Camera::get_uvw() const {
    auto w = (look_from - look_at).normalize();
    auto u = up.cross_product(w).normalize();
    auto v = w.cross_product(u);
    return std::tuple<Vector3, Vector3, Vector3>(w, u, v);
}
