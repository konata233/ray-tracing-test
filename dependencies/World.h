//
// Created on 2024/9/22.
//

#ifndef RAY_TRACING_WORLD_H
#define RAY_TRACING_WORLD_H


#include <vector>
#include <memory>
#include "Hittable.h"

class World : public Hittable {
public:
    std::vector<std::shared_ptr<Hittable>> objects;

    World() = default;

    explicit World(std::shared_ptr<Hittable> initial);

    World& push_back(std::shared_ptr<Hittable> obj);

    World& clear();

    bool hit(const Ray& ray, const Range& range, HitContext& result) const override;
};


#endif //RAY_TRACING_WORLD_H
