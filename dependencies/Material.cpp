//
// Created on 2024/9/22.
//

#include "Material.h"

Lambertian::Lambertian(const Color& albedo) {
    this->albedo = albedo;
}

bool Lambertian::scatter(const Ray& ray_in, const HitContext& ctx, Color& color, Ray& scattered) const {
    auto dir = ctx.normal + Vector3::random_unit_vec();
    if (dir.near_zero()) {
        dir = ctx.normal;
    }
    scattered = Ray(ctx.pos, dir);
    color = albedo;
    return true;
}

bool Metal::scatter(const Ray& ray_in, const HitContext& ctx, Color& color, Ray& scattered) const {
    auto reflected = Vector3::reflect(ray_in.dir(), ctx.normal);
    scattered = Ray(ctx.pos, reflected);
    color = albedo;
    return true;
}

Metal::Metal(const Color& albedo) {
    this->albedo = albedo;
}
