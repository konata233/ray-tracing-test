//
// Created on 2024/9/21.
//

#include "Vector.h"
#include "Util.h"

#define range(_var, _a, _b) (_var >= _a && _var < _b)

Vector3::Vector3() = default;

Vector3::Vector3(const double* data) {
    this->data[0] = data[0];
    this->data[1] = data[1];
    this->data[2] = data[2];
}

double Vector3::x() const {
    return data[0];
}

double Vector3::y() const {
    return data[1];
}

double Vector3::z() const {
    return data[2];
}

Vector3 Vector3::operator-(const Vector3& rhs) const {
    return {this->x() - rhs.x(), this->y() - rhs.y(), this->z() - rhs.z()};
}

Vector3 Vector3::operator-() const {
    return {-this->x(), -this->y(), -this->z()};
}

Vector3 Vector3::operator+(const Vector3& rhs) const {
    return {this->x() + rhs.x(), this->y() + rhs.y(), this->z() + rhs.z()};
}

Vector3 Vector3::operator+() {
    return *this;
}

double Vector3::operator[](int idx) const {
    idx = range(idx, 0, 3) ? idx : 0;
    return this->data[idx];
}

double& Vector3::operator[](int idx) {
    idx = range(idx, 0, 3) ? idx : 0;
    return this->data[idx];
}

Vector3 Vector3::operator*(double rhs) const {
    return {this->x() * rhs, this->y() * rhs, this->z() * rhs};
}

Vector3& Vector3::operator*=(double rhs) {
    this->data[0] *= rhs;
    this->data[1] *= rhs;
    this->data[2] *= rhs;
    return *this;
}

Vector3 Vector3::operator/(double rhs) const {
    return (*this * (1 / rhs));
}

Vector3& Vector3::operator/=(double rhs) {
    rhs = 1/ rhs;
    this->data[0] *= rhs;
    this->data[1] *= rhs;
    this->data[2] *= rhs;
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& rhs) {
    this->data[0] += rhs.x();
    this->data[1] += rhs.y();
    this->data[2] += rhs.z();
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs) {
    this->data[0] -= rhs.x();
    this->data[1] -= rhs.y();
    this->data[2] -= rhs.z();
    return *this;
}

Vector3::Vector3(double x, double y, double z) {
    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;
}

double Vector3::mod_squared() const {
    return this->x() * this->x() + this->y() * this->y() + this->z() * this->z();
}

double Vector3::mod() const {
    return std::sqrt(mod_squared());
}

double Vector3::dot_product(const Vector3& rhs) const {
    return this->x() * rhs.x() + this->y() * rhs.y() + this->z() * rhs.z();
}

Vector3 Vector3::normalize() const {
    double mod = 1 / this->mod();
    return {this->x() * mod, this->y() * mod, this->z() * mod};
}

Vector3 Vector3::random_unit_vec() {
    return random_vec(-1.0, 1.0).normalize();
}

Vector3 Vector3::random_vec() {
    return {random_double(), random_double(), random_double()};
}

Vector3 Vector3::random_vec(double min, double max) {
    return {random_double(min, max), random_double(min, max), random_double(min, max)};
}

Vector3 Vector3::random_with_normal(const Vector3& normal) {
    auto vec = random_unit_vec();
    if (vec.dot_product(normal) > 0.0) {
        return vec;
    } else {
        return -vec;
    }
}

bool Vector3::near_zero() const {
    double small = 1e-8;
    return (std::fabs(x()) < small && std::fabs(y()) < small && std::fabs(z()) < small);
}

Vector3 Vector3::reflect(const Vector3& ray_direction, const Vector3& normal) {
    return ray_direction - normal * (2 * normal.dot_product(ray_direction));
}

Vector3 Vector3::operator*(const Vector3& rhs) const {
    return {this->x() * rhs.x(), this->y() * rhs.y(), this->z() * rhs.z()};
}
