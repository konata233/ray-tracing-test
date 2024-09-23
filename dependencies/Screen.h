//
// Created on 2024/9/22.
//

#ifndef RAY_TRACING_SCREEN_H
#define RAY_TRACING_SCREEN_H

#include "Vector.h"
#include "Color.h"
#include "World.h"
#include "Util.h"
#include "Ray.h"

class Screen {
public:
    void render(const World& world);

    auto ray_at(int i, int j);

    auto ray_color(Ray& ray_in, int depth, const World& world);

    static Vector3 random_scatter();

    Screen(int width, double aspect, int sample, int max_depth, double vp_width, double focal_len,
           const Point3& center);

    [[nodiscard]] unsigned char* serialize_all() const;

    ~Screen();
protected:
    int img_width;
    int img_height;
    int sample;
    int max_depth;
    double sample_scale;
    double aspect;

    double viewport_height;
    double viewport_width;
    double focal_length;
    Point3 center;

    Vector3 viewport_u;
    Vector3 viewport_v;

    Vector3 u_pixel;
    Vector3 v_pixel;

    Point3 viewport_origin;

    Color* buffer;
};


#endif //RAY_TRACING_SCREEN_H