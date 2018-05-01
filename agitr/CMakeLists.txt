cmake_minimum_required(VERSION 2.8.3)
project(agitr)

find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs turtlesim)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES agitr
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories( include ${catkin_INCLUDE_DIRS})

add_executable(hello src/hello.cpp)
add_executable(pubvel src/pubvel.cpp)
add_executable(subpose src/subpose.cpp)
add_executable(vel_printer src/vel_printer.cpp)

target_link_libraries(hello ${catkin_LIBRARIES})
target_link_libraries(pubvel ${catkin_LIBRARIES})
target_link_libraries(subpose ${catkin_LIBRARIES})
target_link_libraries(vel_printer ${catkin_LIBRARIES})
