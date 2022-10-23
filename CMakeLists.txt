$header
$header
cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

project(first_code)

include_directories(./src/global)

add_executable(${PROJECT_NAME} 
        ./src/main/GetNameList.c
        ./src/main/main.c
        ./src/main/PrintNameList.c
        ./src/main/SetParams.c)

add_subdirectory(./src/global)

add_subdirectory(./src/main/SetupJob)

add_subdirectory(./src/main/SingleStep)

target_link_libraries(${PROJECT_NAME} PUBLIC global  PUBLIC SetupJob PUBLIC
  SingleStep PRIVATE m)
