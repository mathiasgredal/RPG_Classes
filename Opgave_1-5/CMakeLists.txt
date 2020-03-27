cmake_minimum_required(VERSION 3.12)

project(Opgave_1-5)
set (CMAKE_CXX_STANDARD 11)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


add_executable(opgave_1-5 main.cpp
	party.cpp party.h
	character.cpp character.h
	shop.cpp shop.h
	equipment.cpp equipment.h
	money.cpp money.h)

TARGET_LINK_LIBRARIES(opgave_1-5 LINK_PUBLIC ${Boost_LIBRARIES} )


