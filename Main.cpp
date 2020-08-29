#include "Julia_Set.h"
#include <filesystem>

int main()
{
    Julia ju;

    sf::RenderWindow window(sf::VideoMode(IMAGE_WIDTH, IMAGE_HEIGHT), "Julia");
    window.setFramerateLimit(0);

    std::filesystem::remove_all("Ju_Images");
    std::filesystem::create_directory("Ju_Images");

    sf::Image image;
    image.create(IMAGE_WIDTH, IMAGE_HEIGHT, sf::Color(0, 0, 0));
    sf::Texture texture;
    sf::Sprite sprite;

    bool stateChanged = true; // track whether the image needs to be regenerated
    int imageCount = 0;
    double offsetX = -0.7; // and move around
    double offsetY = 0.0;
    double zoom = 0.004; // allow the user to zoom in and out...

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                stateChanged = true; // image needs to be recreated when the user changes zoom or offset
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Equal:
                    zoom *= 0.9;
                    break;
                case sf::Keyboard::Dash:
                    zoom /= 0.9;
                    break;
                case sf::Keyboard::W:
                    offsetY -= 40 * zoom;
                    break;
                case sf::Keyboard::S:
                    offsetY += 40 * zoom;
                    break;
                case sf::Keyboard::A:
                    offsetX -= 40 * zoom;
                    break;
                case sf::Keyboard::D:
                    offsetX += 40 * zoom;
                    break;
                default:
                    stateChanged = false;
                    break;
                }
            default:
                break;
            }
        }

        if (stateChanged)
        {
            ju.updateImage(zoom, offsetX, offsetY, image);
            texture.loadFromImage(image);
            sprite.setTexture(texture);
#ifdef _WIN32
            texture.copyToImage().saveToFile("Ju_Images\\ju" + std::to_string(imageCount) + ".png");
#endif
#ifdef linux
            texture.copyToImage().saveToFile("Ju_Images/ju" + std::to_string(imageCount) + ".png");
#endif
            ++imageCount;
            stateChanged = false;
        }
        window.draw(sprite);
        window.display();
    }
}