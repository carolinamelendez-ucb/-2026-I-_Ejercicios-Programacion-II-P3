#pragma once
#include <string>
#include <iostream>
#include "Figura.h"
#include "Circulo.h"
#include "Rectangulo.h"

using namespace std;


class vectorFiguras {
private:
    Figura** figuras;
    int cantidad;
    int tamanio;
public:
    vectorFiguras(int tam) {
        this->cantidad = 0;
        this->tamanio = tam;
        this->figuras = new Figura * [tam];
    }

    void agregarFiguras(Figura* nvaFigura) {
        if (cantidad < tamanio) {
            figuras[cantidad] = nvaFigura;
            cantidad++;
        }
        else {
            cout << "No se puede agregar mas figuras" << endl;
        }
    }

    void calcularTodasLaAreas() {
        for (int i = 0;i < cantidad;i++) {
            cout << " Figura " << i + 1 << " Area: " << figuras[i]->calcularArea() << " m2 " << endl;
        }
    }
};