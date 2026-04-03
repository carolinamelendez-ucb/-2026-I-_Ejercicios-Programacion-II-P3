#pragma once
#include <iostream>
using namespace std;

class Proyecto {
protected:
    string codigoProyecto;
    string nombreProyecto;

public:
    Proyecto(string cod, string nombre) {
        codigoProyecto = cod;
        nombreProyecto = nombre;
    }

    string getCodigo() { return codigoProyecto; }

    virtual float calcularCosto() = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Proyecto() {}
};