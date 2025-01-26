project(leyla_runtime)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/runtime/*.cpp")

add_library(leyla_runtime)
target_sources(leyla_runtime PRIVATE ${SOURCE_FILES})

target_link_libraries(leyla_runtime PUBLIC leyla_thirdparty)

