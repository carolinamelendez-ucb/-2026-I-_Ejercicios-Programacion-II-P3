#pragma once
#include <iostream>
#include <string>

using namespace std;

class Asiento {
private:
    string codigoAsiento;
    string estado;

public:
    Asiento() : codigoAsiento(""), estado("Disponible") {}

    Asiento(string _codigoAsiento) : codigoAsiento(_codigoAsiento), estado("Disponible") {}

    string obtenerCodigo() const { return codigoAsiento; }
    string obtenerEstado() const { return estado; }

    bool estaDisponible() const { return estado == "Disponible"; }
    bool estaOcupado() const { return estado == "Ocupado"; }

    void ocupar() {
        if (estaDisponible()) {
            estado = "Ocupado";
        }
    }

    void liberar() {
        if (estaOcupado()) {
            estado = "Disponible";
        }
    }
};