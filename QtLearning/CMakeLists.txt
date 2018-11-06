cmake_minimum_required(VERSION 3.5)
project(QtLearning)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CURRENT_INCLUDE ON)


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)

set(Qt_Lib Qt5::Widgets Qt5::Core Qt5::Gui Qt5::WebEngine Qt5::WebEngineWidgets)

qt5_add_resources(RC src/qtlearning.qrc)


file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HDR src/*.h)

add_executable(QtLearning ${SRC} ${HDR} ${RC})
target_link_libraries(QtLearning ${Qt_Lib})
