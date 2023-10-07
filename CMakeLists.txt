# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

project( main )
cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE "TRUE")

# # CGAL and its components
# find_package( CGAL QUIET COMPONENTS  )

# if ( NOT CGAL_FOUND )

#   message(STATUS "This project requires the CGAL library, and will not be compiled.")
#   return()  

# endif()


# # Boost and its components
# find_package( Boost REQUIRED )

# if ( NOT Boost_FOUND )

#   message(STATUS "This project requires the Boost library, and will not be compiled.")

#   return()  

# endif()

# Creating entries for target: main
# ############################

add_executable(main  main.cpp)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(segment_ds_lib PRIVATE ${GNU_OPTIONS})
    target_compile_options(main PRIVATE ${GNU_OPTIONS})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(segment_ds_lib PRIVATE ${CLANG_OPTIONS})
    target_compile_options(main PRIVATE ${CLANG_OPTIONS})
    target_link_options(segment_ds_lib PUBLIC "-stdlib=libc++")
    # Disable this if you want to use libc++
else()
    target_compile_options(segment_ds_lib PRIVATE ${MSVC_OPTIONS})
    target_compile_options(main PRIVATE ${MSVC_OPTIONS})
endif()

set_property(TARGET main PROPERTY CXX_STANDARD 17)

add_to_cached_list( CGAL_EXECUTABLE_TARGETS main )

# Link the executable to CGAL and third-party libraries
target_link_libraries(main ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES})
target_link_libraries(main PUBLIC segment_ds_lib)
target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_BINARY_DIR}/src)
add_subdirectory(test)