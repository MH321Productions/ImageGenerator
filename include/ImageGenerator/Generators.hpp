#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <random>

using rgb = unsigned char;

class GeneratorManager;
class Renderer;

class Generator {
    protected:
        Renderer* renderer;
        int width, height, size;
    
    public:
        Generator(const GeneratorManager& main);

        virtual bool generateImage() = 0;
};

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

#endif //GENERATOR_HPP