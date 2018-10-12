#include "ControlSystem.hpp"

ControlSystem::ControlSystem() {
    _objDetector = new VideoObjectDetector(0);
    cv::waitKey(1000);
    _platform = new Platform();
    _stateMachine = new StateMachine();
    _accepter = new MessageAccepter();
    //VideoObjectDetector &&kek = std::move(VideoObjectDetector());
}

void ControlSystem::Move(float distance) {
    _platform->Move(distance);
}

void ControlSystem::Rotate(float angle) {
    _platform->Rotate(angle);
}

void ControlSystem::Run() {
    std::cout << "start" << std::endl;
    _stateMachine->SetState(std::bind(&ControlSystem::Wait, this));
    while (!isEnd) {
        Update();
    }
    std::cout << "end" << std::endl;
}

void ControlSystem::Update() {
    _stateMachine->Update();
}

void ControlSystem::Wait() {
    std::string message = _accepter->RecieveMessage();
    if (message == "end") {
        isEnd = true;
    }
    if (message == "start")
        _stateMachine->SetState(std::bind(&ControlSystem::Find, this));

}

void ControlSystem::Find() {
    cv::Mat frame;
    std::vector<Entity> arr;
    for (int i = 0; i < 5; ++i) {
        _objDetector->ReadImage(frame);
        _objDetector->Detect(frame, arr);

        if (!arr.empty()) {
            for (auto &j :arr) {
                rectangle(frame, cv::Point(j.Pos.x, j.Pos.y), cv::Point(j.Pos.x + j.Pos.width, j.Pos.y + j.Pos.height),
                          cv::Scalar(255, 0, 0));
            }
            cv::imshow("Detected Person", frame);
            _stateMachine->SetState(std::bind(&ControlSystem::Approach, this));
        }

    }
    Rotate(15);
}

void ControlSystem::Approach() {
    for (int i = 0; i < 5; ++i) {
        Move(5);
    }
    _stateMachine->SetState(std::bind(&ControlSystem::Wait, this));
}

ControlSystem::~ControlSystem() {
    delete _objDetector;
    delete _accepter;
    delete _stateMachine;
    delete _platform;
}
