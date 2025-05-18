#include "libs.hpp"
#include "renderable.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Clicker");
    window.setFramerateLimit(60);

    renderable player(sf::Vector2f(100, 100), 33, 30, "assets/alpha/hand.png",
                      33, 30);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (renderable *renderable : renderable::getRenderables()) {
            renderable->render(window);
        }

        window.display();
    }

    return 0;
}
