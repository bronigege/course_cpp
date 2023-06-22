cmake_minimum_required(VERSION 3.25)
project(functors)

set(CMAKE_CXX_STANDARD 17)

add_executable(functors main.cpp Account.cpp Account.h Point.cpp Point.h AccountPrivate.cpp AccountPrivate.h Clientes.cpp Clientes.h Funtor.cpp Funtor.h)
