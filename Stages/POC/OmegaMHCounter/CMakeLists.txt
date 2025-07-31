cmake_minimum_required(VERSION 3.25)

project(OmegaMHCounter CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(vendor/raylib)

set(WIDGET_DIR ${CMAKE_CURRENT_SOURCE_DIR}/widgets)
set(WIDGET_INCLUDE_DIR ${WIDGET_DIR})
set(WIDGET_SOURCES 
    ${WIDGET_DIR}/container/container.cpp 
    ${WIDGET_DIR}/label/label.cpp
    ${WIDGET_DIR}/button/button.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${WIDGET_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC . ${WIDGET_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} raylib)

if(APPLE)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/Debug)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
elseif(WIN32)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
endif(APPLE)

set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_WARNING_AS_ERROR ON)
