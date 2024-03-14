cmake_minimum_required(VERSION 3.16)

project(box_with_molecules)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH ${QT_DIR})

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

#=================== INCLUSION OF Project Files ====================#
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    ${INCLUDE_DIR}/*.h
    ${SOURCE_DIR}/*.cpp
)

#qt_add_executable(box_with_molecules main.cpp)
#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the executable
add_executable(box_with_molecules ${SOURCES})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(box_with_molecules Qt6::Widgets)
target_link_libraries(box_with_molecules Qt6::Core)