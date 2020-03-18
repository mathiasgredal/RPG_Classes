cmake_minimum_required(VERSION 3.12)

project(Opgave_2-4)
set (CMAKE_CXX_STANDARD 11)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(opgave_2-4 main.cpp equipment.cpp equipment.h character.cpp character.h shop.cpp shop.h)

TARGET_LINK_LIBRARIES(opgave_2-4 LINK_PUBLIC ${Boost_LIBRARIES} )


