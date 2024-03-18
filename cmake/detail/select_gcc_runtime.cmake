cmake_minimum_required (VERSION 3.0.2)

# select_gcc_runtime(STATIC|DYNAMIC)
# 
# This macro selects (for all targets) static or dynamic compiler and C++ runtime for MSVC projects.
# It does not attempt to statically link the C runtime (glibc) because that is very difficult to make work correctly and attempting it is not recommended.
#
# NOTE: This macro presently assumes we want to use libstdc++ and not some other c++ runtime lib.
#
macro(select_gcc_runtime which)
	if (NOT "${GCC_RUNTIME_SELECTED}")

		if (${CMAKE_COMPILER_IS_GNUCC})
			# gcc based compiler (it is dynamic by default)

			if ("${which}" STREQUAL "STATIC")
				foreach(SUFF IN LISTS RELEASE_CONFIGS)
					foreach(TYPE IN ITEMS EXE SHARED MODULE)
						set(CMAKE_${TYPE}_LINKER_FLAGS_${SUFF} "${CMAKE_${TYPE}_LINKER_FLAGS_${SUFF}} -static-libgcc")
					endforeach(TYPE)
				endforeach(SUFF)
		
				# gcc-4.5 introduced -static-libstdc++, BUT IT DOESN'T SEEM TO WORK LIKE THE TRIED-AND-TRUE METHOD BELOW!
				#if (${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "4.5")
				#	# statically link to libgcc and libstdc++
				#	foreach(SUFF IN LISTS RELEASE_CONFIGS)
				#		foreach(TYPE IN ITEMS EXE SHARED MODULE)
				#			set(CMAKE_${TYPE}_LINKER_FLAGS_${SUFF} "${CMAKE_${TYPE}_LINKER_FLAGS_${SUFF}} -static-libstdc++")
				#		endforeach(TYPE)
				#	endforeach(SUFF)
				#else()

					link_all_targets_statically_to_lib(stdc++)

				#endif()
		
			endif()

		endif()

		set(GCC_RUNTIME_SELECTED TRUE)
		set(GCC_RUNTIME ${which})
	endif()

endmacro()

if (NOT "${GCC_RUNTIME}")
	set(GCC_RUNTIME "DYNAMIC")
endif()
