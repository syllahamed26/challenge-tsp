cmake_minimum_required(VERSION 3.24)
project(challenge_tsp)

set(CMAKE_CXX_STANDARD 17)

add_executable(challenge_tsp main.cpp services/solution.h services/FileManagement.cpp model/City.cpp model/City.h services/typeSolution.cpp services/typeRecherche.cpp)
