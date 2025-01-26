file(GLOB_RECURSE EDITOR_SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/tools/editor/*.cpp")


add_executable(leyla_editor)
target_sources(leyla_editor PRIVATE ${EDITOR_SOURCE_FILES})

target_link_libraries(leyla_editor PRIVATE leyla_runtime)
