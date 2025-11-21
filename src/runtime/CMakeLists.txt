project(nyx_runtime)

nyx_collect_all("src/runtime" SOURCE_FILES MODULE_FILES)

add_library(nyx_runtime)
target_sources(nyx_runtime PRIVATE ${SOURCE_FILES} PUBLIC FILE_SET CXX_MODULES FILES ${MODULE_FILES})

target_link_libraries(nyx_runtime PUBLIC nyx_thirdparty)

