#ifndef FLYHELPER2_CONTROLSYSTEM_HPP
#define FLYHELPER2_CONTROLSYSTEM_HPP
#include <iostream>
#include <vector>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "VideoObjectDetector.hpp"
#include "Platform.hpp"
#include "StateMachine.hpp"
#include "MessageAccepter.hpp"

class ControlSystem {
    VideoObjectDetector *_objDetector;
    Platform *_platform;
    StateMachine *_stateMachine;
    MessageAccepter *_accepter;
    bool isEnd=false;
public:
    ControlSystem();

    virtual ~ControlSystem();

    void Move(float distance);

    void Rotate(float angle);

    void Run();

    void Update();

    void Wait();
    void Find();
    void Approach();

};


#endif //FLYHELPER2_CONTROLSYSTEM_HPP
