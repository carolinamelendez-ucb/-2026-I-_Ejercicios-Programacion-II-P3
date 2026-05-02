#pragma once
#include <iostream>
#include <string>
using namespace std;

class Espacio {
private:
    string codigo;
    int    nivel;
    string sector;
    bool   estaOcupado;

public:
    Espacio(const string& codigo, int nivel, const string& sector)
        : codigo(codigo), nivel(nivel), sector(sector), estaOcupado(false) {
    }

    string getCodigo() {
        return codigo;
    }

    bool getEstaOcupado() {
        return estaOcupado;
    }

    void cambiarEstadoAOcupado() {
        estaOcupado = true;
    }

    void cambiarEstadoADisponible() {
        estaOcupado = false;
    }

    static bool compararCodigo(Espacio* espacioAcomparar, string codigo) {
        return espacioAcomparar->codigo == codigo;
    }

    static bool compararDisponibilidad(Espacio* espacioAcomparar, bool estaDisponible) {
        return espacioAcomparar->estaOcupado == estaDisponible;
    }

    void mostrar() {
        cout << "  Espacio [" << codigo << "] "
            << "Nivel: " << nivel << " | "
            << "Sector: " << sector << " | "
            << "Estado: " << (estaOcupado ? "Ocupado" : "Disponible")
            << endl;
    }
};
