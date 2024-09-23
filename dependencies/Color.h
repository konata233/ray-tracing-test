//
// Created on 2024/9/21.
//

#ifndef RAY_TRACING_COLOR_H
#define RAY_TRACING_COLOR_H

#include <tuple>
#include "Vector.h"
#include "Util.h"

class Color {
public:
    [[nodiscard]] int r() const;
    [[nodiscard]] int g() const;
    [[nodiscard]] int b() const;

    [[nodiscard]] std::tuple<unsigned char, unsigned char, unsigned char> serialize() const;

    Color operator*(const Color& rhs) const;

    Color operator+(const Color& rhs) const;

    Color operator+=(const Color& rhs);

    Color operator*(double rhs) const;

    Color() = default;

    explicit Color(Vector3 normalized);

    Color(double r_normalized, double g_normalized, double b_normalized);

    Vector3 color_normalized;
};


#endif //RAY_TRACING_COLOR_H
