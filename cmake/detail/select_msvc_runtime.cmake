cmake_minimum_required (VERSION 3.0.2)


# select_msvc_runtime(STATIC|DYNAMIC)
# 
# This macro selects (for all targets) static or dynamic C & C++ runtimes for MSVC projects.
#
# NOTE:
# 	Given the way it must be done in cmake, this macro MUST be invoked 
# 	before any binary targets are defined in the current scope.
# 
macro(select_msvc_runtime which)
	if (MSVC)
		if ("${which}" STREQUAL "STATIC")
			set(MSVC_RUNTIME "STATIC")
			set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
		elseif("${which}" STREQUAL "DYNAMIC")
			set(MSVC_RUNTIME "DYNAMIC")
			set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
		else()
			message(FATAL_ERROR "Unknown runtime library type: [${which}]")
		endif()
	endif()
endmacro()

if (NOT "${MSVC_RUNTIME}")
	set(MSVC_RUNTIME "DYNAMIC")
endif()
