#include "input/event.hpp"

bool BaseInputEvent::Dispatched() const { return _dispatchedDuration > 0; }
bool BaseInputEvent::RefreshDispatchedDuration() {
    return --_dispatchedDuration > 0;
}

template <typename T>
bool InputEvent<T>::Subscribe(Listener listener) {
    return callbacks.insert(listener).second;
}

template <typename T>
bool InputEvent<T>::Unsubscribe(Listener listener) {
    return callbacks.erase(listener) > 0;
}

template <typename T>
void InputEvent<T>::Dispatch(uint duration, T arg) {
    _dispatchedDuration = duration;
    for (Listener listener : callbacks) {
        listener(arg);
    }
}

bool InputEvent<void>::Subscribe(Listener listener) {
    return callbacks.insert(listener).second;
}

bool InputEvent<void>::Unsubscribe(Listener listener) {
    return callbacks.erase(listener) > 0;
}

void InputEvent<void>::Dispatch(uint duration) {
    _dispatchedDuration = duration;
    for (Listener listener : callbacks) {
        listener();
    }
}

// explicit instantiations
template class InputEvent<int>;
