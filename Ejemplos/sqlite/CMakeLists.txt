cmake_minimum_required(VERSION 3.25)
project(sqlite)

set(CMAKE_CXX_STANDARD 23)

find_package(SQLite3 REQUIRED)

set(SOURCES main.cpp)
set(SOURCES_BD utils/bd/Sqlite.cpp)
set(SOURCES_LOGGER utils/logger/Logger.cpp utils/logger/Colors.h)

add_executable(sqlite ${SOURCES} ${SOURCES_BD} ${SOURCES_LOGGER})

# Vincula la biblioteca SQLite3 a tu ejecutable
target_link_libraries(sqlite ${SQLite3_LIBRARIES})
