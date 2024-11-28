#include "Tarea.h"
#include <iostream>

Tarea::Tarea(const std::string& id, const std::string& desc, int duracion)
    : id(id), desc(desc), duracion(duracion) {}

std::string Tarea::getId() const {
    return id;
}

std::string Tarea::getDesc() const {
    return desc;
}

int Tarea::getDuracion() const {
    return duracion;
}

std::string Tarea::toString() const {
    return "Tarea: " + desc + ", Duracion: " + std::to_string(duracion) + " minutos";
}
