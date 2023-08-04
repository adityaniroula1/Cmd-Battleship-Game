cmake_minimum_required(VERSION 3.23)
project(proj4)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj4 proj4.cpp Area.cpp Battlecruiser.cpp Entity.cpp Game.cpp Ghost.cpp Hydralisk.cpp Marine.cpp Mutalisk.cpp Terran.cpp Zerg.cpp Zergling.cpp)
