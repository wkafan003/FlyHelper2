#ifndef FLYHELPER2_VIDEOOBJECTDETECTOR_H
#define FLYHELPER2_VIDEOOBJECTDETECTOR_H


#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
struct Entity {
    std::string Type;
    cv::Rect Pos;
    Entity(const std::string &Type, const cv::Rect &Pos);
};
class VideoObjectDetector {
private:
    cv::CascadeClassifier _cascade;
    cv::VideoCapture _capture;
public:
    explicit VideoObjectDetector(int vid = 0, const std::__cxx11::string &path = "haarcascade_frontalcatface.xml");

    explicit VideoObjectDetector(const char *videoPath,
                                 const std::__cxx11::string &cascadePath = "haarcascade_frontalcatface.xml");

    void ReadImage(cv::Mat &frame) ;

    void operator>>(cv::Mat &frame);
    void Detect(const cv::Mat &image, std::vector<Entity> &DObjects) ;
};

#endif //FLYHELPER2_VIDEOOBJECTDETECTOR_H
