//
// Created on 2024/9/21.
//

#ifndef RAY_TRACING_VECTOR_H
#define RAY_TRACING_VECTOR_H

#include "Util.h"
#include <cmath>

class Vector3 {
public:
    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    Vector3 operator-(const Vector3& rhs) const;

    Vector3 operator-() const;

    Vector3 operator+(const Vector3& rhs) const;

    Vector3 operator+();

    double operator[](int idx) const;

    double& operator[](int idx);

    Vector3 operator*(double rhs) const;

    Vector3 operator*(const Vector3& rhs) const;

    Vector3& operator*=(double rhs);

    Vector3 operator/(double rhs) const;

    Vector3& operator/=(double rhs);

    Vector3& operator+=(const Vector3& rhs);

    Vector3& operator-=(const Vector3& rhs);

    [[nodiscard]] double mod() const;

    [[nodiscard]] double mod_squared() const;

    [[nodiscard]] Vector3 normalize() const;

    static Vector3 random_vec();

    static Vector3 random_vec(double min, double max);

    static Vector3 random_unit_vec();

    static Vector3 random_unit_vec2d();

    static Vector3 random_with_normal(const Vector3& normal);

    static Vector3 reflect(const Vector3& ray_direction, const Vector3& normal);

    static Vector3 refract(const Vector3& ray_direction, const Vector3& normal, double refraction_idx);

    [[nodiscard]] double dot_product(const Vector3& rhs) const;

    [[nodiscard]] Vector3 cross_product(const Vector3& rhs) const;

    [[nodiscard]] bool near_zero() const;

    Vector3();

    explicit Vector3(const double* data);

    Vector3(double x, double y, double z);
protected:
    double data[3] {0, 0, 0};
};

using Point3 = Vector3;

#endif //RAY_TRACING_VECTOR_H
