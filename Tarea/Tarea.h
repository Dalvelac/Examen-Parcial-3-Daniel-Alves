#ifndef TAREA_H
#define TAREA_H

#include <string>

class Tarea {
private:
    std::string id;
    std::string desc;
    int duracion;

public:
    Tarea(const std::string& id, const std::string& desc, int duracion);
    std::string getId() const;
    std::string getDesc() const;
    int getDuracion() const;
    std::string toString() const;
};

#endif //TAREA_H
