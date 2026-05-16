#pragma once
#include <iostream>
#include <string>

using namespace std;

class Espacio {
private:
    string codigo;
    int nivel;
    string sector;
    bool estaOcupado;
    static int totalEspaciosCreados;

public:
    Espacio(const string& codigo, int nivel) : codigo(codigo), nivel(nivel) {
        sector = "";
        estaOcupado = false;
        totalEspaciosCreados++;
    }

    void asignarSector(const string& nuevoSector) {
        sector = nuevoSector;
    }

    void ocupar() {
        estaOcupado = true;
    }

    void desocupar() {
        estaOcupado = false;
    }

    void mostrarInformacion() {
        cout << "Codigo: " << codigo << " Nivel: " << nivel
            << " Sector: " << sector << " Ocupado: " << (estaOcupado ? "Si" : "No") << endl;
    }

    static void mostrarTotalEspaciosCreados() {
        cout << "Total espacios creados: " << totalEspaciosCreados << endl;
    }

    ~Espacio() {
        cout << "Espacio " << codigo << " destruido" << endl;
        totalEspaciosCreados--;
    }
};

int Espacio::totalEspaciosCreados = 0;