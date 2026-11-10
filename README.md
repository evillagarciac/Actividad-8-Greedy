# Actividad 8 - Algoritmos Voraces (Greedy)

Curso: **Análisis y Diseño de Algoritmos**  
Lenguaje: **C++**  
Estudiante: Esteban Daniel Villagarcía Campos

## Problemas resueltos

1. **Mochila fraccional:** ordena los objetos por su relación `valor/peso` y selecciona cada objeto una sola vez (completo o parcialmente). También admite objetos gratuitos de peso cero y valor no negativo.
2. **Cobertura de antenas:** ordena las posiciones de las casas y coloca cada antena en `primera_casa_no_cubierta + R` para cubrir el máximo tramo posible hacia la derecha.

## Estructura

```text
Actividad_8_Greedy/
├── src/
│   ├── main.cpp      # Menú y lectura de datos
│   ├── Greedy.h       # Estructura y declaraciones
│   └── Greedy.cpp     # Resolución de ambos problemas
├── pruebas/
│   ├── casos.txt      # Entradas de los ejemplos y casos límite
│   ├── resultados.txt # Resultados obtenidos con el ejecutable
│   └── ejecutar_pruebas.sh # Verifica los cuatro ejemplos
├── Informe_Actividad_8.pdf
├── Informe_Actividad_8.docx
├── INSTRUCCIONES_GITHUB.md
├── historial_commits.txt
└── README.md
```

## Compilar

Desde la carpeta raíz:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/Greedy.cpp -o actividad8
```

## Ejecutar

```bash
./actividad8
```

En Windows (MinGW):

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp src/Greedy.cpp -o actividad8.exe
actividad8.exe
```

El menú permite seleccionar el ejercicio e ingresar cualquier cantidad de elementos entre 0 y 10000. Los valores y pesos deben ser no negativos. El rango `R` es entero de 0 a 2 000 000 000 y las posiciones de las casas están entre -2 000 000 000 y 2 000 000 000; estas restricciones evitan desbordamientos aritméticos. No se requiere ninguna biblioteca externa.

## Ejemplos rápidos

**Mochila, caso 1:** elige opción 1, escribe `3`, capacidad `50`, y los pares `60 10`, `100 20`, `120 30`. El valor total es `240.00`.

**Antenas, caso 1:** elige opción 2, escribe `7`, rango `5` y posiciones `1 2 7 11 20 21 30`. Las antenas quedan en `6` y `25`.

## Complejidad

Si `n` es el número de objetos o de casas, ambos algoritmos realizan un ordenamiento de `O(n log n)` seguido de un recorrido de `O(n)`. Por tanto, el tiempo total es **O(n log n)**. El almacenamiento de entrada usa arreglos estáticos acotados; el ordenamiento utiliza memoria auxiliar de pila típicamente `O(log n)`.

## Validación

Los casos de prueba están en `pruebas/casos.txt` y las salidas verificadas en `pruebas/resultados.txt`. Se comprobaron los dos ejemplos del enunciado para cada problema, entradas desordenadas, capacidad cero, rango cero y posiciones repetidas.

## Historial de cambios

El ZIP de entrega conserva la carpeta `.git` con commits locales para poder inspeccionar `git log --oneline`. Las instrucciones para publicar el proyecto sin perder esos commits están en `INSTRUCCIONES_GITHUB.md`.

## Informe académico

- Versión editable en Google Docs: https://docs.google.com/document/d/1pqOFR7p9tSOJQIYDeGN287rOeSLr9OqMcdTLFCPuwF4/edit