# Actividad 8 - Algoritmos Voraces (Greedy)

Curso: **Análisis y Diseño de Algoritmos**  
Lenguaje: **C++**  
Estudiante: Esteban Daniel Villagarcía Campos

## Problemas resueltos

1. **Mochila fraccional:** ordena los objetos por su relación `valor/peso` y selecciona cada objeto una sola vez (completo o parcialmente). También admite objetos gratuitos de peso cero y valor no negativo.
2. **Cobertura de antenas:** ordena las posiciones de las casas y coloca cada antena en `primera_casa_no_cubierta + R` para cubrir el máximo tramo posible hacia la derecha.

## Estructura

```
Actividad-8-Greedy/
├── src/
│   ├── main.cpp      # Menú y lectura de datos
│   ├── Greedy.h      # Estructura y declaraciones
│   └── Greedy.cpp    # Resolución de ambos problemas
├── pruebas/
│   ├── casos.txt            # Entradas de los ejemplos y casos límite
│   ├── resultados.txt       # Resultados obtenidos con el ejecutable
│   └── ejecutar_pruebas.sh  # Verifica los cuatro ejemplos
├── Informe_Actividad_8.pdf
└── README.md
```

## Compilar

Desde la carpeta raíz:

```
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/Greedy.cpp -o actividad8
```

## Ejecutar

```
./actividad8
```

En Windows (MinGW):

```
g++ -std=c++17 -Wall -Wextra src/main.cpp src/Greedy.cpp -o actividad8.exe
actividad8.exe
```

El menú permite seleccionar el ejercicio e ingresar cualquier cantidad de elementos entre 0 y 10000. Los valores y pesos deben ser no negativos. El rango `R` es entero de 0 a 2 000 000 000 y las posiciones de las casas están entre -2 000 000 000 y 2 000 000 000; estas restricciones evitan desbordamientos aritméticos. No se requiere ninguna biblioteca externa.

## Ejemplos rápidos

**Mochila, caso 1:** elige opción 1, escribe `3`, capacidad `50`, y los pares `60 10`, `100 20`, `120 30`. El valor total es `240.00`.

**Antenas, caso 1:** elige opción 2, escribe `7`, rango `5` y posiciones `1 2 7 11 20 21 30`. Las antenas quedan en `6` y `25`.

## Complejidad

Si `n` es el número de objetos o de casas, ambos algoritmos realizan un ordenamiento de `O(n log n)` seguido de un recorrido de `O(n)`. Por tanto, el tiempo total es **O(n log n)**.

Espacio: `O(n)` para los datos (arreglos estáticos acotados) y `O(log n)` auxiliar por el ordenamiento.

## Validación

Los casos de prueba están en `pruebas/casos.txt` y las salidas verificadas en `pruebas/resultados.txt`. Se comprobaron los dos ejemplos del enunciado para cada problema, entradas desordenadas, capacidad cero, rango cero y posiciones repetidas.

## Historial

Consulta los commits con `git log --oneline`.

## Informe académico

El informe completo con la explicación de las estrategias, el análisis de complejidad y los ejemplos de ejecución está en `Informe_Actividad_8.pdf`.
