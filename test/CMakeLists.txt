project(test)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR/../src})

add_executable(run_tests SecondLayerTest.cpp NodeTest.cpp)
target_link_libraries(run_tests GTest::gtest_main segment_ds_lib)

include(GoogleTest)
gtest_discover_tests(run_tests)