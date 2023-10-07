file(GLOB_RECURSE HEADER_FILES *.h)

set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE "TRUE")

# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

  message(STATUS "This project requires the Boost library, and will not be compiled.")

  return()  

endif()

set(SOURCE_FILES
    ElmInt.cpp
    SegmentDS.cpp
    FirstLayerNode.cpp
    SecondLayerNode.cpp
    SegmentDS.cpp
    ElmInt.cpp
    Segment.cpp
)


add_library(segment_ds_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(segment_ds_lib ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES})
target_include_directories(segment_ds_lib PUBLIC ./)