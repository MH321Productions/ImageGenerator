#ifndef GENERATOR_HPP
#define GENERATOR_HPP

using rgb = unsigned char;

class GeneratorManager;

class Generator {
    protected:
        rgb* data;
        int width, height, size;
    
    public:
        Generator(const GeneratorManager& main);

        virtual bool generateImage() = 0;
};

#endif //GENERATOR_HPP