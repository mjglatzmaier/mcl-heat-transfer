# Add test executable
add_executable(explicit_fdm_test ExplicitFDM_Test.cpp)

# Link gtest
target_link_libraries(explicit_fdm_test PRIVATE GTest::gtest_main mcl-heat-transfer)

# Register the test with CTest
add_test(NAME HeatTestSuite COMMAND sample_test)