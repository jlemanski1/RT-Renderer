#include <iostream>
#include "ray.hpp"

vec3 colour(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main() {
    //Window Dimensions
    int nx = 200;
    int ny = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    //Vectors
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    //Loop through pixels left to right
    for (int j = ny - 1; j >= 0; j--) {
        //Loop through pixels top to bottom
        for (int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 col = colour(r);
            int ir = int(255.99 * col[0]);  // Red
            int ig = int(255.99 * col[1]);  //Green
            int ib = int(255.99 * col[2]);  //Blue

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}