#include "Greedy.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

// Elegimos primero el mayor beneficio por unidad de peso.
bool mayorRelacion(const Objeto& a, const Objeto& b) {
    // Un objeto de peso cero y valor positivo es gratuito: va primero.
    bool gratisA = (a.peso == 0 && a.valor > 0);
    bool gratisB = (b.peso == 0 && b.valor > 0);
    if (gratisA != gratisB) return gratisA;

    double razonA = (a.peso > 0) ? a.valor / a.peso : 0;
    double razonB = (b.peso > 0) ? b.valor / b.peso : 0;
    if (razonA != razonB) return razonA > razonB;
    return a.id < b.id; // Desempate reproducible.
}

void mochilaFraccional(Objeto objetos[], int n, double capacidad) {
    sort(objetos, objetos + n, mayorRelacion);

    double restante = capacidad;
    double total = 0;
    int seleccionados = 0;

    cout << "\n--- RESULTADO: MOCHILA FRACCIONAL ---\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        // Los objetos de valor cero no mejoran la solucion.
        if (objetos[i].valor <= 0) continue;

        double tomado = 0;
        if (objetos[i].peso == 0) {
            tomado = 0; // Se recibe todo su valor sin ocupar capacidad.
        } else if (restante > 0) {
            tomado = min(objetos[i].peso, restante);
        } else {
            continue;
        }

        double fraccion = (objetos[i].peso == 0) ? 1.0 : tomado / objetos[i].peso;
        double aporte = objetos[i].valor * fraccion;
        if (fraccion <= 0) continue;

        cout << "Objeto " << objetos[i].id << ": ";
        if (fraccion == 1.0) cout << "completo";
        else cout << setprecision(4) << (fraccion * 100) << "%" << setprecision(2);
        cout << " | peso utilizado: " << tomado
             << " | valor obtenido: " << aporte << "\n";

        total += aporte;
        restante -= tomado;
        seleccionados++;
    }

    if (seleccionados == 0) cout << "No se seleccionaron objetos.\n";
    cout << "Valor total: " << total << "\n";
    cout << "Capacidad sin usar: " << restante << "\n";
}

void coberturaAntenas(long long casas[], int n, long long rango) {
    sort(casas, casas + n);

    cout << "\n--- RESULTADO: COBERTURA DE ANTENAS ---\n";
    int i = 0;
    int cantidad = 0;

    while (i < n) {
        // La primera casa no cubierta esta en casas[i].
        // Colocamos la antena lo mas a la derecha posible: casas[i] + R.
        long long antena = casas[i] + rango;
        long long limiteDerecho = antena + rango;
        cantidad++;

        cout << "Antena " << cantidad << " en " << antena
             << " (cubre desde " << antena - rango
             << " hasta " << limiteDerecho << ")\n";

        // Saltamos todas las casas ya cubiertas por esta antena.
        while (i < n && casas[i] <= limiteDerecho) i++;
    }

    if (n == 0) cout << "No hay casas; no se requieren antenas.\n";
    cout << "Cantidad total de antenas: " << cantidad << "\n";
}
