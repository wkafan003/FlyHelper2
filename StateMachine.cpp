#include <utility>
#include "StateMachine.hpp"

void StateMachine::Update(){
    _currentState();
}

void StateMachine::SetState(std::function<void()> state) {
    _currentState = std::move(state);
}
