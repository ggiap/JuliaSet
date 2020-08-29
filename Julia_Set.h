#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <thread>


static constexpr int IMAGE_WIDTH = 800;
static constexpr int IMAGE_HEIGHT = 600;

class Julia
{
public:
    Julia();
    void updateImage(double zoom, double offsetX, double offsetY, sf::Image& image) const;

private:
    static const int MAX = 500; // maximum number of iterations for mandelbrot()
                         
    std::array<sf::Color, MAX + 1> colors;

    int julia(double startReal, double startImag) const;
    sf::Color getColor(int iterations) const;
    void updateImageSlice(double zoom, double offsetX, double offsetY, sf::Image& image, int minY, int maxY) const;
};