#include "renderable.hpp"

#include "../include/utils/window_info.hpp"

renderable::renderable(sf::Vector2f position, int width, int height,
                       const std::string& spritesheet_path, int render_width,
                       int render_height, bool am_i_camera_sensible,
                       float parallax)
    : x(position.x),
      y(position.y),
      _width(width),
      _height(height),
      _render_width(render_width),
      _render_height(render_height),
      _am_i_camera_sensible(am_i_camera_sensible),
      _parallax(parallax)
{
    if (spritesheet_path != "")
        _texture.loadFromFile(spritesheet_path);
    _sprite.setTexture(_texture);
    if (render_width == -1)
        _render_width = width;
    if (render_height == -1)
        _render_height = height;
}

sf::Vector2f renderable::get_position()
{
    if (!_am_i_camera_sensible)
        return sf::Vector2f(x + canvas_position_offset.x,
                            y + canvas_position_offset.y);

    int _diff_x_due_to_flip = -2 * (_direction == -1);

    int x_with_diff = x + _diff_x_due_to_flip;
    int y_with_diff = y;
    int sum_due_to_zoom_x = ((canvas_camera_zoom - 1)) * (x_with_diff);
    int sum_due_to_zoom_y = (canvas_camera_zoom - 1) * (y_with_diff);
    int sum_due_to_parallax_x =
        ((-2 + SCREEN_WIDTH * (-1 + _parallax)) / (2 * _parallax) + 1);
    int sum_due_to_parallax_y =
        ((-2 + SCREEN_HEIGHT * (-1 + _parallax)) / (2 * _parallax) + 1);

    return sf::Vector2f(
        x_with_diff - (canvas_camera_coords.x / _parallax) + sum_due_to_zoom_x +
            sum_due_to_parallax_x + canvas_position_offset.x,
        y_with_diff - (canvas_camera_coords.y / _parallax) + sum_due_to_zoom_y +
            sum_due_to_parallax_y + canvas_position_offset.y);
}

void renderable::update_spritesheet_cords()
{
    sf::IntRect spritesheet_coords;
    spritesheet_coords.top = _render_y * _render_height;
    spritesheet_coords.left =
        _render_x * _render_width + _render_width * ((_direction - 1) / -2);
    spritesheet_coords.width = _render_width * _direction;
    spritesheet_coords.height = _render_height;
    _sprite.setTextureRect(spritesheet_coords);
}

void renderable::render(sf::RenderWindow& window)
{
    update_spritesheet_cords();
    _sprite.setScale(canvas_camera_zoom, canvas_camera_zoom);
    sf::Vector2f position = get_position();
    _sprite.setPosition(position.x, position.y);
    window.draw(_sprite);
}
