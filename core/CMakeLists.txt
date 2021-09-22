cmake_minimum_required( VERSION 3.7 )
project( LAB_SOLVER VERSION 1.0.0 LANGUAGES CXX )

set ( APP_NAME "solver" )

add_executable( ${APP_NAME} src/main.cpp src/maze.cpp src/path.cpp )

target_compile_features( ${APP_NAME} PUBLIC cxx_std_17 )
