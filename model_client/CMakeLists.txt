cmake_minimum_required(VERSION 2.8.3)
project(model_client)

find_package(catkin REQUIRED COMPONENTS
  urdf bot_core_lcmtypes
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES model_client
  CATKIN_DEPENDS urdf
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

add_executable(robot_model_publisher src/robot_model_publisher.cpp)
add_dependencies(robot_model_publisher ${catkin_EXPORTED_TARGETS})
target_link_libraries(robot_model_publisher model_client )


add_executable(urdf_to_graphiz src/urdf_to_graphiz.cpp)
add_dependencies(urdf_to_graphiz ${catkin_EXPORTED_TARGETS})
target_link_libraries(urdf_to_graphiz model_client )