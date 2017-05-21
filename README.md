# CALCULO DE TIEMPOS DE BLOQUEOS

## Presentacion

Programa para el calculo de tiempos de bloqueo para tareas con prioridades inferiores a otras.

## Ejecucion

Para ejecutarlo hay que pasarle los valores en argumentos, la forma sera:

```
./nombre_programa c_i numero_iteraciones T_j... C_j...
```

Donde:

* **c_i**: Es el peor tiempo de ejecucion de una tarea.

* **numero_iteraciones**: Numero de iteraciones que queremos realizar.

* **T_j**: Los periodos de las tareas de prioridad superior

* **C_j**: Los tiempos de ejecucion de las tareas de prioridad superior.

Los tiempos de ejecucion *C_j* estaran a una distancia n de su periodo, siendo n el numero de tareas de prioridad superior.

Ejemplo:
```
# Para 2 tareas de prioridad superior de tiempos 20 y 30 respectivamente y periodos de 100 y 200; mi tarea tiene un tiempo de 25 y queremos hacer 10 iteraciones
llamaremos al programa asi:

$ ./nombre_programa 25 10 100 200 20 30
```

## Creditos

@author Jose Manuel Rodriguez Montes
@version 1.0, 22 de Mayo de 2017
GNU GENERAL PUBLIC LICENSE

## Futuras Versiones

* Documentacion en ingles.

* Incorporacion de tabla con listado de tareas. Eliminamos el proceso de pasar todo los datos por argumentos y calcular tarea a tarea.

* Posibilidad de busqueda de convergencia por parte del programa.