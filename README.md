https://github.com/Dalvelac/Examen-Parcial-3-Daniel-Alves/

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


Estructura del Proyecto

El proyecto consta de varias clases que son responsables de crear tareas, gestionar actores y ejecutar la secuencia de eventos. Los componentes principales del proyecto son:

Launcher: El punto de entrada principal que orquesta la ejecución general.

Actor: Representa a una persona responsable de tareas específicas.

Tarea: Representa una tarea con un ID único, descripción y duración.

Descripción de Archivos

Launcher.h/Launcher.cpp

Launcher es la clase central que crea tareas, crea actores, asigna tareas a los actores y muestra el resultado.

Métodos clave:

crearTareas(): Crea y devuelve una lista de tareas.

crearActores(): Crea y devuelve una lista de actores.

asignarTareas(): Asigna tareas a diferentes actores según el flujo lógico.

ejecutar(): Ejecuta el proceso completo, incluyendo la creación de tareas, su asignación y la impresión de resultados.

Actor.h/Actor.cpp

Representa a los actores involucrados en completar las tareas, como el CEO, el asistente personal, la agencia de viajes y el servicio de transporte.

Métodos clave:

addTarea(const Tarea&): Añade una tarea a la lista de tareas del actor.

getDuracionTotal(): Devuelve la duración total de las tareas asignadas al actor.

toString(): Proporciona una representación formateada del actor y sus tareas.

Tarea.h/Tarea.cpp

Representa las tareas que deben completarse.

Cada tarea tiene un ID, una descripción y una duración.

Métodos clave:

getId(), getDesc(), getDuracion(): Getters para el ID, descripción y duración.

toString(): Proporciona una representación formateada de la tarea.

main.cpp

El punto de entrada del programa que crea una instancia de Launcher y llama a su método ejecutar().

## Cómo Funciona el Código

### Creación de Tareas y Actores

La clase Launcher es responsable de crear una lista de tareas (crearTareas()) y una lista de actores (crearActores()), representando diferentes entidades involucradas en preparar al CEO para su reunión.

### Asignación de Tareas

El método asignarTareas() asigna tareas a los actores de acuerdo con sus responsabilidades. Por ejemplo, el CEO realiza la reserva de vuelo, el asistente personal se encarga de empacar, y el servicio de transporte lleva al CEO al aeropuerto.

### Ejecución del Proceso

El método ejecutar() ejecuta el proceso completo: primero crea las tareas y los actores, luego asigna las tareas a los actores, y finalmente muestra el resultado detallado, incluyendo cuánto tiempo lleva completar las tareas y si es posible cumplir con el tiempo límite de 100 minutos.

### Ejecución del Proyecto

Para ejecutar el proyecto:

### Compilar el proyecto:

Utiliza CMake para compilar el proyecto. Asegúrate de que todos los archivos fuente estén incluidos correctamente.

### Ejecutar el programa:

Una vez compilado, ejecuta el archivo ejecutable generado. Se mostrará el resumen de tareas por cada actor, junto con el tiempo total requerido.

### Ejemplo de Salida

La salida del programa muestra un resumen de las tareas asignadas a cada actor, el tiempo total para cada uno, y si es posible completar las tareas dentro del tiempo límite.
```  
=== Resumen de tareas por actor ===
Actor: CEO de la empresa
  Tarea 1: Tarea: Reserva de vuelo, Duracion: 20 minutos
Tiempo total para CEO de la empresa: 20 minutos
----------------------------------
Actor: Asistente Personal
  Tarea 1: Tarea: Informar a casa para empacar, Duracion: 5 minutos
  Tarea 2: Tarea: Empacar maletas, Duracion: 40 minutos
Tiempo total para Asistente Personal: 45 minutos
----------------------------------
Actor: Agencia de Viajes
  Tarea 1: Tarea: Preparacion del billete por la agencia, Duracion: 10 minutos
  Tarea 2: Tarea: Recoger el billete de la agencia, Duracion: 5 minutos
Tiempo total para Agencia de Viajes: 15 minutos
----------------------------------
Actor: Servicio de Transporte
  Tarea 1: Tarea: Viajar al aeropuerto y facturar, Duracion: 25 minutos
Tiempo total para Servicio de Transporte: 25 minutos
----------------------------------
=== Tiempo total para completar todas las tareas ===
Tiempo total: 105 minutos

=== Verificacion de tiempos ===
El actor CEO de la empresa puede completar sus tareas a tiempo.
El actor Asistente Personal puede completar sus tareas a tiempo.
El actor Agencia de Viajes puede completar sus tareas a tiempo.
El actor Servicio de Transporte puede completar sus tareas a tiempo.
``` 

En este ejemplo, cada actor tiene sus propias tareas, y el programa determina si es posible completar todas las tareas dentro del límite de 100 minutos.

