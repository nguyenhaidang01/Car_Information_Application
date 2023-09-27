# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Car_Information_Application)

# Set the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)

# Create a list of source files
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Common.cpp
    ${SOURCE_DIR}/Display.cpp
    ${SOURCE_DIR}/Sound.cpp
    ${SOURCE_DIR}/General.cpp
    ${SOURCE_DIR}/Setting.cpp
    ${SOURCE_DIR}/Util.cpp
    ${SOURCE_DIR}/CarInfoManager.cpp
)

# Add the header directory to include path
include_directories(${HEADER_DIR})

# Add the libsqlite directory to include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libsqlite/include)

# Specify the path to the SQLite library
set(SQLITE_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libsqlite/lib)

# Add the SQLite library to the project
add_library(sqlite3 STATIC IMPORTED)
set_property(TARGET sqlite3 PROPERTY IMPORTED_LOCATION ${SQLITE_LIB_PATH}/libsqlite3.a)

# Copy the languages.txt file to the build directory
configure_file(${RESOURCE_DIR}/languages.txt ${CMAKE_CURRENT_BINARY_DIR}/languages.txt COPYONLY)
configure_file(${RESOURCE_DIR}/timezones.txt ${CMAKE_CURRENT_BINARY_DIR}/timezones.txt COPYONLY)

# Create the executable from the source files
add_executable(Car_Information_Application ${SOURCES})

# Link the SQLite library to the executable
target_link_libraries(Car_Information_Application sqlite3)
