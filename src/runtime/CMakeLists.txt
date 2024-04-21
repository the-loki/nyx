project(fairy_runtime)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/runtime/*.cpp")

add_library(fairy_runtime)
target_sources(fairy_runtime PRIVATE ${SOURCE_FILES})

target_link_libraries(fairy_runtime PUBLIC fairy_thirdparty)

