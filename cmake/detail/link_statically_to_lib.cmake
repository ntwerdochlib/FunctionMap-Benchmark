cmake_minimum_required (VERSION 3.18.0)

#
# link_all_targets_statically_to_lib(<library-name>)
# 
# This macro causes the all targets to be statically linked to the specified library.
# It does so by creating a folder containing a symlink to the located lib file, adding that folder 
# to the library search paths (-L), and linking to that library by name (-l).
# It does this instead of just adding the library itself to the linker line because other dependencies
# may be adding the library (-l) which would link to the library by searching the search paths (-L's)
#
#	Example: 
#		static_link_to_lib(Xss)
#   Causes all target to be linked statically to libXss.a
#
# NOTE: This macro is applicable only with clang and GNU based linkers, and it will complain if used there.
#
macro(link_all_targets_statically_to_lib libname)
	# note: would test for a LINKER_ID but I don't see that in the cmake vars
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		# have the compiler print the location of the library, create a symlink within our build folder, and add -L<build-folder> and -l<libname> to the linker line
		set(ENV{CGCC_FORCE_COLOR} 0)
		separate_arguments(ARGS UNIX_COMMAND ${CMAKE_CXX_FLAGS})
		execute_process(COMMAND ${CMAKE_CXX_COMPILER} ${ARGS} -print-file-name=lib${libname}.a RESULT_VARIABLE es OUTPUT_VARIABLE libfile OUTPUT_STRIP_TRAILING_WHITESPACE)
		if (${es} EQUAL 0)
			set(libdir "${CMAKE_BINARY_DIR}/lib${libname}")
			file(MAKE_DIRECTORY "${libdir}")
			execute_process(COMMAND ln -sf "${libfile}" "${libdir}/")
			set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${libdir} -l${libname}")
			set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -L${libdir} -l${libname}")
			message(STATUS "linking all targets statically to ${libfile}")
		else()
			message(FATAL_ERROR "could not locate lib${libname}.a for static linking")
		endif()
	else()
		message(FATAL_ERROR "link_all_targets_statically_to_lib is only applicable when using clang or gnu compilers")
	endif()
endmacro()



#
# link_target_statically_to_lib(<target> <library-name>)
# 
# This macro causes the specified target to be statically linked to the specified library.
# It does so by finding the static library and linking the target to it.
# WARNING: If another target uses -l to link in the library it will likely link to the dynamic lib since the -L search paths will be consulted.
#
#	Example: 
#		static_link_target_to_lib(foo Xss)
#   Causes the foo target to be linked statically to libXss.a
#
# NOTE: This macro is applicable only with clang and GNU based linkers, and it will complain if used there.
#
macro(link_target_statically_to_lib target libname)
	# note: would test for a LINKER_ID but I don't see that in the cmake vars
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		# have the compiler print the location of the library, create a symlink within our build folder, and add -L<build-folder> and -l<libname> to the linker line
		set(ENV{CGCC_FORCE_COLOR} 0)
		separate_arguments(ARGS UNIX_COMMAND ${CMAKE_CXX_FLAGS})
		execute_process(COMMAND ${CMAKE_CXX_COMPILER} ${ARGS} -print-file-name=lib${libname}.a RESULT_VARIABLE es OUTPUT_VARIABLE libfile OUTPUT_STRIP_TRAILING_WHITESPACE)
		if (${es} EQUAL 0)
			target_link_libraries(${target} PUBLIC ${libfile})
			message(STATUS "linking target ${target} statically to ${libfile}")
		else()
			message(FATAL_ERROR "could not locate lib${libname}.a for static linking")
		endif()
	else()
		message(FATAL_ERROR "link_target_statically_to_lib is only applicable when using clang or gnu compilers")
	endif()
endmacro()


