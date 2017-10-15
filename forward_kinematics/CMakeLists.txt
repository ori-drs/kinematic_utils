cmake_minimum_required(VERSION 2.8.3)
project(forward_kinematics)

find_package(catkin REQUIRED COMPONENTS
  orocos_kdl urdf urdf_dom
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES forward_kinematics
#  CATKIN_DEPENDS orocos_kdl  urdf urdf_dom
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
   src/treefksolverposfull_recursive.cpp
)
