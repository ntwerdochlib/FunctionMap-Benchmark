cmake_minimum_required(VERSION 3.8)
project(fnmapbm)

set(CMAKE_BUILD_TYPE "RelWithDebInfo")

# set compiler flags
if((CMAKE_CXX_COMPILER_ID MATCHES GNU) OR (CMAKE_CXX_COMPILER_ID MATCHES Clang))
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -DNDEBUG -O3")
endif()

# configure Google Benchmarks
include(FetchContent)
FetchContent_Declare(benchmark
	GIT_REPOSITORY https://github.com/google/benchmark.git
	GIT_TAG origin/main
	GIT_SHALLOW TRUE
)

FetchContent_GetProperties(benchmark)
if(NOT benchmark_POPULATED)
	FetchContent_Populate(benchmark)
	set(BENCHMARK_ENABLE_TESTING OFF CACHE INTERNAL "" FORCE)
	add_subdirectory(${benchmark_SOURCE_DIR} ${benchmark_BINARY_DIR})
endif()                                     

include("cmake/detail/target_destination.cmake")
if (LINUX)
	include("cmake/detail/select_gcc_runtime.cmake")
	select_gcc_runtime(STATIC)
elseif (WIN32)
	include("cmake/detail/select_msvc_runtime.cmake")
	select_msvc_runtime(STATIC)
endif()

set (srcs
	FunctionMap-Benchmark.cpp
)

add_executable(fnmapbm ${srcs})
target_link_libraries(fnmapbm benchmark)

if (WIN32)
	set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "fnmapbm")
endif()

target_destination(fnmapbm "${CMANE_CURRENT_BIN_DIR}")
