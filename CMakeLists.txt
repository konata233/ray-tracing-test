cmake_minimum_required(VERSION 3.29)
project(ray_tracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(ray_tracing main.cpp
        dependencies/Image.cpp
        dependencies/Image.h
        dependencies/Vector.cpp
        dependencies/Vector.h
        dependencies/Color.cpp
        dependencies/Color.h
        dependencies/Ray.cpp
        dependencies/Ray.h
        dependencies/Screen.cpp
        dependencies/Screen.h
        dependencies/Sphere.cpp
        dependencies/Sphere.h
        dependencies/Hittable.cpp
        dependencies/Hittable.h
        dependencies/World.cpp
        dependencies/World.h
        dependencies/Util.cpp
        dependencies/Util.h
        dependencies/Material.cpp
        dependencies/Material.h
        dependencies/Camera.cpp
        dependencies/Camera.h)
