cmake_minimum_required(VERSION 3.16)

project(MyQmlProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)

qt_policy(SET QTP0001 NEW)

# Source files
set(SOURCES
    src/main.cpp
)

# QML files
set(QML_FILES
    qml/main.qml
)

# Resource files
set(RESOURCE_FILES
    qml.qrc
)

# Add executable
qt_add_executable(MyQmlProject
    ${SOURCES}
    ${RESOURCE_FILES}
)

# Add QML module
qt_add_qml_module(MyQmlProject
    URI MyQmlProject
    VERSION 1.0
    QML_FILES ${QML_FILES}
)

# Link against required Qt libraries
target_link_libraries(MyQmlProject PRIVATE
    Qt6::Core
    Qt6::Quick
)

# Install the project
install(TARGETS MyQmlProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY qml DESTINATION ${CMAKE_INSTALL_BINDIR})
