
#ifndef FLYHELPER2_PLATFORM_H
#define FLYHELPER2_PLATFORM_H

#include <opencv2/objdetect.hpp>
#include <iostream>
#include <utility>

class Platform {
private:
    cv::Point3f _rotation;
    cv::Point3f _position;
public:
    void Move(float distance);

    void Rotate(float angle);
};

#endif //FLYHELPER2_PLATFORM_H
