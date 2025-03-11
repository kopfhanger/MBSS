add_rules("mode.debug", "mode.release")

set_languages("c++23")

set_optimize("fastest")

target("mbss")
set_kind("binary")
add_files("src/*.cpp")
add_includedirs("inc")
