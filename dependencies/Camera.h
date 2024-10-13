//
// Created on 2024/9/24.
//

#ifndef RAY_TRACING_CAMERA_H
#define RAY_TRACING_CAMERA_H

#include "Vector.h"

class Camera {
public:
    Point3 look_at;
    Point3 look_from;
    Vector3 up;
    double defocus_angle = 0;
    double focal_len = 0;

    [[nodiscard]] std::tuple<Vector3, Vector3, Vector3> get_uvw() const;

    Camera() = default;

    Camera(Point3 look_from, Point3 look_at, Point3 up);

    Camera(Point3 look_from, Point3 look_at, Point3 up, double defocus_angle_rad, double focal_len);
};


#endif //RAY_TRACING_CAMERA_H
