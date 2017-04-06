cmake_minimum_required(VERSION 2.8)

project (neovox)
set(NEOVOX_SRCS NeoVox.h NeoVox.cpp)

add_library(neovox STATIC ${NEOVOX_SRCS})

include (CTest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory(./test)

set(CMAKE_C_FLAGS -Wall)
set(CMAKE_CXX_FLAGS -Wall)

if(CMAKE_COMPILER_IS_GNUCXX)
    IF(CMAKE_BUILD_TYPE MATCHES Coverage)
        set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
        include(CodeCoverage)
        set(CMAKE_C_FLAGS -Wall ${CMAKE_C_FLAGS_COVERAGE})
        set(CMAKE_CXX_FLAGS -Wall ${CMAKE_CXX_FLAGS_COVERAGE})
        setup_target_for_coverage(neovox_coverage neovox-test coverage)
        find_package(PythonInterp REQUIRED)
        setup_target_for_coverage_cobertura(neovox_coverage_cobertura neovox-test coverage)
    endif()
endif()

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxygen.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
endif()
