#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

class SistemaSuscripciones {
public:
    Usuario** usuarios;
    int cantidadUsuarios;
    int tamanioMax;

    SistemaSuscripciones(int maxUsuarios)
        : cantidadUsuarios(0), tamanioMax(maxUsuarios) {
        usuarios = new Usuario * [maxUsuarios];
    }

    bool existeEmail(const string& email) {
        for (int i = 0; i < cantidadUsuarios; i++) {
            if (usuarios[i]->email == email) {
                return true;
            }
        }
        return false;
    }

    void agregarUsuario(Usuario* nuevoUsuario) {
        if (existeEmail(nuevoUsuario->email)) {
            cout << "Error: Ya existe un usuario con email " << nuevoUsuario->email << endl;
            delete nuevoUsuario;
            return;
        }

        if (cantidadUsuarios < tamanioMax) {
            usuarios[cantidadUsuarios] = nuevoUsuario;
            cantidadUsuarios++;
            cout << "Usuario agregado exitosamente" << endl;
        }
        else {
            cout << "Error: No se pueden agregar mas usuarios" << endl;
            delete nuevoUsuario;
        }
    }

    void procesarTodasLasSuscripciones() {
        for (int i = 0; i < cantidadUsuarios; i++) {
            usuarios[i]->procesarTodasLasSuscripciones();
        }
    }

    void mostrarTodosLosUsuarios() {
        for (int i = 0; i < cantidadUsuarios; i++) {
            usuarios[i]->mostrarSuscripciones();
        }
    }

    float calcularTotalGeneral() {
        float total = 0;
        for (int i = 0; i < cantidadUsuarios; i++) {
            total += usuarios[i]->calcularTotalUsuario();
        }
        return total;
    }

    void mostrarTotalGeneral() {
        cout << "---" << endl;
        cout << "TOTAL GENERAL: " << calcularTotalGeneral() << endl;
    }

    ~SistemaSuscripciones() {
        for (int i = 0; i < cantidadUsuarios; i++) {
            delete usuarios[i];
        }
        delete[] usuarios;
    }
};

