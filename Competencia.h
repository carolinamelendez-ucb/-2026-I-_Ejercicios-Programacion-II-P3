#pragma once
#include <iostream>
#include <string>
#include "VectorEquipos.h"
using namespace std;

class Competencia {
private:
    string nombreCompetencia;
    int maxEquipos;
    Equipo** equiposInscritos;
    int cantidadInscritos;
    int capacidad;

    void expandir() {
        int nuevaCapacidad = this->capacidad * 2;
        Equipo** nuevosEquipos = new Equipo * [nuevaCapacidad];

        for (int i = 0; i < this->cantidadInscritos; i++) {
            nuevosEquipos[i] = this->equiposInscritos[i];
        }

        delete[] this->equiposInscritos;
        this->equiposInscritos = nuevosEquipos;
        this->capacidad = nuevaCapacidad;
    }

public:
    Competencia(const string& nombreCompetencia, int maxEquipos) {
        this->nombreCompetencia = nombreCompetencia;
        this->maxEquipos = maxEquipos;
        this->capacidad = 10;
        this->cantidadInscritos = 0;
        this->equiposInscritos = new Equipo * [this->capacidad];
    }

    ~Competencia() {
        delete[] this->equiposInscritos;
        cout << "Destructor de Competencia: " << this->nombreCompetencia << endl;
    }

    string getNombreCompetencia() {
        return this->nombreCompetencia;
    }

    bool inscribirEquipo(Equipo* equipo) {
        // Verificar si ya se alcanzó el máximo de equipos
        if (this->cantidadInscritos >= this->maxEquipos) {
            cout << "No se puede inscribir: la competencia esta llena" << endl;
            return false;
        }

        // Verificar que ningún socio del equipo ya esté inscrito con otro equipo
        Socio* piloto = equipo->getPiloto();
        Socio* copiloto = equipo->getCopiloto();

        for (int i = 0; i < this->cantidadInscritos; i++) {
            if (this->equiposInscritos[i]->socioEnEquipo(piloto) ||
                this->equiposInscritos[i]->socioEnEquipo(copiloto)) {
                cout << "No se puede inscribir: un socio ya esta inscrito con otro equipo" << endl;
                return false;
            }
        }

        if (this->cantidadInscritos >= this->capacidad) {
            expandir();
        }
        this->equiposInscritos[this->cantidadInscritos] = equipo;
        this->cantidadInscritos++;
        cout << "Equipo inscrito exitosamente en la competencia" << endl;
        return true;
    }

    void mostrarInscritos() {
        cout << "\n=== COMPETENCIA: " << this->nombreCompetencia << " ===" << endl;
        cout << "Equipos inscritos (" << this->cantidadInscritos << "/"
            << this->maxEquipos << "):" << endl;
        for (int i = 0; i < this->cantidadInscritos; i++) {
            cout << i + 1 << ". ";
            this->equiposInscritos[i]->mostrar();
            cout << endl;
        }
    }
};
