cmake_minimum_required(VERSION 3.22)
project(nyx)

set(CMAKE_CXX_STANDARD 20)

function(nyx_collect_all source_files_var_name module_files_var_name)
    file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/runtime/*.cpp")
    file(GLOB_RECURSE MODULE_FILES "${CMAKE_SOURCE_DIR}/src/runtime/*.cppm")
    set(${source_files_var_name} ${SOURCE_FILES} PARENT_SCOPE)
    set(${module_files_var_name} ${MODULE_FILES} PARENT_SCOPE)
endfunction()

include_directories(src)
add_subdirectory(thirdparty)
add_subdirectory(src/runtime)
add_subdirectory(src/tools)