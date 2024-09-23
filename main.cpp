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
    auto a = (Vector3(1,2,3) - Vector3(0, 1, -1));

    Sphere s = Sphere(Point3(0, 0, 1), 0.5, nullptr);
    HitContext ctx;
    bool hit = s.hit(Ray(Point3(0, 0, 0), Vector3(0, 0, 1)), Range(0.001, infinity), ctx);
    std::cout << (hit ? "hit!" : "not hit");
    //return 0;

    auto lambertian = std::make_shared<Lambertian>(Color(1, 0, 0));
    auto metal = std::make_shared<Metal>(Color(1, 1, 1));
    auto sphere0 = std::make_shared<Sphere>(Point3(-0.5, 0, -1.0), 0.3, lambertian);
    auto sphere1 = std::make_shared<Sphere>(Point3(0.5, 0, -1.0), 0.3, metal);

    World world = World();
    world.push_back(sphere0).push_back(sphere1);
    Screen screen = Screen(1920, 16.0 / 9.0, 10, 5, 2, 0.5, Point3(0, 0, 0));
    screen.render(world);
    auto buffer = screen.serialize_all();
    ImageDevice device = ImageDevice(buffer, 3, 1920, 1080);
    char filename[] = "test.png";
    device.write_to_file(filename);
    return 0;
}
