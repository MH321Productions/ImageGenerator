cmake_minimum_required(VERSION 3.16)

project(image-generator LANGUAGES CXX)

include_directories(src)
include_directories(include)

#Subdirectories
include_directories(lib/stb)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

#Libraries

list(APPEND libs
)

#External Libraries
if (WIN32)
    set(CMAKE_BUILD_TYPE Release)
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
else()
endif()

#Main program
add_executable(Program src/Main.cpp)
set_target_properties(Program PROPERTIES OUTPUT_NAME "imgen")

if (WIN32)
    target_link_libraries(Program PRIVATE "${libs}")
	
	set_target_properties("${libs}" PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded")
	#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
else()
    target_link_libraries(Program PRIVATE "${libs}")
endif()
