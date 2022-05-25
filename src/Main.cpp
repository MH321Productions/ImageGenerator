#include <iostream>
#include "ImageGenerator/ImageGenerator.hpp"
#include "ImageGenerator/Generators.hpp"

using namespace std;

int main(int anzahl, char* args[]) {
    cout << "Hello World" << endl;

    //Tests
    GeneratorManager man(1920, 1080, "Test.png", PNG);
    //RandomGenerator rand(man, 20);
    //ColorGenerator color(man);
    TransparentGenerator trans(man);
    man.generateImage();
}
