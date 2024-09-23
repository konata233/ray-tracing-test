//
// Created on 2024/9/22.
//

#include "Ray.h"

Ray::Ray() {
    this->direction = Point3(0, 0, 0);
}

Ray::Ray(const Point3& orig, const Vector3& dir) {
    this->origin = orig;
    this->direction = dir;
}

const Point3& Ray::orig() const {
    return this->origin;
}

const Vector3& Ray::dir() const {
    return this->direction;
}

Point3 Ray::at(double t) const {
    return origin + direction * t;
}
