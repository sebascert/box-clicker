#include "utils/window_info.hpp"
#include "canvas.hpp"
#include "renderable.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                            "Clicker");
    window.setFramerateLimit(60);

    renderable player(sf::Vector2f(100, 100), 33, 30, "assets/alpha/hand.png",
                      33, 30);

    canvas main_canvas(sf::Vector2f(200, 300), 150, 100);
    main_canvas.add_renderable(new renderable(sf::Vector2f(30, 30), 33, 30,
                                              "assets/alpha/hand.png", 33, 30));
    main_canvas.add_renderable(new renderable(sf::Vector2f(70, 30), 33, 30,
                                              "assets/alpha/hand.png", 33, 30));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (canvas *canva : canvas::get_canvases()) {
            canva->render(window);
        }

        window.display();
    }

    return 0;
}
