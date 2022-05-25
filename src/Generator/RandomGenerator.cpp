#include <iostream>
#include <chrono>
#include "ImageGenerator/Generators.hpp"
#include "PixelRenderer/Renderer.hpp"
#include "PixelRenderer/Geometry.hpp"

using namespace std;
using namespace chrono;


RandomGenerator::RandomGenerator(GeneratorManager& main, const long& seed, const int& blockSize)
: Generator(main), seed(seed), blockSize(blockSize) {
    gen.seed(seed);
}

RandomGenerator::RandomGenerator(GeneratorManager& main, const int& blockSize)
: RandomGenerator(main, system_clock::now().time_since_epoch().count(), blockSize) {} //Use standard seed (system time)


bool RandomGenerator::generateImage() {
    Color c;
    Rect r(0, 0, blockSize, blockSize);
    int i;
    renderer->setBlendingMethod(BlendingMethod::NoBlending);

    for (int y = 0; y < height; y += blockSize) {
        for (int x = 0; x < width; x += blockSize) {
            //Generate random values for r, g, b, a
            c.setValue(gen() % 256, c.r);
            c.setValue(gen() % 256, c.g);
            c.setValue(gen() % 256, c.b);
            c.setValue(gen() % 256, c.a);

            r.x = x;
            r.y = y;
            renderer->setColor(c);
            renderer->fillRect(r);
        }
    }

    return true;
}