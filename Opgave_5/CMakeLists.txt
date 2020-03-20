cmake_minimum_required(VERSION 3.12)

project(Opgave_5)
set (CMAKE_CXX_STANDARD 11)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


add_executable(opgave_5 main.cpp money.cpp money.h InfInt.h)

TARGET_LINK_LIBRARIES(opgave_5 LINK_PUBLIC ${Boost_LIBRARIES} )


