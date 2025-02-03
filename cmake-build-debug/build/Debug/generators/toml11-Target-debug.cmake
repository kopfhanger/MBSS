# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(toml11_FRAMEWORKS_FOUND_DEBUG "") # Will be filled later
conan_find_apple_frameworks(toml11_FRAMEWORKS_FOUND_DEBUG "${toml11_FRAMEWORKS_DEBUG}" "${toml11_FRAMEWORK_DIRS_DEBUG}")

set(toml11_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET toml11_DEPS_TARGET)
    add_library(toml11_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET toml11_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Debug>:${toml11_FRAMEWORKS_FOUND_DEBUG}>
             $<$<CONFIG:Debug>:${toml11_SYSTEM_LIBS_DEBUG}>
             $<$<CONFIG:Debug>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### toml11_DEPS_TARGET to all of them
conan_package_library_targets("${toml11_LIBS_DEBUG}"    # libraries
                              "${toml11_LIB_DIRS_DEBUG}" # package_libdir
                              "${toml11_BIN_DIRS_DEBUG}" # package_bindir
                              "${toml11_LIBRARY_TYPE_DEBUG}"
                              "${toml11_IS_HOST_WINDOWS_DEBUG}"
                              toml11_DEPS_TARGET
                              toml11_LIBRARIES_TARGETS  # out_libraries_targets
                              "_DEBUG"
                              "toml11"    # package_name
                              "${toml11_NO_SONAME_MODE_DEBUG}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${toml11_BUILD_DIRS_DEBUG} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Debug ########################################
    set_property(TARGET toml11::toml11
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Debug>:${toml11_OBJECTS_DEBUG}>
                 $<$<CONFIG:Debug>:${toml11_LIBRARIES_TARGETS}>
                 )

    if("${toml11_LIBS_DEBUG}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET toml11::toml11
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     toml11_DEPS_TARGET)
    endif()

    set_property(TARGET toml11::toml11
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Debug>:${toml11_LINKER_FLAGS_DEBUG}>)
    set_property(TARGET toml11::toml11
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Debug>:${toml11_INCLUDE_DIRS_DEBUG}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET toml11::toml11
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Debug>:${toml11_LIB_DIRS_DEBUG}>)
    set_property(TARGET toml11::toml11
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Debug>:${toml11_COMPILE_DEFINITIONS_DEBUG}>)
    set_property(TARGET toml11::toml11
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Debug>:${toml11_COMPILE_OPTIONS_DEBUG}>)

########## For the modules (FindXXX)
set(toml11_LIBRARIES_DEBUG toml11::toml11)
