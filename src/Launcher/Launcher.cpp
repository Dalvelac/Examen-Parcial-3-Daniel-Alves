#include "Launcher.h"
#include <iostream>
#include <iomanip> // Para formatear la salida

using namespace std;

vector<Tarea> Launcher::crearTareas() {
    return {
        Tarea("A", "Reserva de vuelo", 20),
        Tarea("B", "Informar a casa para empacar", 5),
        Tarea("C", "Empacar maletas", 40),
        Tarea("D", "Preparacion del billete por la agencia", 10),
        Tarea("E", "Recoger el billete de la agencia", 5),
        Tarea("F", "Llevar el billete a la oficina", 10),
        Tarea("G", "Recoger las maletas de casa", 20),
        Tarea("H", "Llevar maletas a la oficina", 25),
        Tarea("I", "Conversacion sobre documentos requeridos", 35),
        Tarea("J", "Dictar instrucciones para ausencia", 25),
        Tarea("K", "Reunir documentos", 15),
        Tarea("L", "Organizar documentos", 5),
        Tarea("M", "Viajar al aeropuerto y facturar", 25)
    };
}

vector<Actor> Launcher::crearActores() {
    return {
        Actor("1", "CEO de la empresa"),
        Actor("2", "Asistente Personal"),
        Actor("3", "Agencia de Viajes"),
        Actor("4", "Servicio de Transporte")
    };
}

void Launcher::asignarTareas(vector<Actor>& actores, const vector<Tarea>& tareas) {
    // Asignar tareas a los actores
    actores[0].addTarea(tareas[0]); // CEO: Reserva de vuelo
    actores[1].addTarea(tareas[1]); // Asistente: Informar a casa
    actores[1].addTarea(tareas[2]); // Asistente: Empacar maletas
    actores[2].addTarea(tareas[3]); // Agencia: Preparar billete
    actores[2].addTarea(tareas[4]); // Agencia: Recoger billete
    actores[3].addTarea(tareas[12]); // Transporte: Viajar al aeropuerto
}

void Launcher::ejecutar() {
    vector<Tarea> tareas = crearTareas();
    vector<Actor> actores = crearActores();

    asignarTareas(actores, tareas);

    int tiempoTotal = 0;
    cout << "=== Resumen de tareas por actor ===" << endl;

    // Mostrar informacion de cada actor
    for (const auto& actor : actores) {
        cout << "Actor: " << actor.getDesc() << endl;
        cout << actor.toString();
        tiempoTotal += actor.getDuracionTotal();
        cout << "Tiempo total para " << actor.getDesc() << ": "
             << actor.getDuracionTotal() << " minutos" << endl;
        cout << "----------------------------------" << endl;
    }

    cout << "=== Tiempo total para completar todas las tareas ===" << endl;
    cout << "Tiempo total: " << tiempoTotal << " minutos" << endl;

    // Verificar si los actores completan a tiempo
    cout << "\n=== Verificacion de tiempos ===" << endl;
    for (const auto& actor : actores) {
        if (actor.getDuracionTotal() > 100) {
            cout << "El actor " << actor.getDesc() << " NO puede completar sus tareas a tiempo." << endl;
        } else {
            cout << "El actor " << actor.getDesc() << " puede completar sus tareas a tiempo." << endl;
        }
    }
}
