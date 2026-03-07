#pragma once
#include <iostream>
#include "Equipo.h"

using namespace std;

class Competencia {

private:

    string nombre;
    Equipo** equipos;
    int maxEquipos;
    int indice;

public:

    Competencia(string nombre, int maxEquipos) {
        this->nombre = nombre;
        this->maxEquipos = maxEquipos;
        indice = 0;
        equipos = new Equipo * [maxEquipos];
    }

    bool socioYaRegistrado(Socio* s) {

        for (int i = 0; i < indice; i++) {

            if (equipos[i]->getPiloto() == s || equipos[i]->getCopiloto() == s)
                return true;
        }

        return false;
    }

    void agregarEquipo(Equipo* e) {

        if (indice >= maxEquipos) {
            cout << "Competencia llena\n";
            return;
        }

        if (socioYaRegistrado(e->getPiloto()) || socioYaRegistrado(e->getCopiloto())) {

            cout << "Error: un socio ya participa con otro equipo\n";
            return;
        }

        equipos[indice] = e;
        indice++;
    }

    void mostrar() {

        cout << "Competencia: " << nombre << endl;

        for (int i = 0; i < indice; i++) {

            cout << "Equipo " << i + 1 << endl;
            equipos[i]->mostrar();
            cout << endl;
        }
    }
};
