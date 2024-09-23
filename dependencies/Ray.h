//
// Created on 2024/9/22.
//

#ifndef RAY_TRACING_RAY_H
#define RAY_TRACING_RAY_H

#include "Vector.h"

class Ray {
public:
    [[nodiscard]] const Point3& orig() const;

    [[nodiscard]] const Vector3& dir() const;

    Ray();

    Ray(const Point3& orig, const Vector3& dir);

    [[nodiscard]] Point3 at(double t) const;

protected:
   Point3 origin;
   Vector3 direction;
};


#endif //RAY_TRACING_RAY_H
