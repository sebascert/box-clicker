#include "../include/libs.hpp"
#include "./renderable.cpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Clicker");
  window.setFramerateLimit(60);

  std::vector<renderable *> renderable_vector;

  renderable player(renderable_vector, sf::Vector2f(100, 100), 33, 30,
                    "assets/alpha/hand.png", 33, 30);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    for (renderable *renderable : renderable_vector) {
      renderable->render(window);
    }

    window.display();
  }

  return 0;
}
