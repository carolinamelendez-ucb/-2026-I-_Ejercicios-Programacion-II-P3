#pragma once
#include <iostream>
#include <string>
#include "CapacidadMaximaException.h"
using namespace std;

template <class T>
class ArrayGenerico {
private:
    T** lista;
    int tamanio;
    int indice;

public:
    ArrayGenerico(int max) {
        this->tamanio = max;
        this->lista = new T * [tamanio];
        this->indice = 0;
    }

    ~ArrayGenerico() {
        for (int i = 0; i < indice; i++) {
            delete lista[i];
        }
        delete[] lista;
    }

    void registrar(T* nuevoElemento) {
        if (indice < tamanio) {
            lista[indice] = nuevoElemento;
            indice++;
        }
        else {
            throw CapacidadMaximaException();
        }
    }

    T* buscar(string valorBuscado, bool (*funcionComparar)(T*, string)) {
        for (int i = 0; i < indice; i++) {
            if (funcionComparar(lista[i], valorBuscado)) {
                return lista[i];
            }
        }
        return nullptr;
    }

    T* buscar(bool valorBuscado, bool (*funcionComparar)(T*, bool)) {
        for (int i = 0; i < indice; i++) {
            if (funcionComparar(lista[i], valorBuscado)) {
                return lista[i];
            }
        }
        return nullptr;
    }

    void mostrar(bool valorBuscado, bool (*funcionComparar)(T*, bool)) {
        for (int i = 0; i < indice; i++) {
            if (funcionComparar(lista[i], valorBuscado)) {
                lista[i]->mostrar();
            }
        }
    }

    void mostrarTodos() {
        for (int i = 0; i < indice; i++) {
            lista[i]->mostrar();
        }
    }

    void ordenar(bool (*funcionComparar)(T*, T*)) {
        for (int i = 0; i < indice - 1; i++) {
            for (int j = 0; j < indice - i - 1; j++) {
                if (!funcionComparar(lista[j], lista[j + 1])) {
                    T* temp = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = temp;
                }
            }
        }
    }
};