#include "input/event.hpp"

bool BaseInputEvent::dispatched()
{
    return _dispatchedDuration > 0;
}
bool BaseInputEvent::refreshDispatchedDuration()
{
    return --_dispatchedDuration > 0;
}

template <typename T>
bool InputEvent<T>::subscribe(Listener cb)
{
    return callbacks.insert(cb).second;
}

template <typename T>
bool InputEvent<T>::unsubscribe(Listener cb)
{
    return callbacks.erase(cb) > 0;
}

template <typename T>
void InputEvent<T>::dispatch(uint duration, T arg)
{
    _dispatchedDuration = duration;
    for (Listener cb : callbacks) {
        cb(arg);
    }
}

bool InputEvent<void>::subscribe(Listener cb)
{
    return callbacks.insert(cb).second;
}

bool InputEvent<void>::unsubscribe(Listener cb)
{
    return callbacks.erase(cb) > 0;
}

void InputEvent<void>::dispatch(uint duration)
{
    _dispatchedDuration = duration;
    for (Listener cb : callbacks) {
        cb();
    }
}

// explicit instantiations
template class InputEvent<int>;
