#pragma once
#include <iostream>
#include <string>

using namespace std;

class Asiento {
private:
    string codigoAsiento;
    bool estado;
public:
    Asiento(string codigo) {
        codigoAsiento = codigo;
        estado = false;
    }

    string getCodigo() { return codigoAsiento; }
    bool getEstado() { return estado; }

    void ocupar() { estado = true; }
    void liberar() { estado = false; }

    void mostrar() {
        cout << "Asiento: " << codigoAsiento << endl;
        cout << "Estado: " << (estado ? "Ocupado" : "Disponible") << endl;
    }
};
