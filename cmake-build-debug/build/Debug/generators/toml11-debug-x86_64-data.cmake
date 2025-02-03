########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(toml11_COMPONENT_NAMES "")
if(DEFINED toml11_FIND_DEPENDENCY_NAMES)
  list(APPEND toml11_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES toml11_FIND_DEPENDENCY_NAMES)
else()
  set(toml11_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(toml11_PACKAGE_FOLDER_DEBUG "/home/kopfhanger/.conan2/p/toml144874a6f2f9f9/p")
set(toml11_BUILD_MODULES_PATHS_DEBUG )


set(toml11_INCLUDE_DIRS_DEBUG "${toml11_PACKAGE_FOLDER_DEBUG}/include"
			"${toml11_PACKAGE_FOLDER_DEBUG}/include/toml11")
set(toml11_RES_DIRS_DEBUG )
set(toml11_DEFINITIONS_DEBUG )
set(toml11_SHARED_LINK_FLAGS_DEBUG )
set(toml11_EXE_LINK_FLAGS_DEBUG )
set(toml11_OBJECTS_DEBUG )
set(toml11_COMPILE_DEFINITIONS_DEBUG )
set(toml11_COMPILE_OPTIONS_C_DEBUG )
set(toml11_COMPILE_OPTIONS_CXX_DEBUG )
set(toml11_LIB_DIRS_DEBUG )
set(toml11_BIN_DIRS_DEBUG )
set(toml11_LIBRARY_TYPE_DEBUG UNKNOWN)
set(toml11_IS_HOST_WINDOWS_DEBUG 0)
set(toml11_LIBS_DEBUG )
set(toml11_SYSTEM_LIBS_DEBUG )
set(toml11_FRAMEWORK_DIRS_DEBUG )
set(toml11_FRAMEWORKS_DEBUG )
set(toml11_BUILD_DIRS_DEBUG )
set(toml11_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(toml11_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${toml11_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${toml11_COMPILE_OPTIONS_C_DEBUG}>")
set(toml11_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${toml11_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${toml11_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${toml11_EXE_LINK_FLAGS_DEBUG}>")


set(toml11_COMPONENTS_DEBUG )