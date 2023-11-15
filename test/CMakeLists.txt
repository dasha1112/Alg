file (GLOB_RECURSE source_files "*.cpp")
file (GLOB_RECURSE header_files "*.h")

add_executable(test ${source_files} ${header_files})
