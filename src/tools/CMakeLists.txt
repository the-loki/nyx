file(GLOB_RECURSE EDITOR_SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/tools/editor/*.cpp")


add_executable(nyx_editor)
target_sources(nyx_editor PRIVATE ${EDITOR_SOURCE_FILES})

target_link_libraries(nyx_editor PRIVATE nyx_runtime)
