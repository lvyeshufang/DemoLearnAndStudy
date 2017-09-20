PROJECT(QtExample C CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)


if(WIN32 AND MSVC)
	if(CMAKE_CL_64)
		# Paths for 64-bit windows builds
		set(QT5_PATH "D:/3rdParty/QT5.6x64")
        #set(SQLITE3_PATH "C:/dev/SQLite-Win64")
	else()
		# Paths for 32-bit windows builds
		set(QT5_PATH "D:/3rdParty/QT5.6")
        #set(SQLITE3_PATH "C:/dev/SQLite-Win32")
	endif()
	set(CMAKE_PREFIX_PATH "${QT5_PATH};${SQLITE3_PATH}")
endif()
  
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#MESSAGE(DIRECTORY_BIN "=${CMAKE_BINARY_DIR}/BIN")


# https://www.kdab.com/using-cmake-with-qt-5/
================================================================================
# Tell CMake to run moc when necessary:
SET(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies (QtGui and QtCore).
FIND_PACKAGE(Qt5Widgets REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

#add_executable(hello_world main.cpp mainwindow.cpp)

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
#target_link_libraries(hello_world ${Qt5Widgets_LIBRARIES})
================================================================================

ADD_SUBDIRECTORY(ThemeStyleSheet)

