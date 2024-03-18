cmake_minimum_required (VERSION 3.0.2)


# target_destination(target dir)
#
# This function makes sure the given target's final binary ends up in the specified directory unless
# TARGET_DESTINATION_OVERRIDE specifies a path for output.
#
# TARGET_DESTINATION_OVERRIDE can be set (useful when specified from the command line) to override
# where this function directs target output.
#
# NOTE: We have to use the build-type specific variables because otherwise MSVC will create a
#       subfolder in RUNTIME_OUTPUT_DIRECTORY named after the build-type (e.g. outputdir/Debug/...)
#
function (target_destination target dir)
	if (TARGET_DESTINATION_OVERRIDE)
		set(dir "${TARGET_DESTINATION_OVERRIDE}")
	endif()
	set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${dir}")
	foreach(SUFF IN LISTS ALL_CONFIGS)
		set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${SUFF} "${dir}")
	endforeach(SUFF)
endfunction()
