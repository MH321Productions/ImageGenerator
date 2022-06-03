#include <iostream>
#include "ImageGenerator/ImageGenerator.hpp"
#include "ImageGenerator/Generators.hpp"

using namespace std;

int main(int anzahl, char* args[]) {
    cout << "Hello World" << endl;

    //Tests
    GeneratorManager man(1920, 1080, "Test.png", PNG);
    //RandomGenerator rand(man, 20);
    //ColorGenerator color(man, 0xFFFFFFFF);
    //TransparentGenerator trans(man);
    MandelbrotGenerator mandelbrot(man, -2.5, 1.1, 3.5, 132);
    man.generateImage();
}
