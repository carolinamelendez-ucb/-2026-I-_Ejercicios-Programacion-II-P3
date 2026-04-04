#pragma once
#include <iostream>
using namespace std;

class Transporte {

protected:
    string placa;

public:
    Transporte(string placa) {
        this->placa = placa;
    }

    string getPlaca() {
        return placa;
    }

    virtual float calcularCosto(float distancia) = 0;

    virtual ~Transporte() {}
};


class TransporteTerrestre : public Transporte {

public:
    TransporteTerrestre(string placa) : Transporte(placa) {}

    float calcularCosto(float distancia) {

        float costo = distancia * 0.5;

        if (distancia > 100)
            costo *= 1.10;

        return costo;
    }
};


class TransporteAereo : public Transporte {

public:
    TransporteAereo(string placa) : Transporte(placa) {}

    float calcularCosto(float distancia) {

        float costo = distancia * 2.0;

        if (distancia > 1000)
            costo *= 0.85;

        return costo;
    }
};


class TransporteMaritimo : public Transporte {

public:
    TransporteMaritimo(string placa) : Transporte(placa) {}

    float calcularCosto(float distancia) {

        float costo = distancia * 1.2;

        if (distancia > 500)
            costo += 50;

        return costo;
    }
};