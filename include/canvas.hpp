#include "renderable.hpp"

class canvas{
public:
    canvas(int x, int y, int length, int height);
    int x = 0;
    int y = 0;
private:
    int _length = 0;
    int _height = 0;
    std::vector<renderable*> _renderables_in_canvas;
    int _camera_x = 0;
    int _camera_y = 0;
    float _window_camera_zoom = 1;
    int _go_to_camera_x = 0;
    int _go_to_camera_y = 0;
    float _go_to_camera_zoom = 1;
    float _camera_speed = 0.3;
};