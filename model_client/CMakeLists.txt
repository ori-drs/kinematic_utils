cmake_minimum_required(VERSION 2.8.3)
project(model_client)

if (NOT COMMAND pods_use_pkg_config_packages)
  include(cmake/pods.cmake)
endif()

find_package(catkin REQUIRED COMPONENTS
  orocos_kdl
  urdf
  urdf_dom
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES model_client urdf urdf_dom
  CATKIN_DEPENDS orocos_kdl urdf urdf_dom
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(${PROJECT_NAME}
  src/${PROJECT_NAME}/model_client.cpp
)

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
pods_use_pkg_config_packages(${PROJECT_NAME} lcmtypes_bot2-core)

add_executable(robot_model_publisher src/robot_model_publisher.cpp)
add_dependencies(robot_model_publisher ${catkin_EXPORTED_TARGETS})
target_link_libraries(robot_model_publisher model_client )


