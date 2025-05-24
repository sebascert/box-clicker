#ifndef INPUT_EVENT_HPP
#define INPUT_EVENT_HPP

#include <SFML/Window/Event.hpp>

#include <unordered_set>

using EventType = sf::Event::EventType;

// interface for dispatch duration
// consumed when is needed
class BaseInputEvent
{
   public:
    bool dispatched();
    // decreases by one the _dispatchedDuration
    // and returns true if it's still not zero
    bool refreshDispatchedDuration();

   protected:
    BaseInputEvent() = default;
    virtual ~BaseInputEvent() = default;

    uint _dispatchedDuration = 0;
};

template <typename T>
class InputEvent : BaseInputEvent
{
    using Listener = void (*)(T);

   public:
    InputEvent() = default;
    ~InputEvent() = default;

    bool subscribe(Listener cb);
    bool unsubscribe(Listener cb);
    void dispatch(uint duration, T arg);

   private:
    std::unordered_set<Listener> callbacks;
};

template <>
class InputEvent<void> : BaseInputEvent
{
    using Listener = void (*)();

   public:
    InputEvent() = default;
    ~InputEvent() = default;

    bool subscribe(Listener cb);
    bool unsubscribe(Listener cb);
    void dispatch(uint duration);

   private:
    std::unordered_set<Listener> callbacks;
};

#endif  // !input_event_hpp
