#include <iostream>
#include <string>
#include <exception>

#include "cliente.h"
#include "sala.h"
#include "pelicula.h"
#include "funcion.h"

using namespace std;

int main() {
    const int MAX = 10;
    Cliente<int> Clientes[MAX];
    Sala<int> Salas[MAX];
    Pelicula<int> Peliculas[MAX];
    Funcion<int> Funciones[MAX];
    int total_clientes = 0;
    int total_salas = 0;
    int total_peliculas = 0;
    int total_funciones = 0;

    // registrar clientes punto 1
    Clientes[total_clientes++] = Cliente<int>(1, "juan polo", "juan@mail.com");
    Clientes[total_clientes++] = Cliente<int>(2, "ana gomez", "ana@mail.com");

    // mostrar clientes punto 1
    cout << "=== mostrar clientes ===" << endl;
    for (int i = 0; i < total_clientes; i++) {
        Clientes[i].mostrar();
    }

    // registrar salas punto 2
    Salas[total_salas++] = Sala<int>(101, 8, 15);
    Salas[total_salas++] = Sala<int>(102, 10, 20);

    cout << "\n=== mostrar salas ===" << endl;
    for (int i = 0; i < total_salas; i++) {
        Salas[i].mostrar();
    }

    // registrar peliculas punto 3
    Peliculas[total_peliculas++] = Pelicula<int>(201, "el conjuro", 120);
    Peliculas[total_peliculas++] = Pelicula<int>(202, "toy story 4", 95);

    cout << "\n=== mostrar peliculas ===" << endl;
    for (int i = 0; i < total_peliculas; i++) {
        Peliculas[i].mostrar();
    }

    // registrar funciones punto 4
    Funciones[total_funciones++] = Funcion<int>(301, "18:00");
    Funciones[total_funciones++] = Funcion<int>(302, "20:30");

    // asignar pelicula a funcion punto 5
    try {
        Funciones[0].asignar_pelicula("el conjuro");
        Funciones[1].asignar_pelicula("touy story 4");
    }
    catch (const exception& e) {
        cout << "excepcion: " << e.what() << endl;
    }

    // asignar funcion a sala punto 6
    try {
        Funciones[0].asignar_sala("101");
        Funciones[1].asignar_sala("102");
    }
    catch (const exception& e) {
        cout << "excepcion: " << e.what() << endl;
    }

    // asignar cliente a funcion punto 7
    try {
        Funciones[0].asignar_cliente("juan polo");
        Funciones[1].asignar_cliente("ana gomez");
    }
    catch (const exception& e) {
        cout << "excepcion: " << e.what() << endl;
    }

    cout << "\n=== mostrar funciones con asignaciones ===" << endl;
    for (int i = 0; i < total_funciones; i++) {
        Funciones[i].mostrar();
    }

    return 0;
}