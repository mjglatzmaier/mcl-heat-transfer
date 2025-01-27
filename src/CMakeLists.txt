file(GLOB HEAT_TRANSFER_SOURCES *.cpp)

add_library(mcl-heat-transfer STATIC ${HEAT_TRANSFER_SOURCES})
target_include_directories(mcl-heat-transfer PUBLIC ../inc)

# Note: mcl-shared is provided through mcl-mesh
target_link_libraries(mcl-heat-transfer PUBLIC mcl-mesh mcl-shared)