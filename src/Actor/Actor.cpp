#include "Actor.h"
#include <iostream>
#include <iomanip> // Para formatear la salida

Actor::Actor(const std::string& id, const std::string& descripcion)
    : id(id), descripcion(descripcion) {}

std::string Actor::getId() const {
    return id;
}

std::string Actor::getDesc() const {
    return descripcion;
}

int Actor::addTarea(const Tarea& t) {
    listaTareas.push_back(t);
    return listaTareas.size();
}

int Actor::getDuracionTotal() const {
    int total = 0;
    for (const auto& tarea : listaTareas) {
        total += tarea.getDuracion();
    }
    return total;
}

std::string Actor::toString() const {
    std::string resul;
    for (size_t i = 0; i < listaTareas.size(); i++) {
        resul += "  Tarea " + std::to_string(i + 1) + ": " + listaTareas[i].toString() + "\n";
    }
    return resul;
}
