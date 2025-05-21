#include "canvas.hpp"
#include "input/manager.hpp"
#include "renderable.hpp"
#include "utils/window_info.hpp"

#include <SFML/Graphics.hpp>

void handleEventPoll(sf::RenderWindow &window);

int main() {
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
        InputManager::instance().refreshDispatchedEvents();
        handleEventPoll(window);

        window.clear();

        for (canvas *canva : canvas::get_canvases()) {
            canva->render(window);
        }

        window.display();
    }

    return 0;
}

void handleEventPoll(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            /*INPUT EVENTS*/
            /*case sf::Event::LostFocus:*/
            /*case sf::Event::GainedFocus:*/
            case sf::Event::TextEntered:
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
            case sf::Event::MouseWheelMoved:
            case sf::Event::MouseWheelScrolled:
            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
            case sf::Event::MouseMoved:
            case sf::Event::MouseEntered:
            case sf::Event::MouseLeft:
                /*case sf::Event::JoystickButtonPressed:*/
                /*case sf::Event::JoystickButtonReleased:*/
                /*case sf::Event::JoystickMoved:*/
                /*case sf::Event::JoystickConnected:*/
                /*case sf::Event::JoystickDisconnected:*/
                /*case sf::Event::TouchBegan:*/
                /*case sf::Event::TouchMoved:*/
                /*case sf::Event::TouchEnded:*/
                /*case sf::Event::SensorChanged:*/
                InputManager::instance().dispatchEvent(event);
                break;
            default:
                break;
        }
    }
}
