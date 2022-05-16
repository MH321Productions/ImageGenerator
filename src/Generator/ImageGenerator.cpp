#include <iostream>
#include "ImageGenerator/ImageGenerator.hpp"
#include "ImageGenerator/Generators.hpp"
#include "PixelRenderer/Renderer.hpp"
#include "stb_image_write.h"

using namespace std;

GeneratorManager::GeneratorManager(const int& width, const int& height, const string& outFile)
    : width(width), height(height), output(outFile), gen(NULL) {

    //Initialize Renderer
    renderer = new Renderer(width, height);
}

void GeneratorManager::setGenerator(Generator* gen) {
    if (this->gen != NULL) delete this->gen; //Deletes an existing generator, if neccessary
    this->gen = gen;
}

bool GeneratorManager::generateImage() {
    if (!gen) {
        //No Generator available
        cerr << "No generator specified" << endl;
        return false;
    }

    cout << "Creating image" << endl;
    if (!gen->generateImage()) {
        //Image creation failed
        cerr << "Creation failed" << endl;
        return false;
    }

    //Saving image
    cout << "Saving image" << endl;
    
}