cmake_minimum_required(VERSION 3.12)
project(FlyHelper2)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
add_executable(FlyHelper2 main.cpp VideoObjectDetector.cpp VideoObjectDetector.hpp Platform.cpp Platform.hpp MessageAccepter.cpp MessageAccepter.hpp StateMachine.cpp StateMachine.hpp ControlSystem.cpp ControlSystem.hpp)
target_link_libraries(FlyHelper2 ${OpenCV_LIBS})