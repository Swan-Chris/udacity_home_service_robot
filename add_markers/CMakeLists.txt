cmake_minimum_required(VERSION 2.8.3)
project(add_markers)

find_package(catkin REQUIRED COMPONENTS roscpp nav_msgs visualization_msgs tf)

include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(add_markers add_markers.cpp)
target_link_libraries(add_markers ${catkin_LIBRARIES})
if(catkin_EXPORTED_TARGETS)
  add_dependencies(add_markers ${catkin_EXPORTED_TARGETS})
endif()


install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
