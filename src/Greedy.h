#ifndef GREEDY_H
#define GREEDY_H

// Cada objeto aparece una sola vez. El identificador conserva su numero original.
struct Objeto {
    int id;
    double valor;
    double peso;
};

// Ordena por valor/peso y permite tomar, como maximo, una fraccion de cada objeto.
void mochilaFraccional(Objeto objetos[], int n, double capacidad);

// Coloca antenas en cualquier punto entero de la recta para cubrir todas las casas.
void coberturaAntenas(long long casas[], int n, long long rango);

#endif
