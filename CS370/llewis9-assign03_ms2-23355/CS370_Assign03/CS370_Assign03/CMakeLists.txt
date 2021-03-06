cmake_minimum_required(VERSION 3.16)   # CMake version check
project(LimeLight)                        # Create project "LimeLight"
set(CMAKE_CXX_STANDARD 11)             # Enable c++11 standard
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

#add include and link directories
if(APPLE)
    find_library(cf_lib CoreFoundation)
    find_library(cg_lib CoreGraphics)
    find_library(cocoa_lib Cocoa)
    find_library(io_lib IOKit)
    link_directories(${CMAKE_SOURCE_DIR}/lib/MacOSX)
elseif(WIN32)
	file(COPY ${CMAKE_SOURCE_DIR}/lib/Win/glew32.dll DESTINATION ${CMAKE_SOURCE_DIR}/bin)
	file(COPY ${CMAKE_SOURCE_DIR}/lib/Win/glfw3.dll DESTINATION ${CMAKE_SOURCE_DIR}/bin)
    link_directories(${CMAKE_SOURCE_DIR}/lib/Win)
endif()

#Main
set(SOURCE_FILES LimeLight.cpp objloader.cpp utils.cpp)
add_executable(LimeLight ${SOURCE_FILES})

if(APPLE)
    # Add Apple frameworks
    target_link_libraries(LimeLight ${cf_lib})
    target_link_libraries(LimeLight ${cg_lib})
    target_link_libraries(LimeLight ${cocoa_lib})
    target_link_libraries(LimeLight ${io_lib})

    # Add GLFW and GLEW libraries
    target_link_libraries(LimeLight ${OPENGL_gl_LIBRARY})
    target_link_libraries(LimeLight glfw3)
    target_link_libraries(LimeLight glew)
elseif(WIN32)
    # Add GLFW and GLEW libraries
    target_link_libraries(LimeLight ${OPENGL_gl_LIBRARY})
    target_link_libraries(LimeLight glfw3)
    target_link_libraries(LimeLight glew32)
else()
    target_link_libraries(LimeLight OpenGL::GL)
    target_link_libraries(LimeLight glfw)
    target_link_libraries(LimeLight GLEW)
endif()

add_custom_target(MAKE_ZIP DEPENDS output)
add_custom_command(OUTPUT output
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E tar cfv ${CMAKE_SOURCE_DIR}/solution.zip --format=zip --files-from=${CMAKE_SOURCE_DIR}/submit.txt
)



