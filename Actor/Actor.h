#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "..\Tarea/Tarea.h"
#include <string>

class Actor {
private:
    std::string id;
    std::string descripcion;
    std::vector<Tarea> listaTareas;

public:
    Actor(const std::string& id, const std::string& descripcion);
    std::string getId() const;
    std::string getDesc() const;
    int addTarea(const Tarea& t);
    int getDuracionTotal() const;
    std::string toString() const;
};

#endif //ACTOR_H
