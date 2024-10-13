//
// Created on 2024/9/22.
//

#include "Util.h"

const Range Range::empty = Range(infinity, -infinity);

const Range Range::real = Range(-infinity, infinity);

const Range Range::normalize = Range(-1, 1);

const Range Range::normalize_pos = Range(0, 1);

Range::Range() {
    min = infinity;
    max = -infinity;
}

Range::Range(double min, double max) {
    this->min = min;
    this->max = max;
}

double Range::size() const {
    return this->max - this->min;
}

bool Range::contains(double x) const {
    return (x >= this->min && x <= this->max);
}

bool Range::contains_closed(double x) const {
    return (x > this->min && x < this->max);
}

double Range::clamp(double x) const {
    if (x > max) {
        return max;
    } else if (x < min) {
        return min;
    }
    return x;
}
