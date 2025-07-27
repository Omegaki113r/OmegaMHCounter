cmake_minimum_required(VERSION 3.25)

project(OmegaMHCounter CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(vendor/raylib)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} raylib)

if(APPLE)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/Debug)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
elseif(WIN32)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
endif(APPLE)


