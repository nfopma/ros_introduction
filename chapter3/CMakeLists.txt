project(chapter3)

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

add_executable(${PROJECT_NAME}_vel_printer src/vel_printer.cpp)

target_link_libraries(${PROJECT_NAME}_vel_printer ${catkin_LIBRARIES})

# Back to the normal name...
set_target_properties(${PROJECT_NAME}_vel_printer PROPERTIES OUTPUT_NAME vel_printer PREFIX "")

##### Second node (there must be a better way for this)

add_executable(vel_filter src/vel_filter.cpp)

target_link_libraries(vel_filter ${catkin_LIBRARIES})

# Back to the normal name...
#set_target_properties(${PROJECT_NAME}_vel_filter PROPERTIES OUTPUT_NAME vel_filter PREFIX "")
