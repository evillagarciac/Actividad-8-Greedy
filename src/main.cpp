#include "Greedy.h"
#include <iostream>

using namespace std;

// Limite de lectura para mantener el ejercicio sencillo y con arreglos estaticos.
const int MAX_DATOS = 10000;

void ejecutarMochila() {
    static Objeto objetos[MAX_DATOS];
    int n;
    double capacidad;

    cout << "\nCantidad de objetos (0 a " << MAX_DATOS << "): ";
    cin >> n;
    if (!cin || n < 0 || n > MAX_DATOS) {
        cout << "Cantidad invalida.\n";
        return;
    }

    cout << "Capacidad de la mochila: ";
    cin >> capacidad;
    if (!cin || capacidad < 0) {
        cout << "Capacidad invalida.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        objetos[i].id = i + 1;
        cout << "Objeto " << i + 1 << " - valor y peso: ";
        cin >> objetos[i].valor >> objetos[i].peso;
        if (!cin || objetos[i].valor < 0 || objetos[i].peso < 0) {
            cout << "Datos invalidos: valor y peso no pueden ser negativos.\n";
            return;
        }
    }

    mochilaFraccional(objetos, n, capacidad);
}

void ejecutarAntenas() {
    static long long casas[MAX_DATOS];
    int n;
    long long rango;

    cout << "\nCantidad de casas (0 a " << MAX_DATOS << "): ";
    cin >> n;
    if (!cin || n < 0 || n > MAX_DATOS) {
        cout << "Cantidad invalida.\n";
        return;
    }

    cout << "Rango de cobertura R (entero no negativo): ";
    cin >> rango;
    if (!cin || rango < 0 || rango > 2000000000LL) {
        cout << "Rango invalido.\n";
        return;
    }

    cout << "Escribe las posiciones de las casas: ";
    for (int i = 0; i < n; i++) {
        cin >> casas[i];
        if (!cin || casas[i] < -2000000000LL || casas[i] > 2000000000LL) {
            cout << "Posicion invalida.\n";
            return;
        }
    }

    coberturaAntenas(casas, n, rango);
}

int main() {
    int opcion;
    do {
        cout << "\n=================================\n";
        cout << "    ACTIVIDAD 8 - GREEDY\n";
        cout << "=================================\n";
        cout << "1. Mochila fraccional\n";
        cout << "2. Cobertura de antenas\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (!cin) {
            cout << "Entrada no numerica. Fin del programa.\n";
            break;
        }

        if (opcion == 1) ejecutarMochila();
        else if (opcion == 2) ejecutarAntenas();
        else if (opcion != 0) cout << "Opcion no valida.\n";
    } while (opcion != 0 && cin);

    cout << "Programa finalizado.\n";
    return 0;
}
