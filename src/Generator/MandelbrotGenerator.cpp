#include <iostream>
#include <cmath>
#include <cinttypes>
#include "ImageGenerator/Generators.hpp"
#include "PixelRenderer/Renderer.hpp"
#include "PixelRenderer/Geometry.hpp"

using namespace std;

enum ColorNumber {NoColor, Red, Green, Blue};

/**
 * Helper class for complex numbers
 */ 
class Complex {
    public:
        double r, i;

        Complex(const double& r, const double& i) : r(r), i(i) {}
        Complex() : r(0), i(0) {}

        Complex operator + (const Complex& b) const {
            return {r + b.r, i + b.i};
        }

        Complex operator - (const Complex& b) const {
            return {r - b.r, i - b.i};
        }

        Complex operator * (const Complex& b) const {
            return {
                r * b.r - i * b.i,
                r * b.i + i * b.r
            };
        }

        double abs() const {
            return sqrt(r * r + i * i);
        }
};

const unsigned int MandelbrotGenerator::maxSteps = 256;
const double MandelbrotGenerator::threshold = 2.5;
const double MandelbrotGenerator::midScale = 1.470588235;
const double MandelbrotGenerator::highScale = 2.941176471;
const double MandelbrotGenerator::oneThird = 1.0 / 3.0;
const double MandelbrotGenerator::twoThird = 2.0 / 3.0;

MandelbrotGenerator::MandelbrotGenerator(GeneratorManager& main, const double& posX, const double& posY, const double& size, const int& colorMap)
: Generator(main), posX(posX), posY(posY), cWidth(size), cHeight(size / ratio) {
    invert = colorMap / 100 != 0;
    firstColor = (colorMap % 100) / 10;
    secondColor = colorMap % 10;
}

bool MandelbrotGenerator::generateImage() {
    Color c;
    Complex start(posX, posY);
    Complex offset, pos, cPixel;
    double offsetX, offsetY;
    unsigned int grayscale;

    renderer->setBlendingMethod(BlendingMethod::NoBlending);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            offsetX = (double) x / (double) width * cWidth;     //Value between 0 and cWidth for complex offset
            offsetY = -(double) y / (double) height * cHeight;   //Value between 0 and -cHeight for complex offset
            offset = {offsetX, offsetY};
            pos = start + offset; // Complex position of current pixel
            grayscale = 0;

            cPixel = {0, 0};
            while (cPixel.abs() <= threshold && grayscale < maxSteps) {
                cPixel = (cPixel * cPixel) + pos;
                grayscale++;
            }

            //This gives a wierd, but funny color scheme
            //c = Color((int) ((cPixel.r + 2.0) / 3.0 * 255), (int) ((cPixel.i + 1.0) / 2.0 * 255), (int) (cPixel.abs() / threshold * 255), 255);
            
            double value = (double) grayscale / (double) maxSteps;
            c = getColor(value);

            renderer->setPixel(x, y, c);
        }
    }

    return true;
}

Color MandelbrotGenerator::getColor(double& value) {
    if (invert) value = 1.0 - value;

    double normal = value;
    double mid = max((value - oneThird) * 1.5, 0.0);
    double high = max((value - twoThird) * 3, 0.0);

    double r, g, b;

    if (firstColor == NoColor) {
        r = normal;
        g = normal;
        b = normal;
    } else if (firstColor == Red) {
        r = normal;
        if (secondColor == Green) {
            g = mid;
            b = high;
        } else if (secondColor == Blue) {
            g = high;
            b = mid;
        } else {
            g = 0;
            b = 0;
        }
    } else if (firstColor == Green) {
        g = normal;
        if (secondColor == Red) {
            r = mid;
            b = high;
        } else if (secondColor == Blue) {
            r = high;
            b = mid;
        } else {
            r = 0;
            b = 0;
        }
    } else if (firstColor == Blue) {
        b = normal;
        if (secondColor == Red) {
            r = mid;
            g = high;
        } else if (secondColor == Green) {
            r = high;
            g = mid;
        } else {
            r = 0;
            g = 0;
        }
    }

    return {(int) (r * 255), (int) (g * 255), (int) (b * 255), 255};
}