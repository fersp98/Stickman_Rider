cmake_minimum_required(VERSION 3.8)

# Please try it to match with actual project name
set(CMAKE_PROJECT_NAME "stickman_rider")
project(${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
# Verify OS environment to define folders
if(WIN32)
    set(SFML_ROOT "C:/SFML-2.4.2")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${SFML_ROOT}/lib")
    set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
elseif(UNIX AND NOT APPLE)
    set(SFML_ROOT "/usr/share/SFML")
endif()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SFML_ROOT}/cmake/Modules")
set(SOURCE_FILES main.cpp)
FILE(GLOB_RECURSE AF "AudioFile/*.h" "AudioFile/*.cpp")
FILE(GLOB_RECURSE SRC "src/*.h" "src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES} ${SRC} ${AF})

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()
find_package(SFML COMPONENTS audio network graphics window system REQUIRED)

# Detect and add SFML
if(SFML_FOUND AND WIN32)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${CMAKE_PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
elseif(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${CMAKE_PROJECT_NAME} ${SFML_LIBRARIES})
endif()