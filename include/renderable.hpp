#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "libs.hpp"

class renderable
{
   public:
    renderable(sf::Vector2f position, int width, int height,
               const std::string& spritesheet_path = "", int render_width = -1,
               int render_height = -1, bool am_i_camera_sensible = true, float parallax = 1);
    ~renderable()
    {
    }
    virtual void render(sf::RenderWindow &window);
    void update_spritesheet_cords();
    sf::Vector2f get_position();

    int x = 0;
    int y = 0;
    sf::Vector2f canvas_position_offset;
    sf::Vector2f canvas_camera_coords;
    float canvas_camera_zoom = 1;

   protected:
    int _width;
    int _height;
    int _render_width;
    int _render_height;
    int _render_x = 0;
    int _render_y = 0;
    int _direction = 1;
    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _am_i_camera_sensible = false;
    float _parallax = 1;
};

#endif
