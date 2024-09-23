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

inline double rad(double deg);

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

};

double random_double();

double random_double(double min, double max);

double gamma_correct(double linear);

#endif //RAY_TRACING_UTIL_H
