#pragma once
#include <iostream>
#include <string>
#include "Socio.h"
using namespace std;

class Equipo {
private:
    string nombreEquipo;
    string autoCompetencia;
    Socio* piloto;
    Socio* copiloto;

public:
    Equipo(const string& nombreEquipo, const string& autoCompetencia,
        Socio* piloto, Socio* copiloto) {
        this->nombreEquipo = nombreEquipo;
        this->autoCompetencia = autoCompetencia;
        this->piloto = piloto;
        this->copiloto = copiloto;
    }

    ~Equipo() {
        cout << "Destructor del equipo: " << this->nombreEquipo << endl;
        // No eliminamos los socios porque son compartidos
    }

    string getNombreEquipo() {
        return this->nombreEquipo;
    }

    string getAutoCompetencia() {
        return this->autoCompetencia;
    }

    Socio* getPiloto() {
        return this->piloto;
    }

    Socio* getCopiloto() {
        return this->copiloto;
    }

    void setNombreEquipo(const string& nuevoNombre) {
        this->nombreEquipo = nuevoNombre;
    }

    void setAutoCompetencia(const string& nuevoAuto) {
        this->autoCompetencia = nuevoAuto;
    }

    bool socioEnEquipo(Socio* socio) {
        return (this->piloto == socio || this->copiloto == socio);
    }

    void mostrar() {
        cout << "Equipo: " << this->nombreEquipo
            << ", Auto: " << this->autoCompetencia << endl;
        cout << "  Piloto: ";
        this->piloto->mostrar();
        cout << "  Copiloto: ";
        this->copiloto->mostrar();
    }
};