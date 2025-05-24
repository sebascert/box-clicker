#include "canvas.hpp"

canvas::canvas(sf::Vector2f position, int width, int height, sf::Color background_color)
    : renderable(position, width, height)
{
    canvases.push_back(this);
    _background_rectangle.setSize(sf::Vector2f(width, height));
    _background_rectangle.setFillColor(background_color);
}

void canvas::render(sf::RenderWindow &window)
{
    sf::Vector2f position = get_position();
    _background_rectangle.setPosition(position.x, position.y);
    window.draw(_background_rectangle);

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