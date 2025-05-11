#include <iostream>
#include "vec3.h"

int main() {
    // image
    int image_width = 256;
    int image_height = 256;

    // render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height-j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {

            auto r = double(i) / (image_width-1); // scales 0-1
            auto g = double(j) / (image_height-1); // scales 0-1
            auto b = 0.0;

            int ir = (int(255.99) * r);
            int ig = (int(255.99) * g);
            int ib = (int(255.99) * b);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }
    std::clog << "\rDone.                   \n";
}