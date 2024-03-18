cmake_minimum_required(VERSION 3.20.0)

include("${CMAKE_CURRENT_LIST_DIR}/detail/target_destination.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/detail/link_statically_to_lib.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/detail/select_msvc_runtime.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/detail/select_gcc_runtime.cmake")

