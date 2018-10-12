
#include "VideoObjectDetector.hpp"

VideoObjectDetector::VideoObjectDetector(int vid, const std::string &path) {
    _cascade.load(path);
    _capture.open(vid);
    if (!_capture.isOpened())
        throw "error";
}

VideoObjectDetector::VideoObjectDetector(const char *videoPath, const std::string &cascadePath) {
    _cascade.load(cascadePath);
    _capture.open(videoPath);
    if (!_capture.isOpened())
        throw "error";
}

void VideoObjectDetector::ReadImage(cv::Mat &frame) {
    _capture >> frame;
}

void VideoObjectDetector::Detect(const cv::Mat &image, std::vector<Entity> &DObjects) {
    std::vector<cv::Rect> faces;
    DObjects.clear();
    _cascade.detectMultiScale(image, faces, 1.1,
                              2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    for (auto &face : faces) {
        DObjects.emplace_back("Person", face);
    }
}

void VideoObjectDetector::operator>>(cv::Mat &frame) {
    ReadImage(frame);
}

Entity::Entity(const std::string &Type, const cv::Rect &Pos) : Type(Type), Pos(Pos) {

}
