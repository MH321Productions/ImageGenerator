#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <random>
#include "PixelRenderer/Renderer.hpp"

using rgb = unsigned char;

class GeneratorManager;

class Generator {
    protected:
        Renderer* renderer;
        int width, height, size;
    
    public:
        Generator(const GeneratorManager& main);

        virtual bool generateImage() = 0;
};

/**
 * Generator that generates an image
 * containing random colored blocks
 */ 
class RandomGenerator : public virtual Generator {
    private:
        long seed;
        std::mt19937_64 gen;
        int blockSize;

    public:
        /**
         * Initializes a new Random Generator with the given seed and block size
         * @param main The instance of the manager
         * @param seed The seed for the RNG to use
         * @param blockSize the size of the generated blocks
         */ 
        RandomGenerator(const GeneratorManager& main, const long& seed, const int& blockSize = 10);

        /**
         * Initializes a new Random Generator with the standard seed (system time)
         * and given block size
         * @param main The instance of the manager
         * @param blockSize the size of the generated blocks
         */ 
        RandomGenerator(const GeneratorManager& main, const int& blockSize = 10);

        virtual bool generateImage();
};

/**
 * Generates an image with a single color
 */ 
class ColorGenerator: public virtual Generator {
    private:
        Color c;
    
    public:
        /**
         * Initializes a new Color Generator with the given PixelRenderer Color class
         * @param main The instance of the manager
         * @param c The color class to use
         */ 
        ColorGenerator(const GeneratorManager& main, const Color& c);

        /**
         * Initializes a new Color Generator with the given color values for r, g, b and a separated
         * @param main The instance of the manager
         * @param r The red   value (0-255)
         * @param g The green value (0-255)
         * @param b The blue  value (0-255)
         * @param a The alpha value (0-255) (standard: 255)
         */ 
        ColorGenerator(const GeneratorManager& main, const rgb& r, const rgb& g, const rgb& b, const rgb& a = 255);

        /**
         * Initializes a new Color Generator with the given color values for r, g, b and a in a single HTML-style value
         * (0xRRGGBBAA)
         * @param main The instance of the manager
         * @param rgba The color value (0-0xFFFFFFFF)
         */ 
        ColorGenerator(const GeneratorManager& main, const uint32_t& rgbaColor);

        /**
         * Initializes a new Color Generator with a randomized color
         * @param main The instance of the manager
         */ 
        ColorGenerator(const GeneratorManager& main);

        virtual bool generateImage();
};

#endif //GENERATOR_HPP