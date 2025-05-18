#include "../include/libs.hpp"

class renderable {
public:
  renderable(std::vector<renderable *> &my_vector, sf::Vector2f position,
             int width, int height, std::string spritesheet_path,
             int render_width = -1, int render_height = -1);
  ~renderable() {}
  void render(sf::RenderWindow &window);
  void update_spritesheet_cords();
  sf::Vector2f get_position();

  int x = 0;
  int y = 0;

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
  std::vector<renderable *> &_my_vector;
};