//
// Created on 2024/9/21.
//

#include "Color.h"

const Range range(0.0000, 0.9999);

Color::Color(Vector3 normalized) {
    this->color_normalized = normalized;
}

int Color::r() const {
    return int(range.clamp(gamma_correct(color_normalized.x())) * 256.0);
}

int Color::g() const {
    return int(range.clamp(gamma_correct(color_normalized.y())) * 256.0);
}

int Color::b() const {
    return int(range.clamp(gamma_correct(color_normalized.z())) * 256.0);
}

Color::Color(double r_normalized, double g_normalized, double b_normalized) {
    this->color_normalized[0] = r_normalized;
    this->color_normalized[1] = g_normalized;
    this->color_normalized[2] = b_normalized;
}

std::tuple<unsigned char, unsigned char, unsigned char> Color::serialize() const {
    auto tuple = std::tuple<unsigned char, unsigned char,unsigned char>(this->r(), this->g(), this->b());
    return tuple;
}

Color Color::operator*(const Color& rhs) const {
    return {this->color_normalized[0] * rhs.color_normalized[0],
            this->color_normalized[1] * rhs.color_normalized[1],
            this->color_normalized[2] * rhs.color_normalized[2]};
}

Color Color::operator+=(const Color& rhs) {
    auto& r = this->color_normalized[0];
    r += rhs.color_normalized[0];
    auto& g = this->color_normalized[1];
    g += rhs.color_normalized[1];
    auto& b = this->color_normalized[2];
    b += rhs.color_normalized[2];
    return *this;
}

Color Color::operator*(double rhs) const {
    return {this->color_normalized[0] * rhs,
            this->color_normalized[1] * rhs,
            this->color_normalized[2] * rhs};
}

Color Color::operator+(const Color& rhs) const {
    return {this->color_normalized[0] + rhs.color_normalized[0],
            this->color_normalized[1] + rhs.color_normalized[1],
            this->color_normalized[2] + rhs.color_normalized[2]};
}
