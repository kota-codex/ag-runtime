cmake_minimum_required(VERSION 3.15)
project(agRuntime LANGUAGES C)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  MESSAGE(FATAL_ERROR "Toolchain file not set, try using: cmake --preset default")
endif()

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

ag_ffi_configure_target(ag_runtime "") #TODO: move defs to sys.ag
