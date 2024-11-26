/*
 * Ustedes son Project Managers en una empresa internacional. Reciben una llamada urgente de un alto ejecutivo, informándoles que el CEO de la compañía ha aterrizado en Barcelona desde Estados Unidos y tiene una reunión crucial para las 19:30 en la ciudad. Sin embargo, el ejecutivo cuenta con solo 100 minutos antes de que cierre la facturación para su vuelo desde Madrid a Barcelona.

Objetivo: Debido a la urgencia de la situación, necesitan optimizar las tareas para cumplir con el objetivo de que el ejecutivo llegue a la reunión a tiempo. A continuación se detalla la lista de tareas necesarias, sus descripciones y las duraciones de cada una. Su misión es identificar las dependencias entre las tareas, calcular el tiempo total para completar las tareas en el orden adecuado, y determinar si es posible cumplir con el plazo de 100 minutos.

Tareas, Descripciones y Duraciones:

    A: Reserva de vuelo (20 min)
    B: Informar a casa para empacar (5 min)
    C: Empacar maletas (40 min)
    D: Preparación del billete por la agencia (10 min)
    E: Recoger el billete de la agencia (5 min)
    F: Llevar el billete a la oficina (10 min)
    G: Recoger las maletas de casa (20 min)
    H: Llevar maletas a la oficina (25 min)
    I: Conversación sobre documentos requeridos (35 min)
    J: Dictar instrucciones para ausencia (25 min)
    K: Reunir documentos (15 min)
    L: Organizar documentos (5 min)
    M: Viajar al aeropuerto y facturar (25 min)

Dependencias entre tareas:

    Algunas tareas deben ser realizadas antes que otras, por ejemplo, no se puede viajar al aeropuerto antes de haber recogido las maletas.
    Además, la reserva del vuelo debe completarse antes de recoger el billete, y la preparación del billete debe ocurrir antes de llevar el billete a la oficina.

Objetivos del Reto:

    Definir el Objetivo del Proyecto: Identificar el propósito principal del proyecto (optimizar la gestión del tiempo para cumplir con el plazo de 100 minutos) y no solo las tareas.

    Diagrama de Flujo del Cronograma: Crear un diagrama de flujo para visualizar el cronograma del proyecto, teniendo en cuenta solo las dependencias entre tareas y no restricciones de recursos.

    Desarrollo de Algoritmo en C++:
        Crear un programa en C++ que permita calcular el orden de ejecución de las tareas en función de sus dependencias.
        Determinar el tiempo total necesario para completar todas las tareas.
        Evaluar si es posible completar las tareas en 100 minutos o menos.
        Imprimir el orden óptimo de ejecución de las tareas y su tiempo total.
*/

/* Respuesta:
Persona 1 (P1):

0-20 min: A (Reserva de vuelo)
20-30 min: D (Preparación del billete por la agencia)
30-35 min: E (Recoger el billete de la agencia)
35-45 min: F (Llevar el billete a la oficina)
60-85 min: M (Viajar al aeropuerto y facturar)

Persona 2 (P2):

0-5 min: B (Informar a casa para empacar)
5-45 min: C (Empacar maletas)
45-65 min: G (Recoger las maletas de casa)
65-85 min: H (Llevar maletas a la oficina)

Persona 3 (P3):

0-35 min: I (Conversación sobre documentos requeridos)
35-50 min: K (Reunir documentos)
50-55 min: L (Organizar documentos)
55-80 min: J (Dictar instrucciones para ausencia)
*/

#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    string tarea[13] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"};
    string descripcion[13] = {"Reserva de vuelo", "Informar a casa para empacar", "Empacar maletas", "Preparación del billete por la agencia", "Recoger el billete de la agencia", "Llevar el billete a la oficina", "Recoger las maletas de casa", "Llevar maletas a la oficina", "Conversación sobre documentos requeridos", "Dictar instrucciones para ausencia", "Reunir documentos", "Organizar documentos", "Viajar al aeropuerto y facturar"};
    int duracion[13] =  {20, 5, 40, 10, 5, 10, 20, 25, 35, 25, 15, 5, 25};
    int dependencias[13] = {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1};

    cout << "Objetivos de el Proyecto: \n" << "Optimizar la gestión del tiempo para cumplir con el plazo de 100 minutos\n\n";
    cout << "Diagrama de Flujo del Cronograma: \n";
    cout << "Contaremos con la ayuda de 3 personas para realizar las tareas\n" << "Persona 1 (P1), que sería nosotros: \n" << "0-20 min: A (Reserva de vuelo)\n" << "20-30 min: D (Preparación del billete por la agencia)\n" << "30-35 min: E (Recoger el billete de la agencia)\n" << "35-45 min: F (Llevar el billete a la oficina)\n" << "60-85 min: M (Viajar al aeropuerto y facturar)\n\n" << "Persona 2 (P2): \n" << "0-5 min: B (Informar a casa para empacar)\n" << "5-45 min: C (Empacar maletas)\n" << "45-65 min: G (Recoger las maletas de casa)\n" << "65-85 min: H (Llevar maletas a la oficina)\n\n" << "Persona 3 (P3): \n" << "0-35 min: I (Conversación sobre documentos requeridos)\n" << "35-50 min: K (Reunir documentos)\n" << "50-55 min: L (Organizar documentos)\n" << "55-80 min: J (Dictar instrucciones para ausencia)\n\n";

    int tiempo_total_1 = 0;
    for (int i = 0; i < 13; i++) {
        tiempo_total_1 += duracion[i];
    }

    cout << "Tiempo total necesario para completar todas las tareas: " << tiempo_total << " minutos\n";

    return 0;
}
