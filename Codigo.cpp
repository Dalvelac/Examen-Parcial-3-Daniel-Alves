#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Definicion de una tarea
struct Tarea {
    string nombre;
    int duracion;
    vector<int> dependencias; // Indices de tareas de las que depende
};

// Funcion para calcular el orden optimo
void calcularOrdenOptimo(Tarea tareas[], int n) {
    int gradoEntrada[13] = {0}; // Grado de entrada (dependencias) de cada tarea
    vector<int> ordenEjecucion;
    int tiempoTotal = 0;

    // Calcular el grado de entrada para cada tarea
    for (int i = 0; i < n; i++) {
        for (int dep : tareas[i].dependencias) {
            gradoEntrada[i]++;
        }
    }

    // Cola para procesar tareas con grado de entrada 0
    queue<int> cola;
    for (int i = 0; i < n; i++) {
        if (gradoEntrada[i] == 0) {
            cola.push(i);
        }
    }

    // Procesar tareas
    while (!cola.empty()) {
        int tareaActual = cola.front();
        cola.pop();
        ordenEjecucion.push_back(tareaActual);
        tiempoTotal += tareas[tareaActual].duracion;

        // Reducir el grado de entrada de las tareas dependientes
        for (int i = 0; i < n; i++) {
            if (find(tareas[i].dependencias.begin(), tareas[i].dependencias.end(), tareaActual) != tareas[i].dependencias.end()) {
                gradoEntrada[i]--;
                if (gradoEntrada[i] == 0) {
                    cola.push(i);
                }
            }
        }
    }

    // Verificar si se procesaron todas las tareas
    if (ordenEjecucion.size() != n) {
        cout << "No es posible completar las tareas debido a una dependencia ciclica.\n";
        return;
    }

    // Mostrar el resultado
    cout << "Orden optimo de ejecucion de las tareas:\n";
    for (int tarea : ordenEjecucion) {
        cout << tareas[tarea].nombre << " ";
    }
    cout << "\nTiempo total necesario: " << tiempoTotal << " minutos.\n";

    // Evaluar si es posible cumplir con el plazo de 100 minutos
    if (tiempoTotal <= 100) {
        cout << "Es posible completar las tareas dentro del limite de 100 minutos.\n";
    } else {
        cout << "No es posible completar las tareas dentro del limite de 100 minutos.\n";
    }
}

int main() {
    // Definicion de las tareas
    Tarea tareas[13] = {
        {"A", 20, {}},            // Reserva de vuelo
        {"B", 5, {}},             // Informar a casa para empacar
        {"C", 40, {1}},           // Empacar maletas (depende de B)
        {"D", 10, {0}},           // Preparacion del billete (depende de A)
        {"E", 5, {3}},            // Recoger el billete (depende de D)
        {"F", 10, {4}},           // Llevar el billete a la oficina (depende de E)
        {"G", 20, {2}},           // Recoger las maletas (depende de C)
        {"H", 25, {6}},           // Llevar maletas a la oficina (depende de G)
        {"I", 35, {}},            // Conversacion sobre documentos
        {"J", 25, {}},            // Dictar instrucciones
        {"K", 15, {8}},           // Reunir documentos (depende de I)
        {"L", 5, {10}},           // Organizar documentos (depende de K)
        {"M", 25, {5, 7, 11}}     // Viajar al aeropuerto (depende de F, H, L)
    };

    int n = 13; // Numero de tareas

    // Calcular el orden optimo y evaluar la viabilidad
    calcularOrdenOptimo(tareas, n);

    return 0;
}
