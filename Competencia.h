#pragma once
#include "equipo.h"

class Competencia {
private:
    Equipo** equipos;
    int indice;
    int maxEquipos;

public:
    Competencia(int maxEquipos) {
        this->maxEquipos = maxEquipos;
        indice = 0;
        equipos = new Equipo * [maxEquipos];
    }
    bool socioRepetido(Equipo* nuevo) {
        for (int i = 0; i < indice; i++) {
            if (equipos[i]->getPiloto() == nuevo->getPiloto() || equipos[i]->getPiloto() == nuevo->getCopiloto() ||
                equipos[i]->getCopiloto() == nuevo->getPiloto() || equipos[i]->getCopiloto() == nuevo->getCopiloto()) {
                return true;
            }
        }
        return false;
    }
    void agregarEquipo(Equipo* eq) {
        if (indice >= maxEquipos) {
            cout << "Competencia llena" << endl;
            return;
        }
        if (socioRepetido(eq)) {
            cout << "Un socio ya participa con otro equipo" << endl;
            return;
        }
        equipos[indice] = eq;
        indice++;
    }
    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << "Equipo " << i + 1 << endl;
            equipos[i]->mostrar();
            cout << endl;
        }
    }
};
