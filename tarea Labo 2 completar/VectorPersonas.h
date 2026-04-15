#pragma once
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

class VectorPersonas {
public:
    Persona** personas;
    int cantidad;
    int tamanio;

    VectorPersonas(int tamanioMax) {
        this->personas = new Persona * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    bool existeCi(int ci) {
        for (int i = 0; i < cantidad; i++) {
            if (personas[i]->ci == ci) {
                return true;
            }
        }
        return false;
    }

    void agregar(Persona* nuevaPersona) {
        if (existeCi(nuevaPersona->ci)) {
            cout << "Error: Ya existe una persona con CI " << nuevaPersona->ci << endl;
            delete nuevaPersona;
            return;
        }

        if (cantidad < tamanio) {
            personas[cantidad] = nuevaPersona;
            cantidad++;
            cout << "Persona agregada exitosamente" << endl;
        }
        else {
            cout << "Error: El vector esta lleno" << endl;
            delete nuevaPersona;
        }
    }

    Persona* buscarPorCi(int ci) {
        for (int i = 0; i < cantidad; i++) {
            if (personas[i]->ci == ci) {
                return personas[i];
            }
        }
        return nullptr;
    }

    void mostrarEstudiantes() {
        cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            if (personas[i]->esEstudiante()) {
                personas[i]->mostrarInformacion();
            }
        }
    }

    void mostrarDocentes() {
        cout << "\n=== LISTA DE DOCENTES ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            if (personas[i]->esDocente()) {
                personas[i]->mostrarInformacion();
            }
        }
    }

    Persona* getEstudianteQueMasPaga() {
        Persona* mayor = nullptr;
        float maxPago = -1;

        for (int i = 0; i < cantidad; i++) {
            if (personas[i]->esEstudiante()) {
                float pago = personas[i]->totalPagado;
                if (pago > maxPago) {
                    maxPago = pago;
                    mayor = personas[i];
                }
            }
        }
        return mayor;
    }

    ~VectorPersonas() {
        for (int i = 0; i < cantidad; i++) {
            delete personas[i];
        }
        delete[] personas;
    }
};