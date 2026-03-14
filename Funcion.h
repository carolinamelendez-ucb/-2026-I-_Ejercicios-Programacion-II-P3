#pragma once
#include "Sala.h"
#include "Pelicula.h"

class Funcion {

private:
    int codigo;
    Sala* sala;
    Pelicula* pelicula;
    int boletosVendidos;
    float precio;

public:

    Funcion(int codigo, Sala* sala, Pelicula* pelicula, float precio)
        : codigo(codigo), sala(sala), pelicula(pelicula), precio(precio)
    {
        boletosVendidos = 0;
    }

    void venderBoleto() {

        if (boletosVendidos < sala->getCapacidad()) {
            boletosVendidos++;
        }
        else {
            cout << "Sala llena" << endl;
        }
    }

    float getGanancia() {
        return boletosVendidos * precio;
    }

    Pelicula* getPelicula() {
        return pelicula;
    }

    void mostrar() {

        cout << "Funcion: " << codigo << endl;
        pelicula->mostrar();
        sala->mostrar();
        cout << "Boletos vendidos: " << boletosVendidos << endl;
    }
};