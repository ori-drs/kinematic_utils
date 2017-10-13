cmake_minimum_required(VERSION 2.8.3)
# needed for string arrays
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-deprecated-declarations")

if (NOT COMMAND pods_use_pkg_config_packages)
  include(cmake/pods.cmake)
endif()

project(orocos_kdl)

#find_package(catkin REQUIRED COMPONENTS
#  pronto_math
#  pronto_vis
#  pronto_lcm
#  pronto_conversions
#  cv_bridge
#  bot2_frames_cpp
#  urdf
#  urdf_dom
#)

catkin_package(
  INCLUDE_DIRS
    include
#  CATKIN_DEPENDS urdf urdf_dom
#   pronto_math cv_bridge pronto_lcm bot2_frames_cpp pronto_vis urdf
# cv_bridge pronto_vis 
#    pronto_conversions 
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
ADD_SUBDIRECTORY( src )









#############
## Install ##
#############

install(TARGETS ${TARGETS}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


# Mark cpp header files for installation
#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
