#include "../include/renderable.hpp"

renderable::renderable(std::vector<renderable*>& my_vector, sf::Vector2f position, int width, int height,   
                        std::string spritesheet_path, int render_width, int render_height):
_my_vector(my_vector),x(position.x), y(position.y), _width(width), _height(height), _render_width(render_width),
_render_height(render_height){

    my_vector.push_back(this);
    _texture.loadFromFile(spritesheet_path);
    _sprite.setTexture(_texture);
    if(render_width == -1) _render_width = width;
    if(render_height == -1) _render_height = height;
}

sf::Vector2f renderable::get_position(){
    return sf::Vector2f(x, y);
}

void renderable::update_spritesheet_cords(){
    sf::IntRect spritesheet_coords;
    spritesheet_coords.top = _render_y * _render_height;
    spritesheet_coords.left = _render_x * _render_width + _render_width * ((_direction - 1)/-2);
    spritesheet_coords.width = _render_width * _direction;
    spritesheet_coords.height = _render_height;
    _sprite.setTextureRect(spritesheet_coords);
}

void renderable::render(sf::RenderWindow& window){
    update_spritesheet_cords();
    sf::Vector2f position = get_position();
    _sprite.setPosition(position.x, position.y);
    window.draw(_sprite);
}
