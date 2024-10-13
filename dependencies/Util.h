//
// Created on 2024/9/22.
//
#pragma once

#ifndef RAY_TRACING_UTIL_H
#define RAY_TRACING_UTIL_H

#include <limits>
#include <random>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979323857;

inline double rad(double deg) {
    return deg * pi / 180.0;
}

class Range {
public:
    double min;
    double max;

    Range();

    Range(double min, double max);

    [[nodiscard]] double size() const;

    [[nodiscard]] bool contains(double x) const;

    [[nodiscard]] bool contains_closed(double x) const;

    [[nodiscard]] double clamp(double x) const;

    static const Range empty;

    static const Range real;

    static const Range normalize;

    static const Range normalize_pos;

};

inline double random_double() {
    static std::random_device device;
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    static std::mt19937 gen(device());
    return dist(gen);
}

inline double random_double(double min, double max) {
    return min + random_double() * (max - min);
}

inline double gamma_correct(double linear) {
    if (linear > 0) {
        return std::sqrt(linear);
    }
    return 0;
}

#endif //RAY_TRACING_UTIL_H
