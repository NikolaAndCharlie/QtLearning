cmake_minimum_required(VERSION 3.5)
project(extendWindow)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CURRENT_INCLUDE ON)


find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)


set(Qt_Lib Qt5::Widgets Qt5::Core Qt5::Gui)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HDR src/*.h)

add_executable(extendWindow WIN32 ${SRC} ${HDR})
target_link_libraries(extendWindow ${Qt_Lib})
