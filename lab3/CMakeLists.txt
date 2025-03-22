cmake_minimum_required(VERSION 3.1.0)
project(NegativeList)

# Prevent in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif()

set(CMAKE_BUILD_TYPE Debug)  
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} Main.cpp ${SOURCES})

# Flaga do testowania błędu kompilacji
option(ENABLE_ERROR_TEST "Włącz test błędu kompilacji" OFF)


target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})


target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

if(ENABLE_ERROR_TEST)
    target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_ERROR_TEST)
endif()