cmake_minimum_required(VERSION 3.16)
project(ag_runtime)

add_subdirectory(ag-ffi-header)

add_library (ag_runtime STATIC
    src/runtime.c
    src/blob.c
    src/ag-queue.c
    src/utf8.c
    src/ag-assert.c
    src/array/array-base-inc.h
    src/array/array-base-impl.h
    src/array/array-base.c
    src/array/own-array.c
    src/array/weak-array.c
    src/array/shared-array.c
    src/map/map-base-impl.h
    src/map/map-base.c
    src/map/own-map.c
    src/map/shared-map.c
    src/map/weak-map.c
)
target_compile_definitions(ag_runtime PRIVATE AG_STANDALONE_COMPILER_MODE)
set_property(TARGET ag_runtime PROPERTY C_STANDARD 11)
target_include_directories(ag_runtime PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ag_runtime PUBLIC ag_ffi_header)

install(
    TARGETS ag_runtime
    EXPORT ag_runtimeTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
