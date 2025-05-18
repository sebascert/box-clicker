#include "canvas.hpp"

canvas::canvas(sf::Vector2f position, int width, int height)
    : renderable(position, width, height)
{
    canvases.push_back(this);
}

void canvas::render(sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(_width, _height));
    rectangle.setFillColor(sf::Color::White);
    sf::Vector2f position = get_position();
    rectangle.setPosition(position.x, position.y);
    window.draw(rectangle);

    for (renderable *renderable : _renderables_inside_canvas) {
        renderable->canvas_position_offset = sf::Vector2f(x, y);
        renderable->canvas_camera_coords = sf::Vector2f(_camera_x, _camera_y);
        renderable->canvas_camera_zoom = _camera_zoom;
        renderable->render(window);
    }
}

void canvas::add_renderable(renderable *renderable)
{
    _renderables_inside_canvas.push_back(renderable);
}

std::vector<canvas *> canvas::canvases;