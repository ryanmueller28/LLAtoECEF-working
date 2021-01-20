# CMmakeLists.txt for SciTech tecnhical Interview
# Ryan Mueller
# Set Minimum CMAKE Version
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Project name, ensure it's set to a Unix system
if(UNIX)
	project(LLAtoECEF)
endif(UNIX)

# Set Include Variables
set(include_files
	include/*.h)

# Set Source Variables
file(GLOB SOURCES
	src/*.cpp)

# Create executable if Unix
if(UNIX)
	add_executable(LLAtoECEF ${SOURCES})
endif(UNIX)
