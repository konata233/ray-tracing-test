//
// Created on 2024/9/22.
//

#include <iostream>
#include "Screen.h"
#include "Material.h"

Screen::Screen(int width, double aspect, int sample, int max_depth, double vfov_rad, Camera& camera) {
    this->img_width = width;
    this->img_height = int(width / aspect);
    this->sample = sample;
    this->sample_scale = 1.0 / sample;
    this->max_depth = max_depth;
    this->aspect = aspect;

    this->center = camera.look_from;
    this->focal_length = camera.focal_len;
    this->defocus_angle = camera.defocus_angle;
    double defocus_rad = focal_length * std::tan(camera.defocus_angle * 0.5);

    this->fov = vfov_rad;
    this->viewport_height = std::tan(vfov_rad * 0.5) * 2 * focal_length;
    this->viewport_width = viewport_height * aspect;

    auto [u, v, w] = camera.get_uvw();

    this->defocus_u = u * defocus_rad;
    this->defocus_v = v * defocus_rad;

    this->viewport_u = u * viewport_width;
    this->viewport_v = v * viewport_height;

    this->u_pixel = viewport_u * (1.0 / this->img_width);
    this->v_pixel = viewport_v * (1.0 / this->img_height);

    this->viewport_origin = this->center - (w * focal_length) // -look_at!!
            - viewport_u / 2 - viewport_v / 2;

    this->buffer = new Color[img_width * img_height];
}

auto Screen::ray_at(int i, int j) {
    auto offset = random_scatter();
    auto defocus = Vector3::random_unit_vec2d().normalize();
    auto pos = this->viewport_origin + ((u_pixel * (i + offset.x())) + (v_pixel * (j + offset.y())));
    //std::cout << pos.x() << " " << pos.y() << std::endl;
    auto ray_dir = pos - (this->defocus_angle <= 0 ? this->center
            : (this->center + (defocus_u * defocus.x() + defocus_v * defocus.y())));
    return Ray(center, ray_dir);
}

Vector3 Screen::random_scatter() {
    return {random_double() - 0.5, random_double() - 0.5, 0};
}

auto Screen::ray_color(Ray& ray_in, int depth, const World& world) {
    if (depth <= 0) {
        return Color(0, 0, 0);
    }
    HitContext ctx;
    if (world.hit(ray_in, Range(0.001, infinity), ctx)) {
        Ray scattered;
        Color color;
        if (ctx.material->scatter(ray_in, ctx, color, scattered)) {
            return color * ray_color(scattered, depth - 1, world);
        } else {
            return Color(0, 0, 0);
        }
    }
    auto a = Range::normalize_pos.clamp((ray_in.dir().normalize().y() + 1) - 0.4);
    //std::cout << a << std::endl;
    return Color(1, 1, 1) * (1.0 - a) + Color(0.6, 0.6, 1) * a;
}

void Screen::render(const World& world) {
    for (int i = 0; i < img_width; i++) {
        std::cout << "Rendering: column " << i + 1 << " of " << img_width << "..." << std::endl;
        for (int j = 0; j < img_height; j++) {
            auto color = Color(0, 0, 0);
            for (int k = 0; k < sample; k++) {
                auto ray = ray_at(i, j);
                color += ray_color(ray, max_depth, world);
            }
            color = color * sample_scale;
            this->buffer[j * img_width + i] = color;
        }
    }
}



Screen::~Screen() {
    delete[] this->buffer;
}

unsigned char* Screen::serialize_all() const {
    auto* buf = new unsigned char[img_width * img_height * 3];
    for (int i = 0; i < img_width; i++) {
        for (int j = 0; j < img_height; j++) {
            auto [r, g, b] = this->buffer[j * img_width + i].serialize();
            buf[(j * img_width + i) * 3 + 0] = r;
            buf[(j * img_width + i) * 3 + 1] = g;
            buf[(j * img_width + i) * 3 + 2] = b;
        }
    }
    return buf;
}
