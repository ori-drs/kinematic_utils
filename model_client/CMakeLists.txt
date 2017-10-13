cmake_minimum_required(VERSION 2.8.3)
# needed for string arrays
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-deprecated-declarations")

if (NOT COMMAND pods_use_pkg_config_packages)
  include(cmake/pods.cmake)
endif()

project(model_client)

find_package(catkin REQUIRED COMPONENTS
#  pronto_math
#  pronto_vis
#  pronto_lcm
#  pronto_conversions
#  cv_bridge
#  bot2_frames_cpp
  urdf
  urdf_dom
)

catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS urdf urdf_dom
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
set(LIBRARY_NAME model_client)

add_library(${LIBRARY_NAME} src/model_client/model_client.cpp)
add_dependencies(${LIBRARY_NAME} ${catkin_EXPORTED_TARGETS} urdf urdf_dom)
pods_use_pkg_config_packages(${LIBRARY_NAME} occ-map lcmtypes_octomap-utils)
target_link_libraries(${LIBRARY_NAME} ${OCTOMAP_LIBRARIES} urdf)


################

add_executable(robot_model_publisher src/robot_model_publisher.cpp)
add_dependencies(robot_model_publisher ${catkin_EXPORTED_TARGETS} urdf urdf_dom)
pods_use_pkg_config_packages(robot_model_publisher lcm)
target_link_libraries(robot_model_publisher model_client urdf urdf_dom
  lcmtypes_bot2-core)
#                             urdf lcm 
#                             lcmtypes_robot_model_publisher model-client)


#add_executable(husky-path-follower src/path_follower.cpp  )
#target_link_libraries(husky-path-follower boost_system ${OpenCV_LIBRARIES}
#  pronto_math pronto_vis bot2_frames_cpp)
#pods_use_pkg_config_packages(husky-path-follower
#  bot2-core bot2-frames bot2-param-client model-client kdl-parser path-util)


# Demo application to do gaze tracking with the Valkyrie head
#add_executable(husky-gaze-tracking-demo src/gazeTrackingDemo.cpp)
#target_link_libraries(husky-gaze-tracking-demo boost_thread boost_system 
#  boost_filesystem boost_signals)
#pods_use_pkg_config_packages(husky-gaze-tracking-demo bot2-core)
# drake-rbm drake-ik lcm 
#bot2-core bot2-frames eigen3 model-client)


#add_executable(husky-joints2frames src/joints2frames.cpp  )
#target_link_libraries(husky-joints2frames boost_system
#  pronto_lcm pronto_vis bot2_frames_cpp)
#  kdl-parser orocos-kdl model-client forward-kinematics)
#pods_use_pkg_config_packages(husky-joints2frames
#  bot2-param-client)# model-client kdl-parser)



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
