#include <utility>
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ControlSystem.hpp"
using namespace std;
using namespace cv;

int main() {
    ControlSystem sys;
    sys.Run();
//    VideoObjectDetector detector;
//    vector<Entity> arr;
//    Mat frame;
//    for (int j = 0; j < 250; ++j) {
//        cout << j << endl;
//        detector >> frame;
//        detector.Detect(frame, arr);
//        for (auto &i :arr) {
//            rectangle(frame,Point(i.Pos.x,i.Pos.y),Point(i.Pos.x+i.Pos.width,i.Pos.y+i.Pos.height),
//                    Scalar(255,0,0));
//            cout << i.Pos << endl;
//        }
//        imshow("kek",frame);
//        waitKey(30);
//    }
    waitKey(0);
    return 0;
}