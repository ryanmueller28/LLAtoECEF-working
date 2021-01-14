# CMmakeLists.txt for SciTech tecnhical Interview
# Ryan Mueller
# Set Minimum CMAKE Version
cmake_minimum_required(VERSION 3.10)

# Set Project name, ensure it's set to a Unix system
if(UNIX)
	project(LLAtoECEF)
endif(UNIX)

# Set Include Variables
target_include_directories(GLOB INCLUDE
	include/*.h)

# Set Source Variables
set(GLOB SOURCES
	src/*.cpp)

# Create executable if Unix
if(UNIX)
	add_executable(LLAtoECEF ${SOURCES} ${INCLUDE})
endif(UNIX)
