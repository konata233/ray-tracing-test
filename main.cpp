#include <iostream>
#include <memory>
#include "dependencies/Sphere.h"
#include "dependencies/Screen.h"
#include "dependencies/Image.h"
#include "dependencies/Material.h"
#include "dependencies/Color.h"
#include "dependencies/Vector.h"
#include "dependencies/World.h"

int main() {
    auto a = (Vector3(1,2,3).cross_product(Vector3(0, 1, -1)));
    Color c1 = Color(0.3, 0.2, 1) * Color(0.2, 0.5, 0.3);
    std::cout << c1.color_normalized[0] << " " << c1.color_normalized[1] << " " << c1.color_normalized[2];
    Sphere s = Sphere(Point3(0, 0, 1), 0.5, nullptr);
    HitContext ctx;
    bool hit = s.hit(Ray(Point3(0, 0, 0), Vector3(0, 0, 1)), Range(0.001, infinity), ctx);
    std::cout << (hit ? "hit!" : "not hit");
    //return 0;

    auto ground_lambertian = std::make_shared<Lambertian>(Color(1, 1, 0.1));
    auto metal = std::make_shared<Metal>(Color(1, 0.6, 1), 0);
    auto dielectric = std::make_shared<Dielectric>(1.33);
    auto air = std::make_shared<Dielectric>(1);
    auto lambertian = std::make_shared<Lambertian>(Color(0, 0, 1));
    auto sphere0 = std::make_shared<Sphere>(Point3(0, 0, -1.0), 0.5, lambertian);
    auto sphere1 = std::make_shared<Sphere>(Point3(1, 0, -1.0), 0.5, metal);
    auto sphere2 = std::make_shared<Sphere>(Point3(-1, 0, -1.0), -0.5, dielectric); // invert normal
    auto ground = std::make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100.0, ground_lambertian);

    World world = World();
    world.push_back(ground);
    world.push_back(sphere1).push_back(sphere0).push_back(sphere2);//.push_back(std::make_shared<Sphere>(Point3(-1.5, 0.1, -1.0), 0.45, metal));

    Camera camera = Camera(Point3(-2, 2, 1), Point3(0, 0, -1), Vector3(0, 1, 0), rad(0), 3.4);
    Screen screen = Screen(800, 16.0 / 9.0, 120, 50, rad(30), camera);
    screen.render(world);
    auto buffer = screen.serialize_all();
    ImageDevice device = ImageDevice(buffer, 3, 800, 450);
    char filename[] = "test.png";
    device.write_to_file(filename);
    return 0;
}
