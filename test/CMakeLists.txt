cmake_minimum_required(VERSION 2.8)

set(NEOVOX_TESTS NeoVox-test.cpp main.cpp)

add_executable(neovox-test ${NEOVOX_TESTS})
target_link_libraries(neovox-test neovox)
target_link_libraries(neovox-test ${GTEST_BOTH_LIBRARIES})
add_test(neovox-test neovox-test)

if(CMAKE_COMPILER_IS_GNUCXX)
    IF(CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
        include(CodeCoverage)
        set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS_COVERAGE})
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_COVERAGE})
    endif()
endif()