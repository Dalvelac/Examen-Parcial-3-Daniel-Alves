cmake_minimum_required(VERSION 3.10)
project(Examen_Parcial_3_daniel_alves)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES
        ${SRC_DIR}/Launcher/Launcher.cpp
        ${SRC_DIR}/Actor/Actor.cpp
        ${SRC_DIR}/Tarea/Tarea.cpp
        ${PROJECT_SOURCE_DIR}/main.cpp
)
include_directories(
        ${SRC_DIR}/Actor
        ${SRC_DIR}/Tarea
        ${SRC_DIR}/Launcher
)
add_executable(Examen_Parcial_3_daniel_alves ${SOURCES})
