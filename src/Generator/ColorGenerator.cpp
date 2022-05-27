#include <chrono>
#include <random>
#include "ImageGenerator/Generators.hpp"
#include "PixelRenderer/Renderer.hpp"

using namespace std;
using namespace chrono;

ColorGenerator::ColorGenerator(GeneratorManager& main, const Color& c) : Generator(main), c(c){}

ColorGenerator::ColorGenerator(GeneratorManager& main, const rgb& r, const rgb& g, const rgb& b, const rgb& a)
: ColorGenerator(main, Color(r, g, b, a)) {}

ColorGenerator::ColorGenerator(GeneratorManager& main, const uint32_t& rgbaColor)
: ColorGenerator(main, Color(rgbaColor)) {}

ColorGenerator::ColorGenerator(GeneratorManager& main) : Generator(main) {
    mt19937 gen;
    gen.seed(system_clock::now().time_since_epoch().count());
    c.setValue(gen() % 256, c.r);
    c.setValue(gen() % 256, c.g);
    c.setValue(gen() % 256, c.b);
    c.setValue(gen() % 256, c.a);
}


bool ColorGenerator::generateImage() {
    renderer->setColor(c);
    renderer->clear();
    return true;
}