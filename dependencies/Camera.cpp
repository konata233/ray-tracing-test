//
// Created on 2024/9/24.
//

#include "Camera.h"

Camera::Camera(Point3 look_from, Point3 look_at, Point3 up, double defocus_angle_rad, double focal_len) {
    this->look_at = look_at;
    this->look_from = look_from;
    this->up = up;
    this->defocus_angle = defocus_angle_rad;
    this->focal_len = focal_len;
}

std::tuple<Vector3, Vector3, Vector3> Camera::get_uvw() const {
    auto w = (look_from - look_at).normalize();
    auto u = up.cross_product(w).normalize();
    auto v = w.cross_product(u);
    return {u, v, w};
}

Camera::Camera(Point3 look_from, Point3 look_at, Point3 up) {
    this->look_at = look_at;
    this->look_from = look_from;
    this->up = up;
    this->defocus_angle = 0;
    this->focal_len = (look_at - look_from).mod();
}
