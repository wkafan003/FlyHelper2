#include "Platform.hpp"

void Platform::Move(float distance) {
    std::cout << "Движение на " << distance << " единиц"<< std::endl;
}

void Platform::Rotate(float angle) {
    std::cout << "Поворот на " << angle << " градусов" << std::endl;
}
