#pragma once
#include <iostream>
using namespace std;

class Transporte {
protected:
    string placaVehiculo;

public:
    Transporte(string p) {
        placaVehiculo = p;
    }

    string getPlaca() const {
        return placaVehiculo;
    }

    virtual float calcularCosto(float distancia) = 0;

    virtual ~Transporte() {}
};


class TransporteTerrestre : public Transporte {
public:
    TransporteTerrestre(string p) : Transporte(p) {}

    float calcularCosto(float distancia) override {
        float resultado = 0.5 * distancia;

        if (distancia > 100) {
            resultado = resultado + (resultado * 0.10);
        }

        return resultado;
    }
};


class TransporteAereo : public Transporte {
public:
    TransporteAereo(string p) : Transporte(p) {}

    float calcularCosto(float distancia) override {
        float total = 2 * distancia;

        if (distancia > 1000) {
            total = total - (total * 0.15);
        }

        return total;
    }
};


class TransporteMaritimo : public Transporte {
public:
    TransporteMaritimo(string p) : Transporte(p) {}

    float calcularCosto(float distancia) override {
        float costoFinal = distancia * 1.2;

        if (distancia > 500) {
            costoFinal = costoFinal + 50;
        }

        return costoFinal;
    }
};
