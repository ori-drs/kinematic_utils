cmake_minimum_required(VERSION 2.8.3)

if (NOT COMMAND pods_use_pkg_config_packages)
  include(cmake/pods.cmake)
endif()

project(kdl_parser)

find_package(catkin REQUIRED COMPONENTS
  orocos_kdl
  urdf
  urdf_dom
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES kdl-parser
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

######################################################
set(LIBRARY_NAME kdl-parser)

add_library(${LIBRARY_NAME} src/kdl_parser.cpp)
pods_use_pkg_config_packages(${LIBRARY_NAME} eigen3)


#add_executable(check_kdl_parser src/check_kdl_parser.cpp)
#add_dependencies(check_kdl_parser ${catkin_EXPORTED_TARGETS})
#target_link_libraries(check_kdl_parser ${catkin_LIBRARIES} kdl-parser)


#############
## Install ##
#############

