#pragma once
#include <iostream>
#include <string>

using namespace std;

class Organizador {

private:
    string nombre;
    int id;
    int rank;
    bool disponible;

public:
    Organizador(const string& nombre, int id)
        : nombre(nombre), id(id), rank(0), disponible(true)
    {
    }

    string getNombre() { return nombre; }
    int getRank() { return rank; }
    bool estaDisponible() { return disponible; }

    void ocupar() { disponible = false; }

    void liberar() { disponible = true; }

    void incrementarRank() { rank++; }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << id << endl;
        cout << "Rank: " << rank << endl;
        cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
    }

};