cmake_minimum_required(VERSION 3.16)

project(box_with_molecules)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if(NOT "$ENV{Qt6_DIR}" STREQUAL "")
    set(CMAKE_PREFIX_PATH "$ENV{Qt6_DIR}")
endif()

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

#=================== INCLUSION OF Project Files ====================#
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(FORMS_DIR ${PROJECT_SOURCE_DIR}/forms)

include_directories(${INCLUDE_DIR})
#include_directories(${SOURCE_DIR})
include_directories(${FORMS_DIR})

file(GLOB_RECURSE SOURCES
    ${FORMS_DIR}/*.ui
    ${INCLUDE_DIR}/*.h
    ${SOURCE_DIR}/*.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#=================== SETUP EXECTUABLE ====================#

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
add_executable(box_with_molecules ${SOURCES})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(box_with_molecules Qt6::Widgets)
target_link_libraries(box_with_molecules Qt6::Core)