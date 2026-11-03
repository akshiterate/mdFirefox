cmake_minimum_required(VERSION 4.4.3)

project(MdFirefox LANGUAGES C CXX)

add_subdirectory(external/md4c)

add_executable(MdFirefox src/main.cpp)

target_link_libraries(MdFirefox PRIVATE md4c-html)

set_target_properties(MdFirefox PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
