# Add test executable
add_executable(sample_test sample_test.cpp)

# Link gtest
target_link_libraries(sample_test PRIVATE GTest::gtest_main mcl-heat-transfer)

# Register the test with CTest
add_test(NAME HeatTestSuite COMMAND sample_test)