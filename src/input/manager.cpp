#include "input/manager.hpp"

void InputManager::refreshDispatchedEvents()
{
    dispatched_events.erase(
        std::remove_if(
            dispatched_events.begin(), dispatched_events.end(),
            [](BaseInputEvent* e) { return !e->refreshDispatchedDuration(); }),
        dispatched_events.end());
}

void InputManager::dispatchEvent(sf::Event& sf_event)
{
    switch (sf_event.type) {
            /*case sf::Event::LostFocus:*/
            /*case sf::Event::GainedFocus:*/
            /*case sf::Event::TextEntered:*/
            /*case sf::Event::KeyPressed:*/
            /*case sf::Event::KeyReleased:*/
            /*case sf::Event::MouseWheelMoved:*/
            /*case sf::Event::MouseWheelScrolled:*/
            /*case sf::Event::MouseMoved:*/
            /*case sf::Event::MouseEntered:*/
            /*case sf::Event::MouseLeft:*/
            /*case sf::Event::JoystickButtonPressed:*/
            /*case sf::Event::JoystickButtonReleased:*/
            /*case sf::Event::JoystickMoved:*/
            /*case sf::Event::JoystickConnected:*/
            /*case sf::Event::JoystickDisconnected:*/
            /*case sf::Event::TouchBegan:*/
            /*case sf::Event::TouchMoved:*/
            /*case sf::Event::TouchEnded:*/
            /*case sf::Event::SensorChanged:*/
            /*triggerInputEvent(event);*/
        case sf::Event::MouseButtonPressed:
            on_mouse_click_enter.dispatch(INPUT_EVENT_DURATION,
                                          sf_event.mouseButton.button);
            break;
        case sf::Event::MouseButtonReleased:
            on_mouse_click_exit.dispatch(INPUT_EVENT_DURATION,
                                         sf_event.mouseButton.button);
            break;
        default:
            // do nothing silently
            break;
    }
}
