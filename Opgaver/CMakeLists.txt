cmake_minimum_required(VERSION 3.12)

project(Opgaver)
set (CMAKE_CXX_STANDARD 11)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


add_executable(opgaver main.cpp party.cpp party.h)

TARGET_LINK_LIBRARIES(opgaver LINK_PUBLIC ${Boost_LIBRARIES} )


