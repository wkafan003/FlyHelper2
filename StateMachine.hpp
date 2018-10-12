#ifndef FLYHELPER2_STATEMACHINE_HPP
#define FLYHELPER2_STATEMACHINE_HPP

#include <iostream>
#include <functional>
class StateMachine {
private:
    std::function<void()> _currentState;
public:
    void Update();
    void SetState(std::function<void()> state);
};


#endif //FLYHELPER2_STATEMACHINE_HPP
