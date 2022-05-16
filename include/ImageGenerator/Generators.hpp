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

    public:
        /**
         * Initializes a new Random Generator with the given seed
         * @param main The instance of the manager
         * @param seed The seed for the RNG to use
         */ 
        RandomGenerator(const GeneratorManager& main, const long& seed);

        /**
         * Initializes a new Random Generator with the standard seed (system time)
         * @param main The instance of the manager
         */ 
        RandomGenerator(const GeneratorManager& main);

        virtual bool generateImage() = 0;
};

#endif //GENERATOR_HPP