cmake_minimum_required(VERSION 2.8.3)
# needed for string arrays
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-deprecated-declarations")

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
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS orocos_kdl
    urdf urdf_dom
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
add_dependencies(${LIBRARY_NAME} ${catkin_EXPORTED_TARGETS} urdf urdf_dom)
target_link_libraries(${LIBRARY_NAME} urdf orocos-kdl)
pods_use_pkg_config_packages(${LIBRARY_NAME} eigen3)



add_executable(check_kdl_parser src/check_kdl_parser.cpp)
add_dependencies(check_kdl_parser ${catkin_EXPORTED_TARGETS} kdl-parser)
target_link_libraries(check_kdl_parser urdf orocos-kdl kdl-parser)


#############
## Install ##
#############

install(TARGETS ${TARGETS}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


# Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
