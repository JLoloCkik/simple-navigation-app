cmake_minimum_required(VERSION 3.14)
project(simple-navigation-app)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(    
        SimpleNavigationAppLib SHARED   
        angle.cpp geo_coordinate.cpp graph/edge.cpp graph/vertex.cpp graph/graph.cpp waypoint.h
)
add_executable(SimpleNavigationApp main.cpp)
target_link_libraries(SimpleNavigationApp SimpleNavigationAppLib)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)



# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        navigation_test
        angle_test.cpp
        geo_coordinate_test.cpp
        waypoint_test.cpp
        graph/vertex_test.cpp
        graph/graph_test.cpp


)
target_link_libraries(
        navigation_test
        GTest::gtest_main
        GTest::gmock
        SimpleNavigationAppLib
)

include(GoogleTest)
gtest_discover_tests(navigation_test)