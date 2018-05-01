project(chapter7)

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

add_executable(${PROJECT_NAME}_vel_filter src/vel_filter.cpp)

target_link_libraries(${PROJECT_NAME}_vel_filter ${catkin_LIBRARIES})

# Back to the normal name...
set_target_properties(${PROJECT_NAME}_vel_filter PROPERTIES OUTPUT_NAME vel_filter PREFIX "")
