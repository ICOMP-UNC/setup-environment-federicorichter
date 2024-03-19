# version minima requerida por este proyecto de cmake
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# detalles del proyecto
project(
	"FirstProjectInCmake"
	VERSION 1.1.0
	DESCRIPTION "CMake C Project Template for Operating Systems II"
	LANGUAGES C
)

# enable testing
include(CTest)

set(CMAKE_C_STANDARD 17)

# include directory where to find headers
include_directories(include)

# module to fetch a repository
include(FetchContent)

set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

# enable debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

FetchContent_MakeAvailable(Unity)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

target_link_libraries(${PROJECT_NAME}  StatiCLib DynamiCLib)


if (RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests) #if variable RUN_TESTS or RUN_COVERAGE exists
endif()