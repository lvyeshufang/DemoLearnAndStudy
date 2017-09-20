
# Widgets finds its own dependencies (QtGui and QtCore).
FIND_PACKAGE(Qt5Xml REQUIRED)

# The Qt5Xml_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
INCLUDE_DIRECTORIES(${Qt5Xml_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
ADD_DEFINITIONS(${Qt5Xml_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
SET(CMAKE_CXX_FLAGS "${Qt5Xml_EXECUTABLE_COMPILE_FLAGS}")


SET(ProjName ThemeStyleSheet)
SET(SRC "")


AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC)

ADD_EXECUTABLE(${ProjName} ${SRC})
TARGET_LINK_LIBRARIES(${ProjName} ${Qt5Widgets_LIBRARIES} ${Qt5Xml_LIBRARIES})


SET_PROPERTY( GLOBAL PROPERTY USE_FOLDERS ON)
SET_PROPERTY(TARGET ${ProjName} PROPERTY FOLDER "QtStyleSheet")


#SET_TARGET_PROPERTIES( ${ProjName}
#    PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
#)

#MESSAGE(DIRECTORY_BIN "=${CMAKE_BINARY_DIR}/BIN")
#MESSAGE(INFO_COPY "=COPY FILE ${CMAKE_CURRENT_SOURCE_DIR}/config/uistyle.xml TO ${CMAKE_BINARY_DIR}/bin/uistyle.xml")

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config/uistyle.xml ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config/uistyle.xml COPYONLY)