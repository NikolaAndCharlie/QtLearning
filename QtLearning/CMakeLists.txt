cmake_minimum_required(VERSION 3.5)
project(QtLearning)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CURRENT_INCLUDE ON)


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)


set(Qt_Lib Qt5::Widgets Qt5::Core Qt5::Gui)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HDR src/*.h)

qt5_add_resources(RC src/logo.qrc)

add_executable(QtLearning ${SRC} ${HDR} ${RC})
target_link_libraries(QtLearning ${Qt_Lib})
