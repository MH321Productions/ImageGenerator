#ifndef IMAGE_GENERATOR_HPP
#define IMAGE_GENERATOR_HPP

#include <string>

using rgb = unsigned char;

class Generator;
class Renderer;

class GeneratorManager {
    friend class Generator;
    private:
        Renderer* renderer;
        int width, height, size; //Image dimensions
        std::string output; //Path to output file
        Generator* gen;
    
    public:
        /**
         * Initialize the Image Generator with the dimensions of the image and a path
         * to the output file
         * @param width The width in pixel
         * @param height The height in pixel
         * @param outFile The path to the output image
         */ 
        GeneratorManager(const int& width, const int& height, const std::string& outFile);

        void setGenerator(const Generator& gen);

        bool generateImage();
};

#endif //IMAGE_GENERATOR_HPP