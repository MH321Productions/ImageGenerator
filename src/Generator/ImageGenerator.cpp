#include <iostream>
#include "ImageGenerator/ImageGenerator.hpp"
#include "ImageGenerator/Generators.hpp"
#include "PixelRenderer/Renderer.hpp"
#include "stb_image_write.h"

using namespace std;

GeneratorManager::GeneratorManager(const int& width, const int& height, const string& outFile, ImageFormat format)
    : width(width), height(height), output(outFile), gen(NULL), format(format), size(width * height) {

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
    int result;
    switch (format) {
        case ImageFormat::JPG:
            result = stbi_write_jpg(output.c_str(), width, height, 4, renderer->getData(), 50);
            break;
        case ImageFormat::BMP:
            result = stbi_write_bmp(output.c_str(), width, height, 4, renderer->getData());
            break;
        case ImageFormat::TGA:
            result = stbi_write_tga(output.c_str(), width, height, 4, renderer->getData());
            break;
        
        //Default output is PNG
        case ImageFormat::PNG:
        default:
            result = stbi_write_png(output.c_str(), width, height, 4, renderer->getData(), width * 4);
            break;
    }

    if (!result) {
        cerr << "Couldn't save image" << endl;
        return false;
    }

    return true;
}

Generator::Generator(const GeneratorManager& main)
: renderer(main.renderer), width(main.width), height(main.height), size(main.size) {}