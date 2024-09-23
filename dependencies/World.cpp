//
// Created on 2024/9/22.
//

#include "World.h"

World::World(std::shared_ptr<Hittable> initial) {
    this->objects.push_back(initial);
}

World& World::push_back(std::shared_ptr<Hittable> obj) {
    this->objects.push_back(obj);
    return *this;
}

World& World::clear() {
    this->objects.clear();
    return *this;
}

bool World::hit(const Ray& ray, const Range& range, HitContext& result) const {
    HitContext temp;
    bool hit = false;
    double dist_min = range.max;

    for (const auto& obj: objects) {
        if (obj->hit(ray, Range(range.min, dist_min), temp)) {
            hit = true;
            dist_min = temp.t;
            result = temp;
        }
    }
    return hit;
}
