#include "libs.hpp"
#include "renderable.hpp"

class canvas : public renderable
{
   public:
    canvas(sf::Vector2f position, int width, int height);
    void render(sf::RenderWindow &window) override;
    void add_renderable(renderable *renderable);

    static std::vector<canvas *> get_canvaseses()
    {
        return canvases;
    }

   private:
    std::vector<renderable *> _renderables_inside_canvas;
    int _camera_x = 0;
    int _camera_y = 0;
    float _camera_zoom = 1;
    int _go_to_camera_x = 0;
    int _go_to_camera_y = 0;
    float _go_to_camera_zoom = 1;
    float _camera_speed = 0.3;

    static std::vector<canvas *> canvases;
};
