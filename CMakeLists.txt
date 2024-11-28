cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Examen_Parcial_3_daniel_alves)

# Usar estándar de C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir todos los archivos fuente (excepto Lanzador/Lanzador.cpp si no existe)
set(SOURCES
        Actor/Actor.cpp
        Crud/Crud.cpp
        Tarea/Tarea.cpp
        Launcher/Launcher.cpp
        main.cpp
)

# Incluir directorios de encabezados
include_directories(
        ${PROJECT_SOURCE_DIR}/Launcher
        ${PROJECT_SOURCE_DIR}/Actor
        ${PROJECT_SOURCE_DIR}/Crud
        ${PROJECT_SOURCE_DIR}/Lanzador
        ${PROJECT_SOURCE_DIR}/Tarea
)

# Crear el ejecutable principal
add_executable(Examen_Parcial_3_daniel_alves ${SOURCES})
