# Examen Parcial 3 Daniel Alves

## Diagrama de Flujo

![Diagrama de flujo](https://github.com/Dalvelac/Examen-Parcial-3-Daniel-Alves/blob/main/Diagrama%20de%20flujo.png)
Creado utilizando lucid.app 

## Enunciado del ejercicio

Ustedes son Project Managers en una empresa internacional. Reciben una llamada urgente de un alto ejecutivo, informándoles que el CEO de la compañía ha aterrizado en Barcelona desde Estados Unidos y tiene una reunión crucial para las 19:30 en la ciudad. Sin embargo, el ejecutivo cuenta con solo 100 minutos antes de que cierre la facturación para su vuelo desde Madrid a Barcelona.

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

Restricciones:

    El tiempo máximo permitido para completar las tareas es de 100 minutos.
    El algoritmo debe gestionar de forma eficiente las dependencias entre las tareas, de tal manera que optimice el tiempo de ejecución.

Entrega:

    Código fuente en C++ que implemente la solución al problema.
    Diagrama de flujo que represente el cronograma de ejecución de las tareas.


## Explicación del codigo entregado [Codigo](https://github.com/linkdelcodigo)

El programa utiliza una estructura de datos simple para representar las tareas y sus dependencias, y asigna las tareas a tres personas para ejecutarlas en paralelo.
Estructura del Código

### Definición de la Estructura de una Tarea
Cada tarea se define como una estructura Tarea que incluye:
    nombre: El nombre de la tarea.
    duracion: El tiempo en minutos que toma completar la tarea.
    dependencias: Una lista de índices que representan las tareas de las que depende.

```
struct Tarea {
    string nombre;
    int duracion;
    vector<int> dependencias;
};
```

Algoritmo Principal: calcularOrdenOptimoConPersonas. Este es el núcleo del programa. Realiza las siguientes operaciones:

  -Cálculo del Grado de Entrada: Determina cuántas dependencias tiene cada tarea. Las tareas sin dependencias se agregan a una cola para ser procesadas primero.
  -Procesamiento de las Tareas: Las tareas se asignan a la persona disponible más pronto, respetando las dependencias. Cada persona tiene un contador de tiempo (tiemposPersonas) que se actualiza con la duración   de las tareas asignadas.
  -Reducción del Grado de Entrada: Cuando una tarea se completa, se reduce el grado de entrada de las tareas dependientes. Si el grado de entrada llega a 0, la tarea queda lista para ejecutarse.
  -Cálculo del Tiempo Total: El tiempo total requerido es el máximo entre los tiempos ocupados por las tres personas.

```
void calcularOrdenOptimoConPersonas(Tarea tareas[], int n) {
    int gradoEntrada[13] = {0};
    int tiemposPersonas[3] = {0, 0, 0};

    // Calcular grado de entrada
    for (int i = 0; i < n; i++) {
        for (int dep : tareas[i].dependencias) {
            gradoEntrada[i]++;
        }
    }

    // Asignar tareas a personas
    ...
}
```

Definición de las Tareas Las tareas se configuran con su nombre, duración y dependencias. Esto permite modelar el problema fácilmente.
```
Tarea tareas[13] = {
    {"A", 20, {}},  // Reserva de vuelo
    {"B", 5, {}},   // Informar a casa para empacar
    {"C", 40, {1}}, // Empacar maletas
    ...
};
``` 

### Resultado Final 

El programa calcula y muestra:

  - El orden óptimo de ejecución de las tareas.
  - El tiempo total necesario.
  - Si es posible completar las tareas dentro del límite de tiempo.
```
    cout << "Orden optimo de ejecucion de las tareas: ...";
    cout << "Tiempo total necesario con 3 personas: " << tiempoTotal << " minutos.\n";
```

### Ejemplo de Ejecución

Entrada de tareas:
```
A: Reserva de vuelo (20 minutos)
B: Informar a casa para empacar (5 minutos)
C: Empacar maletas (40 minutos), depende de B
```
...

Salida esperada:

```
Orden optimo de ejecucion de las tareas:
A B I J D E F C G H K L M 
Tiempo total necesario con 3 personas: 85 minutos.
Es posible completar las tareas dentro del limite de 100 minutos.
```

### Cómo Funciona

  - Se priorizan las tareas sin dependencias.
  - Cada tarea se asigna a la persona con el menor tiempo ocupado.
  - Las dependencias se actualizan dinámicamente para liberar tareas bloqueadas.

