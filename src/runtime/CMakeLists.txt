project(nyx_runtime)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/runtime/*.cpp")

add_library(nyx_runtime)
target_sources(nyx_runtime PRIVATE ${SOURCE_FILES})

target_link_libraries(nyx_runtime PUBLIC nyx_thirdparty)

