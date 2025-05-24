#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "input/event.hpp"
#include "utils/singleton.hpp"

#include <SFML/Window/Event.hpp>

#include <vector>

// manages the player input the game logic receives
class InputManager : public Singleton<InputManager> {
   public:
    // refreshes the status of dispatched events
    // called before every dispatchEvent call
    void RefreshDispatchedEvents();
    void DispatchEvent(sf::Event& sf_event);

    InputEvent<int> on_mouse_click_enter;
    InputEvent<int> on_mouse_click_exit;

   private:
    std::vector<BaseInputEvent*> dispatched_events;

    static constexpr uint INPUT_EVENT_DURATION = 1;
};

#endif  // !INPUT_MANAGER_HPP
