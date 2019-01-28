cmake_minimum_required(VERSION 2.8.3)
project(wall_follower)

find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs sensor_msgs tf)

include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(wall_follower wall_follower.cpp)
target_link_libraries(wall_follower ${catkin_LIBRARIES})
if(catkin_EXPORTED_TARGETS)
  add_dependencies(wall_follower ${catkin_EXPORTED_TARGETS})
endif()


install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
