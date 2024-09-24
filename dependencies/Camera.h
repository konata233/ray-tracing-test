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

    auto get_uvw() const;

    Camera() = default;

    Camera(Point3 look_at, Point3 look_from, Point3 up);
};


#endif //RAY_TRACING_CAMERA_H
