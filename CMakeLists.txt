cmake_minimum_required(VERSION 3.25)
project(uin-campus VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(uin-campus src/version.cpp src/regles.cpp src/saisie.cpp)
target_include_directories(uin-campus PUBLIC include)
target_compile_definitions(uin-campus PUBLIC UIN_VERSION="${PROJECT_VERSION}")

add_executable(uin-campus-app app/main.cpp)
target_link_libraries(uin-campus-app PRIVATE uin-campus)
