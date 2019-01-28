cmake_minimum_required(VERSION 2.8.3)
project(pick_objects)

find_package(catkin REQUIRED COMPONENTS roscpp move_base_msgs actionlib tf)

include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(pick_objects pick_objects.cpp)
target_link_libraries(pick_objects ${catkin_LIBRARIES})
if(catkin_EXPORTED_TARGETS)
  add_dependencies(pick_objects ${catkin_EXPORTED_TARGETS})
endif()


install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
