#pragma once
#include <iostream>
#include <string>
#include "Figura.h"

using namespace std;

class VectorFiguras {
private:
    Figura** figuras;
    int tamanio;
    int cantidad;

public:
    VectorFiguras(int tamanioMax) {
        this->figuras = new Figura * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    void agregar(Figura* nuevaFigura) {
        if (cantidad < tamanio) {
            figuras[cantidad] = nuevaFigura;
            cantidad++;
        }
        else {
            cout << "El vector esta lleno, no se puede agregar" << endl;
        }
    }

    void calcularTodasLasAreas() {
        for (int i = 0; i < cantidad; i++) {
            cout << "Figura " << i + 1 << " - Area: " << figuras[i]->calcularArea() << " m2" << endl;
        }
    }

    ~VectorFiguras() {
        for (int i = 0; i < cantidad; i++) {
            delete figuras[i];
        }
        delete[] figuras;
    }
};

