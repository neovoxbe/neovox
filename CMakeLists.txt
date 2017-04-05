cmake_minimum_required(VERSION 2.8)

project (neovox)
set(NEOVOX_SRCS NeoVox.h NeoVox.cpp)

add_library(neovox STATIC ${NEOVOX_SRCS})

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory(./test)

if(CMAKE_COMPILER_IS_GNUCXX)
    IF(CMAKE_BUILD_TYPE MATCHES Coverage)
        set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
        include(CodeCoverage)
        set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS_COVERAGE})
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_COVERAGE})
        setup_target_for_coverage(neovox_coverage neovox-test coverage)
    endif()
endif()
