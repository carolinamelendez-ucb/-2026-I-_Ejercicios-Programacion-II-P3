#pragma once
#include <iostream>
#include <string>
#include "Suscripcion.h"

using namespace std;

class Usuario {
public:
    string nombre;
    string email;
    Suscripcion** suscripciones;
    int cantidadSuscripciones;
    int tamanioMax;

    Usuario(const string& nombre, const string& email, int maxSuscripciones)
        : nombre(nombre), email(email), cantidadSuscripciones(0), tamanioMax(maxSuscripciones) {
        suscripciones = new Suscripcion * [maxSuscripciones];
    }

    void agregarSuscripcion(PlanSuscripcion* plan) {
        if (cantidadSuscripciones < tamanioMax) {
            suscripciones[cantidadSuscripciones] = new Suscripcion(plan);
            cantidadSuscripciones++;
        }
        else {
            cout << "Error: No se pueden agregar mas suscripciones a " << nombre << endl;
        }
    }

    void procesarTodasLasSuscripciones() {
        for (int i = 0; i < cantidadSuscripciones; i++) {
            suscripciones[i]->procesar();
        }
    }

    void mostrarSuscripciones() {
        cout << "Usuario: " << nombre << endl;
        cout << "---" << endl;
        for (int i = 0; i < cantidadSuscripciones; i++) {
            cout << "Suscripcion " << i + 1 << ":" << endl;
            suscripciones[i]->mostrarDetalle();
            cout << endl;
        }
    }

    float calcularTotalUsuario() {
        float total = 0;
        for (int i = 0; i < cantidadSuscripciones; i++) {
            total += suscripciones[i]->costoFinal;
        }
        return total;
    }

    ~Usuario() {
        for (int i = 0; i < cantidadSuscripciones; i++) {
            delete suscripciones[i];
        }
        delete[] suscripciones;
    }
};

