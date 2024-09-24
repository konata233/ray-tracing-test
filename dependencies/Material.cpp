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
    auto reflected = Vector3::reflect(ray_in.dir(), ctx.normal) + (Vector3::random_unit_vec() * fuzziness);
    scattered = Ray(ctx.pos, reflected);
    color = albedo;
    return (scattered.dir().dot_product(ctx.normal) > 0);
}

Metal::Metal(const Color& albedo, double fuzziness = 0) {
    this->albedo = albedo;
    this->fuzziness = fuzziness;
}

///
/// \param refraction_index sin(i) / sin(r)
Dielectric::Dielectric(double refraction_index) {
    this->refraction_index = std::fmax(1.0, refraction_index);
}

bool Dielectric::scatter(const Ray& ray_in, const HitContext& ctx, Color& color, Ray& scattered) const {
    double idx = ctx.front_face ? refraction_index : (1 / refraction_index);
    Vector3 normalized = ray_in.dir().normalize();
    double cos_theta = std::min(ctx.normal.dot_product(-normalized), 1.0);
    double sin_theta = std::sqrt(1 - cos_theta * cos_theta);

    Vector3 out;
    bool can_refract = sin_theta * idx <= 1;
    if (can_refract && reflectance(cos_theta, idx) <= random_double()) {
        out = Vector3::refract(normalized, ctx.normal, idx);
    } else {
        out = Vector3::reflect(normalized, ctx.normal);
    }
    color = Color(1, 1, 1);
    scattered = Ray(ctx.pos, out);
    return true;
}

double Dielectric::reflectance(double cos_theta, double refraction_idx) {
    double r = (1 - refraction_idx) / (1 + refraction_idx);
    r = r * r;
    return r + (1 - r) * std::pow((1 - cos_theta),5);
}
