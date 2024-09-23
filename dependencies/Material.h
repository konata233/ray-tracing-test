//
// Created on 2024/9/22.
//

#ifndef RAY_TRACING_MATERIAL_H
#define RAY_TRACING_MATERIAL_H

#include "Ray.h"
#include "Color.h"
#include "Hittable.h"

class Material {
public:
    virtual bool scatter(const Ray& ray_in, const HitContext& ctx, Color& color, Ray& scattered) const = 0;
};

class Lambertian : public Material {
public:
    bool scatter(const Ray& ray_in, const HitContext& ctx, Color& color, Ray& scattered) const override;

    explicit Lambertian(const Color& albedo);
protected:
    Color albedo;
};

class Metal : public Material {
public:
    bool scatter(const Ray& ray_in, const HitContext& ctx, Color& color, Ray& scattered) const override;

    explicit Metal(const Color& albedo);

protected:
    Color albedo;
};


#endif //RAY_TRACING_MATERIAL_H
